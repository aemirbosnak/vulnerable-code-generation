//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[50];
    char phone[15];
    char email[50];
} contact;

void add_contact(contact *book, int index, char *name, char *phone, char *email) {
    strcpy(book[index].name, name);
    strcpy(book[index].phone, phone);
    strcpy(book[index].email, email);
}

void search_contact(contact *book, int size, char *name) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(book[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\nEmail: %s\n", book[i].name, book[i].phone, book[i].email);
        }
    }
}

int main() {
    contact book[MAX_ENTRIES];
    int size = 0;

    while (size < MAX_ENTRIES) {
        printf("Enter name (or type 'exit' to quit): ");
        char name[50];
        scanf("%s", name);

        if (strcmp(name, "exit") == 0) {
            break;
        }

        int index = size;
        while (index > 0 && book[index - 1].name[0]!= '\0') {
            index--;
        }

        printf("Enter phone number: ");
        char phone[15];
        scanf("%s", phone);

        printf("Enter email address: ");
        char email[50];
        scanf("%s", email);

        add_contact(book, index, name, phone, email);
        size++;
    }

    printf("Phone book:\n");
    while (size > 0) {
        size--;
        printf("%s\n", book[size].name);
    }

    return 0;
}