//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PhoneBook {
    char name[100];
    char number[20];
    struct PhoneBook *next;
};

struct PhoneBook *head = NULL;

void addPhoneBookEntry(char *name, char *number) {
    struct PhoneBook *newEntry = (struct PhoneBook *) malloc(sizeof(struct PhoneBook));
    if (newEntry == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    strcpy(newEntry->name, name);
    strcpy(newEntry->number, number);
    newEntry->next = NULL;
    if (head == NULL) {
        head = newEntry;
    } else {
        struct PhoneBook *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newEntry;
    }
}

void displayPhoneBook() {
    struct PhoneBook *temp = head;
    while (temp!= NULL) {
        printf("%s: %s\n", temp->name, temp->number);
        temp = temp->next;
    }
}

int main() {
    char name[100];
    char number[20];
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter number: ");
    scanf("%s", number);
    addPhoneBookEntry(name, number);
    displayPhoneBook();
    return 0;
}