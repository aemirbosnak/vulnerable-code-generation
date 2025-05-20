//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100
#define MAX_MESSAGE_LEN 1000

// Node structure for linked list
typedef struct node {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    struct node* next;
} Node;

// Function prototypes
void add_node(Node** head, char* name, char* email);
void print_list(Node* head);
void send_message(Node* head, char* message);

int main() {
    Node* head = NULL;

    // Add nodes to the list
    add_node(&head, "John Doe", "john.doe@example.com");
    add_node(&head, "Jane Doe", "jane.doe@example.com");
    add_node(&head, "Bob Smith", "bob.smith@example.com");

    // Print the list
    printf("Mailing list:\n");
    print_list(head);

    // Send a message to the list
    char message[MAX_MESSAGE_LEN] = "Hello everyone,\n\nThis is a test message.\n\nBest regards,\nThe Management";
    send_message(head, message);

    return 0;
}

// Function to add a node to the list
void add_node(Node** head, char* name, char* email) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    strcpy(new_node->email, email);
    new_node->next = *head;
    *head = new_node;
}

// Function to print the list
void print_list(Node* head) {
    while (head!= NULL) {
        printf("%s (%s)\n", head->name, head->email);
        head = head->next;
    }
}

// Function to send a message to the list
void send_message(Node* head, char* message) {
    while (head!= NULL) {
        FILE* fp = fopen(head->email, "w");
        if (fp!= NULL) {
            fprintf(fp, "From: Mailing List Manager <manager@example.com>\n");
            fprintf(fp, "To: %s\n", head->name);
            fprintf(fp, "Subject: Test Message\n");
            fprintf(fp, "Content-Type: text/plain; charset=utf-8\n\n");
            fprintf(fp, "%s", message);
            fclose(fp);
        }
        head = head->next;
    }
}