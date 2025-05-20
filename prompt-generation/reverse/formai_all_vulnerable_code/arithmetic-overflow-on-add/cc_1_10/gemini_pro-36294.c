//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct appointment {
    time_t start_time;
    time_t end_time;
    char *description;
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment(time_t start_time, time_t end_time, char *description) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Too many appointments.\n");
        return;
    }

    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].end_time = end_time;
    appointments[num_appointments].description = description;
    num_appointments++;
}

void print_appointments() {
    for (int i = 0; i < num_appointments; i++) {
        printf("%s: %s - %s\n", appointments[i].description, ctime(&appointments[i].start_time), ctime(&appointments[i].end_time));
    }
}

void find_appointments(time_t start_time, time_t end_time) {
    for (int i = 0; i < num_appointments; i++) {
        if (appointments[i].start_time >= start_time && appointments[i].end_time <= end_time) {
            printf("%s: %s - %s\n", appointments[i].description, ctime(&appointments[i].start_time), ctime(&appointments[i].end_time));
        }
    }
}

void delete_appointment(time_t start_time) {
    for (int i = 0; i < num_appointments; i++) {
        if (appointments[i].start_time == start_time) {
            for (int j = i; j < num_appointments - 1; j++) {
                appointments[j] = appointments[j + 1];
            }
            num_appointments--;
            return;
        }
    }
}

int main() {
    // Add some sample appointments.
    add_appointment(time(NULL), time(NULL) + 3600, "Lunch with Bob");
    add_appointment(time(NULL) + 3600, time(NULL) + 7200, "Meeting with Alice");
    add_appointment(time(NULL) + 7200, time(NULL) + 10800, "Dinner with Carol");

    // Print the appointments.
    printf("Appointments:\n");
    print_appointments();

    // Find appointments between 2:00 PM and 3:00 PM.
    printf("\nAppointments between 2:00 PM and 3:00 PM:\n");
    find_appointments(time(NULL) + 7200, time(NULL) + 10800);

    // Delete the appointment with the start time of 2:00 PM.
    delete_appointment(time(NULL) + 7200);

    // Print the appointments again.
    printf("\nAppointments after deleting the 2:00 PM appointment:\n");
    print_appointments();

    return 0;
}