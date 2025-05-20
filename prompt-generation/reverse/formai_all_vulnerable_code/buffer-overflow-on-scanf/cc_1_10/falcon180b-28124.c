//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    time_t start_time;
    time_t end_time;
} Appointment;

void add_appointment(Appointment* appointments, int num_appointments) {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    time_t start_time, end_time;

    printf("Enter name of appointment: ");
    scanf("%s", name);

    printf("Enter description of appointment: ");
    scanf("%s", description);

    printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", &start_time);

    printf("Enter end time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", &end_time);

    appointments[num_appointments].name[0] = '\0';
    strncpy(appointments[num_appointments].name, name, MAX_NAME_LENGTH - 1);
    appointments[num_appointments].description[0] = '\0';
    strncpy(appointments[num_appointments].description, description, MAX_DESCRIPTION_LENGTH - 1);
    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].end_time = end_time;

    num_appointments++;
}

void display_appointments(Appointment* appointments, int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("Name: %s\n", appointments[i].name);
        printf("Description: %s\n", appointments[i].description);
        printf("Start time: %s\n", ctime(&appointments[i].start_time));
        printf("End time: %s\n\n", ctime(&appointments[i].end_time));
    }
}

void delete_appointment(Appointment* appointments, int num_appointments) {
    int index;

    printf("Enter index of appointment to delete: ");
    scanf("%d", &index);

    if (index >= 0 && index < num_appointments) {
        num_appointments--;
        for (int i = index; i < num_appointments; i++) {
            appointments[i] = appointments[i+1];
        }
    } else {
        printf("Invalid index.\n");
    }
}

int main(void) {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (true) {
        printf("\nAppointment Scheduler\n");
        printf("1. Add appointment\n");
        printf("2. Display appointments\n");
        printf("3. Delete appointment\n");
        printf("4. Exit\n");

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
            delete_appointment(appointments, num_appointments);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}