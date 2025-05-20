//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPT 10
#define MAX_NAME 50
#define MAX_TIME 10

typedef struct {
    char name[MAX_NAME];
    int start_time;
    int end_time;
} Appointment;

Appointment schedule[MAX_APPT];
int num_appts = 0;

void print_schedule() {
    printf("\n----SCHEDULE----\n");
    for (int i = 0; i < num_appts; i++) {
        printf("%s: %d-%d\n", schedule[i].name, schedule[i].start_time, schedule[i].end_time);
    }
}

int add_appointment(char *name, int start, int end) {
    if (num_appts >= MAX_APPT) {
        printf("\nAppointment calendar is full!\n");
        return 0;
    }

    strcpy(schedule[num_appts].name, name);
    schedule[num_appts].start_time = start;
    schedule[num_appts].end_time = end;

    num_appts++;
    return 1;
}

int main() {
    char name[MAX_NAME];
    int start, end;
    time_t now;
    int choice;

    while (1) {
        printf("\n1. Add Appointment\n2. View Schedule\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter start time (HHMM): ");
                scanf("%d%d", &start, &start);
                printf("Enter end time (HHMM): ");
                scanf("%d%d", &end, &end);

                add_appointment(name, start * 60, end * 60);
                printf("Appointment added successfully!\n");
                break;

            case 2:
                print_schedule();
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
                break;
        }

        time(&now);
        printf("\nCurrent time: %s", ctime(&now));
    }

    return 0;
}