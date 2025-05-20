//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_APPOINTMENT_LENGTH 50

struct appointment {
    char description[MAX_APPOINTMENT_LENGTH];
    time_t start_time;
    time_t end_time;
};

void print_appointment(struct appointment *appointment) {
    printf("Description: %s\n", appointment->description);
    printf("Start Time: %s\n", ctime(&appointment->start_time));
    printf("End Time: %s\n", ctime(&appointment->end_time));
    printf("\n");
}

void add_appointment(struct appointment *appointments, int num_appointments, char *description, time_t start_time, time_t end_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Cannot add more than %d appointments.\n", MAX_APPOINTMENTS);
        return;
    }

    appointments[num_appointments].description[0] = '\0';
    strncat(appointments[num_appointments].description, description, MAX_APPOINTMENT_LENGTH - 1);
    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].end_time = end_time;

    num_appointments++;
}

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    time_t current_time = time(NULL);

    add_appointment(appointments, num_appointments, "Meeting with Boss", current_time + 3600, current_time + 4200);
    add_appointment(appointments, num_appointments, "Lunch with Coworkers", current_time + 7200, current_time + 7500);

    printf("Today's Schedule:\n");

    for (int i = 0; i < num_appointments; i++) {
        print_appointment(&appointments[i]);
    }

    return 0;
}