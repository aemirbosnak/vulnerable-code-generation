//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a mailing list
struct MailingList {
    char name[100];
    char email[100];
    struct MailingList *next;
};

// Function to create a new mailing list
struct MailingList* createMailingList(char* name, char* email) {
    struct MailingList* newList = (struct MailingList*)malloc(sizeof(struct MailingList));
    strcpy(newList->name, name);
    strcpy(newList->email, email);
    newList->next = NULL;
    return newList;
}

// Function to add a new mailing list to the end of the list
void addMailingList(struct MailingList** list, char* name, char* email) {
    struct MailingList* newList = createMailingList(name, email);
    if (*list == NULL) {
        *list = newList;
    } else {
        struct MailingList* current = *list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newList;
    }
}

// Function to print all mailing lists in the list
void printMailingLists(struct MailingList* list) {
    struct MailingList* current = list;
    while (current != NULL) {
        printf("%s <-> %s\n", current->name, current->email);
        current = current->next;
    }
}

// Function to delete a mailing list from the list
void deleteMailingList(struct MailingList** list, char* name) {
    struct MailingList* current = *list;
    struct MailingList* previous = NULL;
    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }
    if (current != NULL) {
        if (previous == NULL) {
            *list = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
    }
}

int main() {
    struct MailingList* list = NULL;

    // Add some mailing lists to the list
    addMailingList(&list, "John Doe", "johndoe@example.com");
    addMailingList(&list, "Jane Doe", "janedoe@example.com");
    addMailingList(&list, "Bob Smith", "bobsmith@example.com");
    addMailingList(&list, "Alice Johnson", "alicejohnson@example.com");

    // Print all mailing lists in the list
    printf("Mailing lists:\n");
    printMailingLists(list);

    // Delete a mailing list from the list
    deleteMailingList(&list, "Bob Smith");

    // Print all mailing lists in the list again
    printf("\nMailing lists after deletion:\n");
    printMailingLists(list);

    return 0;
}