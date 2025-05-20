//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_APPOINTMENTS 10
#define MAX_NAME_LENGTH 20

typedef struct Appointment {
    char name[MAX_NAME_LENGTH];
    char date[MAX_NAME_LENGTH];
    char time[MAX_NAME_LENGTH];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];

void initializeAppointments() {
    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        appointments[i].name[0] = '\0';
        appointments[i].date[0] = '\0';
        appointments[i].time[0] = '\0';
    }
}

int validateAppointment(char *name, char *date, char *time) {
    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        if (strcmp(appointments[i].name, name) == 0 &&
            strcmp(appointments[i].date, date) == 0 &&
            strcmp(appointments[i].time, time) == 0) {
            return 0;
        }
    }
    return 1;
}

void bookAppointment(char *name, char *date, char *time) {
    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        if (appointments[i].name[0] == '\0') {
            strcpy(appointments[i].name, name);
            strcpy(appointments[i].date, date);
            strcpy(appointments[i].time, time);
            return;
        }
    }
    printf("Error: No available appointments.\n");
}

int main() {
    initializeAppointments();

    char name[MAX_NAME_LENGTH];
    char date[MAX_NAME_LENGTH];
    char time[MAX_NAME_LENGTH];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter the date of your appointment: ");
    scanf("%s", date);

    printf("Enter the time of your appointment: ");
    scanf("%s", time);

    if (validateAppointment(name, date, time) == 0) {
        bookAppointment(name, date, time);
    } else {
        printf("Error: Appointment already booked.\n");
    }

    return 0;
}