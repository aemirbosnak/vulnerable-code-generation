//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    time_t start_time;
    time_t end_time;
} appointment;

void add_appointment(appointment *appointments, int num_appointments, char *name, time_t start_time, time_t end_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Cannot add more than %d appointments.\n", MAX_APPOINTMENTS);
        return;
    }

    strcpy(appointments[num_appointments].name, name);
    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].end_time = end_time;

    num_appointments++;
}

void print_appointments(appointment *appointments, int num_appointments) {
    printf("Appointments:\n");

    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s to %s\n", appointments[i].name, ctime(&appointments[i].start_time), ctime(&appointments[i].end_time));
    }
}

int main() {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    char name[MAX_NAME_LENGTH];
    time_t start_time, end_time;

    while (1) {
        printf("\nOptions:\n1. Add appointment\n2. Print appointments\n3. Exit\n");
        scanf("%d", &num_appointments);

        switch (num_appointments) {
        case 1:
            printf("Enter name: ");
            scanf("%s", name);

            printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
            scanf("%s", ctime(&start_time));

            printf("Enter end time (YYYY-MM-DD HH:MM:SS): ");
            scanf("%s", ctime(&end_time));

            add_appointment(appointments, num_appointments, name, start_time, end_time);
            break;

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