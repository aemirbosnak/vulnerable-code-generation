//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
} Contact;

Contact phone_book[MAX_CONTACTS];
int num_contacts = 0;

void add_contact(char *name, char *phone) {
    if (num_contacts == MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }

    strcpy(phone_book[num_contacts].name, name);
    strcpy(phone_book[num_contacts].phone, phone);
    num_contacts++;
}

void print_phone_book() {
    for (int i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", phone_book[i].name, phone_book[i].phone);
    }
}

void search_contact(char *name) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            printf("%s: %s\n", phone_book[i].name, phone_book[i].phone);
            return;
        }
    }

    printf("Contact not found!\n");
}

void delete_contact(char *name) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            for (int j = i; j < num_contacts - 1; j++) {
                phone_book[j] = phone_book[j + 1];
            }

            num_contacts--;
            printf("Contact deleted!\n");
            return;
        }
    }

    printf("Contact not found!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nSerenity Phone Book\n");
        printf("1. Add contact\n");
        printf("2. Print phone book\n");
        printf("3. Search contact\n");
        printf("4. Delete contact\n");
        printf("5. Quit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[50], phone[20];

                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone: ");
                scanf("%s", phone);

                add_contact(name, phone);
                break;
            }

            case 2:
                print_phone_book();
                break;

            case 3: {
                char name[50];

                printf("Enter name: ");
                scanf("%s", name);

                search_contact(name);
                break;
            }

            case 4: {
                char name[50];

                printf("Enter name: ");
                scanf("%s", name);

                delete_contact(name);
                break;
            }

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}