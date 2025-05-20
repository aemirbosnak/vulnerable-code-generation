//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    time_t appointment_time;
    int duration;
} appointment;

void add_appointment(appointment* appointments, int num_appointments) {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter phone number: ");
    scanf("%s", appointments[num_appointments].phone);

    printf("Enter appointment time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", appointments[num_appointments].appointment_time);

    printf("Enter appointment duration (in minutes): ");
    scanf("%d", &appointments[num_appointments].duration);

    num_appointments++;
}

void print_appointments(appointment* appointments, int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s (%s) on %s for %d minutes\n", appointments[i].name, appointments[i].phone, ctime(&appointments[i].appointment_time), appointments[i].duration);
    }
}

int main() {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        add_appointment(appointments, num_appointments);
    }

    print_appointments(appointments, num_appointments);

    return 0;
}