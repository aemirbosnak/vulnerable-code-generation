//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    char date[11]; // Format: YYYY-MM-DD
    char time[6];  // Format: HH:MM
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

// Function prototypes
void display_menu();
void add_appointment();
void view_appointments();
void clear_appointments();
void exit_program();

int main() {
    int choice;
    
    do {
        display_menu();
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer
        
        switch(choice) {
            case 1: add_appointment(); break;
            case 2: view_appointments(); break;
            case 3: clear_appointments(); break;
            case 4: exit_program(); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4);
    
    return 0;
}

void display_menu() {
    printf("\n--- Appointment Scheduler ---\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Clear All Appointments\n");
    printf("4. Exit\n");
    printf("-----------------------------\n");
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full!\n");
        return;
    }
    
    Appointment new_appointment;
    
    printf("Enter name of the person: ");
    fgets(new_appointment.name, MAX_NAME_LEN, stdin);
    strtok(new_appointment.name, "\n"); // Remove newline character
    
    printf("Enter date (YYYY-MM-DD): ");
    fgets(new_appointment.date, 11, stdin);
    strtok(new_appointment.date, "\n"); // Remove newline character
    
    printf("Enter time (HH:MM): ");
    fgets(new_appointment.time, 6, stdin);
    strtok(new_appointment.time, "\n"); // Remove newline character
    
    appointments[appointment_count++] = new_appointment;
    printf("Appointment added successfully!\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    
    printf("\n--- Appointments ---\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d. %s - %s at %s\n", i + 1, appointments[i].name, appointments[i].date, appointments[i].time);
    }
    printf("----------------------\n");
}

void clear_appointments() {
    appointment_count = 0;
    printf("All appointments have been cleared.\n");
}

void exit_program() {
    printf("Exiting the appointment scheduler. Goodbye!\n");
}