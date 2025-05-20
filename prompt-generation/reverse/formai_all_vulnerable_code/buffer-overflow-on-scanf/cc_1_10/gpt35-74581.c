//FormAI DATASET v1.0 Category: Ebook reader ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define constants
#define MAX_EBOOKS 1000
#define MAX_FILENAME_LENGTH 100
#define MAX_BOOK_TITLE_LENGTH 100
#define MAX_AUTHOR_NAME_LENGTH 100
#define MAX_PUBLISHER_NAME_LENGTH 100
#define MAX_YEAR_LENGTH 5
#define MAX_ISBN_LENGTH 20

// Define a structure to hold book details
typedef struct {
    char title[MAX_BOOK_TITLE_LENGTH];
    char author[MAX_AUTHOR_NAME_LENGTH];
    char publisher[MAX_PUBLISHER_NAME_LENGTH];
    char year[MAX_YEAR_LENGTH];
    char isbn[MAX_ISBN_LENGTH];
    char filename[MAX_FILENAME_LENGTH];
} ebook_t;

// Define an array to hold all ebooks
ebook_t ebooks[MAX_EBOOKS];

// Keep track of the number of ebooks in the array
int num_ebooks = 0;

// Function to add a new ebook to the array
void add_ebook(char *title, char *author, char *publisher, char *year, char *isbn, char *filename) {
    // Check if array is full
    if (num_ebooks >= MAX_EBOOKS) {
        printf("Error: Maximum number of ebooks reached.\n");
        return;
    }
    
    // Copy details to new ebook object
    strncpy(ebooks[num_ebooks].title, title, MAX_BOOK_TITLE_LENGTH);
    strncpy(ebooks[num_ebooks].author, author, MAX_AUTHOR_NAME_LENGTH);
    strncpy(ebooks[num_ebooks].publisher, publisher, MAX_PUBLISHER_NAME_LENGTH);
    strncpy(ebooks[num_ebooks].year, year, MAX_YEAR_LENGTH);
    strncpy(ebooks[num_ebooks].isbn, isbn, MAX_ISBN_LENGTH);
    strncpy(ebooks[num_ebooks].filename, filename, MAX_FILENAME_LENGTH);
    
    // Increment ebook count
    num_ebooks++;
}

// Function to print all ebook details to console
void print_ebooks() {
    int i;
    if (num_ebooks == 0) {
        printf("No ebooks found.\n");
        return;
    }
    printf("%-40s %-20s %-20s %-10s %s\n", "Title", "Author", "Publisher", "Year", "ISBN");
    printf("---------------------------------------------------------------------------------------------------\n");
    for (i = 0; i < num_ebooks; i++) {
        printf("%-40s %-20s %-20s %-10s %s\n", ebooks[i].title, ebooks[i].author, ebooks[i].publisher, ebooks[i].year, ebooks[i].isbn);
    }
}

// Function to search for an ebook by title
void search_ebook(char *title) {
    int i, found = 0;
    for (i = 0; i < num_ebooks; i++) {
        if (strcmp(ebooks[i].title, title) == 0) {
            printf("%-40s %-20s %-20s %-10s %s\n", "Title", "Author", "Publisher", "Year", "ISBN");
            printf("---------------------------------------------------------------------------------------------------\n");
            printf("%-40s %-20s %-20s %-10s %s\n", ebooks[i].title, ebooks[i].author, ebooks[i].publisher, ebooks[i].year, ebooks[i].isbn);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Error: Ebook not found.\n");
    }
}

// Main function
int main() {
    int choice;
    char title[MAX_BOOK_TITLE_LENGTH];
    char author[MAX_AUTHOR_NAME_LENGTH];
    char publisher[MAX_PUBLISHER_NAME_LENGTH];
    char year[MAX_YEAR_LENGTH];
    char isbn[MAX_ISBN_LENGTH];
    char filename[MAX_FILENAME_LENGTH];
    
    while (1) {
        printf("1. Add new ebook\n");
        printf("2. View all ebooks\n");
        printf("3. Search ebook by title\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter ebook title: ");
                scanf(" %[^\n]%*c", title);
                printf("Enter author name: ");
                scanf(" %[^\n]%*c", author);
                printf("Enter publisher name: ");
                scanf(" %[^\n]%*c", publisher);
                printf("Enter publication year: ");
                scanf("%s", year);
                printf("Enter ISBN: ");
                scanf("%s", isbn);
                printf("Enter ebook filename: ");
                scanf(" %[^\n]%*c", filename);
                add_ebook(title, author, publisher, year, isbn, filename);
                break;
            case 2:
                print_ebooks();
                break;
            case 3:
                printf("Enter ebook title to search: ");
                scanf(" %[^\n]%*c", title);
                search_ebook(title);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}