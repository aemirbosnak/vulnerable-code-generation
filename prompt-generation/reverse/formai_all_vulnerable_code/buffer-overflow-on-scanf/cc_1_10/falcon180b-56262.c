//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phoneNumber[MAX_PHONE_NUMBER_LENGTH];
    time_t appointmentTime;
} Appointment;

int main() {
    int numAppointments = 0;
    Appointment appointments[MAX_APPOINTMENTS];
    char input[100];
    int choice;

    printf("Welcome to the Appointment Scheduler!\n");
    printf("Please enter your name: ");
    scanf("%s", input);
    strcpy(appointments[numAppointments].name, input);

    while (numAppointments < MAX_APPOINTMENTS) {
        printf("\nPlease select an option:\n");
        printf("1. Add an appointment\n");
        printf("2. View appointments\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the date and time of the appointment (YYYY-MM-DD HH:MM:SS): ");
                scanf("%s", input);
                strptime(input, "%Y-%m-%d %H:%M:%S", &appointments[numAppointments].appointmentTime);
                printf("Enter the phone number associated with this appointment: ");
                scanf("%s", appointments[numAppointments].phoneNumber);
                numAppointments++;
                break;
            case 2:
                printf("\nAppointment Schedule:\n");
                for (int i = 0; i < numAppointments; i++) {
                    printf("%s - %s on %s\n", appointments[i].name, appointments[i].phoneNumber, ctime(&appointments[i].appointmentTime));
                }
                break;
            case 3:
                printf("\nThank you for using the Appointment Scheduler!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}