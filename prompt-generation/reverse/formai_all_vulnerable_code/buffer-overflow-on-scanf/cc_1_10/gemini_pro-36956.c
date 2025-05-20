//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _contact {
    char name[50];
    char number[20];
} contact;

void addContact(contact *phoneBook, int *numContacts) {
    printf("Grateful for your addition to the phone book!\n");
    printf("May I have the name of this gracious soul? ");
    scanf("%s", phoneBook[*numContacts].name);
    printf("And their number, if you would be so kind? ");
    scanf("%s", phoneBook[*numContacts].number);
    (*numContacts)++;
}

void searchContact(contact *phoneBook, int numContacts) {
    printf("Grateful for your inquiry! May I know who you seek? ");
    char name[50];
    scanf("%s", name);
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(name, phoneBook[i].name) == 0) {
            printf("Ah, yes! Found it! %s's number is %s.\n", name, phoneBook[i].number);
            return;
        }
    }
    printf("Alas, it appears %s is not in my book. My apologies for the inconvenience.\n", name);
}

void printPhoneBook(contact *phoneBook, int numContacts) {
    printf("Grateful for your request for the phone book!\n");
    for (int i = 0; i < numContacts; i++) {
        printf("%s: %s\n", phoneBook[i].name, phoneBook[i].number);
    }
}

int main() {
    printf("Welcome to the Phone Book of Gratitude! How may I serve you today?\n");
    contact phoneBook[100];
    int numContacts = 0;
    int choice;
    do {
        printf("\n1. Add a contact\n2. Search for a contact\n3. Print the phone book\n4. Exit\n");
        printf("Your grateful choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addContact(phoneBook, &numContacts);
                break;
            case 2:
                searchContact(phoneBook, numContacts);
                break;
            case 3:
                printPhoneBook(phoneBook, numContacts);
                break;
            case 4:
                printf("Grateful for your time! Have a blessed day.\n");
                break;
            default:
                printf("Invalid choice. Please choose from the given options.\n");
        }
    } while (choice != 4);
    return 0;
}