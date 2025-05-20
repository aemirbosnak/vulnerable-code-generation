//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: shocked
// Mailing list manager example program in a shocked style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct MailingList {
    char* name;
    char* email;
    struct MailingList* next;
};

struct MailingList* create_mailing_list() {
    struct MailingList* list = malloc(sizeof(struct MailingList));
    list->name = NULL;
    list->email = NULL;
    list->next = NULL;
    return list;
}

void add_to_mailing_list(struct MailingList* list, char* name, char* email) {
    struct MailingList* new_node = malloc(sizeof(struct MailingList));
    new_node->name = name;
    new_node->email = email;
    new_node->next = NULL;

    if (list == NULL) {
        list = new_node;
        return;
    }

    struct MailingList* current = list;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void print_mailing_list(struct MailingList* list) {
    struct MailingList* current = list;
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Email: %s\n", current->email);
        current = current->next;
    }
}

int main() {
    struct MailingList* list = create_mailing_list();
    add_to_mailing_list(list, "John Doe", "johndoe@example.com");
    add_to_mailing_list(list, "Jane Doe", "janedoe@example.com");
    add_to_mailing_list(list, "Jim Smith", "jimsmith@example.com");

    print_mailing_list(list);

    return 0;
}