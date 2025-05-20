//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_BOOKS 10
#define MAX_BOOK_TITLE 100

typedef struct {
    char title[MAX_BOOK_TITLE];
    FILE *file;
} Book;

Book library[MAX_BOOKS];
int book_count = 0;

void add_book(const char *filename) {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }
    
    library[book_count].file = fopen(filename, "r");
    if (!library[book_count].file) {
        printf("Error opening file: %s\n", filename);
        return;
    }
    
    strncpy(library[book_count].title, filename, MAX_BOOK_TITLE);
    library[book_count].title[MAX_BOOK_TITLE - 1] = '\0';
    book_count++;
    printf("Added book: %s\n", filename);
}

void display_books() {
    printf("Available books:\n");
    for (int i = 0; i < book_count; i++) {
        printf("%d. %s\n", i + 1, library[i].title);
    }
}

void read_book(int index) {
    char line[MAX_LINE_LENGTH];
    if (index < 0 || index >= book_count) {
        printf("Invalid book selection.\n");
        return;
    }
    
    printf("Reading %s...\n", library[index].title);
    while (fgets(line, sizeof(line), library[index].file)) {
        printf("%s", line);
    }
    fclose(library[index].file);
    library[index].file = NULL;  // Book is no longer open
    printf("End of %s.\n", library[index].title);
}

int main() {
    char command[10];
    char filename[MAX_BOOK_TITLE];

    while (1) {
        printf("Enter command (add, list, read, exit): ");
        scanf("%s", command);
        
        if (strcmp(command, "add") == 0) {
            printf("Enter filename to add: ");
            scanf("%s", filename);
            add_book(filename);
        } else if (strcmp(command, "list") == 0) {
            display_books();
        } else if (strcmp(command, "read") == 0) {
            int index;
            printf("Enter book number to read: ");
            scanf("%d", &index);
            read_book(index - 1);  // Convert to zero-based index
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the Ebook Reader. Goodbye!\n");
            break;
        } else {
            printf("Unknown command: %s\n", command);
        }
    }
    
    // Freeing allocated resources (if any were used)
    for (int i = 0; i < book_count; i++) {
        if (library[i].file) {
            fclose(library[i].file);
        }
    }
    
    return 0;
}