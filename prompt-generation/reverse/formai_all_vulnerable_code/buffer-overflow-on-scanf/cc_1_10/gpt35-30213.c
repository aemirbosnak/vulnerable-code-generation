//FormAI DATASET v1.0 Category: Ebook reader ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char title[100];
    char author[100];
    char ebook_file[100];
    char genre[50];
};

struct user {
    char name[50];
    char email[50];
    char password[50];
};

int main() {
    int num_books;
    struct book *library;

    printf("Enter the number of books in your library: ");
    scanf("%d", &num_books);

    // Allocate memory for library array
    library = (struct book*) malloc(num_books * sizeof(struct book));

    // Populate the array
    for(int i = 0; i < num_books; i++) {
        printf("\nBook %d\n", i + 1);
        printf("Title: ");
        scanf("%s", library[i].title);
        printf("Author: ");
        scanf("%s", library[i].author);
        printf("Ebook file (without extension): ");
        scanf("%s", library[i].ebook_file);
        printf("Genre: ");
        scanf("%s", library[i].genre);
    }

    // Display books
    printf("\nYour library:\n");
    for(int i = 0; i < num_books; i++) {
        printf("\nBook %d\n", i + 1);
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Ebook file name: %s.epub\n", library[i].ebook_file);
        printf("Genre: %s\n", library[i].genre);
    }

    // Free allocated memory
    free(library);

    // End of program
    return 0;
}