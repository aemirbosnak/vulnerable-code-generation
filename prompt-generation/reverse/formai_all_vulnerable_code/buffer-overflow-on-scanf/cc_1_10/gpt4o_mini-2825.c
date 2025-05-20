//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Appointment {
    char title[50];
    char date[11];  // Format: YYYY-MM-DD
    char time[6];   // Format: HH:MM
    struct Appointment* next;
} Appointment;

Appointment* head = NULL;

// Function to create a new appointment
void createAppointment() {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    printf("Enter appointment title: ");
    scanf(" %[^\n]%*c", newAppointment->title);
    printf("Enter date (YYYY-MM-DD): ");
    scanf(" %[^\n]%*c", newAppointment->date);
    printf("Enter time (HH:MM): ");
    scanf(" %[^\n]%*c", newAppointment->time);
    
    newAppointment->next = head;
    head = newAppointment;
    
    printf("Appointment created successfully!\n");
}

// Function to display all appointments
void viewAppointments() {
    if (head == NULL) {
        printf("No appointments found.\n");
        return;
    }
    
    Appointment* current = head;
    printf("\n---- Appointments ----\n");
    while (current != NULL) {
        printf("Title: %s | Date: %s | Time: %s\n", current->title, current->date, current->time);
        current = current->next;
    }
}

// Function to delete an appointment
void deleteAppointment() {
    char title[50];
    printf("Enter the title of the appointment to delete: ");
    scanf(" %[^\n]%*c", title);
    
    Appointment* current = head;
    Appointment* previous = NULL;

    while (current != NULL && strcmp(current->title, title) != 0) {
        previous = current;
        current = current->next;
    }
    
    if (current == NULL) {
        printf("No appointment found with the title: %s\n", title);
        return;
    }

    if (previous == NULL) {
        head = current->next;  // The appointment to delete is the head
    } else {
        previous->next = current->next;
    }
    
    free(current);
    printf("Appointment deleted successfully!\n");
}

// Function to display main menu
void displayMenu() {
    printf("\n=== Appointment Scheduler ===\n");
    printf("1. Create Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("============================\n");
}

// Main function to run the scheduler
int main() {
    int choice;
    
    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                deleteAppointment();
                break;
            case 4:
                printf("Exiting the appointment scheduler...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    
    // Free the list before exiting
    Appointment* current = head;
    while (current != NULL) {
        Appointment* temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}