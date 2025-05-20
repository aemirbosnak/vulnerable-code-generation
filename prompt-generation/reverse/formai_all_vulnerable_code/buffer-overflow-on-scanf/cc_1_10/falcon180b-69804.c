//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 100
#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

contact mailing_list[MAX_LIST_SIZE];
int list_size = 0;

void add_contact(char *name, char *email) {
    if (list_size >= MAX_LIST_SIZE) {
        printf("Error: Mailing list is full.\n");
        return;
    }

    strcpy(mailing_list[list_size].name, name);
    strcpy(mailing_list[list_size].email, email);

    list_size++;
}

void remove_contact(int index) {
    if (index < 0 || index >= list_size) {
        printf("Error: Invalid contact index.\n");
        return;
    }

    list_size--;

    for (int i = index; i < list_size; i++) {
        strcpy(mailing_list[i].name, mailing_list[i+1].name);
        strcpy(mailing_list[i].email, mailing_list[i+1].email);
    }
}

void display_contacts() {
    printf("Mailing List:\n");

    for (int i = 0; i < list_size; i++) {
        printf("%d. %s (%s)\n", i+1, mailing_list[i].name, mailing_list[i].email);
    }
}

int main() {
    int choice;

    do {
        printf("1. Add Contact\n2. Remove Contact\n3. Display Mailing List\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[MAX_NAME_LEN], email[MAX_EMAIL_LEN];
                printf("Enter contact name: ");
                scanf("%s", name);
                printf("Enter contact email: ");
                scanf("%s", email);

                add_contact(name, email);
                printf("Contact added successfully.\n");
                break;
            }

            case 2: {
                int index;
                printf("Enter contact index to remove: ");
                scanf("%d", &index);

                remove_contact(index);
                printf("Contact removed successfully.\n");
                break;
            }

            case 3: {
                display_contacts();
                break;
            }

            case 4: {
                printf("Exiting...\n");
                break;
            }

            default: {
                printf("Invalid choice. Please try again.\n");
            }
        }
    } while (choice!= 4);

    return 0;
}