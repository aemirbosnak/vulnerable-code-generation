//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 50
#define MAX_NAME_LENGTH 50

struct appointment {
    char name[MAX_NAME_LENGTH];
    time_t start_time;
    time_t end_time;
};

void add_appointment(struct appointment* appointments, int num_appointments, char* name, time_t start_time, time_t end_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Maximum number of appointments reached.\n");
        return;
    }

    strncpy(appointments[num_appointments].name, name, MAX_NAME_LENGTH);
    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].end_time = end_time;

    num_appointments++;
}

void print_appointments(struct appointment* appointments, int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s to %s\n", appointments[i].name, ctime(&appointments[i].start_time), ctime(&appointments[i].end_time));
    }
}

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (1) {
        printf("1. Add appointment\n2. Print appointments\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[MAX_NAME_LENGTH];
                time_t start_time, end_time;

                printf("Enter name: ");
                scanf("%s", name);

                printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
                scanf("%s", ctime(&start_time));

                printf("Enter end time (YYYY-MM-DD HH:MM:SS): ");
                scanf("%s", ctime(&end_time));

                add_appointment(appointments, num_appointments, name, start_time, end_time);
                break;
            }
            case 2: {
                print_appointments(appointments, num_appointments);
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}