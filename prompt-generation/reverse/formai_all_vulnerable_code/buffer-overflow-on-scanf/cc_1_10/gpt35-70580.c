//FormAI DATASET v1.0 Category: Phone Book ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[50];
    char phone[20];
};

struct phonebook {
    struct contact contacts[100];
    int count;
};

void displayPhonebook(struct phonebook pb) {
    printf("PHONE BOOK\n");
    printf("----------------------------------------------------\n");
    printf("No.  Name\t\t\tPhone Number\n");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < pb.count; i++) {
        printf("%d.   %-25s%s\n", i+1, pb.contacts[i].name, pb.contacts[i].phone);
    }
    printf("----------------------------------------------------\n");
}

struct phonebook addContact(struct phonebook pb, struct contact c) {
    pb.contacts[pb.count] = c;
    pb.count++;
    return pb;
}

struct phonebook removeContact(struct phonebook pb, int index) {
    if (index >= pb.count) {
        printf("Invalid index.\n");
    } else {
        for (int i = index; i < pb.count-1; i++) {
            pb.contacts[i] = pb.contacts[i+1];
        }
        pb.count--;
        printf("Contact removed.\n");
    }
    return pb;
}

int main() {
    struct phonebook pb;
    pb.count = 0;
    int choice = 0;

    while (choice != 4) {
        printf("\nPHONE BOOK MENU\n");
        printf("1. Display phone book\n");
        printf("2. Add contact\n");
        printf("3. Remove contact\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayPhonebook(pb);
                break;
            case 2:
                printf("Enter name: ");
                scanf("%s", pb.contacts[pb.count].name);
                printf("Enter phone number: ");
                scanf("%s", pb.contacts[pb.count].phone);
                pb = addContact(pb, pb.contacts[pb.count]);
                printf("Contact added.\n");
                break;
            case 3:
                printf("Enter index of contact: ");
                int index;
                scanf("%d", &index);
                pb = removeContact(pb, index-1);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}