//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: inquisitive
// mailing_list.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mailing_list {
    char name[50];
    char email[50];
    struct mailing_list *next;
};

struct mailing_list *head = NULL;

void add_to_list(char *name, char *email) {
    struct mailing_list *new_node = (struct mailing_list *)malloc(sizeof(struct mailing_list));
    strcpy(new_node->name, name);
    strcpy(new_node->email, email);
    new_node->next = head;
    head = new_node;
}

void remove_from_list(char *name) {
    struct mailing_list *temp = head;
    struct mailing_list *prev = NULL;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void print_list() {
    struct mailing_list *temp = head;
    while (temp != NULL) {
        printf("%s: %s\n", temp->name, temp->email);
        temp = temp->next;
    }
}

int main() {
    add_to_list("John", "john@example.com");
    add_to_list("Jane", "jane@example.com");
    add_to_list("Bob", "bob@example.com");

    print_list();

    remove_from_list("Bob");

    print_list();

    return 0;
}