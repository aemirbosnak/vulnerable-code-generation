//FormAI DATASET v1.0 Category: Phone Book ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[30];
    char phoneNumber[20];
} PhoneBookEntry;

void addEntry(PhoneBookEntry phoneBook[], int* numEntries);
void displayEntries(PhoneBookEntry phoneBook[], int numEntries);
void searchEntry(PhoneBookEntry phoneBook[], int numEntries);

int main() {
    PhoneBookEntry phoneBook[MAX_ENTRIES];
    int numEntries = 0;
    char choice;
    
    do {
        printf("Welcome to My Phone Book\n");
        printf("------------------------\n");
        printf("1. Add an entry\n");
        printf("2. Display all entries\n");
        printf("3. Search for an entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        
        switch(choice) {
            case '1':
                addEntry(phoneBook, &numEntries);
                break;
                
            case '2':
                displayEntries(phoneBook, numEntries);
                break;
                
            case '3':
                searchEntry(phoneBook, numEntries);
                break;
                
            case '4':
                printf("Thank you for using My Phone Book!\n");
                break;
                
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    } while(choice != '4');
    
    return 0;
}

void addEntry(PhoneBookEntry phoneBook[], int* numEntries) {
    char name[30], phoneNumber[20];
    
    while(getchar() != '\n');
    printf("\nEnter the name: ");
    fgets(name, 30, stdin);
    name[strlen(name) - 1] = '\0';
    printf("Enter the phone number: ");
    fgets(phoneNumber, 20, stdin);
    phoneNumber[strlen(phoneNumber) - 1] = '\0';
    
    PhoneBookEntry newEntry;
    strcpy(newEntry.name, name);
    strcpy(newEntry.phoneNumber, phoneNumber);
    
    phoneBook[*numEntries] = newEntry;
    (*numEntries)++;
    
    printf("Entry added successfully!\n\n");
}

void displayEntries(PhoneBookEntry phoneBook[], int numEntries) {
    if(numEntries == 0) {
        printf("No entries found.\n\n");
    } else {
        printf("\n %-30s %-20s\n", "Name", "Phone Number");
        printf("-----------------------------------------------------------\n");
        
        for(int i = 0; i < numEntries; i++) {
            printf(" %-30s %-20s\n", phoneBook[i].name, phoneBook[i].phoneNumber);
        }
        
        printf("\n");
    }
}

void searchEntry(PhoneBookEntry phoneBook[], int numEntries) {
    if(numEntries == 0) {
        printf("No entries found.\n\n");
    } else {
        char name[30];
        int matchedEntries = 0;
        
        while(getchar() != '\n');
        printf("\nEnter the name to search: ");
        fgets(name, 30, stdin);
        name[strlen(name) - 1] = '\0';
        
        printf("\n %-30s %-20s\n", "Name", "Phone Number");
        printf("-----------------------------------------------------------\n");
        
        for(int i = 0; i < numEntries; i++) {
            if(strcmp(name, phoneBook[i].name) == 0) {
                printf(" %-30s %-20s\n", phoneBook[i].name, phoneBook[i].phoneNumber);
                matchedEntries++;
            }
        }
        
        if(matchedEntries == 0) {
            printf("No entries found with name '%s'\n", name);
        } else {
            printf("\n%d entries found with name '%s'\n", matchedEntries, name);
        }
        
        printf("\n");
    }
}