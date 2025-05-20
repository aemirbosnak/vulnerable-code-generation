//FormAI DATASET v1.0 Category: File handling ; Style: lively
#include<stdio.h>
#include<stdlib.h>

// structure to hold information about a book
struct Book {
    char title[50];
    char author[50];
    int num_pages;
    float price;
};

// function to add a new book to the library
void add_book() {
    struct Book book;
    
    printf("Enter book title: ");
    scanf("%s", book.title);
    
    printf("Enter book author: ");
    scanf("%s", book.author);
    
    printf("Enter number of pages: ");
    scanf("%d", &book.num_pages);
    
    printf("Enter price: ");
    scanf("%f", &book.price);
    
    // open file in write mode
    FILE *file = fopen("library.txt", "a");
    
    // check if file opened successfully
    if (file == NULL) {
        printf("Error opening file!");
        exit(1);
    }
    
    // write book data to file
    fprintf(file, "%s,%s,%d,%.2f\n", book.title, book.author, book.num_pages, book.price);
    
    // close file
    fclose(file);
    
    printf("\nBook added to library successfully!\n\n");
}

// function to display all books in the library
void display_books() {
    printf("Books in library:\n");
    
    // open file in read mode
    FILE *file = fopen("library.txt", "r");
    
    // check if file opened successfully
    if (file == NULL) {
        printf("Error opening file!");
        exit(1);
    }
    
    // read each line of file and display book data
    char line[100];
    while (fgets(line, 100, file) != NULL) {
        char *token = strtok(line, ",");
        printf("\nTitle: %s", token);
        
        token = strtok(NULL, ",");
        printf("\nAuthor: %s", token);
        
        token = strtok(NULL, ",");
        printf("\nNumber of pages: %s", token);
        
        token = strtok(NULL, ",");
        printf("\nPrice: %s\n", token);
    }
    
    // close file
    fclose(file);
}

int main() {
    int choice;
    
    printf("Welcome to the library!\n");
    
    while (1) {
        printf("Please choose an option:\n");
        printf("1. Add a book\n");
        printf("2. Display all books\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                display_books();
                break;
            case 3:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice\n\n");
        }
    }
    
    return 0;
}