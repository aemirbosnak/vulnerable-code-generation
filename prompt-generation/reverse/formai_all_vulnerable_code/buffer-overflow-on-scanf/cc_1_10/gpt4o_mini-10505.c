//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for an appointment
typedef struct Appointment {
    char title[100];
    char date[11]; // Format: YYYY-MM-DD
    char time[6];  // Format: HH:MM
    struct Appointment* next;
} Appointment;

// Function prototypes
Appointment* createAppointment(char* title, char* date, char* time);
void addAppointment(Appointment** head, char* title, char* date, char* time);
void viewAppointments(Appointment* head);
void deleteAppointment(Appointment** head, char* title);
void freeAppointments(Appointment* head);

// Main function
int main() {
    Appointment* appointments = NULL;
    int choice;
    char title[100], date[11], time[6];

    do {
        printf("\n----- Appointment Scheduler -----\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                printf("Enter appointment title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove newline

                printf("Enter appointment date (YYYY-MM-DD): ");
                fgets(date, sizeof(date), stdin);
                date[strcspn(date, "\n")] = '\0'; // Remove newline

                printf("Enter appointment time (HH:MM): ");
                fgets(time, sizeof(time), stdin);
                time[strcspn(time, "\n")] = '\0'; // Remove newline
                
                addAppointment(&appointments, title, date, time);
                printf("Appointment added successfully!\n");
                break;

            case 2:
                printf("\n--- Your Appointments ---\n");
                viewAppointments(appointments);
                break;

            case 3:
                printf("Enter the title of the appointment to delete: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove newline

                deleteAppointment(&appointments, title);
                break;

            case 4:
                printf("Exiting the scheduler. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    freeAppointments(appointments);
    return 0;
}

// Create a new appointment
Appointment* createAppointment(char* title, char* date, char* time) {
    Appointment* newAppointment = (Appointment*) malloc(sizeof(Appointment));
    if (newAppointment) {
        strcpy(newAppointment->title, title);
        strcpy(newAppointment->date, date);
        strcpy(newAppointment->time, time);
        newAppointment->next = NULL;
    }
    return newAppointment;
}

// Add an appointment to the list
void addAppointment(Appointment** head, char* title, char* date, char* time) {
    Appointment* newAppointment = createAppointment(title, date, time);
    if (!newAppointment) {
        printf("Memory allocation failed!\n");
        return;
    }
    newAppointment->next = *head;
    *head = newAppointment;
}

// View all appointments
void viewAppointments(Appointment* head) {
    if (!head) {
        printf("No appointments found!\n");
        return;
    }
    Appointment* current = head;
    while (current) {
        printf("Title: %s, Date: %s, Time: %s\n", current->title, current->date, current->time);
        current = current->next;
    }
}

// Delete an appointment by title
void deleteAppointment(Appointment** head, char* title) {
    Appointment* current = *head;
    Appointment* previous = NULL;

    while (current != NULL && strcmp(current->title, title) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Appointment not found!\n");
        return;
    }

    if (previous == NULL) {
        *head = current->next; // the appointment to delete is the first one
    } else {
        previous->next = current->next; // Bypass the appointment to delete
    }

    free(current);
    printf("Appointment deleted successfully!\n");
}

// Free all appointments
void freeAppointments(Appointment* head) {
    while (head) {
        Appointment* temp = head;
        head = head->next;
        free(temp);
    }
}