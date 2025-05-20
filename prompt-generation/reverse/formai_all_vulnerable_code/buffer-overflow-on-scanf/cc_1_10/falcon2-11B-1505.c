//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct phonebook {
    char name[100];
    char number[20];
    struct phonebook* next;
};

struct phonebook* head = NULL;

void insert(char name[], char number[]) {
    struct phonebook* new_entry = (struct phonebook*)malloc(sizeof(struct phonebook));
    strcpy(new_entry->name, name);
    strcpy(new_entry->number, number);
    new_entry->next = NULL;

    if (head == NULL) {
        head = new_entry;
    } else {
        struct phonebook* current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_entry;
    }
}

void display() {
    struct phonebook* current = head;
    if (head == NULL) {
        printf("Phone Book is empty\n");
        return;
    }
    printf("Phone Book:\n");
    while (current!= NULL) {
        printf("%s -> %s\n", current->name, current->number);
        current = current->next;
    }
}

int main() {
    char name[100], number[20];

    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter number: ");
    scanf("%s", number);

    insert(name, number);

    display();

    return 0;
}