//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

// Structure for appointment details
typedef struct {
    char name[50];
    char service[50];
    time_t appointment_time;
    int duration;
} Appointment;

// Function to compare appointment times
int compare_appointment_times(const void *a, const void *b) {
    const Appointment *appointment_a = (const Appointment *)a;
    const Appointment *appointment_b = (const Appointment *)b;

    if (appointment_a->appointment_time < appointment_b->appointment_time) {
        return -1;
    } else if (appointment_a->appointment_time > appointment_b->appointment_time) {
        return 1;
    } else {
        return 0;
    }
}

// Function to print appointment details
void print_appointment(Appointment appointment) {
    printf("Name: %s\n", appointment.name);
    printf("Service: %s\n", appointment.service);
    printf("Appointment Time: %s\n", ctime(&appointment.appointment_time));
    printf("Duration: %d minutes\n\n", appointment.duration);
}

// Function to schedule appointments
void schedule_appointments() {
    int choice;
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("\n*** Schedule an Appointment ***\n");
        printf("1. New Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", appointments[num_appointments].name);
            printf("Enter service: ");
            scanf("%s", appointments[num_appointments].service);
            printf("Enter appointment time (YYYY-MM-DD HH:MM:SS): ");
            scanf("%s", appointments[num_appointments].appointment_time);
            printf("Enter duration in minutes: ");
            scanf("%d", &appointments[num_appointments].duration);
            num_appointments++;
            break;

        case 2:
            qsort(appointments, num_appointments, sizeof(Appointment), compare_appointment_times);
            for (int i = 0; i < num_appointments; i++) {
                print_appointment(appointments[i]);
            }
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }
}

int main() {
    srand(time(NULL));

    schedule_appointments();

    return 0;
}