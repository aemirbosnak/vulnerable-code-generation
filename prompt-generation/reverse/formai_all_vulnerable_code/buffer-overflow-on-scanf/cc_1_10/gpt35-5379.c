//FormAI DATASET v1.0 Category: Ebook reader ; Style: invasive
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LEN 1000

// Structure to hold book information
struct Book {
    char title[MAX_LEN];
    char author[MAX_LEN];
    char publisher[MAX_LEN];
    char genre[MAX_LEN];
};

// Function to read book information from file
void read_book_info(struct Book* book, FILE* fp) {
    char line[MAX_LEN];
    fgets(line, MAX_LEN, fp);
    strcpy(book->title, line);
    
    fgets(line, MAX_LEN, fp);
    strcpy(book->author, line);
    
    fgets(line, MAX_LEN, fp);
    strcpy(book->publisher, line);
    
    fgets(line, MAX_LEN, fp);
    strcpy(book->genre, line);
}

// Function to display book information
void display_book_info(const struct Book* book) {
    printf("Title: %s", book->title);
    printf("Author: %s", book->author);
    printf("Publisher: %s", book->publisher);
    printf("Genre: %s", book->genre);
}

// Function to read user choice
int read_choice() {
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Main function
int main() {
    printf("Welcome to EBook Reader!\n");
    
    // Open books list file
    FILE* fp = fopen("books.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open books list file\n");
        return -1;
    }
    
    // Read books information
    struct Book books[5];
    for (int i = 0; i < 5; i++) {
        read_book_info(&books[i], fp);
    }
    
    // Close books list file
    fclose(fp);
    
    int choice;
    do {
        // Display menu options
        printf("\nMenu Options:");
        printf("\n1. List all books");
        printf("\n2. Search a book");
        printf("\n3. Exit");
        
        // Read user choice
        choice = read_choice();
        
        switch (choice) {
            case 1:
                // Display all books information
                printf("\nAll books information:\n\n");
                for (int i = 0; i < 5; i++) {
                    display_book_info(&books[i]);
                }
                break;
                
            case 2: {
                // Search a book
                char title[MAX_LEN];
                printf("\nEnter book title to search: ");
                getchar(); // To flush the newline character from input
                fgets(title, MAX_LEN, stdin);
                
                // Remove newline character from title
                title[strlen(title)-1] = '\0';
                
                // Search book
                int found = 0;
                for (int i = 0; i < 5; i++) {
                    if (strcmp(books[i].title, title) == 0) {
                        printf("\nBook found:\n\n");
                        display_book_info(&books[i]);
                        found = 1;
                        break;
                    }
                }
                
                // If book not found
                if (!found) {
                    printf("\nBook not found\n");
                }
                break;
            }
                
            case 3:
                // Exit
                printf("\nThanks for using EBook Reader!\n");
                break;
                
            default:
                printf("\nInvalid choice! Please enter valid choice\n");
                break;
        }
    } while (choice != 3);
    
    return 0;
}