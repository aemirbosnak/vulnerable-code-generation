//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Ken Thompson
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

void add_appointment(struct appointment* appointments, int num_appointments) {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);

    time_t start_time;
    printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", appointments[num_appointments].start_time);

    time_t end_time;
    printf("Enter end time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", appointments[num_appointments].end_time);

    num_appointments++;
}

void print_appointments(struct appointment* appointments, int num_appointments) {
    printf("Name\tStart Time\tEnd Time\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s\t%s\t%s\n", appointments[i].name, appointments[i].start_time, appointments[i].end_time);
    }
}

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("1. Add appointment\n2. Print appointments\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment(appointments, num_appointments);
                break;
            case 2:
                print_appointments(appointments, num_appointments);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}