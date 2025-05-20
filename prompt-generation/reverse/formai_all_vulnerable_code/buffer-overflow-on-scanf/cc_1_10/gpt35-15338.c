//FormAI DATASET v1.0 Category: Ebook reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Ebook structure
struct Ebook {
    char title[100];
    char author[100];
    char filename[100];
};

// Function to read ebooks
void read_ebook(struct Ebook ebook) {
    printf("Reading %s by %s...\n", ebook.title, ebook.author);

    FILE *fp;
    char ch;
 
    // Open the ebook file
    fp = fopen(ebook.filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", ebook.filename);
        return;
    }
 
    // Read and print the ebook contents
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }
 
    // Close the ebook file
    fclose(fp);
}

int main() {
    // Create an array of Ebook structures
    struct Ebook library[3];

    // Add some sample ebooks to the library
    strcpy(library[0].title, "The Art of War");
    strcpy(library[0].author, "Sun Tzu");
    strcpy(library[0].filename, "the_art_of_war.txt");

    strcpy(library[1].title, "The Adventures of Sherlock Holmes");
    strcpy(library[1].author, "Arthur Conan Doyle");
    strcpy(library[1].filename, "sherlock_holmes.txt");

    strcpy(library[2].title, "The Great Gatsby");
    strcpy(library[2].author, "F. Scott Fitzgerald");
    strcpy(library[2].filename, "the_great_gatsby.txt");

    // Print out the library contents
    printf("Library Contents:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s by %s\n", library[i].title, library[i].author);
    }

    // Choose an ebook to read
    int choice;
    do {
        printf("\nChoose an ebook to read (1-3): ");
        scanf("%d", &choice);
    } while (choice < 1 || choice > 3);

    // Read the chosen ebook
    read_ebook(library[choice-1]);

    return 0;
}