//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define NAME_LENGTH 50
#define TIME_LENGTH 10

typedef struct {
    char name[NAME_LENGTH];
    char time[TIME_LENGTH];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void display_appointments() {
    if (appointment_count == 0) {
        printf("WARNING: No appointments scheduled! Are you sure you have entered them correctly?\n");
        return;
    }
    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("Appointment %d: %s at %s\n", i + 1, appointments[i].name, appointments[i].time);
    }
}

int is_time_conflict(const char *new_time) {
    for (int i = 0; i < appointment_count; i++) {
        if (strcmp(appointments[i].time, new_time) == 0) {
            printf("ALERT: Time conflict detected for %s at %s! Please choose a different time.\n", appointments[i].name, new_time);
            return 1;
        }
    }
    return 0;
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("CRITICAL ERROR: Maximum appointment limit reached! Consider removing an existing appointment.\n");
        return;
    }
    
    Appointment new_appointment;
    printf("Enter the name of the person for the appointment: ");
    fgets(new_appointment.name, NAME_LENGTH, stdin);
    new_appointment.name[strcspn(new_appointment.name, "\n")] = '\0'; // Remove newline character

    char time_input[TIME_LENGTH];
    printf("Enter the time of the appointment (HH:MM): ");
    fgets(time_input, TIME_LENGTH, stdin);
    time_input[strcspn(time_input, "\n")] = '\0'; // Remove newline character

    if (is_time_conflict(time_input)) {
        printf("WARNING: Cannot add appointment due to time conflict!\n");
        return;
    }
    
    strcpy(new_appointment.time, time_input);
    appointments[appointment_count++] = new_appointment;
    printf("SUCCESS: Appointment for %s at %s added successfully.\n", new_appointment.name, new_appointment.time);
}

void remove_appointment() {
    if (appointment_count == 0) {
        printf("CAUTION: No appointments to remove! Are you sure you want to do this?\n");
        return;
    }

    display_appointments();
    int appointment_number;
    printf("Enter the appointment number to remove (1 to %d): ", appointment_count);
    scanf("%d", &appointment_number);
    getchar(); // Clear newline from input buffer

    if (appointment_number < 1 || appointment_number > appointment_count) {
        printf("ERROR: Invalid appointment number!\n");
        return;
    }

    appointment_number--; // Convert to zero-based index
    for (int i = appointment_number; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    printf("ALERT: Appointment %d removed successfully.\n", appointment_number + 1);
}

void clear_appointments() {
    appointment_count = 0;
    printf("WARNING: All appointments cleared! Proceed with caution next time!\n");
}

void display_menu() {
    printf("\n--- Appointment Scheduler ---\n");
    printf("1. Add Appointment\n");
    printf("2. Remove Appointment\n");
    printf("3. Display Appointments\n");
    printf("4. Clear All Appointments\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character

        switch (choice) {
            case 1: 
                add_appointment();
                break;
            case 2: 
                remove_appointment();
                break;
            case 3: 
                display_appointments();
                break;
            case 4: 
                clear_appointments();
                break;
            case 5:
                printf("Security Alert: Are you *really* sure you want to exit? (Ctrl+C for termination)\n");
                exit(0);
            default:
                printf("Warning: Invalid choice! Double-check before proceeding!\n");
                break;
        }
    }
    return 0;
}