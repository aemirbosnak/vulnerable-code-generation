//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_MESSAGE_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    time_t appointment_time;
} appointment_t;

int num_appointments = 0;
appointment_t appointments[MAX_APPOINTMENTS];

void add_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, no more appointments available.\n");
        return;
    }

    appointment_t new_appointment;
    printf("Enter your name: ");
    scanf("%s", new_appointment.name);

    printf("Enter your message: ");
    scanf("%s", new_appointment.message);

    time_t now = time(NULL);
    new_appointment.appointment_time = now + 60 * 60 * 24; // 24 hours from now

    appointments[num_appointments] = new_appointment;
    num_appointments++;

    printf("Appointment added successfully.\n");
}

void list_appointments() {
    if (num_appointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    for (int i = 0; i < num_appointments; i++) {
        struct tm* appointment_time_struct = localtime(&appointments[i].appointment_time);

        char appointment_time_str[20];
        strftime(appointment_time_str, sizeof(appointment_time_str), "%Y-%m-%d %H:%M:%S", appointment_time_struct);

        printf("%s - %s (%s)\n", appointments[i].name, appointments[i].message, appointment_time_str);
    }
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("1. Add appointment\n2. List appointments\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                list_appointments();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}