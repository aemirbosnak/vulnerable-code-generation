//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct person {
    char name[MAX];
    int phone;
};

void add_person(struct person* book, int size, char* name, int phone) {
    if (size >= MAX) {
        printf("Phone book is full.\n");
        return;
    }
    strcpy(book[size].name, name);
    book[size].phone = phone;
    size++;
}

void delete_person(struct person* book, int size, char* name) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(book[i].name, name) == 0) {
            memmove(&book[i], &book[i+1], (size - i - 1) * sizeof(struct person));
            size--;
            break;
        }
    }
}

void search_person(struct person* book, int size, char* name) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(book[i].name, name) == 0) {
            printf("Phone number for %s is %d.\n", book[i].name, book[i].phone);
            return;
        }
    }
    printf("Person not found.\n");
}

int main() {
    struct person book[MAX];
    int size = 0;
    char choice;
    do {
        printf("1. Add person\n2. Delete person\n3. Search person\n4. Exit\n");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                printf("Enter name: ");
                scanf("%s", book[size].name);
                printf("Enter phone number: ");
                scanf("%d", &book[size].phone);
                size++;
                break;
            case '2':
                printf("Enter name to delete: ");
                scanf("%s", book[size-1].name);
                delete_person(book, size, book[size-1].name);
                size--;
                break;
            case '3':
                printf("Enter name to search: ");
                scanf("%s", book[size-1].name);
                search_person(book, size, book[size-1].name);
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);
    return 0;
}