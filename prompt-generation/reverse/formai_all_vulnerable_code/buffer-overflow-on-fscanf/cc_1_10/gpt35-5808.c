//FormAI DATASET v1.0 Category: Ebook reader ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char title[100], author[100], publisher[100], isbn[100];
    float price;
} Book;

// function to read an ebook from file and return as a Book struct
Book read_ebook(FILE *fp) {
    Book ebook;
    fgets(ebook.title, 100, fp);
    ebook.title[strlen(ebook.title) - 1] = '\0'; // remove new line character
    fgets(ebook.author, 100, fp);
    ebook.author[strlen(ebook.author) - 1] = '\0'; // remove new line character
    fgets(ebook.publisher, 100, fp);
    ebook.publisher[strlen(ebook.publisher) - 1] = '\0'; // remove new line character
    fgets(ebook.isbn, 100, fp);
    ebook.isbn[strlen(ebook.isbn) - 1] = '\0'; // remove new line character
    fscanf(fp, "%f", &ebook.price);
    return ebook;
}

// function to display a book
void display_book(Book ebook) {
    printf("Title: %s\n", ebook.title);
    printf("Author: %s\n", ebook.author);
    printf("Publisher: %s\n", ebook.publisher);
    printf("ISBN: %s\n", ebook.isbn);
    printf("Price: $%.2f\n", ebook.price);
}

// main function
int main() {
    // open ebook file
    FILE *fp = fopen("ebook.txt", "r");
    
    // check if file opened successfully
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }
    
    // read number of ebooks in file
    int num_ebooks;
    fscanf(fp, "%d", &num_ebooks);
    
    // read ebooks from file and store in array of Book structs
    Book ebooks[num_ebooks];
    for (int i = 0; i < num_ebooks; i++) {
        ebooks[i] = read_ebook(fp);
    }
    
    // close file
    fclose(fp);
    
    // display all ebooks
    for (int i = 0; i < num_ebooks; i++) {
        printf("Ebook %d:\n", i+1);
        display_book(ebooks[i]);
        printf("\n");
    }
    
    return 0;
}