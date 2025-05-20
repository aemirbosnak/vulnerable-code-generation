//FormAI DATASET v1.0 Category: Ebook reader ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for Ebook
struct Ebook {
    char title[100];
    char author[100];
    int year;
    int pages;
    char language[50];
    int filesize;
};

// Function to read Ebook from file
struct Ebook read_ebook(char filename[]) {
    struct Ebook ebook;
    FILE *fptr;

    fptr = fopen(filename, "rb");

    if (fptr == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    fread(&ebook, sizeof(struct Ebook), 1, fptr);

    fclose(fptr);

    return ebook;
}

// Function to print Ebook details
void print_ebook(struct Ebook ebook) {
    printf("Title: %s\n", ebook.title);
    printf("Author: %s\n", ebook.author);
    printf("Year of Publication: %d\n", ebook.year);
    printf("Number of Pages: %d\n", ebook.pages);
    printf("Language: %s\n", ebook.language);
    printf("Filesize: %d KB\n", ebook.filesize);
}

// Main function
int main() {
    char filename[100];
    struct Ebook ebook;

    printf("Enter filename of Ebook: ");
    scanf("%s", filename);

    ebook = read_ebook(filename);

    print_ebook(ebook);

    return 0;
}