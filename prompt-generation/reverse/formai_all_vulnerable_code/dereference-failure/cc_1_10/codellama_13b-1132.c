//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 100
#define MAX_EMAIL_SIZE 100

struct mailing_list {
    char email[MAX_EMAIL_SIZE];
    struct mailing_list *next;
};

struct mailing_list *head;

void add_email(char *email) {
    struct mailing_list *new_node = (struct mailing_list *)malloc(sizeof(struct mailing_list));
    strcpy(new_node->email, email);
    new_node->next = head;
    head = new_node;
}

void remove_email(char *email) {
    struct mailing_list *current = head;
    struct mailing_list *prev = NULL;

    while (current != NULL && strcmp(current->email, email) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Email not found in list\n");
        return;
    }

    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

void print_list() {
    struct mailing_list *current = head;

    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

int main() {
    head = NULL;

    add_email("john.doe@example.com");
    add_email("jane.doe@example.com");
    add_email("john.smith@example.com");

    print_list();

    remove_email("john.doe@example.com");

    print_list();

    return 0;
}