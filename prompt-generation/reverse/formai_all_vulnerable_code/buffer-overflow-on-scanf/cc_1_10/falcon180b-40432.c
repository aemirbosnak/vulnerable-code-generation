//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char phone[15];
} contact;

void add_contact(contact* book, int count, char* name, char* phone) {
    strcpy(book[count].name, name);
    strcpy(book[count].phone, phone);
}

void delete_contact(contact* book, int count) {
    for (int i = count; i < MAX_ENTRIES - 1; i++) {
        strcpy(book[i].name, book[i + 1].name);
        strcpy(book[i].phone, book[i + 1].phone);
    }
}

void print_contacts(contact* book, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s - %s\n", book[i].name, book[i].phone);
    }
}

int main() {
    contact phonebook[MAX_ENTRIES];
    int count = 0;

    while (count < MAX_ENTRIES) {
        char name[50];
        char phone[15];

        printf("Enter name: ");
        scanf("%s", name);

        printf("Enter phone number: ");
        scanf("%s", phone);

        add_contact(phonebook, count, name, phone);

        count++;
    }

    int choice;

    do {
        printf("\nPhonebook:\n");
        print_contacts(phonebook, count);

        printf("\nChoose an option:\n1. Add contact\n2. Delete contact\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                count++;
                add_contact(phonebook, count, "", "");
                break;
            case 2:
                printf("Enter name to delete: ");
                char delname[50];
                scanf("%s", delname);

                for (int i = 0; i < count; i++) {
                    if (strcmp(phonebook[i].name, delname) == 0) {
                        delete_contact(phonebook, i);
                        count--;
                        break;
                    }
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}