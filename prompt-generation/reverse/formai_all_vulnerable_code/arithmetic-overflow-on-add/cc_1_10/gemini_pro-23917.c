//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char *name;
    char *description;
    time_t start_time;
    time_t end_time;
} appointment_t;

appointment_t *appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment(char *name, char *description, time_t start_time, time_t end_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Too many appointments.\n");
        return;
    }

    appointment_t *appointment = malloc(sizeof(appointment_t));
    if (appointment == NULL) {
        printf("Error: Out of memory.\n");
        return;
    }

    appointment->name = strdup(name);
    appointment->description = strdup(description);
    appointment->start_time = start_time;
    appointment->end_time = end_time;

    appointments[num_appointments++] = appointment;
}

void print_appointments() {
    for (int i = 0; i < num_appointments; i++) {
        printf("%s: %s\n", appointments[i]->name, appointments[i]->description);
        printf("Start time: %s\n", ctime(&appointments[i]->start_time));
        printf("End time: %s\n", ctime(&appointments[i]->end_time));
        printf("\n");
    }
}

void delete_appointment(char *name) {
    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i]->name, name) == 0) {
            free(appointments[i]->name);
            free(appointments[i]->description);
            free(appointments[i]);
            appointments[i] = appointments[num_appointments - 1];
            num_appointments--;
            return;
        }
    }

    printf("Error: Appointment not found.\n");
}

void clear_appointments() {
    for (int i = 0; i < num_appointments; i++) {
        free(appointments[i]->name);
        free(appointments[i]->description);
        free(appointments[i]);
    }

    num_appointments = 0;
}

int main() {
    add_appointment("Meeting with John", "Discuss project plans", time(NULL) + 3600, time(NULL) + 4800);
    add_appointment("Lunch with Mary", "Catch up and talk about work", time(NULL) + 7200, time(NULL) + 8400);
    add_appointment("Doctor's appointment", "Annual checkup", time(NULL) + 10800, time(NULL) + 12000);

    print_appointments();

    delete_appointment("Meeting with John");

    print_appointments();

    clear_appointments();

    return 0;
}