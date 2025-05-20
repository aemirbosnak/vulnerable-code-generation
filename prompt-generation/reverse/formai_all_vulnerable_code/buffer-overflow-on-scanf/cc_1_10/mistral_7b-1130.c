//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPT 10
#define MAX_NAME_LEN 20
#define MAX_DURATION 60

typedef struct {
    char name[MAX_NAME_LEN];
    int start_time, duration;
} Appointment;

Appointment appointments[MAX_APPT];
int num_appts = 0;

void print_schedule() {
    int i, j;
    printf("\nSCHEDULE:\n");
    printf("-------------------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s | %-10s |\n", "NAME", "START TIME", "END TIME", "DURATION");
    printf("-------------------------------------------------------\n");
    for (i = 0; i < num_appts; i++) {
        printf("| %-20s | %-10d | %-10d | %-10d |\n", appointments[i].name, appointments[i].start_time,
               appointments[i].start_time + appointments[i].duration, appointments[i].duration);
    }
    printf("-------------------------------------------------------\n");
}

void add_appointment(char *name, int start_time, int duration) {
    if (num_appts >= MAX_APPT) {
        printf("Appointment calendar is full!\n");
        return;
    }
    strcpy(appointments[num_appts].name, name);
    appointments[num_appts].start_time = start_time;
    appointments[num_appts].duration = duration;
    num_appts++;
}

int main() {
    int choice, start_time, duration;
    char name[MAX_NAME_LEN];

    while (1) {
        printf("\nAppointment Scheduler\n");
        printf("1. Add Appointment\n");
        printf("2. Print Schedule\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your name: ");
                scanf("%s", name);
                printf("Enter start time (in minutes): ");
                scanf("%d", &start_time);
                printf("Enter duration (in minutes): ");
                scanf("%d", &duration);
                add_appointment(name, start_time, duration);
                break;
            case 2:
                print_schedule();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}