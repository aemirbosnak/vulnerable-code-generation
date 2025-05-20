//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15
#define MAX_ENTRIES 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* name, char* number) {
    strcpy(entries[num_entries].name, name);
    strcpy(entries[num_entries].number, number);
    num_entries++;
}

void display_entries() {
    printf("Phone Book Entries:\n");
    for(int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].name, entries[i].number);
    }
}

int main() {
    char input[100];
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
    int choice = 0;

    printf("Welcome to the Phone Book!\n");
    printf("1. Add Entry\n");
    printf("2. Display Entries\n");
    printf("3. Exit\n");

    while(choice!= 3) {
        printf("Enter your choice: ");
        scanf("%s", input);

        if(strcmp(input, "1") == 0) {
            printf("Enter name: ");
            scanf("%s", name);

            printf("Enter phone number: ");
            scanf("%s", number);

            add_entry(name, number);
            printf("Entry added!\n");
        } else if(strcmp(input, "2") == 0) {
            display_entries();
        } else {
            printf("Invalid choice.\n");
        }

        printf("Press enter to continue...\n");
        fflush(stdin);
        getchar();
    }

    return 0;
}