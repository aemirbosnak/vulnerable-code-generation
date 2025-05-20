//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct PhoneBookEntry {
    char name[50];
    char phoneNumber[20];
};

struct PhoneBook {
    struct PhoneBookEntry entries[100];
    int numEntries;
};

struct PhoneBook book;

int main() {
    book.numEntries = 0;
    int choice = 0;
    int option = 0;

    while (1) {
        printf("Welcome to the Phone Book!\n");
        printf("Please select an option:\n");
        printf("1. Add an entry\n");
        printf("2. Remove an entry\n");
        printf("3. Search an entry\n");
        printf("4. Print all entries\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the entry: ");
                fgets(book.entries[book.numEntries].name, sizeof(book.entries[book.numEntries].name), stdin);
                printf("Enter the phone number of the entry: ");
                fgets(book.entries[book.numEntries].phoneNumber, sizeof(book.entries[book.numEntries].phoneNumber), stdin);
                book.numEntries++;
                break;

            case 2:
                printf("Enter the name of the entry you want to remove: ");
                fgets(book.entries[book.numEntries].name, sizeof(book.entries[book.numEntries].name), stdin);
                book.numEntries--;
                break;

            case 3:
                printf("Enter the name of the entry you want to search: ");
                fgets(book.entries[book.numEntries].name, sizeof(book.entries[book.numEntries].name), stdin);
                for (int i = 0; i < book.numEntries; i++) {
                    if (strcmp(book.entries[i].name, book.entries[book.numEntries].name) == 0) {
                        printf("Phone number: %s\n", book.entries[i].phoneNumber);
                    }
                }
                break;

            case 4:
                for (int i = 0; i < book.numEntries; i++) {
                    printf("%s: %s\n", book.entries[i].name, book.entries[i].phoneNumber);
                }
                break;

            case 5:
                exit(0);
                break;

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}