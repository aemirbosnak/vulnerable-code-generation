//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME 50
#define MAX_NUMBER 15

typedef struct {
    char name[MAX_NAME];
    char number[MAX_NUMBER];
} entry_t;

int main() {
    entry_t entries[MAX_ENTRIES];
    int num_entries = 0;
    char choice;
    char name[MAX_NAME];
    char number[MAX_NUMBER];

    do {
        printf("Phone Book\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Delete entry\n");
        printf("4. Display all entries\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter number: ");
                scanf("%s", number);
                strcpy(entries[num_entries].name, name);
                strcpy(entries[num_entries].number, number);
                num_entries++;
                break;
            case '2':
                printf("Enter name to search: ");
                scanf("%s", name);
                for(int i = 0; i < num_entries; i++) {
                    if(strcmp(entries[i].name, name) == 0) {
                        printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
                    }
                }
                break;
            case '3':
                printf("Enter name to delete: ");
                scanf("%s", name);
                for(int i = 0; i < num_entries; i++) {
                    if(strcmp(entries[i].name, name) == 0) {
                        strcpy(entries[i].name, "");
                        strcpy(entries[i].number, "");
                    }
                }
                break;
            case '4':
                printf("All entries:\n");
                for(int i = 0; i < num_entries; i++) {
                    printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
                }
                break;
            case '5':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= '5');

    return 0;
}