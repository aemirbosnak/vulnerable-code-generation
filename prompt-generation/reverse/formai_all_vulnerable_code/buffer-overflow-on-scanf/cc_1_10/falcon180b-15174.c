//Falcon-180B DATASET v1.0 Category: Database querying ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_ADDRESS_LEN 100
#define MAX_PHONE_LEN 20
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char address[MAX_ADDRESS_LEN];
    char phone[MAX_PHONE_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

void print_contact(Contact* c) {
    printf("Name: %s\n", c->name);
    printf("Address: %s\n", c->address);
    printf("Phone: %s\n", c->phone);
    printf("Email: %s\n\n", c->email);
}

int main() {
    Contact contacts[3] = {
        {"John Doe", "123 Main St", "555-1234", "john@example.com"},
        {"Jane Smith", "456 Elm St", "555-5678", "jane@example.com"},
        {"Bob Johnson", "789 Oak St", "555-9012", "bob@example.com"}
    };

    int num_contacts = sizeof(contacts) / sizeof(Contact);

    printf("Post-Apocalyptic Contact List\n");
    printf("=============================\n");

    while(1) {
        printf("1. Search by name\n");
        printf("2. Search by address\n");
        printf("3. Search by phone\n");
        printf("4. Search by email\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        if(choice == 5) {
            break;
        }

        char search_str[MAX_NAME_LEN];
        printf("Enter the search string: ");
        scanf("%s", search_str);

        int found_count = 0;
        for(int i=0; i<num_contacts; i++) {
            Contact* c = &contacts[i];
            if(strcmp(c->name, search_str) == 0) {
                print_contact(c);
                found_count++;
            } else if(strcmp(c->address, search_str) == 0) {
                print_contact(c);
                found_count++;
            } else if(strcmp(c->phone, search_str) == 0) {
                print_contact(c);
                found_count++;
            } else if(strcmp(c->email, search_str) == 0) {
                print_contact(c);
                found_count++;
            }
        }

        if(found_count == 0) {
            printf("No results found.\n");
        }
    }

    return 0;
}