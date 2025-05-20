//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Entry;

int main() {
    int numEntries = 0;
    Entry entries[MAX_ENTRIES];

    while (numEntries < MAX_ENTRIES) {
        printf("Enter a name and phone number, or type 'quit' to exit:\n");
        char input[MAX_NAME_LENGTH + MAX_NUMBER_LENGTH + 2];
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        int nameLen = strlen(input);
        if (nameLen > MAX_NAME_LENGTH) {
            printf("Error: Name is too long.\n");
            continue;
        }

        int numberLen = strlen(input + nameLen + 1);
        if (numberLen > MAX_NUMBER_LENGTH) {
            printf("Error: Phone number is too long.\n");
            continue;
        }

        strcpy(entries[numEntries].name, input);
        strcpy(entries[numEntries].number, input + nameLen + 1);
        numEntries++;
    }

    printf("Phone book:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s: %s\n", entries[i].name, entries[i].number);
    }

    return 0;
}