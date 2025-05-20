//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TIME_SLOTS 10
#define MAX_APPOINTMENT_LENGTH 2
#define MAX_APPOINTMENTS 100

typedef struct {
    char name[50];
    int start_time;
    int end_time;
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, no more appointments can be added.\n");
        return;
    }

    printf("Enter the name of the appointment: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter the start time (in 24-hour format): ");
    scanf("%d", &appointments[num_appointments].start_time);

    printf("Enter the end time (in 24-hour format): ");
    scanf("%d", &appointments[num_appointments].end_time);

    num_appointments++;
}

void display_appointments() {
    if (num_appointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    int i;
    for (i = 0; i < num_appointments; i++) {
        printf("%s: %02d:%02d - %02d:%02d\n", appointments[i].name, appointments[i].start_time / 100, appointments[i].start_time % 100, appointments[i].end_time / 100, appointments[i].end_time % 100);
    }
}

void schedule_appointments() {
    int i, j;
    for (i = 0; i < num_appointments; i++) {
        for (j = i + 1; j < num_appointments; j++) {
            if (appointments[i].start_time > appointments[j].start_time) {
                appointment temp = appointments[i];
                appointments[i] = appointments[j];
                appointments[j] = temp;
            }
        }
    }
}

int main() {
    int choice;

    do {
        printf("1. Add appointment\n");
        printf("2. Display appointments\n");
        printf("3. Schedule appointments\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                display_appointments();
                break;
            case 3:
                schedule_appointments();
                display_appointments();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}