//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_RECORDS 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Record;

Record database[MAX_RECORDS];
int num_records = 0;

void menu() {
    printf("\n========= MENU =========\n");
    printf("1. Add contact\n");
    printf("2. Remove contact\n");
    printf("3. Print all contacts\n");
    printf("4. Search for contact\n");
    printf("5. Exit\n");
    printf("========================\n");
    printf("Enter your choice (1-5): ");
}

void add_contact() {
    if (num_records == MAX_RECORDS) {
        printf("Error: Database full\n");
        return;
    }
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter email: ");
    scanf("%s", email);
    strcpy(database[num_records].name, name);
    strcpy(database[num_records].email, email);
    num_records++;
    printf("Contact added successfully!\n");
}

void remove_contact() {
    char name[MAX_NAME_LENGTH];
    printf("Enter name to remove: ");
    scanf("%s", name);
    int i;
    for (i = 0; i < num_records; i++) {
        if (strcmp(database[i].name, name) == 0) {
            memmove(&database[i], &database[i+1], sizeof(Record) * (num_records - i - 1));
            num_records--;
            printf("Contact removed successfully!\n");
            return;
        }
    }
    printf("Error: Contact not found\n");
}

void print_contacts() {
    int i;
    for (i = 0; i < num_records; i++) {
        printf("%s\t%s\n", database[i].name, database[i].email);
    }
}

void search_contact() {
    char name[MAX_NAME_LENGTH];
    printf("Enter name to search for: ");
    scanf("%s", name);
    int i;
    for (i = 0; i < num_records; i++) {
        if (strcmp(database[i].name, name) == 0) {
            printf("%s\t%s\n", database[i].name, database[i].email);
            return;
        }
    }
    printf("Error: Contact not found\n");
}

int main() {
    int choice;
    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                remove_contact();
                break;
            case 3:
                print_contacts();
                break;
            case 4:
                search_contact();
                break;
            case 5:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Error: Invalid choice\n");
        }
    } while (1);
}