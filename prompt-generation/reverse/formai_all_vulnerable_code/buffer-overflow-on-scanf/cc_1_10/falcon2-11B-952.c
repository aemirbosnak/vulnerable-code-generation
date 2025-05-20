//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PhoneBook {
    char name[50];
    char phone[20];
};

int main() {
    struct PhoneBook phoneBook[10]; // Array to hold phone book entries
    int numEntries = 0; // Number of entries in phone book
    
    // Prompt user for number of entries
    printf("Enter the number of entries in the phone book: ");
    scanf("%d", &numEntries);
    
    // Prompt user for name and phone number for each entry
    for (int i = 0; i < numEntries; i++) {
        printf("Enter name for entry %d: ", i + 1);
        scanf("%s", phoneBook[i].name);
        printf("Enter phone number for entry %d: ", i + 1);
        scanf("%s", phoneBook[i].phone);
    }
    
    // Print out the phone book entries
    printf("Phone Book Entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s - %s\n", phoneBook[i].name, phoneBook[i].phone);
    }
    
    // Prompt user for phone number to search for
    printf("Enter phone number to search for: ");
    char search[20];
    scanf("%s", search);
    
    // Search for phone number in phone book
    int found = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i].phone, search) == 0) {
            printf("%s - %s\n", phoneBook[i].name, phoneBook[i].phone);
            found = 1;
        }
    }
    
    // If phone number not found, prompt user to try again
    if (!found) {
        printf("Phone number not found.\n");
        printf("Enter phone number to search for: ");
        scanf("%s", search);
        for (int i = 0; i < numEntries; i++) {
            if (strcmp(phoneBook[i].phone, search) == 0) {
                printf("%s - %s\n", phoneBook[i].name, phoneBook[i].phone);
                found = 1;
            }
        }
    }
    
    // Free memory allocated for phone book entries
    for (int i = 0; i < numEntries; i++) {
        free(phoneBook[i].name);
        free(phoneBook[i].phone);
    }
    
    // Clean up
    return 0;
}