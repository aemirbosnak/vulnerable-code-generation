//FormAI DATASET v1.0 Category: Phone Book ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    char name[50];
    char phone[15];
};

void addPerson(struct person *book, int size) {
    // Add a person to the phone book
    printf("Enter the person's name: ");
    scanf(" %[^\n]s", book[size].name);
    printf("Enter the person's phone number: ");
    scanf(" %[^\n]s", book[size].phone);
    printf("Added %s with phone number %s\n", book[size].name, book[size].phone);
}

void searchPerson(struct person *book, int size) {
    // Search for a person in the phone book
    char name[50];
    printf("Enter the name of the person to search for: ");
    scanf(" %[^\n]s", name);
    for(int i=0; i<size; i++) {
        if(strcmp(book[i].name, name) == 0) {
            printf("%s's phone number is %s\n", name, book[i].phone);
            return;
        }
    }
    printf("%s not found in the phone book.\n", name);
}

void printBook(struct person *book, int size) {
    // Print the phone book
    printf("Phone Book:\n");
    for(int i=0; i<size; i++) {
        printf("%s: %s\n",book[i].name,book[i].phone);
    }
}

int main() {
    struct person phoneBook[100];
    int size = 0;
    int choice;
    do {
        printf("Phone Book Menu:\n");
        printf("1. Add a person\n");
        printf("2. Search for a person\n");
        printf("3. Print the phone book\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addPerson(phoneBook, size);
                size++;
                break;
            case 2:
                searchPerson(phoneBook, size);
                break;
            case 3:
                printBook(phoneBook, size);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while(choice != 4);

    return 0;
}