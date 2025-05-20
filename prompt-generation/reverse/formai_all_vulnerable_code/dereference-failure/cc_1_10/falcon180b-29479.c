//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECTS 100
#define MAX_BODIES 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

typedef struct {
    char subject[MAX_SUBJECTS];
    char body[MAX_BODIES];
} email;

typedef struct node {
    contact *data;
    struct node *next;
} node;

typedef struct {
    node *head;
} list;

void add_contact(list *lst, char *name, char *email) {
    contact *new_contact = (contact*)malloc(sizeof(contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->email, email);
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = new_contact;
    new_node->next = NULL;
    if (lst->head == NULL) {
        lst->head = new_node;
    } else {
        node *temp = lst->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void send_email(list *lst, char *subject, char *body) {
    node *temp = lst->head;
    while (temp!= NULL) {
        contact *contact = temp->data;
        printf("Sending email to %s (%s)\n", contact->name, contact->email);
        temp = temp->next;
    }
}

int main() {
    list contacts;
    contacts.head = NULL;

    add_contact(&contacts, "John Doe", "john@example.com");
    add_contact(&contacts, "Jane Smith", "jane@example.com");

    send_email(&contacts, "Hello World!", "This is a test email.");

    return 0;
}