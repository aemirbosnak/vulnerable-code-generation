//FormAI DATASET v1.0 Category: Ebook reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book { 
    int id; 
    char title[50]; 
    char author[50]; 
    char genre[20]; 
    char filename[50]; 
}; 

int main() { 

    // Create a library of books 
    struct Book books[3]; 
    books[0].id = 1; 
    strcpy(books[0].title, "The Catcher in the Rye"); 
    strcpy(books[0].author, "J. D. Salinger"); 
    strcpy(books[0].genre, "Coming-of-Age Fiction"); 
    strcpy(books[0].filename, "catcher.epub");
    
    books[1].id = 2; 
    strcpy(books[1].title, "To Kill a Mockingbird"); 
    strcpy(books[1].author, "Harper Lee"); 
    strcpy(books[1].genre, "Southern Gothic Fiction"); 
    strcpy(books[1].filename, "mockingbird.epub");
    
    books[2].id = 3; 
    strcpy(books[2].title, "1984"); 
    strcpy(books[2].author, "George Orwell"); 
    strcpy(books[2].genre, "Dystopian Fiction"); 
    strcpy(books[2].filename, "1984.epub"); 

    int selectedBook; 
    
    // Display the library 
    printf("Welcome to the Ebook library!\n");
    printf("Please select a book to read:\n");
    for(int i = 0; i < 3; i++) {
        printf("%d. %s by %s\n", books[i].id, books[i].title, books[i].author);
    }
    scanf("%d", &selectedBook);

    // Open the ebook file 
    char filepath[100] = "books/"; 
    strcat(filepath, books[selectedBook-1].filename); 
    FILE *fp = fopen(filepath, "r"); 
    
    if(fp == NULL) {
        printf("Error: Cannot open book file.\n");
        exit(EXIT_FAILURE);
    }
    
    // Read ebook file
    printf("Loading book...\n\n"); 
    char ch; 
    while ((ch = fgetc(fp)) != EOF) { 
        printf("%c", ch);
    } 
    
    fclose(fp); 

    return 0;
}