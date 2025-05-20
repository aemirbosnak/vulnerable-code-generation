//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

struct Appointment {
    int id;
    char name[50];
    char date[11];
    char time[6];
};

struct Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

bool isValidTime(char *time) {
    int hour = atoi(strtok(time, ":"));
    int minute = atoi(strtok(NULL, ":"));
    if (hour < 0 || hour > 23) {
        return false;
    }
    if (minute < 0 || minute > 59) {
        return false;
    }
    return true;
}

void scheduleAppointment() {
    struct Appointment appointment;
    printf("Enter name: ");
    gets(appointment.name);
    printf("Enter date (YYYY-MM-DD): ");
    gets(appointment.date);
    printf("Enter time (HH:MM): ");
    gets(appointment.time);
    if (!isValidTime(appointment.time)) {
        printf("Invalid time. Appointment not scheduled.\n");
        return;
    }
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Appointment slots full. Appointment not scheduled.\n");
        return;
    }
    appointment.id = appointmentCount + 1;
    appointments[appointmentCount++] = appointment;
    printf("Appointment successfully scheduled.\n");
}

void displayAppointments() {
    if (appointmentCount == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    printf("ID\tNAME\t\tDATE\t\tTIME\n");
    for (int i = 0; i < appointmentCount; i++) {
        struct Appointment appointment = appointments[i];
        printf("%d\t%s\t\t%s\t%s\n", appointment.id, appointment.name, appointment.date, appointment.time);
    }
}

void cancelAppointment() {
    int appointmentId;
    printf("Enter appointment ID to cancel: ");
    scanf("%d", &appointmentId);
    getchar(); // To consume newline after scanf
    bool found = false;
    for (int i = 0; i < appointmentCount; i++) {
        if (appointments[i].id == appointmentId) {
            found = true;
            for (int j = i; j < appointmentCount - 1; j++) {
                appointments[j] = appointments[j + 1];
            }
            appointmentCount--;
            break;
        }
    }
    if (found) {
        printf("Appointment successfully cancelled.\n");
    } else {
        printf("Appointment not found.\n");
    }
}

int getMenuChoice() {
    int choice;
    printf("\n1. Schedule appointment\n");
    printf("2. Display appointments\n");
    printf("3. Cancel appointment\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    getchar(); // To consume newline after scanf
    return choice;
}

int main() {
    while (true) {
        int choice = getMenuChoice();
        switch (choice) {
            case 1:
                scheduleAppointment();
                break;
            case 2:
                displayAppointments();
                break;
            case 3:
                cancelAppointment();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}