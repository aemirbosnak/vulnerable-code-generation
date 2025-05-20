//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
    time_t appointment_time;
} Appointment;

int main() {
    int num_appointments;
    Appointment appointments[MAX_APPOINTMENTS];
    char input_buffer[100];
    time_t current_time;
    int i;

    printf("Welcome to the Appointment Scheduler!\n");

    // Get current time
    time(&current_time);

    // Get number of appointments
    printf("How many appointments do you have today? ");
    scanf("%d", &num_appointments);

    // Get appointment details
    for (i = 0; i < num_appointments; i++) {
        printf("\nAppointment %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", appointments[i].name);
        printf("Phone number: ");
        scanf("%s", appointments[i].phone_number);
        printf("Appointment time (HH:MM AM/PM): ");
        scanf("%s", input_buffer);

        // Convert input time to time_t
        appointments[i].appointment_time = strptime(input_buffer, "%I:%M %p", &appointments[i].appointment_time);
    }

    // Display appointments
    printf("\nToday's appointments:\n");
    for (i = 0; i < num_appointments; i++) {
        printf("%s: %s (%s)\n", appointments[i].name, ctime(&appointments[i].appointment_time), appointments[i].phone_number);
    }

    return 0;
}