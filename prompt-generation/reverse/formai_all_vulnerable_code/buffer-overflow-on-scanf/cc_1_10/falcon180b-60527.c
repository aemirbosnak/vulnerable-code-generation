//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[15];
} Contact;

Contact contacts[MAX_CONTACTS];
int num_contacts = 0;

void add_contact() {
    printf("Enter name: ");
    scanf("%s", contacts[num_contacts].name);

    printf("Enter phone number: ");
    scanf("%s", contacts[num_contacts].phone);

    num_contacts++;
}

void view_contacts() {
    for (int i = 0; i < num_contacts; i++) {
        printf("%d. %s - %s\n", i+1, contacts[i].name, contacts[i].phone);
    }
}

void remove_contact() {
    printf("Enter contact number to remove: ");
    int remove_num;
    scanf("%d", &remove_num);

    if (remove_num < 1 || remove_num > num_contacts) {
        printf("Invalid contact number.\n");
        return;
    }

    for (int i = remove_num-1; i < num_contacts-1; i++) {
        strcpy(contacts[i].name, contacts[i+1].name);
        strcpy(contacts[i].phone, contacts[i+1].phone);
    }

    num_contacts--;
}

void search_contact() {
    printf("Enter name to search: ");
    char search_name[50];
    scanf("%s", search_name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            printf("Found contact: %s - %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }

    printf("Contact not found.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nPhone Book\n");
        printf("1. Add contact\n");
        printf("2. View contacts\n");
        printf("3. Remove contact\n");
        printf("4. Search contact\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                view_contacts();
                break;
            case 3:
                remove_contact();
                break;
            case 4:
                search_contact();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}