//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define NAME_LENGTH 50
#define DESC_LENGTH 100
#define TIME_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char description[DESC_LENGTH];
    char time[TIME_LENGTH];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

// Function to create an appointment
void create_appointment(char name[], char description[], char time[]) {
    if (appointment_count < MAX_APPOINTMENTS) {
        strcpy(appointments[appointment_count].name, name);
        strcpy(appointments[appointment_count].description, description);
        strcpy(appointments[appointment_count].time, time);
        appointment_count++;
        printf("Appointment created successfully!\n");
    } else {
        printf("Error: Maximum appointment limit reached!\n");
    }
}

// Function to display all appointments
void display_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    printf("\n--- Scheduled Appointments ---\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Name: %s\n", appointments[i].name);
        printf("Description: %s\n", appointments[i].description);
        printf("Time: %s\n", appointments[i].time);
        printf("----------------------------\n");
    }
}

// Function to remove an appointment
void remove_appointment(int index) {
    if (index < 1 || index > appointment_count) {
        printf("Error: Invalid appointment index!\n");
        return;
    }
    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    printf("Appointment removed successfully!\n");
}

// Function to display menu options
void display_menu() {
    printf("\n--- Appointment Scheduler Menu ---\n");
    printf("1. Create Appointment\n");
    printf("2. Display Appointments\n");
    printf("3. Remove Appointment\n");
    printf("4. Exit\n");
    printf("----------------------------------\n");
}

// Main function
int main() {
    int choice;
    char name[NAME_LENGTH];
    char description[DESC_LENGTH];
    char time[TIME_LENGTH];
    
    while (1) {
        display_menu();
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character
        
        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character
                printf("Enter Description: ");
                fgets(description, DESC_LENGTH, stdin);
                description[strcspn(description, "\n")] = 0; // Remove newline character
                printf("Enter Time (e.g., YYYY-MM-DD HH:MM): ");
                fgets(time, TIME_LENGTH, stdin);
                time[strcspn(time, "\n")] = 0; // Remove newline character
                create_appointment(name, description, time);
                break;
            case 2:
                display_appointments();
                break;
            case 3:
                printf("Enter appointment number to remove: ");
                int index;
                scanf("%d", &index);
                remove_appointment(index);
                break;
            case 4:
                printf("Exiting the scheduler. Goodbye!\n");
                exit(0);
            default:
                printf("Error: Invalid option! Please try again.\n");
                break;
        }
    }
    
    return 0;
}