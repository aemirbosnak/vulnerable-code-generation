//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: standalone
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 100
#define MAX_LEN 100

typedef struct {
    char email[MAX_LEN];
    char name[MAX_LEN];
} contact;

contact list[MAX_EMAILS];
int num_contacts = 0;

void add_contact() {
    if (num_contacts == MAX_EMAILS) {
        printf("Mailing list is full!\n");
        return;
    }

    printf("Enter email address: ");
    scanf("%s", list[num_contacts].email);

    printf("Enter name: ");
    scanf("%s", list[num_contacts].name);

    num_contacts++;
}

void delete_contact() {
    printf("Enter email address to delete: ");
    char email[MAX_LEN];
    scanf("%s", email);

    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(list[i].email, email) == 0) {
            break;
        }
    }

    if (i == num_contacts) {
        printf("Email address not found!\n");
        return;
    }

    for (int j = i; j < num_contacts - 1; j++) {
        list[j] = list[j + 1];
    }

    num_contacts--;
}

void print_list() {
    printf("Mailing List:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%2d. %-20s (%s)\n", i + 1, list[i].name, list[i].email);
    }
}

int main() {
    int choice;
    do {
        printf("\nMailing List Manager\n");
        printf("1. Add contact\n");
        printf("2. Delete contact\n");
        printf("3. Print list\n");
        printf("4. Quit\n");
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
                print_list();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}