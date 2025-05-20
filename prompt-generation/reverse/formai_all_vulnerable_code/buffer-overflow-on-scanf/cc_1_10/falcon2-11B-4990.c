//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

typedef struct {
    char *start_time;
    char *duration;
    char *description;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment(char *start_time, char *duration, char *description) {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointments limit reached.\n");
        return;
    }
    appointments[appointment_count].start_time = strdup(start_time);
    appointments[appointment_count].duration = strdup(duration);
    appointments[appointment_count].description = strdup(description);
    appointment_count++;
}

void remove_appointment(int index) {
    if (index < 0 || index >= appointment_count) {
        printf("Invalid appointment index.\n");
        return;
    }
    free(appointments[index].start_time);
    free(appointments[index].duration);
    free(appointments[index].description);
    appointment_count--;
}

void display_appointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    printf("Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("  %s - %s (%s)\n", appointments[i].start_time, appointments[i].duration, appointments[i].description);
    }
}

int main() {
    char start_time[100];
    char duration[100];
    char description[100];

    printf("Enter start time (HH:MM AM/PM): ");
    scanf("%s", start_time);

    printf("Enter duration (HH:MM AM/PM): ");
    scanf("%s", duration);

    printf("Enter description: ");
    scanf("%s", description);

    add_appointment(start_time, duration, description);

    display_appointments();

    return 0;
}