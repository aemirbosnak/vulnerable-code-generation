//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 64
#define MAX_EMAIL_LEN 256
#define MAX_SUBJECTS 100
#define MAX_BODY 1000

// Node structure for linked list
typedef struct node {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    int subscribed;
    struct node *next;
} Node;

// Function prototypes
void add_node(Node **head, char *name, char *email);
void print_list(Node *head);
void send_email(Node *head, char *subject, char *body);

int main() {
    Node *head = NULL;

    // Add nodes to the list
    add_node(&head, "John Doe", "john@example.com");
    add_node(&head, "Jane Smith", "jane@example.com");

    // Print the list
    print_list(head);

    // Send an email to all subscribed members
    send_email(head, "Test Email", "Hello World!");

    return 0;
}

void add_node(Node **head, char *name, char *email) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    strcpy(new_node->email, email);
    new_node->subscribed = 1;
    new_node->next = *head;
    *head = new_node;
}

void print_list(Node *head) {
    while (head!= NULL) {
        printf("Name: %s\nEmail: %s\n", head->name, head->email);
        head = head->next;
    }
}

void send_email(Node *head, char *subject, char *body) {
    while (head!= NULL) {
        if (head->subscribed) {
            printf("Sending email to %s...\n", head->email);
        }
        head = head->next;
    }
}