//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char name[50];
    int date;
    int time;
} Appointment;

void addAppointment(Appointment *appointments, int numAppointments, char *name, int date, int time) {
    if (numAppointments == MAX_APPOINTMENTS) {
        printf("Sorry, the schedule is full.\n");
        return;
    }
    strcpy(appointments[numAppointments].name, name);
    appointments[numAppointments].date = date;
    appointments[numAppointments].time = time;
    numAppointments++;
}

void displayAppointments(Appointment *appointments, int numAppointments) {
    printf("Schedule:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%s - %d/%d %d:%02d\n", appointments[i].name, appointments[i].date, appointments[i].date, appointments[i].time/60, appointments[i].time%60);
    }
}

int main() {
    int numAppointments = 0;
    Appointment appointments[MAX_APPOINTMENTS];
    char name[50];
    int date, time;

    printf("Welcome to the Appointment Scheduler!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add appointment\n");
        printf("2. Display schedule\n");
        printf("3. Exit\n");

        scanf("%d", &date);

        switch (date) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter date (mm/dd/yyyy): ");
                scanf("%d/%d/%d", &date, &date, &date);
                printf("Enter time (hh:mm): ");
                scanf("%d:%d", &time, &time);
                addAppointment(appointments, numAppointments, name, date, time);
                break;
            case 2:
                displayAppointments(appointments, numAppointments);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}