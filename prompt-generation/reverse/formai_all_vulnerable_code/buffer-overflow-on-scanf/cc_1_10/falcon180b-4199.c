//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[50];
    char phone[20];
} entry;

entry phonebook[MAX_ENTRIES];
int count = 0;

void addEntry() {
    if(count >= MAX_ENTRIES) {
        printf("Phonebook is full!\n");
        return;
    }

    char name[50];
    printf("Enter name: ");
    scanf("%s", name);

    char phone[20];
    printf("Enter phone number: ");
    scanf("%s", phone);

    strcpy(phonebook[count].name, name);
    strcpy(phonebook[count].phone, phone);

    count++;
}

void searchEntry() {
    char searchName[50];
    printf("Enter name to search: ");
    scanf("%s", searchName);

    int i;
    for(i = 0; i < count; i++) {
        if(strcmp(phonebook[i].name, searchName) == 0) {
            printf("Name: %s\nPhone: %s\n", phonebook[i].name, phonebook[i].phone);
            return;
        }
    }

    printf("Entry not found!\n");
}

void deleteEntry() {
    char searchName[50];
    printf("Enter name to delete: ");
    scanf("%s", searchName);

    int i;
    for(i = 0; i < count; i++) {
        if(strcmp(phonebook[i].name, searchName) == 0) {
            strcpy(phonebook[i].name, "");
            strcpy(phonebook[i].phone, "");
            printf("Entry deleted!\n");
            return;
        }
    }

    printf("Entry not found!\n");
}

void viewEntries() {
    int i;
    for(i = 0; i < count; i++) {
        printf("Name: %s\nPhone: %s\n", phonebook[i].name, phonebook[i].phone);
    }
}

int main() {
    int choice;

    do {
        printf("\nPhonebook\n");
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. View all entries\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addEntry();
                break;
            case 2:
                searchEntry();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                viewEntries();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 5);

    return 0;
}