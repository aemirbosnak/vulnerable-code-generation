//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_NUMBER_LENGTH];
    time_t appointment_time;
} appointment;

appointment *appointments = NULL;
int num_appointments = 0;

void add_appointment() {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_NUMBER_LENGTH];
    time_t appointment_time;

    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter phone number: ");
    scanf("%s", phone);
    printf("Enter appointment time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", &appointment_time);

    appointment *new_appointment = malloc(sizeof(appointment));
    strcpy(new_appointment->name, name);
    strcpy(new_appointment->phone, phone);
    new_appointment->appointment_time = appointment_time;

    appointments = realloc(appointments, sizeof(appointment) * ++num_appointments);
    appointments[num_appointments - 1] = *new_appointment;
    free(new_appointment);
}

void view_appointments() {
    time_t current_time = time(NULL);

    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        appointment *appointment = &appointments[i];
        struct tm *appointment_tm = localtime(&appointment->appointment_time);

        if (appointment->appointment_time > current_time) {
            printf("%s - %s - %s\n", appointment->name, appointment->phone, ctime(&appointment->appointment_time));
        }
    }
}

int main() {
    appointments = malloc(sizeof(appointment));
    num_appointments = 0;

    int choice;
    do {
        printf("1. Add appointment\n2. View appointments\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}