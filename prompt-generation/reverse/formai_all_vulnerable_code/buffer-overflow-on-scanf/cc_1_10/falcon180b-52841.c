//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 20
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    time_t appointment_time;
    char *appointment_description;
} appointment;

void print_appointment(appointment *a) {
    printf("Name: %s\n", a->name);
    printf("Phone number: %s\n", a->phone_number);
    printf("Email: %s\n", a->email);
    printf("Appointment time: %s\n", ctime(&a->appointment_time));
    printf("Appointment description: %s\n\n", a->appointment_description);
}

int main() {
    int num_appointments = 0;
    appointment *appointments = malloc(MAX_APPOINTMENTS * sizeof(appointment));

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Enter the name of the person you want to schedule an appointment with (or press enter to stop):\n");
        scanf("%s", appointments[num_appointments].name);

        if (appointments[num_appointments].name[0] == '\0') {
            break;
        }

        printf("Enter the phone number of %s:\n", appointments[num_appointments].name);
        scanf("%s", appointments[num_appointments].phone_number);

        printf("Enter the email of %s:\n", appointments[num_appointments].name);
        scanf("%s", appointments[num_appointments].email);

        printf("Enter the appointment time (YYYY-MM-DD HH:MM:SS):\n");
        scanf("%s", appointments[num_appointments].appointment_description);

        appointments[num_appointments].appointment_time = strptime(appointments[num_appointments].appointment_description, "%Y-%m-%d %H:%M:%S");
        num_appointments++;
    }

    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        print_appointment(&appointments[i]);
    }

    free(appointments);
    return 0;
}