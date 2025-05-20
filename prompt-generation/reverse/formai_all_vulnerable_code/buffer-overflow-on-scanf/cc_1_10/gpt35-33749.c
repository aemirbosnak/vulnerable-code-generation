//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int day;
    int month;
    int year;
    int hour;
    int minute;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];

int numAppointments = 0;

void addAppointment(char *name, int day, int month, int year, int hour, int minute);
void viewAppointments();
void removeAppointment(int num);

int main(void) {
    char choice;
    char name[MAX_NAME_LENGTH];
    int day, month, year, hour, minute;
    int appointmentNum;

    printf("Welcome to the Appointment Scheduler\n\n");

    while (1) {
        printf("Please select an option:\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Remove Appointment\n");
        printf("4. Exit\n");

        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter name: ");
                scanf(" %s", name);
                printf("Enter date (DD/MM/YYYY): ");
                scanf(" %d/%d/%d", &day, &month, &year);
                printf("Enter time (HH:MM): ");
                scanf(" %d:%d", &hour, &minute);
                addAppointment(name, day, month, year, hour, minute);
                break;
            case '2':
                viewAppointments();
                break;
            case '3':
                printf("Enter appointment number to remove: ");
                scanf(" %d", &appointmentNum);
                removeAppointment(appointmentNum);
                break;
            case '4':
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addAppointment(char *name, int day, int month, int year, int hour, int minute) {
    if (numAppointments == MAX_APPOINTMENTS) {
        printf("Cannot add appointment. Maximum number of appointments reached.\n");
        return;
    }

    strcpy(appointments[numAppointments].name, name);
    appointments[numAppointments].day = day;
    appointments[numAppointments].month = month;
    appointments[numAppointments].year = year;
    appointments[numAppointments].hour = hour;
    appointments[numAppointments].minute = minute;

    printf("Appointment added.\n");

    numAppointments++;
}

void viewAppointments() {
    if (numAppointments == 0) {
        printf("No appointments.\n");
        return;
    }

    printf("Appointments:\n");

    for (int i = 0; i < numAppointments; i++) {
        printf("Appointment %d:\n", i+1);
        printf("\tName: %s\n", appointments[i].name);
        printf("\tDate: %02d/%02d/%04d\n", appointments[i].day, appointments[i].month, appointments[i].year);
        printf("\tTime: %02d:%02d\n", appointments[i].hour, appointments[i].minute);
    }
}

void removeAppointment(int num) {
    if (num < 1 || num > numAppointments) {
        printf("Invalid appointment number.\n");
        return;
    }

    for (int i = num-1; i < numAppointments-1; i++) {
        appointments[i] = appointments[i+1];
    }

    numAppointments--;

    printf("Appointment removed.\n");
}