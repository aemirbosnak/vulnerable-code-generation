//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MINUTES_IN_HOUR 60
#define HOURS_IN_DAY 24
#define DAYS_IN_WEEK 7

struct appointment {
    char *name;
    time_t start_time;
    int duration;
};

void add_appointment(struct appointment *appointments, int num_appointments, char *name, time_t start_time, int duration) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, no more appointments available.\n");
        return;
    }

    struct appointment new_appointment = {
       .name = name,
       .start_time = start_time,
       .duration = duration
    };

    appointments[num_appointments] = new_appointment;
    num_appointments++;
}

void display_appointments(struct appointment *appointments, int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        struct appointment appointment = appointments[i];
        printf("%s - %s to %s (%d minutes)\n", appointment.name, ctime(&appointment.start_time), ctime(&appointment.start_time + appointment.duration * 60), appointment.duration);
    }
}

int main() {
    srand(time(NULL));

    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        int duration = rand() % 60 + 1;
        time_t start_time = time(NULL) + rand() % (HOURS_IN_DAY * MINUTES_IN_HOUR);
        char *name = malloc(20);
        sprintf(name, "Appointment %d", num_appointments + 1);

        add_appointment(appointments, num_appointments, name, start_time, duration);
    }

    display_appointments(appointments, num_appointments);

    return 0;
}