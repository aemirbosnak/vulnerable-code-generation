//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define BUFFER_SIZE 1024

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_TITLE_LENGTH];
    int pages;
    char *content;
} Book;

Book library[MAX_BOOKS];
int book_count = 0;

void load_book(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open book file");
        return;
    }

    Book new_book;
    printf("Loading book: %s\n", filename);

    // Read title
    fgets(new_book.title, sizeof(new_book.title), file);
    new_book.title[strcspn(new_book.title, "\n")] = 0; // Remove newline

    // Read author
    fgets(new_book.author, sizeof(new_book.author), file);
    new_book.author[strcspn(new_book.author, "\n")] = 0; // Remove newline

    // Read number of pages
    fscanf(file, "%d\n", &new_book.pages);
    
    // Load content into a dynamic string
    new_book.content = malloc(BUFFER_SIZE * new_book.pages);
    if (!new_book.content) {
        perror("Failed to allocate memory for book content");
        fclose(file);
        return;
    }
    
    char buffer[BUFFER_SIZE];
    size_t content_length = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        size_t len = strlen(buffer);
        if (content_length + len >= BUFFER_SIZE * new_book.pages) {
            break; // Prevent overflow
        }
        strcpy(new_book.content + content_length, buffer);
        content_length += len;
    }

    library[book_count] = new_book;
    book_count++;
    fclose(file);
    printf("Book loaded: %s by %s, Pages: %d\n", new_book.title, new_book.author, new_book.pages);
}

void display_book(int index) {
    if (index < 0 || index >= book_count) {
        printf("Invalid book index.\n");
        return;
    }
    
    Book *book = &library[index];
    printf("\n--- Now Reading: %s by %s ---\n", book->title, book->author);
    
    int start_page = 1;
    char choice;

    do {
        printf("Page %d of %d:\n", start_page, book->pages);
        // Display content for the current page:
        for (int i = (start_page - 1) * BUFFER_SIZE; i < start_page * BUFFER_SIZE && i < strlen(book->content); i++) {
            putchar(book->content[i]);
        }
        
        printf("\n\nPress 'n' for next page, 'p' for previous page, 'q' to quit reading: ");
        choice = getchar();
        while (getchar() != '\n'); // Clear input buffer
        
        if (choice == 'n' && start_page < book->pages) {
            start_page++;
        } else if (choice == 'p' && start_page > 1) {
            start_page--;
        } else if (choice == 'q') {
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }

    } while (1);
    printf("--- Finished reading: %s ---\n", book->title);
}

void free_books() {
    for (int i = 0; i < book_count; i++) {
        free(library[i].content);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <book1.txt> <book2.txt> ...\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        load_book(argv[i]);
    }

    int choice;
    do {
        printf("\nLibrary:\n");
        for (int i = 0; i < book_count; i++) {
            printf("%d. %s by %s\n", i + 1, library[i].title, library[i].author);
        }

        printf("Select a book to read (1-%d) or 0 to exit: ", book_count);
        scanf("%d", &choice);
        while (getchar() != '\n'); // Clear input buffer

        if (choice > 0 && choice <= book_count) {
            display_book(choice - 1);
        } else if (choice != 0) {
            printf("Invalid choice. Please select a valid book.\n");
        }

    } while (choice != 0);

    free_books();
    printf("Exiting the eBook reader. Goodbye!\n");
    return 0;
}