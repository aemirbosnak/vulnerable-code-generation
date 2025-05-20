//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MIN_APPOINTMENT_LENGTH 15
#define MAX_APPOINTMENT_LENGTH 120

typedef struct {
    char name[50];
    int start_time;
    int end_time;
} appointment;

void add_appointment(appointment* list, int num_appointments) {
    printf("Enter name of appointment: ");
    scanf("%s", list[num_appointments].name);

    int start_hour, start_minute;
    printf("Enter start time (HH:MM): ");
    if (sscanf(list[num_appointments].name, "%d:%d", &start_hour, &start_minute)!= 2) {
        printf("Invalid time format. Use HH:MM.\n");
        exit(1);
    }
    list[num_appointments].start_time = start_hour * 60 + start_minute;

    int end_hour, end_minute;
    printf("Enter end time (HH:MM): ");
    if (sscanf(list[num_appointments].name, "%d:%d", &end_hour, &end_minute)!= 2) {
        printf("Invalid time format. Use HH:MM.\n");
        exit(1);
    }
    list[num_appointments].end_time = end_hour * 60 + end_minute;
}

void print_appointments(appointment* list, int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s (%d-%d)\n", list[i].name, list[i].start_time / 60, list[i].end_time / 60);
    }
}

int main() {
    appointment list[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Enter 1 to add an appointment or 0 to quit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            add_appointment(list, num_appointments);
            num_appointments++;
        } else if (choice!= 0) {
            printf("Invalid choice.\n");
        }
    }

    print_appointments(list, num_appointments);

    return 0;
}