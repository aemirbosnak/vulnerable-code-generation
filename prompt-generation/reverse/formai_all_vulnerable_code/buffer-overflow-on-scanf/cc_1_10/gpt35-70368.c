//FormAI DATASET v1.0 Category: Database simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_PHONE_LENGTH 15
#define MAX_EMAIL_LENGTH 100
#define MAX_RECORDS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

Contact database[MAX_RECORDS];
int num_records = 0;

void add_contact(char *name, char *phone, char *email) {
    if (num_records == MAX_RECORDS) {
        printf("Database is full, cannot add more contacts.\n");
    } else {
        strcpy(database[num_records].name, name);
        strcpy(database[num_records].phone, phone);
        strcpy(database[num_records].email, email);
        num_records++;
        printf("Contact added successfully.\n");
    }
}

void search_contact(char *name) {
    int found = 0;
    for (int i = 0; i < num_records; i++) {
        if (strcmp(database[i].name, name) == 0) {
            printf("Name: %s\n", database[i].name);
            printf("Phone: %s\n", database[i].phone);
            printf("Email: %s\n", database[i].email);
            found = 1;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

void list_contacts() {
    for (int i = 0; i < num_records; i++) {
        printf("Name: %s\n", database[i].name);
        printf("Phone: %s\n", database[i].phone);
        printf("Email: %s\n", database[i].email);
        printf("\n");
    }
}

int main() {
    printf("Welcome to the Contact Database!\n\n");
    while (1) {
        printf("Enter the number corresponding to your desired action:\n");
        printf("1. Add a new contact.\n");
        printf("2. Search for a contact.\n");
        printf("3. List all contacts.\n");
        printf("4. Quit.\n");
        int choice;
        scanf("%d", &choice);
        getchar(); // Consume remaining newline character from input buffer.
        switch (choice) {
            case 1:
                printf("Enter name: ");
                char name[MAX_NAME_LENGTH];
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strlen(name)-1] = '\0'; // Remove trailing newline character.
                printf("Enter phone: ");
                char phone[MAX_PHONE_LENGTH];
                fgets(phone, MAX_PHONE_LENGTH, stdin);
                phone[strlen(phone)-1] = '\0'; // Remove trailing newline character.
                printf("Enter email: ");
                char email[MAX_EMAIL_LENGTH];
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strlen(email)-1] = '\0'; // Remove trailing newline character.
                add_contact(name, phone, email);
                break;
            case 2:
                printf("Enter name to search: ");
                char search_name[MAX_NAME_LENGTH];
                fgets(search_name, MAX_NAME_LENGTH, stdin);
                search_name[strlen(search_name)-1] = '\0'; // Remove trailing newline character.
                search_contact(search_name);
                break;
            case 3:
                list_contacts();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
        printf("\n");
    }
    return 0;
}