//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of appointments
#define MAX_APPOINTMENTS 10

// Define structure for Appointment
typedef struct {
    char name[50];
    char date[20];
    char time[10];
} Appointment;

// Function to add appointment
void addAppointment(Appointment appointments[], int *count) {
    if (*count >= MAX_APPOINTMENTS) {
        printf("Maximum number of appointments reached.\n");
        return;
    }
    Appointment newAppointment;
    printf("Enter name: ");
    scanf("%s", newAppointment.name);
    printf("Enter date (MM/DD/YYYY): ");
    scanf("%s", newAppointment.date);
    printf("Enter time (HH:MM): ");
    scanf("%s", newAppointment.time);
    appointments[*count] = newAppointment;
    (*count)++;
}

// Function to display all appointments
void displayAppointments(Appointment appointments[], int count) {
    printf("All Appointments:\n");
    for (int i = 0; i < count; i++) {
        printf("------------------\n");
        printf("Name: %s\n", appointments[i].name);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
    }
    printf("------------------\n");
}

// Main function
int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int count = 0;
    int choice;
    while (1) {
        printf("Appointment Scheduler\n");
        printf("1) Add Appointment\n");
        printf("2) Display Appointments\n");
        printf("3) Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addAppointment(appointments, &count);
                break;
            case 2:
                displayAppointments(appointments, count);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}