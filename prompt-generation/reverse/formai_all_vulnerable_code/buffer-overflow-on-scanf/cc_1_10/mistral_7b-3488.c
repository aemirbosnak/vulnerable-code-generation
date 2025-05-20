//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 10
#define APPOINTMENT_LENGTH 60

typedef struct Appointment {
    char name[50];
    int start_time;
    int end_time;
} Appointment;

Appointment schedule[MAX_APPOINTMENTS];
int num_appointments = 0;

void print_schedule() {
    printf("\nCurrent Schedule:\n");
    printf("------------------\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s: %d:%02d - %d:%02d\n", schedule[i].name,
               schedule[i].start_time / 60, schedule[i].start_time % 60,
               schedule[i].end_time / 60, schedule[i].end_time % 60);
    }
}

int schedule_appointment(char *name, int start_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Maximum number of appointments reached.\n");
        return -1;
    }

    if (start_time % APPOINTMENT_LENGTH != 0) {
        printf("Error: Appointment must be in multiples of %d minutes.\n", APPOINTMENT_LENGTH);
        return -1;
    }

    int end_time = start_time + APPOINTMENT_LENGTH;

    for (int i = 0; i < num_appointments; i++) {
        if (schedule[i].start_time <= end_time && schedule[i].end_time >= start_time) {
            printf("Error: Conflicting appointment for %s.\n", name);
            return -1;
        }
    }

    strcpy(schedule[num_appointments].name, name);
    schedule[num_appointments].start_time = start_time;
    schedule[num_appointments].end_time = end_time;
    num_appointments++;

    printf("Appointment scheduled for %s.\n", name);
    return 0;
}

int main() {
    int choice;
    char name[50];
    int start_time;

    while (1) {
        print_schedule();
        printf("\nWhat would you like to do?\n");
        printf("1. Schedule an appointment\n");
        printf("2. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your name: ");
                scanf("%s", name);
                printf("Enter the start time (in minutes): ");
                scanf("%d", &start_time);
                schedule_appointment(name, start_time);
                break;
            case 2:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}