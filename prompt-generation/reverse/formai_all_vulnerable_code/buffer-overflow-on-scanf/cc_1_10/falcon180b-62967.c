//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000 // Maximum number of entries in the phone book

typedef struct {
    char name[50]; // Name of the contact
    char number[15]; // Contact's phone number
} Contact;

int compareNames(const void *a, const void *b) {
    // Function to sort contacts by name
    Contact *contactA = (Contact *)a;
    Contact *contactB = (Contact *)b;
    return strcmp(contactA->name, contactB->name);
}

int compareNumbers(const void *a, const void *b) {
    // Function to sort contacts by number
    Contact *contactA = (Contact *)a;
    Contact *contactB = (Contact *)b;
    return strcmp(contactA->number, contactB->number);
}

int main() {
    int numEntries = 0;
    Contact *phoneBook = malloc(MAX_ENTRIES * sizeof(Contact)); // Allocate memory for the phone book
    
    while (numEntries < MAX_ENTRIES) { // Add new entries to the phone book
        char name[50];
        char number[15];
        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter number: ");
        scanf("%s", number);
        
        strcpy(phoneBook[numEntries].name, name);
        strcpy(phoneBook[numEntries].number, number);
        numEntries++;
    }
    
    printf("Sorted by name:\n");
    qsort(phoneBook, numEntries, sizeof(Contact), compareNames);
    for (int i = 0; i < numEntries; i++) {
        printf("%s - %s\n", phoneBook[i].name, phoneBook[i].number);
    }
    
    printf("\nSorted by number:\n");
    qsort(phoneBook, numEntries, sizeof(Contact), compareNumbers);
    for (int i = 0; i < numEntries; i++) {
        printf("%s - %s\n", phoneBook[i].name, phoneBook[i].number);
    }
    
    free(phoneBook); // Free memory allocated for the phone book
    
    return 0;
}