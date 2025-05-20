//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to hold appointment details
typedef struct Appointment {
    int id;
    char description[100];
    char date[11]; // Format: YYYY-MM-DD
    struct Appointment* next;
} Appointment;

// Function declarations
Appointment* createAppointment(int id, const char* description, const char* date);
void addAppointment(Appointment** head, Appointment* newAppointment);
void viewAppointments(Appointment* head);
void deleteAppointment(Appointment** head, int id);
void freeAppointments(Appointment* head);

int main() {
    Appointment* appointmentList = NULL;
    int choice, id;
    char description[100], date[11];

    while (1) {
        printf("\nAppointment Scheduler:\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume newline character

        switch (choice) {
            case 1:
                printf("Enter Appointment ID: ");
                scanf("%d", &id);
                getchar(); // to consume newline
                printf("Enter Appointment Description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = 0; // Remove newline
                
                printf("Enter Appointment Date (YYYY-MM-DD): ");
                fgets(date, sizeof(date), stdin);
                date[strcspn(date, "\n")] = 0; // Remove newline

                addAppointment(&appointmentList, createAppointment(id, description, date));
                printf("Appointment added.\n");
                break;

            case 2:
                viewAppointments(appointmentList);
                break;

            case 3:
                printf("Enter Appointment ID to delete: ");
                scanf("%d", &id);
                deleteAppointment(&appointmentList, id);
                break;

            case 4:
                freeAppointments(appointmentList);
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }

    return 0;
}

// Function to create a new appointment
Appointment* createAppointment(int id, const char* description, const char* date) {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    newAppointment->id = id;
    strncpy(newAppointment->description, description, sizeof(newAppointment->description) - 1);
    strncpy(newAppointment->date, date, sizeof(newAppointment->date) - 1);
    newAppointment->next = NULL;
    return newAppointment;
}

// Function to add an appointment to the linked list
void addAppointment(Appointment** head, Appointment* newAppointment) {
    newAppointment->next = *head;
    *head = newAppointment;
}

// Function to view all appointments
void viewAppointments(Appointment* head) {
    if (head == NULL) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\nScheduled Appointments:\n");
    Appointment* current = head;
    while (current != NULL) {
        printf("ID: %d | Description: %s | Date: %s\n", current->id, current->description, current->date);
        current = current->next;
    }
}

// Function to delete an appointment by ID
void deleteAppointment(Appointment** head, int id) {
    Appointment* current = *head;
    Appointment* previous = NULL;

    while (current != NULL && current->id != id) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Appointment with ID %d not found.\n", id);
        return;
    }

    if (previous == NULL) {
        *head = current->next; // The appointment to delete is the first element
    } else {
        previous->next = current->next; // Bypass the appointment to delete
    }

    free(current);
    printf("Appointment with ID %d deleted.\n", id);
}

// Function to free all appointments in the list
void freeAppointments(Appointment* head) {
    Appointment* current = head;
    while (current != NULL) {
        Appointment* next = current->next;
        free(current);
        current = next;
    }
}