//FormAI DATASET v1.0 Category: Phone Book ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct PhoneBookEntry {
    char name[20];
    char phone[15];
};

typedef struct PhoneBookEntry PhoneBookEntry;

void addEntry(PhoneBookEntry *phoneBook, int index) {
    printf("\nEnter name: ");
    scanf("%s", phoneBook[index].name);

    printf("Enter phone number: ");
    scanf("%s", phoneBook[index].phone);
}

void deleteEntry(PhoneBookEntry *phoneBook, int *numEntries) {
    int i;
    char name[20];
    printf("\nEnter name of the person to delete: ");
    scanf("%s", name);

    for(i=0; i<*numEntries; i++) {
        if(strcmp(phoneBook[i].name, name) == 0) {
            // Shift all entries after the i-th entry left by one to remove i-th entry
            for(int j = i; j < *numEntries; j++) {
                strcpy(phoneBook[j].name, phoneBook[j+1].name);
                strcpy(phoneBook[j].phone, phoneBook[j+1].phone);
            }
            (*numEntries)--;
            printf("Successfully deleted %s's entry.", name);
            return;
        }
    }
    printf("Sorry, no entry found for %s.", name);
}

void searchEntry(PhoneBookEntry *phoneBook, int numEntries) {
    int i;
    char name[20];
    printf("\nEnter name of the person to search: ");
    scanf("%s", name);
    for(i=0; i<numEntries; i++) {
        if(strcmp(phoneBook[i].name, name) == 0) {
            printf("%s has phone number %s\n", phoneBook[i].name, phoneBook[i].phone);
            break;
        }
    }
    if(i == numEntries) {
        printf("Sorry, no entry found for %s.", name);
    }
}

void printPhonebook(PhoneBookEntry *phoneBook, int numEntries) {
    int i;
    printf("\nPhoneBook:\n");
    printf("%-20s%-15s\n", "Name", "Phone Number");
    for(i=0; i<numEntries; i++) {
        printf("%-20s%-15s\n", phoneBook[i].name, phoneBook[i].phone);
    }
}

int main() {
    int i, numEntries = 0, selection;
    PhoneBookEntry phoneBook[MAX];

    printf("Welcome to the PhoneBook!\n");

    while(1) {
        printf("\nMenu:\n");
        printf("1. Add an entry\n");
        printf("2. Delete an entry\n");
        printf("3. Search for an entry\n");
        printf("4. Print all entries\n");
        printf("5. Quit\n");
        printf("Enter your selection: ");
        scanf("%d", &selection);

        switch(selection) {
            case 1:
                if(numEntries == MAX) {
                    printf("Sorry, phone book is full.");
                    break;
                }
                addEntry(phoneBook, numEntries++);
                break;
            case 2:
                if(numEntries == 0) {
                    printf("Sorry, phone book is empty.");
                    break;
                }
                deleteEntry(phoneBook, &numEntries);
                break;
            case 3:
                if(numEntries == 0) {
                    printf("Sorry, phone book is empty.");
                    break;
                }
                searchEntry(phoneBook, numEntries);
                break;
            case 4:
                if(numEntries == 0) {
                    printf("Sorry, phone book is empty.");
                    break;
                }
                printPhonebook(phoneBook, numEntries);
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid selection, please try again.");
        }
    }

    return 0;
}