//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

struct appointment {
    char date[11];
    char time[6];
    char name[50];
};

int countAppointments;
struct appointment appointments[MAX_APPOINTMENTS];

void displayMenu()
{
    printf("\n");
    printf("Welcome to Appointment Scheduler\n");
    printf("--------------------------------\n");
    printf("1. New Appointment\n");
    printf("2. List Appointments\n");
    printf("0. Exit\n");
    printf("\n");
}

void addAppointment()
{
    if (countAppointments == MAX_APPOINTMENTS) {
        printf("Maximum number of appointments reached. Unable to add new appointment.");
        return;
    }

    struct appointment newAppointment;

    printf("Date (dd/mm/yyyy): ");
    scanf("%s", newAppointment.date);

    printf("Time (hh:mm): ");
    scanf("%s", newAppointment.time);

    printf("Name: ");
    scanf("%s", newAppointment.name);

    appointments[countAppointments] = newAppointment;
    countAppointments++;

    printf("Appointment added successfully.\n");
}

void listAppointments()
{
    if (countAppointments == 0) {
        printf("No appointments added yet.\n");
        return;
    }

    printf("Appointments:\n");
    printf("-------------------------------------------------\n");
    printf("| %-12s | %-8s | %-50s |\n", "Date", "Time", "Name");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < countAppointments; i++) {
        struct appointment appointment = appointments[i];
        printf("| %-12s | %-8s | %-50s |\n", appointment.date, appointment.time, appointment.name);
    }

    printf("-------------------------------------------------\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                listAppointments();
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid Choice. Please try again.\n");
                break;
        }
    }

    return 0;
}