//FormAI DATASET v1.0 Category: Ebook reader ; Style: Linus Torvalds
/****************************************************************************
 * Ebook reader program written in Linus Torvalds style *
 * Created by (Your Name) *
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Ebook {
    char title[50];
    char author[50];
    char text[10000];
} Ebook;

void read_ebook(Ebook *book) {
    printf("Enter ebook title: ");
    scanf("%s", book->title);
    printf("Enter ebook author: ");
    scanf("%s", book->author);
    printf("Enter ebook text: ");
    scanf("%s", book->text);
}

void display_ebook(Ebook book) {
    printf("\nEbook Title: %s", book.title);
    printf("\nEbook Author: %s", book.author);
    printf("\nEbook Text: %s", book.text);
}

void print_menu() {
    printf("1. Read Ebook\n");
    printf("2. Display Ebook\n");
    printf("3. Exit Program\n");
}

int main(void) {
    Ebook book = {0};
    int choice;

    printf("Welcome to the Ebook Reader!\n");

    while (true) {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                read_ebook(&book);
                break;
            case 2:
                display_ebook(book);
                break;
            case 3:
                printf("Thank you for using the Ebook Reader!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}