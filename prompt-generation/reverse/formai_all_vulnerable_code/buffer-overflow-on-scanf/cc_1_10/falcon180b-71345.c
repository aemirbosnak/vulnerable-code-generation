//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    time_t start_time;
    time_t end_time;
    int duration;
} appointment;

void print_appointment(appointment app) {
    printf("Name: %s\n", app.name);
    printf("Description: %s\n", app.description);
    printf("Start time: %s\n", ctime(&app.start_time));
    printf("End time: %s\n", ctime(&app.end_time));
    printf("Duration: %d minutes\n", app.duration);
    printf("\n");
}

int compare_start_time(const void *a, const void *b) {
    appointment *app1 = (appointment *)a;
    appointment *app2 = (appointment *)b;
    return difftime(app1->start_time, app2->start_time);
}

int compare_end_time(const void *a, const void *b) {
    appointment *app1 = (appointment *)a;
    appointment *app2 = (appointment *)b;
    return difftime(app1->end_time, app2->end_time);
}

int main() {
    int num_appointments, i;
    appointment appointments[MAX_APPOINTMENTS];
    char input[MAX_NAME_LENGTH + MAX_DESCRIPTION_LENGTH + 10];
    time_t current_time, start_time, end_time;

    printf("Welcome to the Brave C Appointment Scheduler!\n\n");

    time(&current_time);
    srand(current_time);

    printf("How many appointments would you like to schedule? ");
    scanf("%d", &num_appointments);

    for (i = 0; i < num_appointments; i++) {
        printf("Enter the name of appointment #%d: ", i+1);
        scanf("%s", appointments[i].name);
        printf("Enter the description of appointment #%d: ", i+1);
        scanf("%s", appointments[i].description);

        do {
            printf("Enter the start time (YYYY-MM-DD HH:MM:SS): ");
            scanf("%s", input);
            strptime(input, "%Y-%m-%d %H:%M:%S", &start_time);
        } while (start_time <= current_time);

        do {
            printf("Enter the end time (YYYY-MM-DD HH:MM:SS): ");
            scanf("%s", input);
            strptime(input, "%Y-%m-%d %H:%M:%S", &end_time);
        } while (end_time <= start_time);

        appointments[i].start_time = start_time;
        appointments[i].end_time = end_time;
        appointments[i].duration = difftime(end_time, start_time) / 60;
    }

    qsort(appointments, num_appointments, sizeof(appointment), compare_start_time);

    printf("\nAppointments sorted by start time:\n");
    for (i = 0; i < num_appointments; i++) {
        print_appointment(appointments[i]);
    }

    qsort(appointments, num_appointments, sizeof(appointment), compare_end_time);

    printf("\n\nAppointments sorted by end time:\n");
    for (i = 0; i < num_appointments; i++) {
        print_appointment(appointments[i]);
    }

    return 0;
}