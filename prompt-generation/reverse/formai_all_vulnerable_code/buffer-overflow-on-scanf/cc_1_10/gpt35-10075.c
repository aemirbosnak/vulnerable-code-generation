//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_APPOINTMENTS 100
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

bool isAvailable(int day, int month, int year, int hour, int minute) {
    for (int i = 0; i < numAppointments; ++i) {
        if (appointments[i].day == day &&
            appointments[i].month == month &&
            appointments[i].year == year &&
            appointments[i].hour == hour &&
            appointments[i].minute == minute) {
            return false;
        }
    }

    return true;
}

void addAppointment() {
    if (numAppointments >= MAX_APPOINTMENTS) {
        printf("Error: No more appointments can be scheduled.\n");
        return;
    }

    printf("Enter appointment details:\n");

    char name[MAX_NAME_LENGTH];
    int day, month, year, hour, minute;

    printf("Name: ");
    scanf("%s", name);

    printf("Date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &month, &year);

    printf("Time (hh:mm): ");
    scanf("%d:%d", &hour, &minute);

    if (!isAvailable(day, month, year, hour, minute)) {
        printf("Error: Appointment already scheduled at that time.\n");
        return;
    }

    Appointment appointment;
    strcpy(appointment.name, name);
    appointment.day = day;
    appointment.month = month;
    appointment.year = year;
    appointment.hour = hour;
    appointment.minute = minute;

    appointments[numAppointments++] = appointment;

    printf("Appointment added successfully!\n");
}

void printAppointments() {
    printf("Scheduled Appointments:\n");

    for (int i = 0; i < numAppointments; ++i) {
        printf("%d. Name: %s\n   Date: %d/%d/%d\n   Time: %02d:%02d\n",
               i + 1,
               appointments[i].name,
               appointments[i].day,
               appointments[i].month,
               appointments[i].year,
               appointments[i].hour,
               appointments[i].minute);
    }
}

int main() {
    while (true) {
        printf("Appointment Scheduler\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Exit\n");
        printf("Enter your selection: ");

        int choice;
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
                exit(0);
            default:
                printf("Error: Invalid choice.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}