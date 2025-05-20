//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_APPOINTMENTS 20

struct Appointment {
    char name[50]; //name of the person who booked the appointment
    int day; //day of the month from 1 to 30
    char time[10]; //time of the appointment in 12 hour format
    char reason[100]; //reason for the appointment
};

struct Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void printAppointments() {
    printf("\n");
    printf("Scheduled Appointments:\n");
    printf("--------------------------------------------------\n");
    printf("| Name\t\t| Day\t| Time\t| Reason\t|\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < appointmentCount; i++) {
        printf("| %-10s\t| %-2d\t| %-5s\t| %-15s\t|\n", appointments[i].name, appointments[i].day, appointments[i].time, appointments[i].reason);
    }
    printf("--------------------------------------------------\n");
}

void scheduleAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Sorry, appointments are fully booked for this month. Please try again next month!\n");
        return;
    }

    struct Appointment appointment;

    printf("Enter Name: ");
    scanf("%s", appointment.name);

    printf("Enter Day (1-30): ");
    scanf("%d", &appointment.day);

    printf("Enter Time (Format: HH:MM AM/PM): ");
    scanf("%s", appointment.time);

    printf("Enter Reason for the Appointment: ");
    getchar(); // consume newline
    fgets(appointment.reason, 100, stdin);

    appointments[appointmentCount] = appointment;
    appointmentCount++;

    printf("Appointment Booked Successfully!\n");

}

int main() {
    printf("\n==========================================\n");
    printf("\t\tYe Olde Appointment Scheduler\n");
    printf("==========================================\n");
    while (1) {
        int choice;
        printf("\nMenu:\n");
        printf("1. View Scheduled Appointments\n");
        printf("2. Schedule a New Appointment\n");
        printf("3. Exit\n");
        printf("Enter choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printAppointments();
                break;
            case 2:
                scheduleAppointment();
                break;
            case 3:
                printf("Exiting Appointment Scheduler. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid Choice. Please try again.\n");
        }
    }
    return 0;
}