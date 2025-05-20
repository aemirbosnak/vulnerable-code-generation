//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_DESC_LEN 50

typedef struct {
    int id;
    char description[MAX_DESC_LEN];
    struct tm date_time;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

// Function to display the date in a readable format
void display_date(struct tm* date_time) {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", date_time);
    printf("%s", buffer);
}

// Function to add a new appointment
void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment limit reached! You cannot add more appointments.\n");
        return;
    }
    
    Appointment new_appointment;
    new_appointment.id = appointment_count + 1;

    printf("Enter description (max %d characters): ", MAX_DESC_LEN - 1);
    getchar(); // Consume newline
    fgets(new_appointment.description, MAX_DESC_LEN, stdin);
    new_appointment.description[strcspn(new_appointment.description, "\n")] = 0; // Remove newline

    printf("Enter date and time (YYYY-MM-DD HH:MM): ");
    char date_input[100];
    fgets(date_input, sizeof(date_input), stdin);
    strptime(date_input, "%Y-%m-%d %H:%M", &new_appointment.date_time);

    appointments[appointment_count++] = new_appointment;
    printf("Appointment with ID %d added successfully!\n", new_appointment.id);
}

// Function to view all appointments
void view_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled!\n");
        return;
    }

    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("ID: %d, Description: '%s', Date & Time: ", appointments[i].id, appointments[i].description);
        display_date(&appointments[i].date_time);
        printf("\n");
    }
}

// Function to delete an appointment
void delete_appointment() {
    if (appointment_count == 0) {
        printf("No appointments to delete!\n");
        return;
    }

    printf("Enter the ID of the appointment to delete: ");
    int id;
    scanf("%d", &id);

    if (id < 1 || id > appointment_count) {
        printf("Invalid appointment ID!\n");
        return;
    }

    for (int i = id - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    printf("Appointment with ID %d deleted successfully!\n", id);
}

// Function to show the menu
void menu() {
    printf("\nAppointment Scheduler Menu:\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
}

// Main function
int main() {
    int choice;
    printf("Welcome to the Appointment Scheduler!\n");

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
                printf("Thank you for using the Appointment Scheduler! Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}