//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 30
#define MAX_DATE_LENGTH 11
#define MAX_TIME_LENGTH 6

typedef struct {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    char time[MAX_TIME_LENGTH];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int numAppointments = 0;

void addAppointment(char *name, char *date, char *time) {
    if (numAppointments >= MAX_APPOINTMENTS) {
        printf("Error: Maximum number of appointments reached.\n");
        return;
    }

    strcpy(appointments[numAppointments].name, name);
    strcpy(appointments[numAppointments].date, date);
    strcpy(appointments[numAppointments].time, time);

    numAppointments++;
}

void printAppointments() {
    printf("Appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%s %s %s\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

int main() {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    char time[MAX_TIME_LENGTH];

    while (1) {
        printf("Enter name, date, and time (or q to quit): ");
        scanf("%s %s %s", name, date, time);

        if (strcmp(name, "q") == 0) {
            break;
        }

        addAppointment(name, date, time);
    }

    printAppointments();

    return 0;
}