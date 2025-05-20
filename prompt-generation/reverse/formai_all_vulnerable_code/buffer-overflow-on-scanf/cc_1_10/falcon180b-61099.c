//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 1000
#define MAX_NAME_SIZE 50
#define MAX_EMAIL_SIZE 100

typedef struct {
    char name[MAX_NAME_SIZE];
    char email[MAX_EMAIL_SIZE];
} Contact;

void add_contact(Contact* list, int size, char* name, char* email) {
    if (size >= MAX_LIST_SIZE) {
        printf("Error: List is full.\n");
        return;
    }

    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(list[i].name, name) == 0) {
            printf("Error: Contact already exists.\n");
            return;
        }
    }

    strcpy(list[size].name, name);
    strcpy(list[size].email, email);
    size++;
}

void remove_contact(Contact* list, int size, char* name) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(list[i].name, name) == 0) {
            memmove(list + i, list + i + 1, (size - i - 1) * sizeof(Contact));
            size--;
            break;
        }
    }
}

void print_contacts(Contact* list, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%s - %s\n", list[i].name, list[i].email);
    }
}

int main() {
    Contact list[MAX_LIST_SIZE];
    int size = 0;

    while (1) {
        printf("1. Add contact\n2. Remove contact\n3. Print contacts\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            char name[MAX_NAME_SIZE];
            char email[MAX_EMAIL_SIZE];
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter email: ");
            scanf("%s", email);
            add_contact(list, size, name, email);
            break;
        }
        case 2: {
            char name[MAX_NAME_SIZE];
            printf("Enter name: ");
            scanf("%s", name);
            remove_contact(list, size, name);
            break;
        }
        case 3: {
            print_contacts(list, size);
            break;
        }
        case 4: {
            exit(0);
        }
        default: {
            printf("Error: Invalid choice.\n");
        }
        }
    }

    return 0;
}