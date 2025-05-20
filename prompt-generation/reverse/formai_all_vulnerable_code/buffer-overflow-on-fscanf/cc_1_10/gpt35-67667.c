//FormAI DATASET v1.0 Category: Ebook reader ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for the Ebook
typedef struct Ebook {
    char title[50];
    char author[50];
    int num_pages;
} Ebook;

// Define a function to display the Ebook details
void display(Ebook book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Number of Pages: %d\n", book.num_pages);
}

// Define a function to load the Ebook from file
Ebook load_ebook(char* filename) {
    Ebook book;
    FILE* file;
    file = fopen(filename, "r");
    
    if(file != NULL) {
        // Read the Ebook details
        fgets(book.title, 50, file);
        fgets(book.author, 50, file);
        fscanf(file, "%d", &book.num_pages);
        
        fclose(file);
    }
    else {
        // If the file cannot be opened, set the Ebook details to default values
        strcpy(book.title, "Unknown");
        strcpy(book.author, "Unknown");
        book.num_pages = 0;
    }
    
    return book;
}

// Define a function to prompt the user for the Ebook filename
char* get_filename() {
    char* filename = (char*) malloc(50 * sizeof(char));
    printf("Enter filename: ");
    scanf("%s", filename);  // Assume the filename does not contain spaces
    return filename;
}

int main() {
    char* filename;
    Ebook book;
    
    filename = get_filename();
    book = load_ebook(filename);
    
    display(book);
    
    free(filename);
    return 0;
}