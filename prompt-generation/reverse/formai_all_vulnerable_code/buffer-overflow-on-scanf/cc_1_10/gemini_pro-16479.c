//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

struct Appointment {
    char name[50];
    char description[200];
    int start_time;
    int end_time;
};

struct Appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Maximum number of appointments reached.\n");
        return;
    }

    char name[50];
    char description[200];
    int start_time;
    int end_time;

    printf("Enter appointment name: ");
    scanf("%s", name);

    printf("Enter appointment description: ");
    scanf(" %[^\n]", description);  // Read the rest of the line

    printf("Enter appointment start time (hh:mm): ");
    scanf("%d:%d", &start_time, &start_time);

    printf("Enter appointment end time (hh:mm): ");
    scanf("%d:%d", &end_time, &end_time);

    strcpy(appointments[num_appointments].name, name);
    strcpy(appointments[num_appointments].description, description);
    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].end_time = end_time;

    num_appointments++;
}

void print_appointments() {
    if (num_appointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s: %s (%d:%02d - %d:%02d)\n", appointments[i].name,
               appointments[i].description, appointments[i].start_time / 100,
               appointments[i].start_time % 100, appointments[i].end_time / 100,
               appointments[i].end_time % 100);
    }
}

void main() {
    int choice;

    do {
        printf("\nAppointment Scheduler\n");
        printf("1. Add Appointment\n");
        printf("2. Print Appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_appointment();
            break;
        case 2:
            print_appointments();
            break;
        case 3:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 3.\n");
        }
    } while (choice != 3);
}