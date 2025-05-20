//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 1000 // maximum number of appointments that can be scheduled
#define MAX_NAME_LENGTH 50 // maximum length of a name
#define MAX_PHONE_NUMBER_LENGTH 15 // maximum length of a phone number
#define MAX_EMAIL_LENGTH 100 // maximum length of an email address

typedef struct {
    char name[MAX_NAME_LENGTH]; // name of the person scheduling the appointment
    char phone_number[MAX_PHONE_NUMBER_LENGTH]; // phone number of the person scheduling the appointment
    char email[MAX_EMAIL_LENGTH]; // email address of the person scheduling the appointment
    time_t appointment_time; // time of the appointment in seconds since Epoch
} appointment;

void print_appointment(appointment *app) {
    printf("Name: %s\n", app->name);
    printf("Phone number: %s\n", app->phone_number);
    printf("Email: %s\n", app->email);
    printf("Appointment time: %s\n", ctime(&app->appointment_time));
}

int main() {
    appointment appointments[MAX_APPOINTMENTS]; // array to store appointments
    int num_appointments = 0; // number of appointments currently scheduled

    while (1) {
        printf("Enter 1 to schedule an appointment\n");
        printf("Enter 2 to view appointments\n");
        printf("Enter 3 to exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_appointments >= MAX_APPOINTMENTS) {
                    printf("Sorry, no more appointments can be scheduled.\n");
                } else {
                    printf("Enter your name:\n");
                    scanf("%s", appointments[num_appointments].name);
                    printf("Enter your phone number:\n");
                    scanf("%s", appointments[num_appointments].phone_number);
                    printf("Enter your email address:\n");
                    scanf("%s", appointments[num_appointments].email);
                    printf("Enter the appointment time (YYYY-MM-DD HH:MM:SS):\n");
                    scanf("%s", appointments[num_appointments].appointment_time);
                    num_appointments++;
                }
                break;
            case 2:
                if (num_appointments == 0) {
                    printf("No appointments scheduled.\n");
                } else {
                    for (int i = 0; i < num_appointments; i++) {
                        print_appointment(&appointments[i]);
                    }
                }
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}