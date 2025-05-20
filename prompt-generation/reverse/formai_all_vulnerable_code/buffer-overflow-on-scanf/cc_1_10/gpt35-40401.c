//FormAI DATASET v1.0 Category: Phone Book ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for the phone book entry
typedef struct {
    char name[50];
    char phone_number[20];
} PhoneBookEntry;

// Define function to display the entries in the phone book
void displayPhoneBook(PhoneBookEntry *phonebook, int count) {
    int i;
    printf("|-------------------------------------------|\n");
    printf("|            PHONE BOOK ENTRIES              |\n");
    printf("|-------------------------------------------|\n");
    printf("|   NAME                 |  PHONE NUMBER     |\n");
    printf("|-------------------------------------------|\n");
    for (i = 0; i < count; i++) {
        printf("|%-25s|%-19s|\n", phonebook[i].name, phonebook[i].phone_number);
    }
    printf("|-------------------------------------------|\n");
}

int main() {
    int choice, i, count = 0;
    PhoneBookEntry *phonebook = malloc(sizeof(PhoneBookEntry));

    printf("========== PHONE BOOK APPLICATION ==========\n");
    do {
        printf("Enter your choice:\n");
        printf("1. Add a new entry\n");
        printf("2. View all entries\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("\nEnter name: ");
                scanf(" %[^\n]", phonebook[count].name);
                printf("Enter phone number: ");
                scanf(" %s", phonebook[count].phone_number);
                count++;
                phonebook = realloc(phonebook, (count + 1) * sizeof(PhoneBookEntry));
                break;
            }
            case 2: {
                if (count == 0) {
                    printf("\nThere are no entries in the phone book.\n\n");
                } else {
                    displayPhoneBook(phonebook, count);
                }
                break;
            }
            case 3: {
                printf("\nExiting phone book application...\n");
                break;
            }
            default: {
                printf("\nInvalid choice. Please try again.\n");
            }
        }
    } while (choice != 3);

    free(phonebook);
    return 0;
}