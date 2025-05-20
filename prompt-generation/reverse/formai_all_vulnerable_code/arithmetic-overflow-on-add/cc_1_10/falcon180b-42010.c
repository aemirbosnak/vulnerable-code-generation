//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
    time_t start_time;
    time_t end_time;
} appointment;

void add_appointment(appointment *appointments, int num_appointments, char *name, int id, time_t start_time, time_t end_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, schedule is full!\n");
        return;
    }

    strcpy(appointments[num_appointments].name, name);
    appointments[num_appointments].id = id;
    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].end_time = end_time;

    num_appointments++;
}

void display_schedule(appointment *appointments, int num_appointments) {
    if (num_appointments == 0) {
        printf("Schedule is empty.\n");
        return;
    }

    printf("Schedule:\n");
    for (int i = 0; i < num_appointments; i++) {
        time_t now = time(NULL);
        if (appointments[i].start_time > now) {
            printf("%s - %d - ", appointments[i].name, appointments[i].id);
            printf("Starting in %ld seconds\n", (appointments[i].start_time - now));
        } else if (appointments[i].end_time > now) {
            printf("%s - %d - ", appointments[i].name, appointments[i].id);
            printf("Currently in progress\n");
        } else {
            printf("%s - %d - ", appointments[i].name, appointments[i].id);
            printf("Ended at %s", ctime(&appointments[i].end_time));
        }
    }
}

int main() {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    add_appointment(appointments, num_appointments, "Breakfast", 1, time(NULL), time(NULL) + 3600);
    add_appointment(appointments, num_appointments, "Lunch", 2, time(NULL) + 3600, time(NULL) + 7200);
    add_appointment(appointments, num_appointments, "Dinner", 3, time(NULL) + 7200, time(NULL) + 10800);

    while (1) {
        display_schedule(appointments, num_appointments);
        sleep(60);
    }

    return 0;
}