//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: retro
#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 100

struct contact {
    char name[50];
    char phone[15];
};

void add_contact(struct contact contacts[], int count) {
    printf("Enter the contact name: ");
    scanf("%s", contacts[count].name);

    printf("Enter the contact phone number: ");
    scanf("%s", contacts[count].phone);

    count++;
}

void search_contact(struct contact contacts[], int count, char search_name[]) {
    int i;

    for (i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            printf("Name: %s\nPhone: %s\n", contacts[i].name, contacts[i].phone);
        }
    }
}

void delete_contact(struct contact contacts[], int count, char delete_name[]) {
    int i;

    for (i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, delete_name) == 0) {
            memmove(&contacts[i], &contacts[i + 1], (count - i - 1) * sizeof(struct contact));
            count--;
            break;
        }
    }
}

int main() {
    struct contact contacts[MAX_ENTRIES];
    int count = 0;

    while (1) {
        printf("\nPhone Book\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (count >= MAX_ENTRIES) {
                printf("Phone book is full.\n");
            } else {
                add_contact(contacts, count);
                count++;
            }
            break;

        case 2:
            printf("Enter the contact name to search: ");
            char search_name[50];
            scanf("%s", search_name);

            search_contact(contacts, count, search_name);
            break;

        case 3:
            printf("Enter the contact name to delete: ");
            char delete_name[50];
            scanf("%s", delete_name);

            delete_contact(contacts, count, delete_name);
            break;

        case 4:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}