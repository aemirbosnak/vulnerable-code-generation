//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define APPOINTMENT_LENGTH 60

typedef struct {
    int id;
    char name[50];
    char description[100];
    int start_time;
    int end_time;
} Appointment;

typedef struct {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments;
} Schedule;

void print_schedule(Schedule schedule) {
    for (int i = 0; i < schedule.num_appointments; i++) {
        printf("%d. %s (%s) %d:00 - %d:%02d\n",
               schedule.appointments[i].id,
               schedule.appointments[i].name,
               schedule.appointments[i].description,
               schedule.appointments[i].start_time / 60,
               (schedule.appointments[i].end_time - schedule.appointments[i].start_time) / 60,
               (schedule.appointments[i].end_time - schedule.appointments[i].start_time) % 60);
    }
}

int add_appointment(Schedule *schedule, char *name, char *description, int start_time, int end_time) {
    if (schedule->num_appointments == MAX_APPOINTMENTS) {
        printf("Cannot add appointment, schedule is full.\n");
        return -1;
    }

    Appointment appointment = {
        .id = schedule->num_appointments + 1,
        .name = name,
        .description = description,
        .start_time = start_time,
        .end_time = end_time
    };

    schedule->appointments[schedule->num_appointments++] = appointment;

    return 0;
}

int main() {
    Schedule schedule = {0};

    int hour, minute;
    char name[50], description[100];

    while (1) {
        printf("\nSchedule:\n");
        print_schedule(schedule);

        printf("\nEnter appointment details:\nName: ");
        scanf("%s", name);
        fgets(description, sizeof(description), stdin);
        description[strcspn(description, "\n")] = 0;

        printf("\nEnter start time (hh:mm): ");
        scanf("%d:%d", &hour, &minute);
        int start_time = hour * 60 + minute;

        printf("\nEnter end time (hh:mm): ");
        scanf("%d:%d", &hour, &minute);
        int end_time = hour * 60 + minute;

        if (add_appointment(&schedule, name, description, start_time, end_time) == -1) {
            continue;
        }

        printf("\nAppointment added successfully.\n");
    }

    return 0;
}