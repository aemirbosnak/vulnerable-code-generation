//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

void add_contact(contact *list, int *size, char *name, char *email) {
    strcpy(list[*size].name, name);
    strcpy(list[*size].email, email);
    (*size)++;
}

void remove_contact(contact *list, int *size, char *email) {
    int i;
    for (i = 0; i < *size; i++) {
        if (strcmp(list[i].email, email) == 0) {
            memmove(&list[i], &list[i + 1], (*size - i - 1) * sizeof(contact));
            (*size)--;
            break;
        }
    }
}

void print_contacts(contact *list, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%s <%s>\n", list[i].name, list[i].email);
    }
}

int main() {
    contact list[100];
    int size = 0;
    char choice;

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. Print contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter name: ");
                scanf("%s", list[size].name);
                printf("Enter email: ");
                scanf("%s", list[size].email);
                add_contact(list, &size, list[size].name, list[size].email);
                break;
            case '2':
                printf("Enter email to remove: ");
                scanf("%s", list[size].email);
                remove_contact(list, &size, list[size].email);
                break;
            case '3':
                print_contacts(list, size);
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (1);

    return 0;
}