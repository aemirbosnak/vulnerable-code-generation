//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Appointment {
    char name[50];
    char date[11]; // Format: YYYY-MM-DD
    char time[6];  // Format: HH:MM
    struct Appointment* next;
} Appointment;

Appointment* head = NULL;

void addAppointment();
void viewAppointments();
void deleteAppointment();
void freeMemory();

int main() {
    int choice;
    
    while (1) {
        printf("\n--- Appointment Scheduler ---\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        
        scanf("%d", &choice);
        getchar(); // To consume the newline character after number input
        
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
                freeMemory();
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}

void addAppointment() {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    if (newAppointment == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    printf("Enter appointment name: ");
    fgets(newAppointment->name, 50, stdin);
    newAppointment->name[strcspn(newAppointment->name, "\n")] = 0; // Remove newline
    printf("Enter appointment date (YYYY-MM-DD): ");
    fgets(newAppointment->date, 11, stdin);
    newAppointment->date[strcspn(newAppointment->date, "\n")] = 0; // Remove newline
    printf("Enter appointment time (HH:MM): ");
    fgets(newAppointment->time, 6, stdin);
    newAppointment->time[strcspn(newAppointment->time, "\n")] = 0; // Remove newline
    
    newAppointment->next = head;
    head = newAppointment;

    printf("Appointment added successfully!\n");
}

void viewAppointments() {
    if (head == NULL) {
        printf("No appointments scheduled.\n");
        return;
    }
    
    Appointment* current = head;
    printf("\n--- Scheduled Appointments ---\n");
    while (current != NULL) {
        printf("Name: %s, Date: %s, Time: %s\n", current->name, current->date, current->time);
        current = current->next;
    }
}

void deleteAppointment() {
    if (head == NULL) {
        printf("No appointments to delete.\n");
        return;
    }
    
    char name[50];
    printf("Enter the name of the appointment to delete: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    Appointment* current = head;
    Appointment* previous = NULL;
    
    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }
    
    if (current == NULL) {
        printf("No appointment found with the name \"%s\".\n", name);
        return;
    }
    
    if (previous == NULL) {
        head = current->next; // Deleting the first appointment
    } else {
        previous->next = current->next; // Bypass the deleted appointment
    }
    
    free(current);
    printf("Appointment \"%s\" deleted successfully!\n", name);
}

void freeMemory() {
    Appointment* current = head;
    while (current != NULL) {
        Appointment* temp = current;
        current = current->next;
        free(temp);
    }
}