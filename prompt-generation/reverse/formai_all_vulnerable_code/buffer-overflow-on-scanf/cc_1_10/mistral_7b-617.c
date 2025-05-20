//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[50];
    char phone[20];
} Contact;

Contact contacts[MAX_ENTRIES];
int num_contacts = 0;

void add_contact(char *name, char *phone) {
    if (num_contacts >= MAX_ENTRIES) {
        printf("Phone book is full!\n");
        return;
    }
    strcpy(contacts[num_contacts].name, name);
    strcpy(contacts[num_contacts].phone, phone);
    num_contacts++;
}

void search_contact(char *name) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcasecmp(contacts[i].name, name) == 0) {
            printf("Found contact: %s - %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }
    printf("Contact not found!\n");
}

int main() {
    char command[20];
    char name[50], phone[20];

    while (1) {
        printf("\nPhone Book>\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Exit\n");
        printf("> ");
        scanf("%s", command);

        switch (command[0]) {
            case '1':
                printf("Name: ");
                scanf("%s", name);
                printf("Phone: ");
                scanf("%s", phone);
                add_contact(name, phone);
                break;
            case '2':
                printf("Name: ");
                scanf("%s", name);
                search_contact(name);
                break;
            case '3':
                return 0;
            default:
                printf("Invalid command!\n");
        }
    }

    return 0;
}