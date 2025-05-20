//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: shocked
/*
 * appointment_scheduler.c
 *
 * This program is an example of a simple appointment scheduler.
 * It prompts the user to enter a date and time for an appointment,
 * and then schedules the appointment based on the entered values.
 *
 * The program uses a data structure called a "linked list" to store
 * the appointment information.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked list node structure
typedef struct node {
    char date[11];
    char time[9];
    struct node* next;
} node;

// Linked list structure
typedef struct {
    node* head;
    node* tail;
} linked_list;

// Function prototypes
void init_list(linked_list* list);
void add_appointment(linked_list* list, char* date, char* time);
void print_list(linked_list* list);

int main() {
    linked_list list;
    char date[11];
    char time[9];

    // Initialize the linked list
    init_list(&list);

    // Prompt the user for appointment information
    printf("Enter appointment date (DD/MM/YYYY): ");
    scanf("%10s", date);
    printf("Enter appointment time (HH:MM): ");
    scanf("%8s", time);

    // Add the appointment to the linked list
    add_appointment(&list, date, time);

    // Print the linked list
    print_list(&list);

    return 0;
}

// Initialize the linked list
void init_list(linked_list* list) {
    list->head = NULL;
    list->tail = NULL;
}

// Add an appointment to the linked list
void add_appointment(linked_list* list, char* date, char* time) {
    node* new_node = (node*) malloc(sizeof(node));
    strcpy(new_node->date, date);
    strcpy(new_node->time, time);
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

// Print the linked list
void print_list(linked_list* list) {
    node* current = list->head;
    while (current != NULL) {
        printf("Appointment on %s at %s\n", current->date, current->time);
        current = current->next;
    }
}