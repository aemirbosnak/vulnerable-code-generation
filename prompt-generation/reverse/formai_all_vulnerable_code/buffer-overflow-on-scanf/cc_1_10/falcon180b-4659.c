//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTACTS 500
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 15

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} Contact;

int num_contacts = 0;
Contact contacts[MAX_CONTACTS];

void add_contact() {
    printf("Enter name (max %d characters): ", MAX_NAME_LEN - 1);
    scanf("%s", contacts[num_contacts].name);
    printf("Enter phone number (max %d characters): ", MAX_NUMBER_LEN - 1);
    scanf("%s", contacts[num_contacts].number);
    num_contacts++;
}

void search_contact() {
    char search_name[MAX_NAME_LEN];
    printf("Enter name to search: ");
    scanf("%s", search_name);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(search_name, contacts[i].name) == 0) {
            printf("Name: %s\nNumber: %s\n", contacts[i].name, contacts[i].number);
        }
    }
}

void delete_contact() {
    printf("Enter name of contact to delete: ");
    char name_to_delete[MAX_NAME_LEN];
    scanf("%s", name_to_delete);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(name_to_delete, contacts[i].name) == 0) {
            for (int j = i; j < num_contacts - 1; j++) {
                strcpy(contacts[j].name, contacts[j+1].name);
                strcpy(contacts[j].number, contacts[j+1].number);
            }
            num_contacts--;
            break;
        }
    }
}

int main() {
    int choice;
    do {
        printf("\nPhone Book\n");
        printf("1. Add contact\n2. Search contact\n3. Delete contact\n4. Exit\n");
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
                delete_contact();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);
    return 0;
}