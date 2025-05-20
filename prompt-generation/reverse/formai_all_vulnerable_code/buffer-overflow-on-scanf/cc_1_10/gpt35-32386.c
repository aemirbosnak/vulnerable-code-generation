//FormAI DATASET v1.0 Category: Phone Book ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 30
#define MAX_PHONE_NUM_LEN 12

typedef struct PhoneBookEntry {
    char name[MAX_NAME_LEN];
    char phoneNum[MAX_PHONE_NUM_LEN];
    struct PhoneBookEntry* next;
} PhoneBookEntry;

void printEntries(PhoneBookEntry* head) {
    if (head == NULL) {
        printf("No entries in phone book.\n");
        return;
    }
    PhoneBookEntry* curr = head;
    printf("Entries in phone book:\n");
    while (curr != NULL) {
        printf("\tName: %s\n", curr->name);
        printf("\tPhone Number: %s\n", curr->phoneNum);
        curr = curr->next;
    }
}

void addEntry(PhoneBookEntry** headPtr, char* name, char* phoneNum) {
    PhoneBookEntry* newEntry = malloc(sizeof(PhoneBookEntry));
    if (newEntry == NULL) {
        printf("Error: Unable to allocate memory for new entry.\n");
        return;
    }
    strncpy(newEntry->name, name, MAX_NAME_LEN-1);
    newEntry->name[MAX_NAME_LEN-1] = '\0';
    strncpy(newEntry->phoneNum, phoneNum, MAX_PHONE_NUM_LEN-1);
    newEntry->phoneNum[MAX_PHONE_NUM_LEN-1] = '\0';
    newEntry->next = NULL;
    if (*headPtr == NULL) {
        *headPtr = newEntry;
    } else {
        PhoneBookEntry* curr = *headPtr;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newEntry;
    }
    printf("Successfully added new entry!\n");
}

void deleteEntry(PhoneBookEntry** headPtr, char* name) {
    if (*headPtr == NULL) {
        printf("Error: Phone book is already empty.\n");
        return;
    }
    PhoneBookEntry* curr = *headPtr;
    if (strcmp(curr->name, name) == 0) {
        *headPtr = curr->next;
        free(curr);
        printf("Successfully deleted entry for %s.\n", name);
        return;
    }
    PhoneBookEntry* prev = curr;
    curr = curr->next;
    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            prev->next = curr->next;
            free(curr);
            printf("Successfully deleted entry for %s.\n", name);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Error: No entry found for %s.\n", name);
}

void clearPhoneBook(PhoneBookEntry** headPtr) {
    if (*headPtr == NULL) {
        printf("Phone book is already empty.\n");
        return;
    }
    PhoneBookEntry* curr = *headPtr;
    while (curr != NULL) {
        PhoneBookEntry* next = curr->next;
        free(curr);
        curr = next;
    }
    *headPtr = NULL;
    printf("Successfully cleared phone book.\n");
}

int main() {
    PhoneBookEntry* phoneBookHead = NULL;
    while (1) {
        printf("\nWelcome to the C Phone Book!\n");
        printf("Please select an option:\n");
        printf("\t1. Add a new entry to the phone book.\n");
        printf("\t2. Delete an existing entry from the phone book.\n");
        printf("\t3. View all entries in the phone book.\n");
        printf("\t4. Clear the phone book.\n");
        printf("\t5. Quit.\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nAdd a new entry to the phone book:\n");
                char name[MAX_NAME_LEN];
                char phoneNum[MAX_PHONE_NUM_LEN];
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phoneNum);
                addEntry(&phoneBookHead, name, phoneNum);
                break;
            case 2:
                printf("\nDelete an existing entry from the phone book:\n");
                char deleteName[MAX_NAME_LEN];
                printf("Enter name of entry to delete: ");
                scanf("%s", deleteName);
                deleteEntry(&phoneBookHead, deleteName);
                break;
            case 3:
                printf("\nView all entries in the phone book:\n");
                printEntries(phoneBookHead);
                break;
            case 4:
                printf("\nClear the phone book:\n");
                clearPhoneBook(&phoneBookHead);
                break;
            case 5:
                printf("\nThank you for using the C Phone Book!\n\n");
                exit(0);
            default:
                printf("\nInvalid choice, please select again.\n");
                break;
        }
    }
    return 0;
}