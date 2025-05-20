//FormAI DATASET v1.0 Category: Database simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_EMAIL_LENGTH 100
#define MAX_ENTRIES 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} entry;

int num_entries = 0;
entry database[MAX_ENTRIES];

void add_entry(char name[], char phone[], char email[]) {
    if (num_entries < MAX_ENTRIES) {
        entry new_entry;
        strcpy(new_entry.name, name);
        strcpy(new_entry.phone, phone);
        strcpy(new_entry.email, email);
        database[num_entries] = new_entry;
        num_entries++;
        printf("Entry added!\n");
    } else {
        printf("Database is full. Entry not added.\n");
    }
}

void print_database() {
    printf("Name\t\tPhone\t\tEmail\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t\t%s\t\t%s\n", database[i].name, database[i].phone, database[i].email);
    }
}

int main() {
    int option;
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];

    do {
        printf("\nOptions:\n\t1. Add entry\n\t2. Print database\n\t3. Quit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone: ");
                scanf("%s", phone);
                printf("Enter email: ");
                scanf("%s", email);
                add_entry(name, phone, email);
                break;
            case 2:
                print_database();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    } while (option != 3);

    return 0;
}