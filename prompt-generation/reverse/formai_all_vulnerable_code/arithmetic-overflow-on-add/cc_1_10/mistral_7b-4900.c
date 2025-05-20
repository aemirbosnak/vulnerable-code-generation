//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 10
#define APPOINTMENT_LENGTH 60

typedef struct Appointment {
    char name[50];
    int start_time, end_time;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void print_menu() {
    printf("\n***** Peaceful Appointment Scheduler *****\n");
    printf("1. Add Appointment\n");
    printf("2. Remove Appointment\n");
    printf("3. List Appointments\n");
    printf("4. Exit\n");
}

void add_appointment(char *name, int start_time, int duration) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Maximum appointments reached.\n");
        return;
    }

    strcpy(appointments[num_appointments].name, name);
    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].end_time = start_time + duration;
    num_appointments++;
}

int check_conflict(int start_time, int duration) {
    for (int i = 0; i < num_appointments; i++) {
        if ((start_time < appointments[i].end_time && start_time + duration > appointments[i].start_time) ||
            (start_time > appointments[i].start_time && start_time < appointments[i].end_time)) {
            return 1;
        }
    }
    return 0;
}

void remove_appointment(int index) {
    if (index < 0 || index >= num_appointments) {
        printf("Invalid appointment index.\n");
        return;
    }

    num_appointments--;
}

void list_appointments() {
    for (int i = 0; i < num_appointments; i++) {
        printf("%d. %s: %d-%d\n", i+1, appointments[i].name, appointments[i].start_time, appointments[i].end_time);
    }
}

int main() {
    int choice, start_time, duration;
    char name[50];

    srand(time(NULL));

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter appointment name: ");
                scanf("%s", name);
                printf("Enter appointment start time (in minutes): ");
                scanf("%d", &start_time);
                printf("Enter appointment duration (in minutes): ");
                scanf("%d", &duration);

                if (check_conflict(start_time, duration)) {
                    printf("Conflicting appointment found. Try another time.\n");
                    continue;
                }

                add_appointment(name, start_time, duration);
                printf("Appointment added successfully.\n");
                break;

            case 2:
                printf("Enter appointment index to remove: ");
                scanf("%d", &choice);
                remove_appointment(choice-1);
                printf("Appointment removed successfully.\n");
                break;

            case 3:
                list_appointments();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}