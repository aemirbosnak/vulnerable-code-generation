//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: visionary
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

// Struct for an appointment
typedef struct {
    char date[20];
    char time[10];
    char description[100];
} Appointment;

// Array of appointments
Appointment appointments[MAX_APPOINTMENTS];

// Count of appointments
int count = 0;

// Function to add an appointment
void addAppointment() {
    if (count >= MAX_APPOINTMENTS) {
        printf("Error: Maximum number of appointments reached.\n");
        return;
    }
    
    printf("Enter the date of the appointment (dd/mm/yyyy): ");
    scanf("%s", appointments[count].date);
    printf("Enter the time of the appointment (hh:mm): ");
    scanf("%s", appointments[count].time);
    printf("Enter a description of the appointment: ");
    scanf(" %[^\n]", appointments[count].description);
    
    count++;
}

// Function to display all appointments
void displayAppointments() {
    if (count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    
    printf("\nAppointments:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s at %s - %s\n", i+1, appointments[i].date, appointments[i].time, appointments[i].description);
    }
}

// Function to search for an appointment
void searchAppointment() {
    char searchTerm[100];
    int matches = 0;
    
    printf("Enter a keyword to search for: ");
    scanf(" %[^\n]", searchTerm);
    
    printf("\nMatching Appointments:\n");
    for (int i = 0; i < count; i++) {
        if (strstr(appointments[i].description, searchTerm) != NULL) {
            printf("%d. %s at %s - %s\n", i+1, appointments[i].date, appointments[i].time, appointments[i].description);
            matches++;
        }
    }
    
    if (matches == 0) {
        printf("No matching appointments found.\n");
    }
}

// Function to delete an appointment
void deleteAppointment() {
    int index;
    
    printf("Enter the index of the appointment to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > count) {
        printf("Invalid index.\n");
        return;
    }
    
    index--;
    for (int i = index; i < count-1; i++) {
        appointments[i] = appointments[i+1];
    }
    
    count--;
    printf("Appointment deleted successfully.\n");
}

// Main function
int main() {
    int choice;
    
    while (true) {
        printf("\nAppointment Scheduler\n");
        printf("1. Add Appointment\n");
        printf("2. Display Appointments\n");
        printf("3. Search Appointments\n");
        printf("4. Delete Appointment\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                displayAppointments();
                break;
            case 3:
                searchAppointment();
                break;
            case 4:
                deleteAppointment();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    
    return 0;
}