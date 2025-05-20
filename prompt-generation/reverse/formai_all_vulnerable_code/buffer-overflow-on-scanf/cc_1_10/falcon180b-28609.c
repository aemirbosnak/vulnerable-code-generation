//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

struct contact {
    char name[MAX];
    char phone[MAX];
};

void add_contact(struct contact *book, int size, char *name, char *phone) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(book[i].name, name) == 0) {
            printf("Contact already exists!\n");
            return;
        }
    }
    strcpy(book[size].name, name);
    strcpy(book[size].phone, phone);
    printf("Contact added successfully!\n");
}

void search_contact(struct contact *book, int size, char *name) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(book[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", book[i].name, book[i].phone);
            return;
        }
    }
    printf("Contact not found!\n");
}

void delete_contact(struct contact *book, int *size, char *name) {
    int i;
    for (i = 0; i < *size; i++) {
        if (strcmp(book[i].name, name) == 0) {
            memmove(&book[i], &book[i+1], sizeof(struct contact) * (*size - i - 1));
            (*size)--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

int main() {
    struct contact book[MAX];
    int size = 0;

    while (1) {
        printf("1. Add contact\n2. Search contact\n3. Delete contact\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[MAX], phone[MAX];
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone: ");
                scanf("%s", phone);
                add_contact(book, size, name, phone);
                break;
            }
            case 2: {
                char name[MAX];
                printf("Enter name: ");
                scanf("%s", name);
                search_contact(book, size, name);
                break;
            }
            case 3: {
                char name[MAX];
                printf("Enter name: ");
                scanf("%s", name);
                delete_contact(book, &size, name);
                break;
            }
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}