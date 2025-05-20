//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

struct appointment {
    char* name;
    char* date;
    char* time;
    int duration;
};

void schedule_appointment(struct appointment* appointments, int num_appointments) {
    int i;
    char buffer[50];

    for (i = 0; i < num_appointments; i++) {
        printf("Enter the name of the appointment: ");
        fgets(buffer, sizeof(buffer), stdin);
        appointments[i].name = strdup(buffer);

        printf("Enter the date of the appointment (YYYY-MM-DD): ");
        fgets(buffer, sizeof(buffer), stdin);
        appointments[i].date = strdup(buffer);

        printf("Enter the time of the appointment (HH:MM AM/PM): ");
        fgets(buffer, sizeof(buffer), stdin);
        appointments[i].time = strdup(buffer);

        printf("Enter the duration of the appointment (in minutes): ");
        scanf("%d", &appointments[i].duration);
    }
}

void print_appointments(struct appointment* appointments, int num_appointments) {
    int i;
    char buffer[50];

    for (i = 0; i < num_appointments; i++) {
        printf("Name: %s\nDate: %s\nTime: %s\nDuration: %d minutes\n\n",
               appointments[i].name, appointments[i].date,
               appointments[i].time, appointments[i].duration);
    }
}

int main() {
    int num_appointments;
    struct appointment appointments[10];

    printf("Enter the number of appointments to schedule: ");
    scanf("%d", &num_appointments);

    if (num_appointments < 1 || num_appointments > 10) {
        printf("Invalid number of appointments.\n");
        return 1;
    }

    schedule_appointment(appointments, num_appointments);

    print_appointments(appointments, num_appointments);

    return 0;
}