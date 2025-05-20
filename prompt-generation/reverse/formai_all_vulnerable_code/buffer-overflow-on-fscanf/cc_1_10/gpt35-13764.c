//FormAI DATASET v1.0 Category: Ebook reader ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Define a struct to hold information about each book in the library
typedef struct {
    char title[50];
    char author[50];
    int numPages;
    char contents[10000];
} Book;

// Define a function to read in a book from a file and store it in a Book struct
Book readBookFromFile(char* fileName) {
    Book b;
    FILE* fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Could not open file: %s\n", fileName);
        exit(1);
    }
    fscanf(fp, "%[^\n]s", b.title);
    fgetc(fp); // Consume the newline character
    fscanf(fp, "%[^\n]s", b.author);
    fgetc(fp); // Consume the newline character
    fscanf(fp, "%d", &b.numPages);
    fgetc(fp); // Consume the newline character
    fgets(b.contents, 10000, fp);
    fclose(fp);
    return b;
}

// Define a function to print out a book's title, author, and number of pages
void printBookSummary(Book b) {
    printf("%s by %s (%d pages)\n", b.title, b.author, b.numPages);
}

int main() {
    // Declare an array of Book structs to hold all the books in the library
    Book library[10];

    // Read in each book from a file and store it in the library
    library[0] = readBookFromFile("book1.txt");
    library[1] = readBookFromFile("book2.txt");
    library[2] = readBookFromFile("book3.txt");
    library[3] = readBookFromFile("book4.txt");
    library[4] = readBookFromFile("book5.txt");
    library[5] = readBookFromFile("book6.txt");
    library[6] = readBookFromFile("book7.txt");
    library[7] = readBookFromFile("book8.txt");
    library[8] = readBookFromFile("book9.txt");
    library[9] = readBookFromFile("book10.txt");

    // Print out a summary of each book in the library
    for (int i = 0; i < 10; i++) {
        printf("Book %d:\n", i+1);
        printBookSummary(library[i]);
        printf("\n");
    }

    // Continuously ask the user which book they would like to view until they enter 'q' to quit
    char input[10];
    while (1) {
        printf("Enter the number of the book you would like to view, or 'q' to quit: ");
        scanf("%s", input);
        if (input[0] == 'q') {
            break;
        }
        int bookNum = atoi(input);
        if (bookNum >= 1 && bookNum <= 10) {
            printf("%s\n\n", library[bookNum-1].contents);
        } else {
            printf("Invalid book number\n\n");
        }
    }

    return 0;
}