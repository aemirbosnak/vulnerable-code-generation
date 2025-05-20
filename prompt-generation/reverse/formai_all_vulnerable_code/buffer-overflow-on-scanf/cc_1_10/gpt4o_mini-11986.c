//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_SIZE 20
#define MAX_TITLE_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char **pages;
    int total_pages;
} eBook;

eBook* load_ebook(const char *filename);
void display_page(eBook *book, int page_number);
void free_ebook(eBook *book);

int main(void) {
    char filename[100];
    printf("Welcome to the eBook Reader!\n");
    printf("Please enter the filename of the ebook: ");
    scanf("%s", filename);

    eBook *book = load_ebook(filename);
    if (!book) {
        printf("Error: could not load the ebook.\n");
        return 1;
    }

    int current_page = 0;
    char command;

    while (1) {
        display_page(book, current_page);
        printf("\nCommands: [n] for next page, [p] for previous page, [q] to quit: ");
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
            printf("Exiting the eBook Reader. Goodbye!\n");
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    free_ebook(book);
    return 0;
}

eBook* load_ebook(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    eBook *book = malloc(sizeof(eBook));
    if (!book) {
        perror("Unable to allocate memory for the eBook");
        fclose(file);
        return NULL;
    }

    printf("Enter a title for the ebook: ");
    scanf(" %[^\n]", book->title);  // Read the title of the ebook

    book->pages = malloc(sizeof(char*) * 100);  // Allocate for a maximum of 100 pages
    if (!book->pages) {
        perror("Unable to allocate memory for pages");
        free(book);
        fclose(file);
        return NULL;
    }

    int page_count = 0;
    char buffer[256];

    while (fgets(buffer, sizeof(buffer), file) && page_count < 100) {
        book->pages[page_count] = malloc(PAGE_SIZE);
        snprintf(book->pages[page_count], PAGE_SIZE, "%s", buffer);
        page_count++;
    }

    book->total_pages = page_count;
    fclose(file);
    
    printf("Successfully loaded eBook: %s with %d pages.\n", book->title, book->total_pages);
    return book;
}

void display_page(eBook *book, int page_number) {
    printf("\n--- Page %d of %d ---\n", page_number + 1, book->total_pages);
    printf("%s", book->pages[page_number]);
}

void free_ebook(eBook *book) {
    for (int i = 0; i < book->total_pages; i++) {
        free(book->pages[i]);
    }
    free(book->pages);
    free(book);
}