//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

struct appointment {
    char name[50];
    time_t start_time;
    time_t end_time;
};

void add_appointment(struct appointment *appointments, int num_appointments, char *name, time_t start_time, time_t end_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, no more appointments can be added.\n");
        return;
    }

    strcpy(appointments[num_appointments].name, name);
    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].end_time = end_time;

    num_appointments++;
}

void display_appointments(struct appointment *appointments, int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s to %s\n", appointments[i].name, ctime(&appointments[i].start_time), ctime(&appointments[i].end_time));
    }
}

void delete_appointment(struct appointment *appointments, int num_appointments, char *name) {
    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            for (int j = i; j < num_appointments - 1; j++) {
                strcpy(appointments[j].name, appointments[j + 1].name);
                appointments[j].start_time = appointments[j + 1].start_time;
                appointments[j].end_time = appointments[j + 1].end_time;
            }

            num_appointments--;
            break;
        }
    }
}

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    add_appointment(appointments, num_appointments, "John Doe", time(NULL) + 3600, time(NULL) + 7200);
    add_appointment(appointments, num_appointments, "Jane Doe", time(NULL) + 1800, time(NULL) + 3600);

    display_appointments(appointments, num_appointments);

    delete_appointment(appointments, num_appointments, "John Doe");

    display_appointments(appointments, num_appointments);

    return 0;
}