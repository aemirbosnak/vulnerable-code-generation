//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *address;
    char *phone;
    char *email;
} Contact;

typedef struct Node {
    Contact data;
    struct Node *next;
} Node;

Node *head = NULL;

void add_contact(char *name, char *address, char *phone, char *email) {
    Contact *new_contact = (Contact *) malloc(sizeof(Contact));
    new_contact->name = strdup(name);
    new_contact->address = strdup(address);
    new_contact->phone = strdup(phone);
    new_contact->email = strdup(email);

    if (head == NULL) {
        head = (Node *) malloc(sizeof(Node));
        head->data = *new_contact;
        head->next = NULL;
    } else {
        Node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = (Node *) malloc(sizeof(Node));
        temp->next->data = *new_contact;
        temp->next->next = NULL;
    }
}

void print_contacts() {
    Node *temp = head;
    while (temp!= NULL) {
        printf("Name: %s\n", temp->data.name);
        printf("Address: %s\n", temp->data.address);
        printf("Phone: %s\n", temp->data.phone);
        printf("Email: %s\n\n", temp->data.email);
        temp = temp->next;
    }
}

int main() {
    add_contact("John Doe", "123 Main St.", "555-1234", "johndoe@example.com");
    add_contact("Jane Smith", "456 Oak Ave.", "555-5678", "janesmith@example.com");

    print_contacts();

    return 0;
}