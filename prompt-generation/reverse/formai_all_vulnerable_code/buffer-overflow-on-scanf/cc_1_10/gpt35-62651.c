//FormAI DATASET v1.0 Category: Ebook reader ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BOOKS 50 // Maximum number of books that can be stored in the system
#define MAX_TITLE_LENGTH 100 // Maximum length of book title
#define MAX_AUTHOR_LENGTH 50 // Maximum length of book author
#define MAX_FILENAME_LENGTH 20 // Maximum length of ebook file names

struct Ebook { 
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char filename[MAX_FILENAME_LENGTH];
};

int main() {
    int num_books = 0; // Number of books currently stored in the system
    struct Ebook ebooks[MAX_BOOKS]; // Array to store the ebooks

    // Displaying the menu options
    printf("Welcome to the Ebook Reader program!\n");
    printf("Please select an option:\n");
    printf("1. Add an ebook\n");
    printf("2. Display all ebooks\n");
    printf("3. Exit\n");

    // Allow the user to select menu options
    int option;
    while (1) { 
        printf("Enter option number: ");
        scanf("%d", &option);

        // Validate the user's input
        if (option < 1 || option > 3) {
            printf("Invalid option. Try again.\n");
            continue;
        }

        // Perform actions based on the user's input
        switch (option) {
            case 1:
                // Adding an ebook to the system
                if (num_books == MAX_BOOKS) {
                    printf("The system is full. Cannot add more ebooks.\n");
                    break;
                }

                printf("Enter ebook title: ");
                scanf("%s", ebooks[num_books].title);

                printf("Enter ebook author: ");
                scanf("%s", ebooks[num_books].author);

                printf("Enter ebook filename: ");
                scanf("%s", ebooks[num_books].filename);

                num_books++;
                printf("Ebook added successfully!\n");
                break;

            case 2:
                // Displaying all ebooks in the system
                if (num_books == 0) {
                    printf("No ebooks found.\n");
                    break;
                }

                printf("Ebooks currently in the system:\n");
                for (int i = 0; i < num_books; i++) {
                    printf("%s by %s (filename: %s)\n", ebooks[i].title, 
                           ebooks[i].author, ebooks[i].filename);
                }
                break;

            case 3:
                // Exiting the program
                printf("Exiting program...\n");
                exit(0);
        }
    }

    return 0;
}