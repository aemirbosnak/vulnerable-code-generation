//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 10
#define MAX_TIME_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    char time[MAX_TIME_LENGTH];
    int duration;
    int status;
} Appointment;

int main() {
    int numAppointments = 0;
    Appointment appointments[MAX_APPOINTMENTS];

    while (numAppointments < MAX_APPOINTMENTS) {
        printf("Enter name (or 'quit' to exit): ");
        char name[MAX_NAME_LENGTH];
        scanf("%s", name);
        if (strcmp(name, "quit") == 0) {
            break;
        }
        strcpy(appointments[numAppointments].name, name);

        printf("Enter date (YYYY-MM-DD): ");
        char date[MAX_DATE_LENGTH];
        scanf("%s", date);
        strcpy(appointments[numAppointments].date, date);

        printf("Enter time (HH:MM): ");
        char time[MAX_TIME_LENGTH];
        scanf("%s", time);
        strcpy(appointments[numAppointments].time, time);

        printf("Enter duration (in minutes): ");
        scanf("%d", &appointments[numAppointments].duration);

        numAppointments++;
    }

    printf("Appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%s on %s at %s (duration %d minutes)\n", appointments[i].name, appointments[i].date, appointments[i].time, appointments[i].duration);
    }

    return 0;
}