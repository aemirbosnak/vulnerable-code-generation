//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MIN_APPOINTMENT_DURATION 15 // in minutes
#define MAX_APPOINTMENT_DURATION 120 // in minutes

typedef struct {
    char name[MAX_NAME_LENGTH];
    time_t start_time;
    int duration;
} Appointment;

int main() {
    int num_appointments = 0;
    Appointment appointments[MAX_APPOINTMENTS];
    char input[MAX_NAME_LENGTH];
    time_t current_time, start_time, end_time;

    srand(time(NULL));

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Enter name for appointment (or leave blank to finish):\n");
        scanf("%s", input);

        if (input[0] == '\0') {
            break;
        }

        strcpy(appointments[num_appointments].name, input);
        appointments[num_appointments].duration = rand() % (MAX_APPOINTMENT_DURATION - MIN_APPOINTMENT_DURATION + 1) + MIN_APPOINTMENT_DURATION;

        current_time = time(NULL);
        start_time = current_time + appointments[num_appointments].duration * 60;
        end_time = start_time + appointments[num_appointments].duration * 60;

        if (end_time > current_time) {
            appointments[num_appointments].start_time = start_time;
            num_appointments++;
        } else {
            printf("Appointment cannot be scheduled for the past.\n");
        }
    }

    printf("Appointments:\n");

    for (int i = 0; i < num_appointments; i++) {
        printf("%s: %s - %s\n", appointments[i].name, ctime(&appointments[i].start_time), ctime(&appointments[i].start_time + appointments[i].duration * 60));
    }

    return 0;
}