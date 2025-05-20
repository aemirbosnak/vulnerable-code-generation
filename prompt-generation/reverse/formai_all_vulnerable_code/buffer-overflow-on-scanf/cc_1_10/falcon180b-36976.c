//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAILS 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
} contact;

void add_contact(contact* list, int size, char* name, char* email) {
    if (size >= MAX_EMAILS) {
        printf("Error: Mailing list is full.\n");
        return;
    }
    strcpy(list[size].name, name);
    strcpy(list[size].email, email);
    size++;
}

void remove_contact(contact* list, int size, char* email) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(list[i].email, email) == 0) {
            memmove(&list[i], &list[i+1], (size - i - 1) * sizeof(contact));
            size--;
            break;
        }
    }
}

void print_contacts(contact* list, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%s (%s)\n", list[i].name, list[i].email);
    }
}

int main() {
    contact list[MAX_EMAILS];
    int size = 0;
    char input[100];
    while (1) {
        printf("1. Add contact\n2. Remove contact\n3. Print contacts\n4. Exit\n");
        scanf("%d", &input[0]);
        switch (input[0]) {
            case 1:
                printf("Enter name: ");
                scanf("%s", &input[1]);
                printf("Enter email: ");
                scanf("%s", &input[2]);
                add_contact(list, size, input[1], input[2]);
                break;
            case 2:
                printf("Enter email to remove: ");
                scanf("%s", &input[1]);
                remove_contact(list, size, input[1]);
                break;
            case 3:
                print_contacts(list, size);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }
    return 0;
}