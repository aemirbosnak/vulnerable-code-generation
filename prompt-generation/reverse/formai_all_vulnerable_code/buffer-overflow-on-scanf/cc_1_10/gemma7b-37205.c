//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ebook {
    char title[50];
    char author[50];
    char genre[50];
    int pages;
    float price;
} Ebook;

Ebook ebooks[100];

void display_ebook(Ebook ebook) {
    printf("Title: %s\n", ebook.title);
    printf("Author: %s\n", ebook.author);
    printf("Genre: %s\n", ebook.genre);
    printf("Pages: %d\n", ebook.pages);
    printf("Price: %.2f\n", ebook.price);
    printf("\n");
}

int main() {
    int i = 0;
    Ebook ebook;

    // Create and initialize the ebook structure
    ebook.title[0] = '\0';
    ebook.author[0] = '\0';
    ebook.genre[0] = '\0';
    ebook.pages = 0;
    ebook.price = 0.0f;

    // Display the menu options
    printf("1. Create New Ebook\n");
    printf("2. Search for Ebook\n");
    printf("3. Update Ebook\n");
    printf("4. Delete Ebook\n");
    printf("Enter your choice: ");

    // Get the user's choice
    int choice = getchar();

    // Process the user's choice
    switch (choice) {
        case 1:
            // Create a new ebook
            printf("Enter the title of the ebook: ");
            scanf("%s", ebook.title);

            printf("Enter the author's name: ");
            scanf("%s", ebook.author);

            printf("Enter the genre of the ebook: ");
            scanf("%s", ebook.genre);

            printf("Enter the number of pages: ");
            scanf("%d", &ebook.pages);

            printf("Enter the price of the ebook: ");
            scanf("%f", &ebook.price);

            // Add the ebook to the array
            ebooks[i] = ebook;
            i++;

            break;
        case 2:
            // Search for an ebook
            printf("Enter the title of the ebook: ");
            scanf("%s", ebook.title);

            // Search for the ebook
            for (int j = 0; j < i; j++) {
                if (strcmp(ebooks[j].title, ebook.title) == 0) {
                    display_ebook(ebooks[j]);
                }
            }

            break;
        case 3:
            // Update an ebook
            printf("Enter the title of the ebook: ");
            scanf("%s", ebook.title);

            // Search for the ebook
            for (int j = 0; j < i; j++) {
                if (strcmp(ebooks[j].title, ebook.title) == 0) {
                    printf("Enter the new title of the ebook: ");
                    scanf("%s", ebooks[j].title);

                    printf("Enter the new author's name: ");
                    scanf("%s", ebooks[j].author);

                    printf("Enter the new genre of the ebook: ");
                    scanf("%s", ebooks[j].genre);

                    printf("Enter the new number of pages: ");
                    scanf("%d", &ebooks[j].pages);

                    printf("Enter the new price of the ebook: ");
                    scanf("%f", &ebooks[j].price);

                    display_ebook(ebooks[j]);
                }
            }

            break;
        case 4:
            // Delete an ebook
            printf("Enter the title of the ebook: ");
            scanf("%s", ebook.title);

            // Search for the ebook
            for (int j = 0; j < i; j++) {
                if (strcmp(ebooks[j].title, ebook.title) == 0) {
                    // Delete the ebook
                    for (int k = j; k < i; k++) {
                        ebooks[k] = ebooks[k+1];
                    }
                    i--;
                }
            }

            break;
    }

    return 0;
}