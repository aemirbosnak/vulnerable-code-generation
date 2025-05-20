//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_APPOINTMENT_LENGTH 100
#define HOURS_PER_DAY 24

struct appointment {
    char title[MAX_APPOINTMENT_LENGTH];
    time_t start_time;
    time_t end_time;
};

void add_appointment(struct appointment* appointments, int num_appointments, char* title, time_t start_time, time_t end_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Too many appointments.\n");
        return;
    }

    struct appointment new_appointment;
    strcpy(new_appointment.title, title);
    new_appointment.start_time = start_time;
    new_appointment.end_time = end_time;

    appointments[num_appointments] = new_appointment;
    num_appointments++;
}

void print_appointments(struct appointment* appointments, int num_appointments) {
    printf("\nAppointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s: %s - %s\n", appointments[i].title, ctime(&appointments[i].start_time), ctime(&appointments[i].end_time));
    }
}

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (1) {
        printf("\nOptions:\n1. Add appointment\n2. Print appointments\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            {
                char title[MAX_APPOINTMENT_LENGTH];
                printf("Enter appointment title: ");
                scanf("%s", title);

                time_t start_time, end_time;
                printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
                scanf("%s", ctime(&start_time));

                printf("Enter end time (YYYY-MM-DD HH:MM:SS): ");
                scanf("%s", ctime(&end_time));

                add_appointment(appointments, num_appointments, title, start_time, end_time);
                break;
            }
        case 2:
            print_appointments(appointments, num_appointments);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}