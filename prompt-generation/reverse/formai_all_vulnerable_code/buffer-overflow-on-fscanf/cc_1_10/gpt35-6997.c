//FormAI DATASET v1.0 Category: Ebook reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char author[50];
    char publisher[50];
    float price;
    int year;
} Book;

int main() {
    Book myLibrary[100];
    int numBooks = 0;

    // Reading books from file 
    FILE *fp = fopen("books.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    while (!feof(fp)) {
        fscanf(fp, "%[^,],%[^,],%[^,],%f,%d\n", myLibrary[numBooks].title, myLibrary[numBooks].author, 
               myLibrary[numBooks].publisher, &myLibrary[numBooks].price, &myLibrary[numBooks].year);
        numBooks++;
    }
    fclose(fp);

    // Printing out the books in the library 
    printf("Library Contents:\n");
    for (int i = 0; i < numBooks; i++) {
        printf("%d. Title: %s\n", i+1, myLibrary[i].title);
        printf("   Author: %s\n", myLibrary[i].author);
        printf("   Publisher: %s\n", myLibrary[i].publisher);
        printf("   Price: $%.2f\n", myLibrary[i].price);
        printf("   Year: %d\n\n", myLibrary[i].year);
    }

    // Ebook Reader functionality
    char title[50];
    int found = 0;
    printf("Enter the title of the book to read: ");
    scanf("%[^\n]", title);
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(title, myLibrary[i].title) == 0) {
            printf("%s\n", myLibrary[i].title);
            printf("%s\n", myLibrary[i].author);
            printf("%s\n", myLibrary[i].publisher);
            printf("%.2f\n", myLibrary[i].price);
            printf("%d\n\n", myLibrary[i].year);
            found = 1;  
            break;     
        }
    }
    if (!found) {
        printf("Book not found in library.\n");
    }

    return 0;
}