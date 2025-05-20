//FormAI DATASET v1.0 Category: Ebook reader ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Define a structure representing an Ebook, with its attributes
struct Ebook {
    char title[100];
    char author[50];
    char genre[50];
    char filename[100];
};

// Define a function to read an Ebook from a file
struct Ebook readEbookFromFile(char* filename) {
    FILE *fptr;
    struct Ebook ebook;

    // Open the file
    fptr = fopen(filename, "r");

    // Read the Ebook attributes from the file
    fscanf(fptr,"%[^\n]", ebook.title);
    fscanf(fptr,"%[^\n]", ebook.author);
    fscanf(fptr,"%[^\n]", ebook.genre);
    fscanf(fptr,"%[^\n]", ebook.filename);

    // Close the file
    fclose(fptr);

    return ebook;
}

// Define a function to display an Ebook
void displayEbook(struct Ebook ebook) {
    printf("Title: %s\n", ebook.title);
    printf("Author: %s\n", ebook.author);
    printf("Genre: %s\n", ebook.genre);
    printf("File name: %s\n", ebook.filename);
}

int main() {
    struct Ebook myEbook;
    char* filename = "myEbook.txt";

    // Read the Ebook from the file
    myEbook = readEbookFromFile(filename);

    // Display the Ebook
    displayEbook(myEbook);

    return 0;
}