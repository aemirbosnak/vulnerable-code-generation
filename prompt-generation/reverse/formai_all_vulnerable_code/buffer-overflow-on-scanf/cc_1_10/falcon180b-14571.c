//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char name[50];
    int start_time;
    int end_time;
} appointment;

void add_appointment(appointment *appointments, int num_appointments) {
    printf("Enter the name of the person: ");
    scanf("%s", &appointments[num_appointments].name);

    printf("Enter the start time (HH:MM): ");
    scanf("%d:%d", &appointments[num_appointments].start_time);

    printf("Enter the end time (HH:MM): ");
    scanf("%d:%d", &appointments[num_appointments].end_time);

    num_appointments++;
}

void print_appointments(appointment *appointments, int num_appointments) {
    for (int i = 0; i < num_appointments; i++) {
        printf("Name: %s\n", appointments[i].name);
        printf("Start time: %02d:%02d\n", appointments[i].start_time / 60, appointments[i].start_time % 60);
        printf("End time: %02d:%02d\n\n", appointments[i].end_time / 60, appointments[i].end_time % 60);
    }
}

int main() {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Would you like to add an appointment? (y/n): ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'y' || choice == 'Y') {
            add_appointment(appointments, num_appointments);
        } else if (choice!= 'n' && choice!= 'N') {
            printf("Invalid choice. Please try again.\n");
        }
    }

    printf("Appointments:\n");
    print_appointments(appointments, num_appointments);

    return 0;
}