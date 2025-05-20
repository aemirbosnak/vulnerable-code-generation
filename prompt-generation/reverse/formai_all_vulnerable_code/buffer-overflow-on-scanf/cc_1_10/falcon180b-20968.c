//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

struct appointment {
    char name[MAX_NAME_LENGTH];
    time_t start_time;
    time_t end_time;
};

void print_appointment(struct appointment* appt) {
    printf("Name: %s\n", appt->name);
    printf("Start Time: %s\n", ctime(&appt->start_time));
    printf("End Time: %s\n", ctime(&appt->end_time));
}

void add_appointment(struct appointment* appointments, int num_appointments, char* name, time_t start_time, time_t end_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Cannot add more than %d appointments.\n", MAX_APPOINTMENTS);
        return;
    }

    struct appointment new_appt;
    strncpy(new_appt.name, name, MAX_NAME_LENGTH);
    new_appt.start_time = start_time;
    new_appt.end_time = end_time;

    appointments[num_appointments] = new_appt;
    num_appointments++;
}

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    time_t current_time;
    time(&current_time);

    while (1) {
        printf("Current Time: %s\n", ctime(&current_time));

        int choice;
        printf("1. Add Appointment\n2. Print All Appointments\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            {
                char name[MAX_NAME_LENGTH];
                time_t start_time, end_time;

                printf("Enter Name: ");
                scanf("%s", name);

                printf("Enter Start Time (YYYY-MM-DD HH:MM:SS): ");
                scanf("%s", &start_time);

                printf("Enter End Time (YYYY-MM-DD HH:MM:SS): ");
                scanf("%s", &end_time);

                add_appointment(appointments, num_appointments, name, start_time, end_time);
                break;
            }
        case 2:
            {
                printf("Appointments:\n");
                for (int i = 0; i < num_appointments; i++) {
                    print_appointment(&appointments[i]);
                }
                break;
            }
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}