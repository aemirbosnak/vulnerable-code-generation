//FormAI DATASET v1.0 Category: Ebook reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printWelcomeMessage() {
    printf("=============================================\n");
    printf("|                                           |\n");
    printf("|      Welcome to the Ebook Reader 3000      |\n");
    printf("|                                           |\n");
    printf("=============================================\n\n");
}

void printBookMenu() {
    printf("Please enter the name of the book you'd like to read:\n");
    printf("1. The Adventures of Huckleberry Finn\n");
    printf("2. The Catcher in the Rye\n");
    printf("3. 1984\n");
    printf("4. To Kill a Mockingbird\n");
    printf("5. Exit Ebook Reader\n");
}

void readBook(char* book) {
    FILE* fp = fopen(book, "r");
    char line[100];

    if (fp == NULL) {
        printf("Error opening file: %s\n", book);
    } else {
        while (fgets(line, 100, fp)) {
            printf("%s", line);
        }
        fclose(fp);
    }
}

int main(void) {
    char book[100];
    int choice = 0;

    printWelcomeMessage();

    while (choice != 5) {
        printBookMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                strcpy(book, "HuckleberryFinn.txt");
                readBook(book);
                break;
            case 2:
                strcpy(book, "CatcherInTheRye.txt");
                readBook(book);
                break;
            case 3:
                strcpy(book, "1984.txt");
                readBook(book);
                break;
            case 4:
                strcpy(book, "ToKillAMockingbird.txt");
                readBook(book);
                break;
            case 5:
                printf("Thank you for using Ebook Reader 3000!\n");
                break;
            default:
                printf("Invalid choice, please try again!\n");
                break;
        }
    }

    return 0;
}