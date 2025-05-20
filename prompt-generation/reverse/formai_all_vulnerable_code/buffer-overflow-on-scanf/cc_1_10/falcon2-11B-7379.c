//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent an appointment
typedef struct {
    char description[50];
    int start_time;
    int duration;
    struct appointment* next;
} appointment;

// Structure to represent the linked list
typedef struct {
    appointment* head;
} appointment_list;

// Function to create a new appointment
appointment* create_appointment(char description[50], int start_time, int duration) {
    appointment* new_appointment = malloc(sizeof(appointment));
    if (new_appointment == NULL) {
        printf("Error: Unable to allocate memory\n");
        return NULL;
    }
    strcpy(new_appointment->description, description);
    new_appointment->start_time = start_time;
    new_appointment->duration = duration;
    new_appointment->next = NULL;
    return new_appointment;
}

// Function to add an appointment to the linked list
void add_appointment(appointment_list* list, char description[50], int start_time, int duration) {
    appointment* new_appointment = create_appointment(description, start_time, duration);
    if (new_appointment == NULL) {
        printf("Error: Unable to add appointment\n");
        return;
    }
    if (list->head == NULL) {
        list->head = new_appointment;
        return;
    }
    appointment* current = list->head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = new_appointment;
    return;
}

// Function to delete an appointment from the linked list
void delete_appointment(appointment_list* list, char description[50], int start_time, int duration) {
    appointment* current = list->head;
    while (current!= NULL && strcmp(current->description, description)!= 0) {
        if (current->next == NULL) {
            printf("Error: Appointment not found\n");
            return;
        }
        current = current->next;
    }
    if (current == NULL) {
        printf("Error: Appointment not found\n");
        return;
    }
    if (current->next == NULL) {
        free(current);
        list->head = NULL;
        return;
    }
    appointment* previous = current;
    while (current->next!= NULL) {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    free(current);
    return;
}

// Function to display all appointments in the linked list
void display_appointments(appointment_list* list) {
    appointment* current = list->head;
    while (current!= NULL) {
        printf("Appointment: %s, Start Time: %d, Duration: %d\n", current->description, current->start_time, current->duration);
        current = current->next;
    }
    return;
}

// Function to display the menu options
void display_menu() {
    printf("1. Add Appointment\n");
    printf("2. Delete Appointment\n");
    printf("3. Display Appointments\n");
    printf("4. Exit\n");
}

// Main function
int main() {
    appointment_list appointment_list;
    appointment_list.head = NULL;

    display_menu();
    char option;
    while (option!= '4') {
        scanf("%c", &option);
        if (option == '1') {
            char description[50];
            int start_time, duration;
            printf("Enter description: ");
            scanf("%s", description);
            printf("Enter start time: ");
            scanf("%d", &start_time);
            printf("Enter duration: ");
            scanf("%d", &duration);
            add_appointment(&appointment_list, description, start_time, duration);
        } else if (option == '2') {
            char description[50];
            int start_time, duration;
            printf("Enter description: ");
            scanf("%s", description);
            printf("Enter start time: ");
            scanf("%d", &start_time);
            printf("Enter duration: ");
            scanf("%d", &duration);
            delete_appointment(&appointment_list, description, start_time, duration);
        } else if (option == '3') {
            display_appointments(&appointment_list);
        } else if (option == '4') {
            printf("Exiting...\n");
            break;
        }
    }

    return 0;
}