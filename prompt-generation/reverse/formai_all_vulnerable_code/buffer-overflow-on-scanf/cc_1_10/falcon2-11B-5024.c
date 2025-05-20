//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[100];
    int day, month, year;
    int time;
    int duration;
} Appointment;

Appointment appointments[100];
int num_appointments = 0;

void add_appointment(char* name, int day, int month, int year, int time, int duration) {
    Appointment new_appointment;
    strcpy(new_appointment.name, name);
    new_appointment.day = day;
    new_appointment.month = month;
    new_appointment.year = year;
    new_appointment.time = time;
    new_appointment.duration = duration;

    appointments[num_appointments] = new_appointment;
    num_appointments++;
}

void schedule_appointment(char* name, int day, int month, int year, int time, int duration) {
    add_appointment(name, day, month, year, time, duration);
    printf("Appointment '%s' scheduled for %d/%d/%d at %d for %d minutes\n", name, month, day, year, time, duration);
}

int main() {
    int choice;
    do {
        printf("1. Add an appointment\n");
        printf("2. List all appointments\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the appointment: ");
                fflush(stdin);
                fgets(appointments[num_appointments].name, sizeof(appointments[num_appointments].name), stdin);
                appointments[num_appointments].name[strcspn(appointments[num_appointments].name, "\n")] = '\0';

                printf("Enter the date (day/month/year): ");
                scanf("%d/%d/%d", &appointments[num_appointments].day, &appointments[num_appointments].month, &appointments[num_appointments].year);

                printf("Enter the time of the appointment (24-hour format): ");
                scanf("%d", &appointments[num_appointments].time);

                printf("Enter the duration of the appointment in minutes: ");
                scanf("%d", &appointments[num_appointments].duration);

                schedule_appointment(appointments[num_appointments].name, appointments[num_appointments].day, appointments[num_appointments].month, appointments[num_appointments].year, appointments[num_appointments].time, appointments[num_appointments].duration);
                break;

            case 2:
                printf("List of appointments:\n");
                for (int i = 0; i < num_appointments; i++) {
                    printf("Appointment %d: %s\n", i+1, appointments[i].name);
                    printf("Date: %d/%d/%d\n", appointments[i].day, appointments[i].month, appointments[i].year);
                    printf("Time: %d\n", appointments[i].time);
                    printf("Duration: %d minutes\n", appointments[i].duration);
                    printf("\n");
                }
                break;

            case 3:
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice!= 3);

    return 0;
}