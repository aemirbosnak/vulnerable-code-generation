//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct appointment {
    char name[50];
    char date[20];
    char time[20];
    char reason[100];
};

void addAppointment(struct appointment *appointments, int numAppointments, char *name, char *date, char *time, char *reason) {
    if (numAppointments >= 100) {
        printf("Sorry, the schedule is full.\n");
        return;
    }
    strcpy(appointments[numAppointments].name, name);
    strcpy(appointments[numAppointments].date, date);
    strcpy(appointments[numAppointments].time, time);
    strcpy(appointments[numAppointments].reason, reason);
    numAppointments++;
}

void displayAppointments(struct appointment *appointments, int numAppointments) {
    printf("Appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("Name: %s\nDate: %s\nTime: %s\nReason: %s\n", appointments[i].name, appointments[i].date, appointments[i].time, appointments[i].reason);
    }
}

void scheduleAppointment(struct appointment *appointments, int numAppointments) {
    char name[50], date[20], time[20], reason[100];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter the date (mm/dd/yyyy): ");
    scanf("%s", date);
    printf("Enter the time (hh:mm am/pm): ");
    scanf("%s", time);
    printf("Enter the reason for the appointment: ");
    scanf("%s", reason);
    addAppointment(appointments, numAppointments, name, date, time, reason);
}

int main() {
    struct appointment appointments[100];
    int numAppointments = 0;
    while (1) {
        printf("1. Schedule an appointment\n2. Display appointments\n3. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            scheduleAppointment(appointments, numAppointments);
            break;
        case 2:
            displayAppointments(appointments, numAppointments);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}