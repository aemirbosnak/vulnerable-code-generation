//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

struct appointment {
    char *name;
    char *date;
    char *time;
    char *description;
};

void addAppointment(struct appointment *appointments, int numAppointments, char *name, char *date, char *time, char *description) {
    if (numAppointments >= MAX_APPOINTMENTS) {
        printf("Sorry, I'm fully booked on that day.\n");
        return;
    }

    for (int i = 0; i < numAppointments; i++) {
        if (appointments[i].name == NULL) {
            appointments[i].name = name;
            appointments[i].date = date;
            appointments[i].time = time;
            appointments[i].description = description;
            printf("Appointment scheduled for %s at %s.\n", date, time);
            return;
        }
    }

    printf("Sorry, I'm fully booked on that day.\n");
}

void viewAppointments(struct appointment *appointments, int numAppointments) {
    if (numAppointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("Upcoming appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("Name: %s\nDate: %s\nTime: %s\nDescription: %s\n", appointments[i].name, appointments[i].date, appointments[i].time, appointments[i].description);
    }
}

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;

    srand(time(NULL));
    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        appointments[i].name = NULL;
        appointments[i].date = NULL;
        appointments[i].time = NULL;
        appointments[i].description = NULL;
    }

    while (1) {
        printf("Enter your name: ");
        char name[50];
        scanf("%s", name);

        printf("Enter the date (YYYY-MM-DD): ");
        char date[11];
        scanf("%s", date);

        printf("Enter the time (HH:MM): ");
        char time[6];
        scanf("%s", time);

        printf("Enter a brief description of the appointment: ");
        char description[100];
        scanf("%s", description);

        addAppointment(appointments, numAppointments, name, date, time, description);
    }

    return 0;
}