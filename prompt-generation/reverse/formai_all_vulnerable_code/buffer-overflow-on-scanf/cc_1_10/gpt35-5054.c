//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Alan Touring
#include <stdio.h>

// Define the maximum number of appointments
#define MAX_APPOINTMENTS 10

// Define the struct for an appointment
typedef struct {
    int day;
    int month;
    int year;
    int hour;
    int minute;
    char description[100];
} Appointment;

// Define an array to hold the appointments
Appointment appointments[MAX_APPOINTMENTS];

// Define a function to add an appointment
void addAppointment() {
    static int appointmentCount = 0;
    if (appointmentCount < MAX_APPOINTMENTS) {
        printf("Enter the appointment day (1-31): ");
        scanf("%d", &appointments[appointmentCount].day);
        printf("Enter the appointment month (1-12): ");
        scanf("%d", &appointments[appointmentCount].month);
        printf("Enter the appointment year: ");
        scanf("%d", &appointments[appointmentCount].year);
        printf("Enter the appointment hour (0-23): ");
        scanf("%d", &appointments[appointmentCount].hour);
        printf("Enter the appointment minute (0-59): ");
        scanf("%d", &appointments[appointmentCount].minute);
        printf("Enter a description of the appointment: ");
        scanf("%s", appointments[appointmentCount].description);
        appointmentCount++;
    } else {
        printf("Cannot add more appointments!\n");
    }
}

// Define a function to print all appointments
void printAppointments() {
    if (appointments[0].day) {
        printf("Appointments:\n");
        for (int i = 0; i < MAX_APPOINTMENTS; i++) {
            if (appointments[i].day) {
                printf("%d/%d/%d %02d:%02d - %s\n", appointments[i].day, appointments[i].month,
                    appointments[i].year, appointments[i].hour, appointments[i].minute, appointments[i].description);
            }
        }
    } else {
        printf("No appointments scheduled.\n");
    }
}

// Main function to run the program
int main() {
    int choice = 0;
    while (choice != 3) {
        printf("Appointment Scheduler\n");
        printf("======================\n");
        printf("1. Add Appointment\n");
        printf("2. Print Appointments\n");
        printf("3. Exit\n");
        printf("Select an option (1-3): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                printAppointments();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}