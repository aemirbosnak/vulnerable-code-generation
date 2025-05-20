//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
    time_t appointment_time;
} appointment;

appointment* create_appointment(char* name, char* phone_number, time_t appointment_time) {
    appointment* new_appointment = (appointment*)malloc(sizeof(appointment));
    strcpy(new_appointment->name, name);
    strcpy(new_appointment->phone_number, phone_number);
    new_appointment->appointment_time = appointment_time;
    return new_appointment;
}

void print_appointment(appointment* appointment) {
    printf("Name: %s\n", appointment->name);
    printf("Phone Number: %s\n", appointment->phone_number);
    printf("Appointment Time: %s", ctime(&appointment->appointment_time));
}

int compare_appointments(const void* a, const void* b) {
    appointment* appointment_a = (appointment*)a;
    appointment* appointment_b = (appointment*)b;
    return difftime(appointment_a->appointment_time, appointment_b->appointment_time);
}

int main() {
    appointment* appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];

    while (1) {
        printf("Enter name: ");
        scanf("%s", name);

        printf("Enter phone number: ");
        scanf("%s", phone_number);

        time_t appointment_time = time(NULL) + 3600; // 1 hour from now

        appointment* new_appointment = create_appointment(name, phone_number, appointment_time);
        if (num_appointments >= MAX_APPOINTMENTS) {
            printf("Sorry, no more appointments available.\n");
        } else {
            appointments[num_appointments] = new_appointment;
            num_appointments++;
        }
    }

    qsort(appointments, num_appointments, sizeof(appointment*), compare_appointments);

    for (int i = 0; i < num_appointments; i++) {
        print_appointment(appointments[i]);
    }

    return 0;
}