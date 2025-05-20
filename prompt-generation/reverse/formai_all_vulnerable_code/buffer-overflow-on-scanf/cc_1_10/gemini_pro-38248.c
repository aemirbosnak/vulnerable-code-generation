//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: Ken Thompson
// A simple appointment scheduler based on a doubly linked list.
// Each node contains the appointment time and description.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AppointmentNode {
    int time;
    char description[100];
    struct AppointmentNode *prev;
    struct AppointmentNode *next;
} AppointmentNode;

// Create a new appointment node.
AppointmentNode *newAppointmentNode(int time, char *description) {
    AppointmentNode *node = malloc(sizeof(AppointmentNode));
    node->time = time;
    strcpy(node->description, description);
    node->prev = NULL;
    node->next = NULL;
    return node;
}

// Insert a new appointment node into the list.
void insertAppointmentNode(AppointmentNode **head, AppointmentNode *node) {
    if (*head == NULL) {
        *head = node;
        return;
    }

    AppointmentNode *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = node;
    node->prev = current;
}

// Delete an appointment node from the list.
void deleteAppointmentNode(AppointmentNode **head, AppointmentNode *node) {
    if (*head == node) {
        *head = node->next;
    } else {
        node->prev->next = node->next;
    }

    if (node->next != NULL) {
        node->next->prev = node->prev;
    }

    free(node);
}

// Print the list of appointments.
void printAppointments(AppointmentNode *head) {
    AppointmentNode *current = head;
    while (current != NULL) {
        printf("%d: %s\n", current->time, current->description);
        current = current->next;
    }
}

// Get the user's input.
void getInput(int *time, char *description) {
    printf("Enter the appointment time (hhmm): ");
    scanf("%d", time);

    printf("Enter the appointment description: ");
    scanf(" %s", description);
}

// Main function.
int main() {
    // Create a new appointment list.
    AppointmentNode *head = NULL;

    // Get the user's input.
    int time;
    char description[100];
    getInput(&time, description);

    // Create a new appointment node.
    AppointmentNode *node = newAppointmentNode(time, description);

    // Insert the new appointment node into the list.
    insertAppointmentNode(&head, node);

    // Print the list of appointments.
    printAppointments(head);

    // Delete the new appointment node from the list.
    deleteAppointmentNode(&head, node);

    // Print the list of appointments.
    printAppointments(head);

    return 0;
}