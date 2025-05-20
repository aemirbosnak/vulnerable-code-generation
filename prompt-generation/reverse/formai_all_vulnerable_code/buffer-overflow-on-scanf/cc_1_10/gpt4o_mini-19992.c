//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_BOOKSHELF 100
#define BUFFER_SIZE 4096

typedef struct {
    char title[100];
    char author[100];
    char *content;
    int total_pages;
} Ebook;

Ebook *create_ebook(const char *filename);
void read_ebook(Ebook *ebook);
void display_page(Ebook *ebook, int page);
void cleanup_ebook(Ebook *ebook);
void print_menu();

int main() {
    char filename[100];
    Ebook *ebook = NULL;
    int current_page = 0;

    print_menu();
    printf("Enter the filename of the ebook to read: ");
    scanf("%s", filename);

    ebook = create_ebook(filename);
    if (ebook == NULL) {
        fprintf(stderr, "Failed to load ebook from %s\n", filename);
        return EXIT_FAILURE;
    }

    while (1) {
        display_page(ebook, current_page);
        
        char command;
        printf("Enter command (n - next page, p - previous page, q - quit): ");
        scanf(" %c", &command);
        
        if (command == 'n') {
            current_page++;
            if (current_page >= ebook->total_pages) {
                printf("You are at the end of the book.\n");
                current_page = ebook->total_pages - 1;
            }
        } else if (command == 'p') {
            current_page--;
            if (current_page < 0) {
                printf("You are at the beginning of the book.\n");
                current_page = 0;
            }
        } else if (command == 'q') {
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    cleanup_ebook(ebook);
    return EXIT_SUCCESS;
}

Ebook *create_ebook(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return NULL;
    }

    Ebook *ebook = malloc(sizeof(Ebook));
    if (!ebook) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return NULL;
    }

    strncpy(ebook->title, "Untitled", sizeof(ebook->title));
    strncpy(ebook->author, "Unknown", sizeof(ebook->author));
    ebook->content = malloc(BUFFER_SIZE);
    if (!ebook->content) {
        fprintf(stderr, "Memory allocation for content failed\n");
        fclose(file);
        free(ebook);
        return NULL;
    }

    char line[MAX_LINE_LENGTH];
    size_t content_length = 0;

    // Read each line and append to content
    while (fgets(line, sizeof(line), file)) {
        content_length += strlen(line);
        if (content_length >= BUFFER_SIZE) {
            fprintf(stderr, "Content size exceeding buffer limits\n");
            break;
        }
        strcat(ebook->content, line);
    }

    fclose(file);
    
    // Assume that content contains a certain number of pages.
    ebook->total_pages = (content_length / MAX_LINE_LENGTH) + 1;

    return ebook;
}

void display_page(Ebook *ebook, int page) {
    printf("\n--- Page %d of %d ---\n", page + 1, ebook->total_pages);
    
    int start_line = page * MAX_LINE_LENGTH;
    int end_line = start_line + MAX_LINE_LENGTH;

    // Display the part of the content according to the page
    char *current_pos = ebook->content + start_line;
    for (int i = start_line; i < end_line && *current_pos != '\0'; i++) {
        putchar(*current_pos++);
    }
    printf("\n");
}

void cleanup_ebook(Ebook *ebook) {
    if (ebook) {
        free(ebook->content);
        free(ebook);
    }
}

void print_menu() {
    printf("Welcome to the E-Book Reader!\n");
    printf("Commands:\n");
    printf("n - Next Page\n");
    printf("p - Previous Page\n");
    printf("q - Quit\n");
}