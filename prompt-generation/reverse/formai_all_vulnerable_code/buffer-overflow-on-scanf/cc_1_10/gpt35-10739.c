//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_APPOINTMENTS 20

struct Appointment {
    char date[11];
    char time[6];
    char patientName[50];
    char doctorName[50];
};

struct Appointment appointments[MAX_APPOINTMENTS];
int appointmentCounter = 0;

void addAppointment() {
    if (appointmentCounter >= MAX_APPOINTMENTS) {
        printf("Sorry, maximum number of appointments reached.\n");
        return;
    }

    struct Appointment newAppointment;

    printf("Enter date (mm/dd/yyyy): ");
    scanf("%s", newAppointment.date);

    printf("Enter time (hh:mm): ");
    scanf("%s", newAppointment.time);

    printf("Enter patient name: ");
    scanf(" %[^\n]s", newAppointment.patientName);

    printf("Enter doctor name: ");
    scanf(" %[^\n]s", newAppointment.doctorName);

    appointments[appointmentCounter] = newAppointment;
    appointmentCounter++;

    printf("Appointment added successfully!\n");
}

void viewAppointments() {
    if (appointmentCounter == 0) {
        printf("No appointments found.\n");
        return;
    }

    printf("%-15s %-10s %-20s %s\n", "Date", "Time", "Patient Name", "Doctor Name");
    for (int i = 0; i < appointmentCounter; i++) {
        printf("%-15s %-10s %-20s %s\n", appointments[i].date, appointments[i].time,
               appointments[i].patientName, appointments[i].doctorName);
    }
}

void deleteAppointment() {
    char searchDate[11], searchTime[6];
    printf("Enter appointment date (mm/dd/yyyy): ");
    scanf("%s", searchDate);

    printf("Enter appointment time (hh:mm): ");
    scanf("%s", searchTime);

    int indexToDelete = -1;
    for (int i = 0; i < appointmentCounter; i++) {
        if (strcmp(appointments[i].date, searchDate) == 0 && strcmp(appointments[i].time, searchTime) == 0) {
            indexToDelete = i;
            break;
        }
    }

    if (indexToDelete == -1) {
        printf("Appointment not found.\n");
        return;
    }

    for (int i = indexToDelete; i < appointmentCounter - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointmentCounter--;

    printf("Appointment deleted successfully!\n");
}

int main() {
    printf("Welcome to Appointment Scheduler!\n");

    bool programRunning = true;
    while (programRunning) {
        printf("What would you like to do?\n");
        printf("1. Schedule new appointment\n");
        printf("2. View appointments\n");
        printf("3. Delete an appointment\n");
        printf("4. Exit program\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                deleteAppointment();
                break;
            case 4:
                printf("Thank you for using Appointment Scheduler!\n");
                programRunning = false;
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}