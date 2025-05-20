//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: Donald Knuth
/*
 * Donald Knuth Appointment Scheduler
 *
 * This program is a unique C Appointment Scheduler that
 * implements the appointment scheduling problem in a
 * Donald Knuth style.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

struct Appointment {
    char name[50];
    int day;
    int time;
};

struct Appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void addAppointment(char *name, int day, int time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Too many appointments, please try again.\n");
        return;
    }
    strcpy(appointments[num_appointments].name, name);
    appointments[num_appointments].day = day;
    appointments[num_appointments].time = time;
    num_appointments++;
}

void printAppointments() {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%d. %s (%d, %d)\n", i + 1, appointments[i].name, appointments[i].day, appointments[i].time);
    }
}

int main() {
    char name[50];
    int day, time;
    printf("Welcome to the appointment scheduler.\n");
    printf("Enter appointment name, day, and time (separated by spaces):\n");
    while (scanf("%s %d %d", name, &day, &time) == 3) {
        addAppointment(name, day, time);
        printf("Appointment added.\n");
        printAppointments();
    }
    return 0;
}