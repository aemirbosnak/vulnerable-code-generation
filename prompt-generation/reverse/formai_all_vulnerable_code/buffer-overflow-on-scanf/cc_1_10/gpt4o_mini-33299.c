//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_SIZE 20
#define MAX_PAGES 100
#define FILE_NAME_SIZE 100

typedef struct {
    char **pages;
    int total_pages;
} eBook;

eBook* load_eBook(const char *filename);
void display_page(eBook *book, int page_number);
void free_eBook(eBook *book);
void navigate(eBook *book);

int main() {
    char filename[FILE_NAME_SIZE];

    printf("Enter the filename of the eBook: ");
    scanf("%s", filename);

    eBook *book = load_eBook(filename);
    if (book == NULL) {
        printf("Error loading eBook\n");
        return 1;
    }

    navigate(book);
    free_eBook(book);
    return 0;
}

eBook* load_eBook(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return NULL;
    }

    eBook *book = (eBook *)malloc(sizeof(eBook));
    book->pages = (char **)malloc(MAX_PAGES * sizeof(char *));
    for (int i = 0; i < MAX_PAGES; i++) {
        book->pages[i] = (char *)malloc(PAGE_SIZE * sizeof(char));
    }

    int page_number = 0;
    while (fgets(book->pages[page_number], PAGE_SIZE, file) && page_number < MAX_PAGES) {
        page_number++;
    }
    book->total_pages = page_number;
    fclose(file);
    return book;
}

void display_page(eBook *book, int page_number) {
    if (page_number < 0 || page_number >= book->total_pages) {
        printf("Invalid page number!\n");
        return;
    }
    printf("Page %d:\n", page_number + 1);
    printf("%s", book->pages[page_number]);
}

void navigate(eBook *book) {
    int current_page = 0;
    char command;

    while (1) {
        display_page(book, current_page);
        printf("Navigate: (n) Next, (p) Previous, (q) Quit: ");
        scanf(" %c", &command);

        if (command == 'n') {
            if (current_page < book->total_pages - 1) {
                current_page++;
            } else {
                printf("You are already on the last page.\n");
            }
        } else if (command == 'p') {
            if (current_page > 0) {
                current_page--;
            } else {
                printf("You are already on the first page.\n");
            }
        } else if (command == 'q') {
            break;
        } else {
            printf("Invalid command! Please try again.\n");
        }
    }
}

void free_eBook(eBook *book) {
    for (int i = 0; i < MAX_PAGES; i++) {
        free(book->pages[i]);
    }
    free(book->pages);
    free(book);
}