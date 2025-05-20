//FormAI DATASET v1.0 Category: Ebook reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>

void displayMenu();
void readBook(char*);

int main()
{
    char bookTitle[50];
    int choice;

    do {

        displayMenu();
        scanf("%d",&choice);

        switch (choice) {
            case 1:
                printf("\nPlease enter the name of the book: ");
                scanf("%s", bookTitle);
                readBook(bookTitle);
                break;

            case 2:
                printf("\nThank you for using this Ebook reader. Goodbye!\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please select a valid option.\n");
                break;
        }

    } while (1);

    return 0;
}

void displayMenu() 
{
    printf("\n=====================\n");
    printf("Ebook Reader Main Menu\n");
    printf("=====================\n");
    printf("1. Open a book\n");
    printf("2. Exit\n");
    printf("=====================\n");
    printf("Please select an option (1-2): ");
}

void readBook(char* title) 
{
    char fileName[75];
    FILE* bookFile;

    sprintf(fileName, "%s.txt", title);

    bookFile = fopen(fileName, "r");

    if (bookFile != NULL) {
        char character;

        printf("\nReading book: %s\n", title);
        printf("===========================================\n");

        while ((character = fgetc(bookFile)) != EOF)
        {
            printf("%c", character);
        }
        printf("\n===========================================\n");

        fclose(bookFile);
    } else {
        printf("\nThe book '%s' could not be found. Please try again.\n", title);
    }

}