//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

int main() {
    entry_t phonebook[MAX_ENTRIES];
    int num_entries = 0;
    char choice;

    do {
        printf("Welcome to the Phone Book!\n");
        printf("What would you like to do?\n");
        printf("1. Add an entry\n");
        printf("2. Search for an entry\n");
        printf("3. Display all entries\n");
        printf("4. Exit\n");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(num_entries < MAX_ENTRIES) {
                    printf("Enter name: ");
                    scanf("%s", phonebook[num_entries].name);
                    printf("Enter number: ");
                    scanf("%s", phonebook[num_entries].number);
                    num_entries++;
                    printf("Entry added successfully!\n");
                } else {
                    printf("Phone book is full!\n");
                }
                break;
            case '2':
                printf("Enter name to search: ");
                scanf("%s", phonebook[0].name);
                for(int i = 1; i <= num_entries; i++) {
                    if(strcmp(phonebook[i].name, phonebook[0].name) == 0) {
                        printf("Name found! Number: %s\n", phonebook[i].number);
                        break;
                    }
                }
                break;
            case '3':
                for(int i = 0; i < num_entries; i++) {
                    printf("Name: %s\tNumber: %s\n", phonebook[i].name, phonebook[i].number);
                }
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while(choice!= '4');

    return 0;
}