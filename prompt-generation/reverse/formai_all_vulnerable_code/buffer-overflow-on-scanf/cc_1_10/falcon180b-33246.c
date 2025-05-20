//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_EMAIL_LENGTH 50

struct appointment {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    time_t appointment_time;
};

void print_appointment(struct appointment* appt) {
    printf("Name: %s\n", appt->name);
    printf("Phone: %s\n", appt->phone);
    printf("Email: %s\n", appt->email);
    printf("Appointment Time: %s\n\n", ctime(&appt->appointment_time));
}

int main() {
    int choice;
    struct appointment* appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    do {
        printf("Appointment Scheduler\n");
        printf("1. Add an appointment\n");
        printf("2. View appointments\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_appointments >= MAX_APPOINTMENTS) {
                    printf("Sorry, the maximum number of appointments has been reached.\n");
                } else {
                    struct appointment new_appt;
                    printf("Enter the name: ");
                    scanf("%s", new_appt.name);
                    printf("Enter the phone number: ");
                    scanf("%s", new_appt.phone);
                    printf("Enter the email address: ");
                    scanf("%s", new_appt.email);
                    printf("Enter the appointment time (YYYY-MM-DD HH:MM:SS): ");
                    scanf("%s", new_appt.appointment_time);
                    strptime(new_appt.appointment_time, "%Y-%m-%d %H:%M:%S", &new_appt.appointment_time);
                    appointments[num_appointments++] = &new_appt;
                    printf("Appointment added.\n");
                }
                break;
            case 2:
                if(num_appointments == 0) {
                    printf("No appointments found.\n");
                } else {
                    printf("Appointments:\n");
                    for(int i=0; i<num_appointments; i++) {
                        print_appointment(appointments[i]);
                    }
                }
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 3);

    return 0;
}