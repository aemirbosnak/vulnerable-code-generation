//FormAI DATASET v1.0 Category: Ebook reader ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_TITLE_LEN 50
#define MAX_AUTHOR_LEN 20
#define MAX_FILENAME_LEN 20

struct Book {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
};

int read_books(char *filename, struct Book *books[]);
void display_books(struct Book *books[], int num_books);
void free_memory(struct Book *books[], int num_books);

int main() {
    printf("Welcome to the Ebook Reader!\n");
    
    // Allocate memory for books
    struct Book *books[MAX_BOOKS];
    
    // Read books from file
    char filename[MAX_FILENAME_LEN];
    printf("Enter filename to read books from: ");
    scanf("%s", filename);
    
    int num_books = read_books(filename, books);
    if (num_books == -1) {
        printf("Error: Could not read from file\n");
        return 1;
    }
    
    // Display books
    display_books(books, num_books);
    
    // Free memory
    free_memory(books, num_books);
    
    return 0;
}

// Read books from file and store them in an array of Book structures
int read_books(char *filename, struct Book *books[]) {
    FILE *fp = fopen(filename, "r");
    if (!fp) return -1; // Error reading file
    
    int num_books = 0;
    char line[MAX_TITLE_LEN + MAX_AUTHOR_LEN + 2];
    char *token, *ptr;
    
    // Read each line and store book data in struct
    while (fgets(line, MAX_TITLE_LEN + MAX_AUTHOR_LEN + 2, fp)) {
        if (num_books >= MAX_BOOKS) break;
        
        // Split line at comma
        token = strtok(line, ",");
        if (token == NULL) continue;
        
        // Copy title to book struct
        ptr = token;
        while (*ptr == ' ') ptr++; // Skip spaces
        strncpy(books[num_books]->title, ptr, MAX_TITLE_LEN);
        books[num_books]->title[MAX_TITLE_LEN - 1] = '\0'; // Make sure string is terminated
        
        // Split again at comma to get author name
        token = strtok(NULL, ",");
        if (token == NULL) continue;
        
        // Copy author to book struct
        ptr = token;
        while (*ptr == ' ') ptr++; // Skip spaces
        strncpy(books[num_books]->author, ptr, MAX_AUTHOR_LEN);
        books[num_books]->author[MAX_AUTHOR_LEN - 1] = '\0'; // Make sure string is terminated
        
        num_books++;
    }
    
    fclose(fp);
    return num_books;
}

// Display array of Book structs
void display_books(struct Book *books[], int num_books) {
    printf("List of books:\n");
    for (int i = 0; i < num_books; i++) {
        printf("%s by %s\n", books[i]->title, books[i]->author);
    }
}

// Free allocated memory for array of Book structs
void free_memory(struct Book *books[], int num_books) {
    for (int i = 0; i < num_books; i++) {
        free(books[i]);
    }
}