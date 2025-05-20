//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME 20
#define MAX_PHONE 10

typedef struct {
    char name[MAX_NAME];
    char phone[MAX_PHONE];
} PhoneBookEntry;

PhoneBookEntry phoneBook[MAX_ENTRIES];
int numEntries = 0;

void addEntry(char name[], char phone[]) {
    if (numEntries == MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }
    strcpy(phoneBook[numEntries].name, name);
    strcpy(phoneBook[numEntries].phone, phone);
    numEntries++;
}

void deleteEntry(char name[]) {
    int i;
    for (i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            for (int j = i; j < numEntries - 1; j++) {
                strcpy(phoneBook[j].name, phoneBook[j + 1].name);
                strcpy(phoneBook[j].phone, phoneBook[j + 1].phone);
            }
            numEntries--;
            break;
        }
    }
}

void searchEntry(char name[]) {
    int i;
    for (i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            break;
        }
    }
}

void displayAllEntries() {
    int i;
    printf("Phone Book:\n");
    for (i = 0; i < numEntries; i++) {
        printf("%s: %s\n", phoneBook[i].name, phoneBook[i].phone);
    }
}

int main() {
    char name[MAX_NAME], phone[MAX_PHONE];
    char choice;

    while (1) {
        printf("Phone Book Menu:\n");
        printf("1. Add entry\n");
        printf("2. Delete entry\n");
        printf("3. Search entry\n");
        printf("4. Display all entries\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter name: ");
                fgets(name, MAX_NAME, stdin);
                fgets(phone, MAX_PHONE, stdin);
                strtok(name, "\n");
                strcpy(phoneBook[numEntries].name, name);
                strcpy(phoneBook[numEntries].phone, phone);
                numEntries++;
                printf("Entry added.\n");
                break;
            case '2':
                printf("Enter name: ");
                fgets(name, MAX_NAME, stdin);
                strtok(name, "\n");
                deleteEntry(name);
                break;
            case '3':
                printf("Enter name: ");
                fgets(name, MAX_NAME, stdin);
                strtok(name, "\n");
                searchEntry(name);
                break;
            case '4':
                displayAllEntries();
                break;
            case '5':
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}