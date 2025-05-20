//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold appointment information
typedef struct {
    char date[20];
    char time[20];
    char name[50];
    char description[100];
} Appointment;

// Function to add a new appointment
void addAppointment(Appointment *appointments, int *numAppointments) {
    Appointment newAppointment;
    printf("Enter date (MM/DD/YYYY): ");
    fgets(newAppointment.date, 20, stdin);
    printf("Enter time (HH:MM AM/PM): ");
    fgets(newAppointment.time, 20, stdin);
    printf("Enter name: ");
    fgets(newAppointment.name, 50, stdin);
    printf("Enter description: ");
    fgets(newAppointment.description, 100, stdin);
    appointments[*numAppointments] = newAppointment;
    *numAppointments += 1;
    printf("Appointment created successfully.\n");
}

// Function to print all appointments
void printAppointments(Appointment *appointments, int numAppointments) {
    if (numAppointments == 0) {
        printf("There are no appointments.\n");
        return;
    }
    printf("All Appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("Date: %sTime: %sName: %sDescription: %s\n\n", appointments[i].date, appointments[i].time, appointments[i].name, appointments[i].description);
    }
}

// Function to search appointments by date and time
void searchAppointments(Appointment *appointments, int numAppointments) {
    char searchDate[20];
    char searchTime[20];
    printf("Enter date to search for (MM/DD/YYYY): ");
    fgets(searchDate, 20, stdin);
    printf("Enter time to search for (HH:MM AM/PM): ");
    fgets(searchTime, 20, stdin);
    for (int i = 0; i < numAppointments; i++) {
        Appointment appointment = appointments[i];
        if (strcmp(appointment.date, searchDate) == 0 && strcmp(appointment.time, searchTime) == 0) {
            printf("Appointment found:\nDate: %sTime: %sName: %sDescription: %s\n\n", appointment.date, appointment.time, appointment.name, appointment.description);
            return;
        }
    }
    printf("Appointment not found.\n");
}

int main() {
    Appointment appointments[100];
    int numAppointments = 0;
    while (1) {
        char option;
        printf("Appointment Scheduler\n");
        printf("1. Add appointment\n");
        printf("2. View all appointments\n");
        printf("3. Search for an appointment\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%c", &option);
        getchar(); // consume newline character
        switch (option) {
            case '1':
                addAppointment(appointments, &numAppointments);
                break;
            case '2':
                printAppointments(appointments, numAppointments);
                break;
            case '3':
                searchAppointments(appointments, numAppointments);
                break;
            case '4':
                printf("Thank you for using the Appointment Scheduler!\n");
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }
    return 0;
}