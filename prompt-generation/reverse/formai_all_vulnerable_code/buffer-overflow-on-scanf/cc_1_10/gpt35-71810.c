//FormAI DATASET v1.0 Category: Phone Book ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact {
    char name[50];
    char phone[15];
} Contact;

void addContact(Contact **phonebook, int *numContacts);
void printPhonebook(Contact *phonebook, int numContacts);
void savePhonebook(Contact *phonebook, int numContacts);
Contact *loadPhonebook(int *numContacts);

int main() {
    Contact *phonebook = NULL;
    int numContacts = 0;
    int choice;

    printf("Welcome to My Phonebook!\n");

    do {
        printf("\nPlease select an option:\n");
        printf("1. Add a contact\n");
        printf("2. Print phonebook\n");
        printf("3. Save phonebook\n");
        printf("4. Load phonebook\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addContact(&phonebook, &numContacts);
            break;
        case 2:
            printPhonebook(phonebook, numContacts);
            break;
        case 3:
            savePhonebook(phonebook, numContacts);
            break;
        case 4:
            phonebook = loadPhonebook(&numContacts);
            break;
        case 5:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 5);

    return 0;
}

void addContact(Contact **phonebook, int *numContacts) {
    printf("\nEnter contact name: ");
    char name[50];
    scanf("%s", name);

    printf("Enter contact phone number: ");
    char phone[15];
    scanf("%s", phone);

    (*numContacts)++;
    *phonebook = (Contact*)realloc(*phonebook, *numContacts * sizeof(Contact));
    strcpy((*phonebook)[*numContacts - 1].name, name);
    strcpy((*phonebook)[*numContacts - 1].phone, phone);

    printf("\nContact added to phonebook!\n");
}

void printPhonebook(Contact *phonebook, int numContacts) {
    printf("\nPHONEBOOK\n");
    if (numContacts == 0) {
        printf("No contacts in phonebook.\n");
    } else {
        int i;
        for (i = 0; i < numContacts; i++) {
            printf("%s: %s\n", phonebook[i].name, phonebook[i].phone);
        }
    }
}

void savePhonebook(Contact *phonebook, int numContacts) {
    printf("\nEnter filename to save phonebook: ");
    char filename[50];
    scanf("%s", filename);

    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error saving phonebook.\n");
    } else {
        fwrite(&numContacts, sizeof(int), 1, fp);
        fwrite(phonebook, sizeof(Contact), numContacts, fp);
        fclose(fp);
        printf("Phonebook saved!\n");
    }
}

Contact *loadPhonebook(int *numContacts) {
    printf("\nEnter filename to load phonebook: ");
    char filename[50];
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error loading phonebook.\n");
        return NULL;
    } else {
        fread(numContacts, sizeof(int), 1, fp);
        Contact *phonebook = (Contact*)malloc(*numContacts * sizeof(Contact));
        fread(phonebook, sizeof(Contact), *numContacts, fp);
        fclose(fp);
        printf("Phonebook loaded!\n");
        return phonebook;
    }
}