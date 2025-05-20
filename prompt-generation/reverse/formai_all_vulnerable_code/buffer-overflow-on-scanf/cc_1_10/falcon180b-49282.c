//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

entry_t phone_book[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    if(num_entries >= MAX_ENTRIES) {
        printf("Phone book is full!\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", phone_book[num_entries].name);

    printf("Enter number: ");
    scanf("%s", phone_book[num_entries].number);

    num_entries++;
}

void search_entry() {
    char search_name[MAX_NAME_LENGTH];

    printf("Enter name to search: ");
    scanf("%s", search_name);

    for(int i=0; i<num_entries; i++) {
        if(strcmp(phone_book[i].name, search_name) == 0) {
            printf("Name: %s\nNumber: %s\n", phone_book[i].name, phone_book[i].number);
            return;
        }
    }

    printf("Entry not found!\n");
}

void delete_entry() {
    char search_name[MAX_NAME_LENGTH];

    printf("Enter name to delete: ");
    scanf("%s", search_name);

    for(int i=0; i<num_entries; i++) {
        if(strcmp(phone_book[i].name, search_name) == 0) {
            memset(phone_book[i].name, 0, MAX_NAME_LENGTH);
            memset(phone_book[i].number, 0, MAX_NUMBER_LENGTH);
            num_entries--;
            printf("Entry deleted!\n");
            return;
        }
    }

    printf("Entry not found!\n");
}

int main() {
    printf("Welcome to the Phone Book!\n");

    while(1) {
        printf("\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Delete entry\n");
        printf("4. Exit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_entry();
                break;
            case 2:
                search_entry();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}