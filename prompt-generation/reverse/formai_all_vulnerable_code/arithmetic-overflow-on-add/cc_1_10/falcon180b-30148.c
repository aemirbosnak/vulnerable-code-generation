//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    time_t start_time;
    time_t end_time;
} appointment;

void add_appointment(appointment *schedule, int num_appointments, char *name, char *description, time_t start_time, time_t end_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Schedule is full.\n");
        return;
    }

    strncpy(schedule[num_appointments].name, name, MAX_NAME_LENGTH);
    strncpy(schedule[num_appointments].description, description, MAX_DESCRIPTION_LENGTH);
    schedule[num_appointments].start_time = start_time;
    schedule[num_appointments].end_time = end_time;

    num_appointments++;
}

void display_schedule(appointment *schedule, int num_appointments) {
    printf("Schedule:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s\n", schedule[i].name, schedule[i].description);
        printf("Start time: %s\n", ctime(&schedule[i].start_time));
        printf("End time: %s\n\n", ctime(&schedule[i].end_time));
    }
}

int main() {
    appointment schedule[MAX_APPOINTMENTS];
    int num_appointments = 0;

    add_appointment(schedule, num_appointments, "Meeting", "Discuss project timeline", time(NULL) + (60*60*2), time(NULL) + (60*60*3));
    add_appointment(schedule, num_appointments, "Lunch", "Grab a bite with colleagues", time(NULL) + (60*60*5), time(NULL) + (60*60*6));
    add_appointment(schedule, num_appointments, "Deadline", "Submit final report", time(NULL) + (60*60*24*3), time(NULL) + (60*60*24*3));

    display_schedule(schedule, num_appointments);

    return 0;
}