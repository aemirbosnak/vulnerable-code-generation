//FormAI DATASET v1.0 Category: Phone Book ; Style: unmistakable
#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 100

struct PhoneBookEntry {
    char name[50]; // The name of the person
    char phone[20]; // The phone number of the person
};

struct PhoneBookEntry phoneBook[MAX_ENTRIES]; // The phone book array
int numEntries = 0; // The number of entries in the phone book

void addEntry(char* name, char* phone) {
    struct PhoneBookEntry newEntry;
    strcpy(newEntry.name, name);
    strcpy(newEntry.phone, phone);
    phoneBook[numEntries] = newEntry;
    numEntries++;
}

void displayEntries() {
    printf("Phone Book:\n");
    for(int i = 0; i < numEntries; i++) {
        printf("%s\t%s\n", phoneBook[i].name, phoneBook[i].phone);
    }
}

int main() {
    int choice;
    char name[50];
    char phone[20];
    do {
        printf("Choose an option:\n");
        printf("1. Add a new phone book entry\n");
        printf("2. Display phone book entries\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the name: ");
                scanf("%s", name);
                printf("Enter the phone number: ");
                scanf("%s", phone);
                addEntry(name, phone);
                printf("Entry added!\n");
                break;
            case 2:
                displayEntries();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 3);
    return 0;
}