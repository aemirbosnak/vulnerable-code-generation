//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_DESC_LENGTH 100
#define DATE_LENGTH 11

typedef struct {
    char date[DATE_LENGTH];
    char description[MAX_DESC_LENGTH];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment();
void view_appointments();
void clear_input_buffer();

int main() {
    int choice;
    while (1) {
        printf("Welcome to the Puzzle Appointment Scheduler!\n");
        printf("1. Add an Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clear_input_buffer();  // Clear newline from input buffer
        
        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                printf("Exiting... See you next time!\n");
                return 0;
            default:
                printf("Invalid choice! Let’s not dwell in the confusion.\n");
        }
    }
    return 0;
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("You have reached the maximum number of appointments!\n");
        return;
    }

    printf("Enter the date of the appointment (YYYY-MM-DD): ");
    fgets(appointments[appointment_count].date, DATE_LENGTH, stdin);
    appointments[appointment_count].date[strcspn(appointments[appointment_count].date, "\n")] = '\0'; // Remove newline

    printf("Enter the description of the appointment: ");
    fgets(appointments[appointment_count].description, MAX_DESC_LENGTH, stdin);
    appointments[appointment_count].description[strcspn(appointments[appointment_count].description, "\n")] = '\0'; // Remove newline

    appointment_count++;
    printf("Appointment added! You're on top of things!\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments found! The schedule is mysteriously empty!\n");
        return;
    }

    printf("Here are your appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d. Date: %s | Description: %s\n", i + 1, appointments[i].date, appointments[i].description);
    }
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Clear the input buffer
}