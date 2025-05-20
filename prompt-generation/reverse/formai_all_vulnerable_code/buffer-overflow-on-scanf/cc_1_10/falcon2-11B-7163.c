//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store phone book entries
struct PhoneBookEntry {
    char name[50];
    char phoneNumber[20];
};

// Function to add a new phone book entry
void addPhoneBookEntry(struct PhoneBookEntry* pb, char* name, char* phoneNumber) {
    int nameSize = strlen(name);
    int phoneSize = strlen(phoneNumber);
    
    if (nameSize > 50 || phoneSize > 20) {
        printf("Phone book entry name or phone number size exceeds limit.\n");
        return;
    }
    
    pb->name[0] = '\0';
    strcpy(pb->name, name);
    pb->phoneNumber[0] = '\0';
    strcpy(pb->phoneNumber, phoneNumber);
    
    printf("Phone book entry added successfully.\n");
}

// Function to display all phone book entries
void displayPhoneBookEntries(struct PhoneBookEntry* pb, int numEntries) {
    for (int i = 0; i < numEntries; i++) {
        printf("%s\t%s\n", pb[i].name, pb[i].phoneNumber);
    }
}

// Main function
int main() {
    // Array to store phone book entries
    struct PhoneBookEntry pb[100];
    
    // Number of entries in phone book
    int numEntries = 0;
    
    while (1) {
        printf("\n1. Add entry\n2. Display entries\n3. Exit\n");
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter name: ");
                char name[50];
                scanf("%s", name);
                
                printf("Enter phone number: ");
                char phoneNumber[20];
                scanf("%s", phoneNumber);
                
                addPhoneBookEntry(pb, name, phoneNumber);
                numEntries++;
                break;
                
            case 2:
                displayPhoneBookEntries(pb, numEntries);
                break;
                
            case 3:
                printf("Exiting program...\n");
                break;
                
            default:
                printf("Invalid choice.\n");
        }
    }
    
    return 0;
}