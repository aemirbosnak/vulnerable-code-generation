//FormAI DATASET v1.0 Category: Phone Book ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 30
#define MAX_PHONE_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

Contact *phone_book;
int num_contacts = 0;
int max_contacts = 1;

void add_contact() {
    if (num_contacts >= max_contacts) {
        max_contacts *= 2;
        phone_book = realloc(phone_book, max_contacts * sizeof(Contact));
    }

    printf("Enter the name: ");
    scanf("%s", phone_book[num_contacts].name);
    printf("Enter the phone number: ");
    scanf("%s", phone_book[num_contacts].phone);

    num_contacts++;
    printf("Contact successfully added!\n");
}

void search_contact() {
    char search_name[MAX_NAME_LENGTH];

    printf("Enter the name to search: ");
    scanf("%s", search_name);

    int found = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, search_name) == 0) {
            printf("Contact found! Name: %s, Phone: %s\n", phone_book[i].name, phone_book[i].phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found!\n");
    }
}

void display_contacts() {
    printf("Phone Book\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("Name: %s, Phone: %s\n", phone_book[i].name, phone_book[i].phone);
    }
}

int main() {
    phone_book = malloc(max_contacts * sizeof(Contact));

    printf("+---------------------+\n");
    printf("|      Phone Book     |\n");
    printf("+---------------------+\n");

    while (1) {
        printf("\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display Contacts\n");
        printf("4. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                search_contact();
                break;
            case 3:
                display_contacts();
                break;
            case 4:
                printf("Goodbye!\n");
                free(phone_book);
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
}