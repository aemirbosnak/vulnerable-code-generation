//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the structure for an appointment
typedef struct Appointment {
    char title[100];
    int start_time;
    int end_time;
} Appointment;

// Function to add an appointment to the scheduler
void addAppointment(Appointment *schedule, int capacity, int *num_appointments, char *title, int start_time, int end_time);

// Function to print the schedule
void printSchedule(Appointment *schedule, int num_appointments);

int main() {
    const int MAX_APPOINTMENTS = 10;
    Appointment schedule[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (1) {
        printf("1. Add Appointment\n");
        printf("2. Print Schedule\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                char title[100];
                int start_time, end_time;
                printf("Enter appointment title: ");
                scanf("%s", title);
                printf("Enter start time: ");
                scanf("%d", &start_time);
                printf("Enter end time: ");
                scanf("%d", &end_time);
                addAppointment(schedule, MAX_APPOINTMENTS, &num_appointments, title, start_time, end_time);
                break;
            }
            case 2: {
                printSchedule(schedule, num_appointments);
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                printf("Invalid choice!\n");
            }
        }
    }

    return 0;
}

void addAppointment(Appointment *schedule, int capacity, int *num_appointments, char *title, int start_time, int end_time) {
    if (*num_appointments < capacity) {
        strcpy(schedule[*num_appointments].title, title);
        schedule[*num_appointments].start_time = start_time;
        schedule[*num_appointments].end_time = end_time;
        (*num_appointments)++;
    } else {
        printf("Schedule is full!\n");
    }
}

void printSchedule(Appointment *schedule, int num_appointments) {
    for (int i = 0; i < num_appointments; i++) {
        printf("%s (%d-%d)\n", schedule[i].title, schedule[i].start_time, schedule[i].end_time);
    }
}