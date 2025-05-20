//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 50
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    time_t start_time;
    time_t end_time;
    int duration;
} appointment;

void add_appointment(appointment* appointments, int num_appointments, char* name, time_t start_time, time_t end_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Cannot add more appointments. Maximum limit reached.\n");
        return;
    }

    strcpy(appointments[num_appointments].name, name);
    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].end_time = end_time;
    appointments[num_appointments].duration = difftime(end_time, start_time);

    num_appointments++;
}

void display_appointments(appointment* appointments, int num_appointments) {
    printf("Appointments:\n");

    for (int i = 0; i < num_appointments; i++) {
        printf("%s: %s - %s (%d minutes)\n", appointments[i].name, ctime(&appointments[i].start_time), ctime(&appointments[i].end_time), appointments[i].duration);
    }
}

int main() {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    char name[MAX_NAME_LENGTH];
    time_t start_time, end_time;

    while (1) {
        printf("Enter name: ");
        scanf("%s", name);

        printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", ctime(&start_time));

        printf("Enter end time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", ctime(&end_time));

        add_appointment(appointments, num_appointments, name, start_time, end_time);

        printf("Appointment added.\n");
    }

    return 0;
}