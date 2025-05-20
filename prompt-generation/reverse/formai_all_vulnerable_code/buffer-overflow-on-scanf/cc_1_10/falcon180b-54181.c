//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 30
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_DURATION 120 // in minutes

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int duration;
    int start_time;
} appointment;

void print_appointment(appointment app) {
    printf("%s - %s\n", app.name, app.description);
    printf("Duration: %d minutes\n", app.duration);
    printf("Start time: %d\n\n", app.start_time);
}

int compare_appointments(const void *a, const void *b) {
    appointment *app1 = (appointment *)a;
    appointment *app2 = (appointment *)b;

    if (app1->start_time < app2->start_time) {
        return -1;
    } else if (app1->start_time > app2->start_time) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int num_appointments;
    appointment appointments[MAX_APPOINTMENTS];

    printf("Enter the number of appointments: ");
    scanf("%d", &num_appointments);

    printf("Enter appointment details:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("Name: ");
        scanf("%s", appointments[i].name);

        printf("Description: ");
        scanf("%s", appointments[i].description);

        printf("Duration: ");
        scanf("%d", &appointments[i].duration);

        printf("Start time (in minutes from now): ");
        scanf("%d", &appointments[i].start_time);
    }

    qsort(appointments, num_appointments, sizeof(appointment), compare_appointments);

    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        print_appointment(appointments[i]);
    }

    return 0;
}