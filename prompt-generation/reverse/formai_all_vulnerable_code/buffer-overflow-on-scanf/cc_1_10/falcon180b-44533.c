//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX_APPOINTMENTS 100
#define MINUTES_IN_HOUR 60

typedef struct {
    char name[50];
    int start_hour;
    int start_minute;
    int duration;
} appointment;

appointment schedule[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, schedule is full!\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", schedule[num_appointments].name);

    printf("Enter start time (HH:MM): ");
    scanf("%d:%d", &schedule[num_appointments].start_hour, &schedule[num_appointments].start_minute);

    printf("Enter duration (in minutes): ");
    scanf("%d", &schedule[num_appointments].duration);

    num_appointments++;
}

void display_schedule() {
    printf("\nSchedule:\n");
    printf("+---------------------------+\n");
    printf("| Time | Name | Duration |\n");
    printf("+---------------------------+\n");

    for (int i = 0; i < num_appointments; i++) {
        int start_time = (schedule[i].start_hour * MINUTES_IN_HOUR) + schedule[i].start_minute;
        int end_time = start_time + schedule[i].duration;

        if (end_time > MINUTES_IN_HOUR) {
            end_time -= MINUTES_IN_HOUR;
        }

        printf("| %02d:%02d | %s | %02d:%02d |\n", start_time / MINUTES_IN_HOUR, start_time % MINUTES_IN_HOUR, schedule[i].name, end_time / MINUTES_IN_HOUR, end_time % MINUTES_IN_HOUR);
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Happy Appointment Scheduler!\n");
    printf("Please enter your name: ");
    scanf("%s", schedule[0].name);

    while (TRUE) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an appointment\n");
        printf("2. Display schedule\n");
        printf("3. Quit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                display_schedule();
                break;
            case 3:
                printf("Goodbye, %s!\n", schedule[0].name);
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}