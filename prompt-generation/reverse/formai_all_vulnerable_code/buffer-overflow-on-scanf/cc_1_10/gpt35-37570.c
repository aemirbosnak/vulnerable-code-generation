//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_APPOINTMENTS 100
#define MAX_NAME 100

// Struct to hold appointment data
typedef struct {
    char name[MAX_NAME];
    int month;
    int day;
    int hour;
    int minute;
} Appointment;

// Prototypes for functions
void print_menu();
void add_appointment();
void delete_appointment();
void view_appointments();

// Global array to hold appointment data
Appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

int main() {
    // Variable to hold user's menu choice
    int choice;

    // Main program loop
    do {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                delete_appointment();
                break;
            case 3:
                view_appointments();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

// Function to print the main menu
void print_menu() {
    printf("\n");
    printf("Appointment Scheduler\n");
    printf("---------------------\n");
    printf("1. Add Appointment\n");
    printf("2. Delete Appointment\n");
    printf("3. View Appointments\n");
    printf("4. Quit\n");
    printf("Please enter your choice (1-4): ");
}

// Function to add a new appointment
void add_appointment() {
    // Check if appointments array is full
    if (num_appointments == MAX_APPOINTMENTS) {
        printf("Appointment scheduler is full.\n");
        return;
    }

    // Get appointment data from user
    char name[MAX_NAME];
    int month, day, hour, minute;
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter month (1-12): ");
    scanf("%d", &month);
    printf("Enter day (1-31): ");
    scanf("%d", &day);
    printf("Enter hour (0-23): ");
    scanf("%d", &hour);
    printf("Enter minute (0-59): ");
    scanf("%d", &minute);

    // Create appointment struct and add to array
    Appointment new_appointment;
    strcpy(new_appointment.name, name);
    new_appointment.month = month;
    new_appointment.day = day;
    new_appointment.hour = hour;
    new_appointment.minute = minute;
    appointments[num_appointments] = new_appointment;
    num_appointments++;

    printf("Appointment added.\n");
}

// Function to delete an appointment
void delete_appointment() {
    // Check if there are any appointments to delete
    if (num_appointments == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    // Get name of appointment to delete
    char name[MAX_NAME];
    printf("Enter name of appointment to delete: ");
    scanf("%s", name);

    // Search for appointment with matching name and delete it
    int i;
    for (i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            break;
        }
    }
    if (i == num_appointments) {
        printf("Appointment not found.\n");
        return;
    }
    for (; i < num_appointments - 1; i++) {
        appointments[i] = appointments[i+1];
    }
    num_appointments--;

    printf("Appointment deleted.\n");
}

// Function to view all appointments
void view_appointments() {
    // Check if there are any appointments to view
    if (num_appointments == 0) {
        printf("No appointments to view.\n");
        return;
    }

    // Print header for appointment list
    printf("%-20s %-10s %-10s %-10s %-10s\n", "Name", "Month", "Day", "Hour", "Minute");

    // Print each appointment in the list
    int i;
    for (i = 0; i < num_appointments; i++) {
        printf("%-20s %-10d %-10d %-10d %-10d\n", appointments[i].name, appointments[i].month, appointments[i].day, appointments[i].hour, appointments[i].minute);
    }
}