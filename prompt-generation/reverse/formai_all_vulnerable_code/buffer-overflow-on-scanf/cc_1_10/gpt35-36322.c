//FormAI DATASET v1.0 Category: Ebook reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

struct eBook {
    char title[50];
    char author[50];
    char publisher[50];
    int year;
    char filePath[100];
};

struct eBook library[10]; // Assuming the library can hold a maximum of 10 eBooks

void addBook() {
    int i = 0;
    while (library[i].filePath[0] != '\0') { // finding the first empty slot in the library
        i++;
    }

    printf("Enter the book title: ");
    scanf("%[^\n]s", library[i].title);
    getchar();

    printf("Enter the author's name: ");
    scanf("%[^\n]s", library[i].author);
    getchar();

    printf("Enter the publisher's name: ");
    scanf("%[^\n]s", library[i].publisher);
    getchar();

    printf("Enter the year of publication: ");
    scanf("%d", &library[i].year);
    getchar();

    printf("Enter the file path of the eBook: ");
    scanf("%[^\n]s", library[i].filePath);
    getchar();

    printf("\nBook added successfully.\n");
}

void displayLibrary() {
    printf("\n");
    printf("%-30s%-30s%-30s%-10s\n", "Title", "Author", "Publisher", "Year");
    printf("---------------------------------------------------------------\n");

    int i = 0;
    while (library[i].filePath[0] != '\0') { // looping through the library until the first empty slot
        printf("%-30s%-30s%-30s%-10d\n", library[i].title, library[i].author, library[i].publisher, library[i].year);
        i++;
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Add a book\n");
        printf("2. Display the library\n");
        printf("3. Exit\n");

        printf("\nChoice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayLibrary();
                break;
            case 3:
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}