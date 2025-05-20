//FormAI DATASET v1.0 Category: Phone Book ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNAMELEN 50
#define MAXPHONENUMLEN 15
#define MAXENTRIES 100

typedef struct {
    char name[MAXNAMELEN+1];
    char phone[MAXPHONENUMLEN+1];
} PhoneBookEntry;

PhoneBookEntry *phoneBook;
int numEntries = 0;

void displayMenu();
void addEntry();
void removeEntry();
void searchByName();
void searchByNumber();
void savePhoneBook();
void loadPhoneBook();

int main() {
    phoneBook = (PhoneBookEntry *)malloc(MAXENTRIES * sizeof(PhoneBookEntry));
    loadPhoneBook();

    char choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        printf("\n");

        switch(choice) {
            case '1':
                addEntry();
                break;
            case '2':
                removeEntry();
                break;
            case '3':
                searchByName();
                break;
            case '4':
                searchByNumber();
                break;
            case '5':
                savePhoneBook();
                break;
            case '6':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != '6');

    free(phoneBook);
    return 0;
}

void displayMenu() {
    printf("C Phone Book\n");
    printf("============\n");
    printf("1. Add new entry\n");
    printf("2. Remove an entry\n");
    printf("3. Search by name\n");
    printf("4. Search by phone number\n");
    printf("5. Save phone book\n");
    printf("6. Exit\n");
}

void addEntry() {
    if(numEntries == MAXENTRIES) {
        printf("Phone book is full. Cannot add more entries.\n");
        return;
    }

    PhoneBookEntry newEntry;

    printf("Enter name (max %d characters): ", MAXNAMELEN);
    scanf(" %[^\n]s", newEntry.name);

    printf("Enter phone number (max %d digits): ", MAXPHONENUMLEN);
    scanf(" %s", newEntry.phone);

    phoneBook[numEntries++] = newEntry;

    printf("Entry added successfully.\n");
}

void removeEntry() {
    char name[MAXNAMELEN+1];
    int index = -1;

    printf("Enter name of entry to remove: ");
    scanf(" %[^\n]s", name);

    for(int i = 0; i < numEntries; i++) {
        if(strcmp(phoneBook[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Entry not found.\n");
        return;
    }

    for(int i = index; i < numEntries-1; i++) {
        phoneBook[i] = phoneBook[i+1];
    }

    numEntries--;

    printf("Entry removed successfully.\n");
}

void searchByName() {
    char name[MAXNAMELEN+1];
    int count = 0;

    printf("Enter name to search for: ");
    scanf(" %[^\n]s", name);

    printf("Results:\n");

    for(int i = 0; i < numEntries; i++) {
        if(strstr(phoneBook[i].name, name) != NULL) {
            printf("%s: %s\n", phoneBook[i].name, phoneBook[i].phone);
            count++;
        }
    }

    if(count == 0) {
        printf("No results found.\n");
    }
}

void searchByNumber() {
    char number[MAXPHONENUMLEN+1];
    int count = 0;

    printf("Enter phone number to search for: ");
    scanf(" %s", number);

    printf("Results:\n");

    for(int i = 0; i < numEntries; i++) {
        if(strcmp(phoneBook[i].phone, number) == 0) {
            printf("%s: %s\n", phoneBook[i].name, phoneBook[i].phone);
            count++;
        }
    }

    if(count == 0) {
        printf("No results found.\n");
    }
}

void savePhoneBook() {
    FILE *file = fopen("phonebook.txt", "w");

    if(file == NULL) {
        printf("Error saving phone book.\n");
        return;
    }

    for(int i = 0; i < numEntries; i++) {
        fprintf(file, "%s\t%s\n", phoneBook[i].name, phoneBook[i].phone);
    }

    fclose(file);

    printf("Phone book saved successfully.\n");
}

void loadPhoneBook() {
    FILE *file = fopen("phonebook.txt", "r");

    if(file == NULL) {
        return;
    }

    char line[MAXNAMELEN + MAXPHONENUMLEN + 2];
    char *name, *phone;

    while(fgets(line, sizeof(line), file) != NULL) {
        name = strtok(line, "\t\n");
        phone = strtok(NULL, "\t\n");

        strcpy(phoneBook[numEntries].name, name);
        strcpy(phoneBook[numEntries].phone, phone);

        numEntries++;
    }

    fclose(file);
}