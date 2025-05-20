//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_NUMBER_LENGTH 20
#define MAX_ENTRIES 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} phonebook_entry;

phonebook_entry phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* name, char* number) {
    strncpy(phonebook[num_entries].name, name, MAX_NAME_LENGTH);
    strncpy(phonebook[num_entries].number, number, MAX_NUMBER_LENGTH);
    num_entries++;
}

void search_entry(char* name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\n", phonebook[i].name);
            printf("Number: %s\n", phonebook[i].number);
        }
    }
}

void delete_entry(char* name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            memmove(phonebook+i, phonebook+i+1, sizeof(phonebook_entry)*(num_entries-i-1));
            num_entries--;
            break;
        }
    }
}

int main() {
    char choice;
    while (1) {
        printf("Enter choice:\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Delete entry\n");
        printf("4. Exit\n");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                printf("Enter name: ");
                char name[MAX_NAME_LENGTH];
                scanf("%s", name);
                printf("Enter number: ");
                char number[MAX_NUMBER_LENGTH];
                scanf("%s", number);
                add_entry(name, number);
                break;
            case '2':
                printf("Enter name to search: ");
                char search_name[MAX_NAME_LENGTH];
                scanf("%s", search_name);
                search_entry(search_name);
                break;
            case '3':
                printf("Enter name to delete: ");
                char delete_name[MAX_NAME_LENGTH];
                scanf("%s", delete_name);
                delete_entry(delete_name);
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}