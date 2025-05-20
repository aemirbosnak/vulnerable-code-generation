//FormAI DATASET v1.0 Category: Phone Book ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* constants */
#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 20
#define MAX_ENTRIES 100

/* data structures */
typedef struct {
    char name[MAX_NAME_LEN+1];
    char phone[MAX_PHONE_LEN+1];
} Entry;

Entry phoneBook[MAX_ENTRIES];
int numEntries = 0;

/* function prototypes */
void addEntry();
void deleteEntry();
void searchByName();
void searchByPhone();
void printPhoneBook();
void savePhoneBook();
void loadPhoneBook();

int main() {
    char choice;
    do {
        printf("\nPhone Book\n");
        printf("1. Add Entry\n");
        printf("2. Delete Entry\n");
        printf("3. Search by Name\n");
        printf("4. Search by Phone\n");
        printf("5. Print Phone Book\n");
        printf("6. Save Phone Book\n");
        printf("7. Load Phone Book\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                addEntry();
                break;
            case '2':
                deleteEntry();
                break;
            case '3':
                searchByName();
                break;
            case '4':
                searchByPhone();
                break;
            case '5':
                printPhoneBook();
                break;
            case '6':
                savePhoneBook();
                break;
            case '7':
                loadPhoneBook();
                break;
            case '0':
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != '0');
    return 0;
}

void addEntry() {
    if (numEntries == MAX_ENTRIES) {
        printf("Phone book is full. Cannot add new entry.\n");
        return;
    }
    printf("Enter name: ");
    scanf(" %[^\n]", phoneBook[numEntries].name); // read until newline
    printf("Enter phone number: ");
    scanf(" %[^\n]", phoneBook[numEntries].phone); // read until newline
    numEntries++;
}

void deleteEntry() {
    char name[MAX_NAME_LEN+1];
    printf("Enter name of entry to delete: ");
    scanf(" %[^\n]", name); // read until newline
    int i;
    for (i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            memcpy(&phoneBook[i], &phoneBook[i+1], sizeof(Entry)*(numEntries-i-1));
            numEntries--;
            printf("Entry deleted.\n");
            return;
        }
    }
    printf("Entry not found.\n");
}

void searchByName() {
    char name[MAX_NAME_LEN+1];
    printf("Enter name to search: ");
    scanf(" %[^\n]", name); // read until newline
    int i;
    for (i = 0; i < numEntries; i++) {
        if (strstr(phoneBook[i].name, name) != NULL) {
            printf("%-s: %-s\n", phoneBook[i].name, phoneBook[i].phone);
        }
    }
}

void searchByPhone() {
    char phone[MAX_PHONE_LEN+1];
    printf("Enter phone number to search: ");
    scanf(" %[^\n]", phone); // read until newline
    int i;
    for (i = 0; i < numEntries; i++) {
        if (strstr(phoneBook[i].phone, phone) != NULL) {
            printf("%-s: %-s\n", phoneBook[i].name, phoneBook[i].phone);
        }
    }
}

void printPhoneBook() {
    int i;
    printf("Phone Book (%d entries):\n", numEntries);
    for (i = 0; i < numEntries; i++) {
        printf("%-s: %-s\n", phoneBook[i].name, phoneBook[i].phone);
    }
}

void savePhoneBook() {
    char filename[MAX_NAME_LEN+1];
    printf("Enter filename to save phone book: ");
    scanf(" %[^\n]", filename); // read until newline
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }
    fwrite(&numEntries, sizeof(numEntries), 1, fp);
    fwrite(phoneBook, sizeof(Entry), numEntries, fp);
    fclose(fp);
    printf("Phone book saved to %s.\n", filename);
}

void loadPhoneBook() {
    char filename[MAX_NAME_LEN+1];
    printf("Enter filename to load phone book: ");
    scanf(" %[^\n]", filename); // read until newline
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }
    fread(&numEntries, sizeof(numEntries), 1, fp);
    fread(phoneBook, sizeof(Entry), numEntries, fp);
    fclose(fp);
    printf("Phone book loaded from %s.\n", filename);
}