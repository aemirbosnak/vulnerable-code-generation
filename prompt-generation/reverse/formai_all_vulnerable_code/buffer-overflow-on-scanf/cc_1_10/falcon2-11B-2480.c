//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

typedef struct appointment {
    char name[50];
    char description[100];
    int start_time;
    int end_time;
} Appointment;

typedef struct appointment_list {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments;
} AppointmentList;

int main() {
    AppointmentList appointments;
    appointments.num_appointments = 0;

    // Add appointments to the list
    printf("Add appointments:\n");
    while (1) {
        char name[50];
        char description[100];
        int start_time, end_time;

        printf("Enter appointment name: ");
        fgets(name, sizeof(name), stdin);
        printf("Enter appointment description: ");
        fgets(description, sizeof(description), stdin);
        printf("Enter start time: ");
        scanf("%d", &start_time);
        printf("Enter end time: ");
        scanf("%d", &end_time);

        if (appointments.num_appointments >= MAX_APPOINTMENTS) {
            printf("Appointment list is full.\n");
            break;
        }

        Appointment new_appointment = {
           .name = name,
           .description = description,
           .start_time = start_time,
           .end_time = end_time,
        };

        appointments.appointments[appointments.num_appointments] = new_appointment;
        appointments.num_appointments++;

        printf("\n");
    }

    // Print the appointment list
    printf("Appointment list:\n");
    for (int i = 0; i < appointments.num_appointments; i++) {
        printf("Name: %s\n", appointments.appointments[i].name);
        printf("Description: %s\n", appointments.appointments[i].description);
        printf("Start time: %d\n", appointments.appointments[i].start_time);
        printf("End time: %d\n", appointments.appointments[i].end_time);
        printf("\n");
    }

    // Remove appointments from the list
    printf("Remove appointments:\n");
    while (1) {
        int index;

        printf("Enter index of appointment to remove: ");
        scanf("%d", &index);

        if (index < 0 || index >= appointments.num_appointments) {
            printf("Invalid index.\n");
        } else {
            appointments.num_appointments--;
            for (int i = index; i < appointments.num_appointments; i++) {
                appointments.appointments[i] = appointments.appointments[i + 1];
            }
        }

        printf("\n");
    }

    return 0;
}