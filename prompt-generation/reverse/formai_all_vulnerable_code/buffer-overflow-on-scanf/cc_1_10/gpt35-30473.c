//FormAI DATASET v1.0 Category: Phone Book ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a phonebook entry structure
typedef struct {
    char name[50];
    char phone[20];
} PhoneEntry;

int main() {
    PhoneEntry* phonebook; // Declare a pointer to a phonebook array
    int numEntries; // Number of entries in the phonebook
    char searchName[50]; // Name to search for in phonebook
    int i;

    // Prompt user for number of entries
    printf("Enter the number of phonebook entries: ");
    scanf("%d", &numEntries);

    // Allocate memory for the phonebook array based on user input
    phonebook = (PhoneEntry*) calloc(numEntries, sizeof(PhoneEntry));

    // Loop through to get user input for each entry in the phonebook
    for (i = 0; i < numEntries; i++) {
        printf("Enter name for entry %d: ", i+1);
        scanf("%s", phonebook[i].name);
        printf("Enter phone number for entry %d: ", i+1);
        scanf("%s", phonebook[i].phone);
    }

    // Prompt user for name to search for in the phonebook
    printf("Enter a name to search for: ");
    scanf("%s", searchName);

    // Loop through the phonebook array to find the matching name
    for (i = 0; i < numEntries; i++) {
        if (strcmp(searchName, phonebook[i].name) == 0) {
            printf("%s's phone number is: %s\n", phonebook[i].name, phonebook[i].phone);
            break;
        }
    }

    // If the name was not found in the phonebook, notify the user
    if (i == numEntries) {
        printf("%s was not found in the phonebook.\n", searchName);
    }

    // Free the allocated memory for the phonebook array
    free(phonebook);

    return 0;   
}