//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: optimized
// Phone Book Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_NUM_LEN 15

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
} PhoneBookEntry;

int main() {
    PhoneBookEntry phoneBook[100];
    int numEntries = 0;
    char command;

    // Print the menu
    printf("Welcome to the phone book!\n");
    printf("1. Add a new entry\n");
    printf("2. Search for an entry\n");
    printf("3. Delete an entry\n");
    printf("4. Print the phone book\n");
    printf("5. Quit\n");

    // Loop until the user quits
    while (1) {
        // Get the user's command
        printf("Enter a command: ");
        scanf("%c", &command);

        // Add a new entry
        if (command == '1') {
            printf("Enter the name: ");
            scanf("%s", phoneBook[numEntries].name);
            printf("Enter the number: ");
            scanf("%s", phoneBook[numEntries].number);
            numEntries++;
        }
        // Search for an entry
        else if (command == '2') {
            printf("Enter the name to search for: ");
            scanf("%s", phoneBook[numEntries].name);
            for (int i = 0; i < numEntries; i++) {
                if (strcmp(phoneBook[i].name, phoneBook[numEntries].name) == 0) {
                    printf("Name: %s\n", phoneBook[i].name);
                    printf("Number: %s\n", phoneBook[i].number);
                }
            }
        }
        // Delete an entry
        else if (command == '3') {
            printf("Enter the name to delete: ");
            scanf("%s", phoneBook[numEntries].name);
            for (int i = 0; i < numEntries; i++) {
                if (strcmp(phoneBook[i].name, phoneBook[numEntries].name) == 0) {
                    for (int j = i; j < numEntries - 1; j++) {
                        phoneBook[j] = phoneBook[j + 1];
                    }
                    numEntries--;
                    break;
                }
            }
        }
        // Print the phone book
        else if (command == '4') {
            for (int i = 0; i < numEntries; i++) {
                printf("Name: %s\n", phoneBook[i].name);
                printf("Number: %s\n", phoneBook[i].number);
            }
        }
        // Quit
        else if (command == '5') {
            break;
        }
    }

    return 0;
}