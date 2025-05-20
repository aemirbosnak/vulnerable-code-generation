//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: standalone
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

void add_appointment(appointment* appointments, int num_appointments) {
    printf("Enter name of appointment: ");
    scanf("%s", appointments[num_appointments].name);
    printf("Enter start time (format: HH:MM:SS): ");
    scanf("%s", appointments[num_appointments].start_time);
    printf("Enter end time (format: HH:MM:SS): ");
    scanf("%s", appointments[num_appointments].end_time);
}

void print_appointments(appointment* appointments, int num_appointments) {
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s to %s\n", appointments[i].name,
                ctime(&appointments[i].start_time),
                ctime(&appointments[i].end_time));
    }
}

int main() {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("1. Add appointment\n2. Print appointments\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_appointment(appointments, num_appointments);
            num_appointments++;
            break;
        case 2:
            print_appointments(appointments, num_appointments);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}