//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_MESSAGE_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    time_t appointment_time;
} appointment;

void add_appointment(appointment* appointments, int num_appointments) {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter message: ");
    scanf("%s", appointments[num_appointments].message);

    time_t now = time(NULL);
    appointments[num_appointments].appointment_time = now + 60 * 60 * 24; // 1 day from now

    num_appointments++;
}

void display_appointments(appointment* appointments, int num_appointments) {
    printf("\nAppointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s: %s\n", appointments[i].name, appointments[i].message);
        printf("Appointment time: %s", ctime(&appointments[i].appointment_time));
    }
}

int main() {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("\nEnter 1 to add an appointment or 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            add_appointment(appointments, num_appointments);
        } else if (choice == 0) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    display_appointments(appointments, num_appointments);

    return 0;
}