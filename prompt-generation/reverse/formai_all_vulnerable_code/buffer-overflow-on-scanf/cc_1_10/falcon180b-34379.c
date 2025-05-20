//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

struct appointment {
    char name[50];
    time_t start_time;
    time_t end_time;
    int duration;
};

void add_appointment(struct appointment *appointments, int num_appointments) {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);
    printf("Enter start time (HH:MM:SS): ");
    scanf("%s", appointments[num_appointments].start_time);
    printf("Enter end time (HH:MM:SS): ");
    scanf("%s", appointments[num_appointments].end_time);
    appointments[num_appointments].duration = difftime(mktime(appointments[num_appointments].end_time), mktime(appointments[num_appointments].start_time));
    num_appointments++;
}

void print_appointments(struct appointment *appointments, int num_appointments) {
    printf("\nAppointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s: %s - %s (%d minutes)\n", appointments[i].name, ctime(&appointments[i].start_time), ctime(&appointments[i].end_time), appointments[i].duration);
    }
}

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("\nAdd an appointment? (y/n): ");
        char choice;
        scanf("%c", &choice);
        if (choice == 'y' || choice == 'Y') {
            add_appointment(appointments, num_appointments);
        } else {
            break;
        }
    }

    printf("\nAppointments:\n");
    print_appointments(appointments, num_appointments);

    return 0;
}