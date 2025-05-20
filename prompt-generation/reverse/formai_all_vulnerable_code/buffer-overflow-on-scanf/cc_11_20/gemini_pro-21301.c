//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char name[32];
    char number[16];
} PhoneBookEntry;

int main() {
    PhoneBookEntry *phoneBook = malloc(sizeof(PhoneBookEntry) * 100);
    int numEntries = 0;
    char input[100];
    while (1) {
        printf("Enter a command (add, find, delete, quit): ");
        scanf("%s", input);
        if (strcmp(input, "add") == 0) {
            printf("Enter name: ");
            scanf("%s", phoneBook[numEntries].name);
            printf("Enter number: ");
            scanf("%s", phoneBook[numEntries].number);
            numEntries++;
        } else if (strcmp(input, "find") == 0) {
            printf("Enter name: ");
            scanf("%s", input);
            for (int i = 0; i < numEntries; i++) {
                if (strcmp(phoneBook[i].name, input) == 0) {
                    printf("Found: %s (%s)\n", phoneBook[i].name, phoneBook[i].number);
                    break;
                }
            }
        } else if (strcmp(input, "delete") == 0) {
            printf("Enter name: ");
            scanf("%s", input);
            for (int i = 0; i < numEntries; i++) {
                if (strcmp(phoneBook[i].name, input) == 0) {
                    for (int j = i; j < numEntries - 1; j++) {
                        phoneBook[j] = phoneBook[j + 1];
                    }
                    numEntries--;
                    printf("Deleted: %s\n", input);
                    break;
                }
            }
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }
    free(phoneBook);
    return 0;
}