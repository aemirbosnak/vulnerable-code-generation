//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    time_t start_time;
    time_t end_time;
    int duration;
} appointment;

void add_appointment(appointment* appointments, int num_appointments) {
    char name[MAX_NAME_LENGTH];
    int duration;

    printf("Enter the name of the person: ");
    scanf("%s", name);

    printf("Enter the duration of the appointment (in minutes): ");
    scanf("%d", &duration);

    time_t start_time = time(NULL) + (60 * duration);

    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, no more appointments can be added.\n");
        return;
    }

    strcpy(appointments[num_appointments].name, name);
    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].end_time = start_time + (60 * duration);
    appointments[num_appointments].duration = duration;

    num_appointments++;
}

void display_appointments(appointment* appointments, int num_appointments) {
    printf("Appointments:\n");
    printf("------------------\n");

    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s to %s (Duration: %d minutes)\n", appointments[i].name, ctime(&appointments[i].start_time), ctime(&appointments[i].end_time), appointments[i].duration);
    }
}

int main() {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (1) {
        printf("\n1. Add appointment\n2. Display appointments\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment(appointments, num_appointments);
                break;
            case 2:
                display_appointments(appointments, num_appointments);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}