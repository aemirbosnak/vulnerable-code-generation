//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    int id;
    char name[50];
    int start_time;
    int end_time;
} Appointment;

Appointment schedule[MAX_APPOINTMENTS];
int num_appointments = 0;

void print_schedule() {
    printf("\n--- SCHEDULE ---\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("\nAppointment %d:\n", schedule[i].id);
        printf("Name: %s\n", schedule[i].name);
        printf("Start Time: %d\n", schedule[i].start_time);
        printf("End Time: %d\n", schedule[i].end_time);
    }
}

int find_next_available_slot(int start_time) {
    for (int i = 0; i < num_appointments; i++) {
        if (schedule[i].start_time > start_time && schedule[i].end_time >= start_time) {
            return -1;
        }
        if (schedule[i].end_time < start_time) {
            return start_time;
        }
    }
    return -1;
}

void add_appointment(char *name, int start_time, int end_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Schedule is full.\n");
        return;
    }
    schedule[num_appointments].id = num_appointments + 1;
    strcpy(schedule[num_appointments].name, name);
    schedule[num_appointments].start_time = start_time;
    schedule[num_appointments].end_time = end_time;
    num_appointments++;
}

int main() {
    int choice, start_time, end_time;
    char name[50];

    while (1) {
        printf("\n--- APPOINTMENT SCHEDULER ---\n");
        printf("1. Add Appointment\n");
        printf("2. Print Schedule\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Start Time (in minutes): ");
                scanf("%d", &start_time);
                printf("Enter End Time (in minutes): ");
                scanf("%d", &end_time);
                add_appointment(name, start_time, end_time);
                break;
            case 2:
                print_schedule();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}