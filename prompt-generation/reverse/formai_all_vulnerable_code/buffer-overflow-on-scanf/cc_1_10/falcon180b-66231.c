//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_APPOINTMENT_LENGTH 50

typedef struct {
    char title[MAX_APPOINTMENT_LENGTH];
    time_t start_time;
    time_t end_time;
} appointment;

void add_appointment(appointment* appointments, int num_appointments, char* title, time_t start_time, time_t end_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, you have reached the maximum number of appointments.\n");
        return;
    }

    strncpy(appointments[num_appointments].title, title, MAX_APPOINTMENT_LENGTH);
    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].end_time = end_time;

    num_appointments++;
}

void print_appointments(appointment* appointments, int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s to %s\n", appointments[i].title, ctime(&appointments[i].start_time), ctime(&appointments[i].end_time));
    }
}

int main() {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    char input[100];
    while (1) {
        printf("Enter appointment title: ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        time_t start_time, end_time;
        printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", input);
        start_time = mktime(input);

        printf("Enter end time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", input);
        end_time = mktime(input);

        add_appointment(appointments, num_appointments, input, start_time, end_time);
    }

    printf("\nAppointments:\n");
    print_appointments(appointments, num_appointments);

    return 0;
}