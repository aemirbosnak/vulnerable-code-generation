//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: relaxed
/* This is a phone book program that allows the user to store and retrieve phone numbers */

#include<stdio.h>
#include<string.h>

#define MAX_ENTRIES 100 // Maximum number of entries allowed in the phone book

typedef struct {
    char name[50]; // Name of the person
    char phone[15]; // Phone number of the person
} entry;

void addEntry(entry entries[], int count, char name[], char phone[]) {
    if(count >= MAX_ENTRIES) { // If the phone book is full
        printf("Phone book is full. Cannot add entry.\n");
        return;
    }
    strcpy(entries[count].name, name); // Copy name to the entry
    strcpy(entries[count].phone, phone); // Copy phone number to the entry
    count++; // Increment the count of entries
}

void displayEntries(entry entries[], int count) {
    printf("Phone book entries:\n");
    for(int i=0; i<count; i++) {
        printf("%s - %s\n", entries[i].name, entries[i].phone);
    }
}

void searchEntry(entry entries[], int count, char name[]) {
    for(int i=0; i<count; i++) {
        if(strcmp(entries[i].name, name) == 0) { // If name matches
            printf("Phone number for %s is %s\n", name, entries[i].phone);
            return;
        }
    }
    printf("No entry found for %s\n", name);
}

int main() {
    entry phoneBook[MAX_ENTRIES]; // Initialize the phone book
    int count = 0; // Initialize the count of entries

    while(1) {
        printf("1. Add entry\n2. Display entries\n3. Search entry\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                    char name[50], phone[15];
                    printf("Enter name: ");
                    scanf("%s", name);
                    printf("Enter phone number: ");
                    scanf("%s", phone);
                    addEntry(phoneBook, count, name, phone);
                    break;
                }
            case 2: {
                    displayEntries(phoneBook, count);
                    break;
                }
            case 3: {
                    char name[50];
                    printf("Enter name to search: ");
                    scanf("%s", name);
                    searchEntry(phoneBook, count, name);
                    break;
                }
            case 4: {
                    exit(0);
                }
            default: {
                    printf("Invalid choice\n");
                }
        }
    }

    return 0;
}