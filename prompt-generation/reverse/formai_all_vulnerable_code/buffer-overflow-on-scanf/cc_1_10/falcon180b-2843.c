//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    time_t date;
    time_t duration;
} Appointment;

void add_appointment(Appointment* appointments, int num_appointments, char* name, time_t date, time_t duration) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Cannot add more appointments. Max limit reached.\n");
        return;
    }

    strncpy(appointments[num_appointments].name, name, MAX_NAME_LENGTH);
    appointments[num_appointments].date = date;
    appointments[num_appointments].duration = duration;
    num_appointments++;
}

void print_appointments(Appointment* appointments, int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s (Duration: %ld seconds)\n", appointments[i].name, ctime(&appointments[i].date), appointments[i].duration);
    }
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (1) {
        printf("\n1. Add appointment\n2. Print appointments\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            char name[MAX_NAME_LENGTH];
            time_t date;
            time_t duration;

            printf("Enter name: ");
            scanf("%s", name);

            printf("Enter date (YYYY-MM-DD HH:MM:SS): ");
            scanf("%s", ctime(&date));

            printf("Enter duration (in seconds): ");
            scanf("%ld", &duration);

            add_appointment(appointments, num_appointments, name, date, duration);
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