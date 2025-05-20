//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DURATION 1440 // 24 hours in minutes

typedef struct {
    char name[MAX_NAME_LENGTH];
    int start_time;
    int duration;
} appointment;

void add_appointment(appointment *schedule, int index) {
    printf("Enter name of appointment: ");
    scanf("%s", schedule[index].name);

    printf("Enter start time (in minutes since midnight): ");
    scanf("%d", &schedule[index].start_time);

    printf("Enter duration (in minutes): ");
    scanf("%d", &schedule[index].duration);
}

void print_appointment(appointment appointment) {
    printf("%s: %d - %d\n", appointment.name, appointment.start_time, appointment.start_time + appointment.duration);
}

void print_schedule(appointment *schedule, int num_appointments) {
    printf("Schedule:\n");
    for (int i = 0; i < num_appointments; i++) {
        print_appointment(schedule[i]);
    }
}

int main() {
    appointment schedule[MAX_APPOINTMENTS];
    int num_appointments = 0;

    printf("Welcome to the appointment scheduler!\n");

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Current number of appointments: %d\n", num_appointments);
        printf("1. Add appointment\n");
        printf("2. Print schedule\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_appointments >= MAX_APPOINTMENTS) {
                printf("Cannot add more appointments.\n");
            } else {
                printf("Enter index for new appointment (0-%d): ", num_appointments);
                scanf("%d", &num_appointments);
                add_appointment(schedule, num_appointments);
            }
            break;

        case 2:
            print_schedule(schedule, num_appointments);
            break;

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}