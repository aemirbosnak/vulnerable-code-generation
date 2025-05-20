//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define DATE_LEN 11
#define TIME_LEN 6
#define DESCRIPTION_LEN 50

typedef struct {
    char date[DATE_LEN];       // The date of the appointment
    char time[TIME_LEN];       // The time of the appointment
    char description[DESCRIPTION_LEN];  // Description of the appointment
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

// Function prototypes
void add_appointment();
void view_appointments();
void delete_appointment();
void display_menu();
void clear_input_buffer();

int main() {
    int choice;
    do {
        display_menu();
        printf("\nChoose an option: ");
        scanf("%d", &choice);
        clear_input_buffer(); // clear the input buffer to avoid buffer overflow

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                delete_appointment();
                break;
            case 4:
                printf("Exiting the appointment scheduler. Have a great day!\n");
                break;
            default:
                printf("Please enter a valid option!\n");
        }

    } while (choice != 4);

    return 0;
}

void display_menu() {
    printf("\n============ Appointment Scheduler ============");
    printf("\n1. Add Appointment");
    printf("\n2. View Appointments");
    printf("\n3. Delete Appointment");
    printf("\n4. Exit");
    printf("\n===============================================");
}

void clear_input_buffer() {
    while (getchar() != '\n'); // Clear the input buffer
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment limit reached! Cannot add more appointments.\n");
        return;
    }

    Appointment new_appointment;

    printf("Enter the date (YYYY-MM-DD): ");
    fgets(new_appointment.date, DATE_LEN, stdin);
    strtok(new_appointment.date, "\n"); // Remove trailing newline

    printf("Enter the time (HH:MM): ");
    fgets(new_appointment.time, TIME_LEN, stdin);
    strtok(new_appointment.time, "\n"); // Remove trailing newline

    printf("Enter a description: ");
    fgets(new_appointment.description, DESCRIPTION_LEN, stdin);
    strtok(new_appointment.description, "\n"); // Remove trailing newline

    appointments[appointment_count++] = new_appointment;
    printf("Appointment added successfully!\n");
}

void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("Appointment %d: Date: %s, Time: %s, Description: %s\n",
            i + 1, appointments[i].date, appointments[i].time, appointments[i].description);
    }
}

void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    int index;
    printf("Enter the appointment number to delete (1 to %d): ", appointment_count);
    scanf("%d", &index);
    clear_input_buffer(); // clear the input buffer 
    index -= 1; // Adjust index for zero-based array

    if (index < 0 || index >= appointment_count) {
        printf("Invalid appointment number!\n");
        return;
    }

    // Shift appointments left to fill the gap
    for (int i = index; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--; // Decrease the appointment count
    printf("Appointment deleted successfully!\n");
}