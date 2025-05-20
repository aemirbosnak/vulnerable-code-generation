//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_NUM_LEN 15
#define MAX_CONTACTS 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
} Contact;

Contact contacts[MAX_CONTACTS];
int num_contacts = 0;

void add_contact() {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Sorry, phone book is full.\n");
        return;
    }

    printf("Enter name (max %d characters): ", MAX_NAME_LEN - 1);
    scanf("%s", contacts[num_contacts].name);

    printf("Enter number (max %d characters): ", MAX_NUM_LEN - 1);
    scanf("%s", contacts[num_contacts].number);

    num_contacts++;
}

void delete_contact() {
    int index;

    printf("Enter contact number to delete (1-%d): ", num_contacts);
    scanf("%d", &index);

    if (index < 1 || index > num_contacts) {
        printf("Invalid contact number.\n");
        return;
    }

    for (int i = index - 1; i < num_contacts - 1; i++) {
        strcpy(contacts[i].name, contacts[i + 1].name);
        strcpy(contacts[i].number, contacts[i + 1].number);
    }

    num_contacts--;
}

void search_contact() {
    char name[MAX_NAME_LEN];

    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", contacts[i].name, contacts[i].number);
            return;
        }
    }

    printf("Contact not found.\n");
}

int main() {
    int choice;

    do {
        printf("\nPhone Book\n");
        printf("1. Add contact\n");
        printf("2. Delete contact\n");
        printf("3. Search contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_contact();
            break;
        case 2:
            delete_contact();
            break;
        case 3:
            search_contact();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}