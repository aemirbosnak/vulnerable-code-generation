//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: complete
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
    int appointment_duration;
} Appointment;

int main() {
    int num_appointments;
    Appointment appointments[MAX_APPOINTMENTS];
    char choice;

    printf("Welcome to the Appointment Scheduler!\n");
    printf("How many appointments would you like to schedule? ");
    scanf("%d", &num_appointments);

    for (int i = 0; i < num_appointments; i++) {
        printf("\nAppointment #%d:\n", i+1);
        printf("Enter the name of the client: ");
        scanf("%s", appointments[i].name);

        printf("Enter the phone number of the client: ");
        scanf("%s", appointments[i].phone_number);

        printf("Enter the appointment time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", appointments[i].appointment_time);

        printf("Enter the appointment duration in minutes: ");
        scanf("%d", &appointments[i].appointment_duration);
    }

    printf("\nAppointments scheduled:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("Appointment #%d:\n", i+1);
        printf("Name: %s\n", appointments[i].name);
        printf("Phone number: %s\n", appointments[i].phone_number);
        printf("Appointment time: %s\n", appointments[i].appointment_time);
        printf("Appointment duration: %d minutes\n\n", appointments[i].appointment_duration);
    }

    printf("\nWould you like to schedule another appointment? (y/n) ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        main();
    } else {
        printf("Thank you for using the Appointment Scheduler!\n");
    }

    return 0;
}