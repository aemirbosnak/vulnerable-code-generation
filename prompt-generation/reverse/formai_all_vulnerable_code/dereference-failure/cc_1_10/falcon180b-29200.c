//Falcon-180B DATASET v1.0 Category: System event logger ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENT_SIZE 1024

// Event structure
typedef struct {
    char message[MAX_EVENT_SIZE];
    time_t timestamp;
} Event;

// Linked list node structure
typedef struct node {
    Event *event;
    struct node *next;
} Node;

// Linked list structure
Node *head = NULL;

// Function to add an event to the linked list
void add_event(Event *event) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->event = event;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to print the linked list
void print_list() {
    Node *temp = head;
    printf("Event Log:\n");
    while (temp!= NULL) {
        printf("%s - %s\n", temp->event->message, ctime(&temp->event->timestamp));
        temp = temp->next;
    }
}

// Function to log an event
void log_event(char *message) {
    Event *event = (Event *)malloc(sizeof(Event));
    strncpy(event->message, message, MAX_EVENT_SIZE);
    event->timestamp = time(NULL);
    add_event(event);
}

int main() {
    log_event("Program started");

    // Example events
    log_event("User logged in");
    log_event("File uploaded");
    log_event("Database query executed");

    print_list();

    return 0;
}