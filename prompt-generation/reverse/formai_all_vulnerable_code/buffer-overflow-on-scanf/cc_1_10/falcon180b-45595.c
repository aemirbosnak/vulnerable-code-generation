//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char name[50];
    time_t start_time;
    time_t end_time;
    char description[100];
} appointment;

void add_appointment(appointment* appointments, int* num_appointments) {
    appointment new_appointment;
    printf("Enter name: ");
    scanf("%s", new_appointment.name);
    printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", new_appointment.description);
    strptime(new_appointment.description, "%Y-%m-%d %H:%M:%S", &new_appointment.start_time);
    printf("Enter end time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", new_appointment.description);
    strptime(new_appointment.description, "%Y-%m-%d %H:%M:%S", &new_appointment.end_time);
    appointments[*num_appointments] = new_appointment;
    (*num_appointments)++;
}

void print_appointments(appointment* appointments, int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s %s - %s\n", appointments[i].name, ctime(&appointments[i].start_time), ctime(&appointments[i].end_time));
    }
}

int main() {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        char choice;
        printf("A - Add appointment\nB - Print appointments\nC - Quit\n");
        scanf(" %c", &choice);
        switch (choice) {
            case 'A':
                add_appointment(appointments, &num_appointments);
                break;
            case 'B':
                print_appointments(appointments, num_appointments);
                break;
            case 'C':
                printf("Thank you for using the appointment scheduler!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}