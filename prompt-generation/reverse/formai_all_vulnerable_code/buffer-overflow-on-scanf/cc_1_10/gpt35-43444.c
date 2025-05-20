//FormAI DATASET v1.0 Category: Ebook reader ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

struct Book {
    char title[50];
    char author[50];
    char genre[50];
    int pageCount;
    float price;
    char fileName[50];
};

int main() {
    int bookCount;
    struct Book *bookList;
    
    // Get the number of books
    printf("How many books do you want to read? ");
    scanf("%d", &bookCount);
    
    // Allocate memory for the bookList
    bookList = (struct Book*) malloc(bookCount * sizeof(struct Book));
    
    // Get details for each book
    for (int i = 0; i < bookCount; i++) {
        printf("Enter details for book %d:\n", i+1);
        printf("Title: ");
        scanf("%s", bookList[i].title);
        printf("Author: ");
        scanf("%s", bookList[i].author);
        printf("Genre: ");
        scanf("%s", bookList[i].genre);
        printf("Page count: ");
        scanf("%d", &bookList[i].pageCount);
        printf("Price: ");
        scanf("%f", &bookList[i].price);
        printf("File name: ");
        scanf("%s", bookList[i].fileName);
    }
    
    // Print book details
    for (int i = 0; i < bookCount; i++) {
        printf("\nBook %d details:\n", i+1);
        printf("Title: %s\n", bookList[i].title);
        printf("Author: %s\n", bookList[i].author);
        printf("Genre: %s\n", bookList[i].genre);
        printf("Page count: %d\n", bookList[i].pageCount);
        printf("Price: %.2f\n", bookList[i].price);
        printf("File name: %s\n", bookList[i].fileName);
    }
    
    // Set default book
    int defaultBook = 1;
    
    // Get user input for book selection
    printf("\nEnter book number to read (default is %d): ", defaultBook);
    scanf("%d", &defaultBook);
    
    // Check if default book number is within range
    if (defaultBook < 1 || defaultBook > bookCount) {
        printf("Invalid book number. Default book selected.\n");
        defaultBook = 1;
    }
    
    // Open the selected book file
    printf("\nOpening %s...\n", bookList[defaultBook-1].fileName);
    FILE *file = fopen(bookList[defaultBook-1].fileName, "r");
    
    // Read the book content
    char c;
    printf("\n=============================================\n");
    while ((c = fgetc(file)) != EOF) {
        printf("%c", c);
    }
    printf("\n=============================================\n");
    
    // Close the file
    fclose(file);
    
    // Free allocated memory
    free(bookList);
    
    return 0;
}