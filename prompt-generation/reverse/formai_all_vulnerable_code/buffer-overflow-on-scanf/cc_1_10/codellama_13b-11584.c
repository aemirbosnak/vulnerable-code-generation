//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
} PhoneBookEntry;

int main() {
    PhoneBookEntry phoneBook[100];
    int numEntries = 0;

    printf("Welcome to the phone book!\n");

    while (1) {
        char command;
        printf("Enter a command (A)dd, (S)earch, (Q)uit: ");
        scanf(" %c", &command);

        switch (command) {
            case 'A':
                printf("Enter a name: ");
                scanf("%s", phoneBook[numEntries].name);
                printf("Enter a phone number: ");
                scanf("%s", phoneBook[numEntries].phone);
                numEntries++;
                break;
            case 'S':
                printf("Enter a name to search for: ");
                char searchName[MAX_NAME_LEN];
                scanf("%s", searchName);
                int i;
                for (i = 0; i < numEntries; i++) {
                    if (strcmp(phoneBook[i].name, searchName) == 0) {
                        printf("Phone number: %s\n", phoneBook[i].phone);
                        break;
                    }
                }
                if (i == numEntries) {
                    printf("Name not found.\n");
                }
                break;
            case 'Q':
                printf("Quitting...\n");
                return 0;
            default:
                printf("Invalid command.\n");
                break;
        }
    }

    return 0;
}