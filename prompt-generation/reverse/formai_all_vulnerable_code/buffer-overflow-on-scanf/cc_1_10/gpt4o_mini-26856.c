//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESC_LENGTH 100
#define MAX_APPOINTMENTS 100

typedef struct Appointment {
    int id;
    char description[MAX_DESC_LENGTH];
    char date[11]; // Format: YYYY-MM-DD
    char time[6];  // Format: HH:MM
    struct Appointment *next;
} Appointment;

Appointment *head = NULL;
int appointment_count = 0;

void addAppointment();
void viewAppointments();
void deleteAppointment();
void freeAppointments();
void displayMenu();

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                deleteAppointment();
                break;
            case 4:
                printf("Exiting... \n");
                freeAppointments();
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n=== Appointment Scheduler ===\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
}

void addAppointment() {
    Appointment *new_appointment = (Appointment *)malloc(sizeof(Appointment));
    if (new_appointment == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    new_appointment->id = ++appointment_count;
    printf("Enter appointment description: ");
    getchar(); // Consume the newline
    fgets(new_appointment->description, MAX_DESC_LENGTH, stdin);
    strtok(new_appointment->description, "\n"); // Remove trailing newline

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", new_appointment->date);
    printf("Enter time (HH:MM): ");
    scanf("%s", new_appointment->time);

    new_appointment->next = head;
    head = new_appointment;

    printf("Appointment added with ID %d!\n", new_appointment->id);
}

void viewAppointments() {
    if (head == NULL) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\n=== Appointments ===\n");
    Appointment *current = head;
    while (current != NULL) {
        printf("ID: %d\n", current->id);
        printf("Description: %s\n", current->description);
        printf("Date: %s\n", current->date);
        printf("Time: %s\n", current->time);
        printf("---------------------\n");
        current = current->next;
    }
}

void deleteAppointment() {
    if (head == NULL) {
        printf("No appointments to delete.\n");
        return;
    }
    
    int id;
    printf("Enter appointment ID to delete: ");
    scanf("%d", &id);

    Appointment *current = head;
    Appointment *prev = NULL;
    
    while (current != NULL && current->id != id) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Appointment with ID %d not found.\n", id);
        return;
    }

    if (prev == NULL) { // Deleting the head
        head = current->next;
    } else {
        prev->next = current->next;
    }
    
    free(current);
    printf("Appointment with ID %d deleted successfully.\n", id);
}

void freeAppointments() {
    Appointment *current = head;
    Appointment *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}