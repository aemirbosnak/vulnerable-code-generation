//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 100
#define MAX_NAME_SIZE 50
#define MAX_EMAIL_SIZE 100

typedef struct {
    char name[MAX_NAME_SIZE];
    char email[MAX_EMAIL_SIZE];
} Contact;

void addContact(Contact* list, int size, char* name, char* email) {
    if (size >= MAX_LIST_SIZE) {
        printf("Error: List is full.\n");
        return;
    }

    strcpy(list[size].name, name);
    strcpy(list[size].email, email);

    size++;
}

void removeContact(Contact* list, int size, char* email) {
    int i;

    for (i = 0; i < size; i++) {
        if (strcmp(list[i].email, email) == 0) {
            memmove(&list[i], &list[i+1], sizeof(Contact) * (size - i - 1));
            size--;
            break;
        }
    }
}

void printList(Contact* list, int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%s - %s\n", list[i].name, list[i].email);
    }
}

int main() {
    Contact list[MAX_LIST_SIZE];
    int size = 0;

    char choice;
    do {
        printf("\nMailing List Manager\n");
        printf("---------------------\n");
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. Print list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter name: ");
                scanf("%s", list[size].name);
                printf("Enter email: ");
                scanf("%s", list[size].email);
                size++;
                break;

            case '2':
                printf("Enter email to remove: ");
                scanf("%s", list[0].email);
                removeContact(list, size, list[0].email);
                break;

            case '3':
                printList(list, size);
                break;

            case '4':
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '4');

    return 0;
}