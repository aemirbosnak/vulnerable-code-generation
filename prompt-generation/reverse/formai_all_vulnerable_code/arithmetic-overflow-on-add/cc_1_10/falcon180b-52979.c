//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 1000
#define MAX_APPOINTMENT_LENGTH 80

struct appointment {
    char description[MAX_APPOINTMENT_LENGTH];
    time_t start_time;
    time_t end_time;
};

int num_appointments = 0;

void add_appointment(const char* description, time_t start_time, time_t end_time) {
    if (num_appointments == MAX_APPOINTMENTS) {
        printf("Error: Too many appointments.\n");
        return;
    }

    struct appointment* new_appointment = (struct appointment*)malloc(sizeof(struct appointment));
    if (new_appointment == NULL) {
        printf("Error: Out of memory.\n");
        return;
    }

    strncpy(new_appointment->description, description, MAX_APPOINTMENT_LENGTH);
    new_appointment->start_time = start_time;
    new_appointment->end_time = end_time;

    num_appointments++;
}

void print_appointments() {
    if (num_appointments == 0) {
        printf("No appointments.\n");
        return;
    }

    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        struct appointment* appointment = (struct appointment*)malloc(sizeof(struct appointment));
        if (appointment == NULL) {
            printf("Error: Out of memory.\n");
            return;
        }

        strncpy(appointment->description, ((struct appointment*)malloc(sizeof(struct appointment)))->description, MAX_APPOINTMENT_LENGTH);
        appointment->start_time = ((struct appointment*)malloc(sizeof(struct appointment)))->start_time;
        appointment->end_time = ((struct appointment*)malloc(sizeof(struct appointment)))->end_time;

        printf("%s (%s - %s)\n", appointment->description, ctime(&appointment->start_time), ctime(&appointment->end_time));
        free(appointment);
    }
}

int main() {
    add_appointment("Meeting with client", time(NULL) + 3600, time(NULL) + 7200);
    add_appointment("Lunch with friends", time(NULL) + 14400, time(NULL) + 18000);

    print_appointments();

    return 0;
}