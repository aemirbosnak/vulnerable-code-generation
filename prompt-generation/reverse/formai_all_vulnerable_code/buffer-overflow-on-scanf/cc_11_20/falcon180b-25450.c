//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_CHARS_PER_BOOK 10000

typedef struct {
    char title[50];
    char author[50];
    char content[MAX_CHARS_PER_BOOK];
} Book;

int main() {
    Book library[MAX_BOOKS];
    int numBooks = 0;
    char choice;

    do {
        printf("\nWelcome to the Cyberpunk Ebook Reader!\n");
        printf("Please choose an option:\n");
        printf("1. Add a book\n");
        printf("2. Remove a book\n");
        printf("3. Read a book\n");
        printf("4. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                if (numBooks >= MAX_BOOKS) {
                    printf("Error: Library is full.\n");
                } else {
                    printf("Enter the title of the book:\n");
                    scanf("%s", library[numBooks].title);
                    printf("Enter the author of the book:\n");
                    scanf("%s", library[numBooks].author);
                    printf("Enter the content of the book:\n");
                    scanf("%[^\n]", library[numBooks].content);
                    numBooks++;
                    printf("Book added successfully!\n");
                }
                break;
            case '2':
                if (numBooks == 0) {
                    printf("Error: Library is empty.\n");
                } else {
                    printf("Enter the index of the book you want to remove:\n");
                    int index;
                    scanf("%d", &index);
                    if (index >= 0 && index < numBooks) {
                        printf("Book removed successfully!\n");
                        numBooks--;
                    } else {
                        printf("Error: Invalid index.\n");
                    }
                }
                break;
            case '3':
                if (numBooks == 0) {
                    printf("Error: Library is empty.\n");
                } else {
                    printf("Enter the index of the book you want to read:\n");
                    int index;
                    scanf("%d", &index);
                    if (index >= 0 && index < numBooks) {
                        printf("\nTitle: %s\nAuthor: %s\n\n", library[index].title, library[index].author);
                        printf("%s", library[index].content);
                    } else {
                        printf("Error: Invalid index.\n");
                    }
                }
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Error: Invalid choice.\n");
        }
    } while (choice!= '4');

    return 0;
}