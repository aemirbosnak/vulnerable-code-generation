//FormAI DATASET v1.0 Category: Phone Book ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char number[20];
} PhoneBookEntry;

void addEntry(PhoneBookEntry book[], int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Sorry, the phone book is full!\n");
        return;
    }

    PhoneBookEntry newEntry;
    printf("Enter name: ");
    fgets(newEntry.name, 50, stdin);
    printf("Enter number: ");
    fgets(newEntry.number, 20, stdin);

    book[*count] = newEntry;

    printf("Entry added!\n");
    (*count)++;
}

void displayEntries(PhoneBookEntry book[], int count) {
    if (count == 0) {
        printf("The phone book is empty!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("%d. Name: %s", i+1, book[i].name);
        printf("   Number: %s", book[i].number);
    }
}

int main() {
    PhoneBookEntry phoneBook[MAX_ENTRIES];
    int numEntries = 0;
    int choice;

    printf("Welcome to your cheerful phone book!\n");

    do {
        printf("\nEnter your choice:\n");
        printf("1. Add entry\n2. Display entries\n3. Exit\n");

        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                addEntry(phoneBook, &numEntries);
                break;
            case 2:
                displayEntries(phoneBook, numEntries);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 3);

    return 0;
}