//FormAI DATASET v1.0 Category: Phone Book ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[30];
    char phone_number[15];
} Contact;

int num_contacts = 0;
Contact phone_book[MAX_CONTACTS];

void add_contact(char *name, char *phone_number) { // Function to add a new contact to the phone book
    if (num_contacts < MAX_CONTACTS) {
        strcpy(phone_book[num_contacts].name, name);
        strcpy(phone_book[num_contacts].phone_number, phone_number);
        num_contacts++;
        printf("%s has been added to the phone book.\n", name);
    } else {
        printf("Phone book is full. Cannot add more contacts.\n");
    }
}

void remove_contact(char *name) { // Function to remove a contact from the phone book
    int i, index = -1;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (i = index; i < num_contacts - 1; i++) {
            strcpy(phone_book[i].name, phone_book[i+1].name);
            strcpy(phone_book[i].phone_number, phone_book[i+1].phone_number);
        }
        num_contacts--;
        printf("%s has been removed from the phone book.\n", name);
    } else {
        printf("%s does not exist in the phone book.\n", name);
    }
}

void search_contact(char *name) { // Function to search for a contact in the phone book
    int i, index = -1;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        printf("Name: %s\nPhone Number: %s\n", phone_book[index].name, phone_book[index].phone_number);
    } else {
        printf("%s does not exist in the phone book.\n", name);
    }
}

void display_contacts() { // Function to display all contacts in the phone book
    printf("Phone Book:\n");
    int i;
    for (i = 0; i < num_contacts; i++) {
        printf("%d. Name: %s\n   Phone Number: %s\n", i+1, phone_book[i].name, phone_book[i].phone_number);
    }
}

int main() { // Main function
    while (1) { // Menu-driven program loop
        printf("\nMenu:\n");
        printf("1. Add a contact\n");
        printf("2. Remove a contact\n");
        printf("3. Search for a contact\n");
        printf("4. Display all contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        getchar(); // Consume the newline character
        switch (choice) {
            case 1: {
                char name[30], phone_number[15];
                printf("Enter name: ");
                fgets(name, 30, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove the newline character from fgets
                printf("Enter phone number: ");
                fgets(phone_number, 15, stdin);
                phone_number[strcspn(phone_number, "\n")] = '\0'; // Remove the newline character from fgets
                add_contact(name, phone_number);
                break;
            }
            case 2: {
                char name[30];
                printf("Enter name: ");
                fgets(name, 30, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove the newline character from fgets
                remove_contact(name);
                break;
            }
            case 3: {
                char name[30];
                printf("Enter name: ");
                fgets(name, 30, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove the newline character from fgets
                search_contact(name);
                break;
            }
            case 4: {
                display_contacts();
                break;
            }
            case 5: {
                printf("Exiting phone book...\n");
                exit(0);
            }
            default: {
                printf("Invalid input. Please try again...\n");
                break;
            }
        }
    }
    return 0;
}