//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    time_t appointment_time;
    int duration;
    int status;
} Appointment;

int main() {
    int choice;
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];

    do {
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Cancel appointment\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                printf("Enter email: ");
                scanf("%s", email);
                printf("Enter appointment time (YYYY-MM-DD HH:MM:SS): ");
                scanf("%s", appointments[num_appointments].appointment_time);
                appointments[num_appointments].duration = 0;
                appointments[num_appointments].status = 1;
                num_appointments++;
                break;
            case 2:
                if(num_appointments == 0) {
                    printf("No appointments.\n");
                } else {
                    printf("Name\tPhone\tEmail\tAppointment Time\tDuration\tStatus\n");
                    for(int i = 0; i < num_appointments; i++) {
                        printf("%s\t%s\t%s\t%s\t%d\t%d\n",
                            appointments[i].name,
                            appointments[i].phone,
                            appointments[i].email,
                            ctime(&appointments[i].appointment_time),
                            appointments[i].duration,
                            appointments[i].status);
                    }
                }
                break;
            case 3:
                printf("Enter appointment ID: ");
                scanf("%d", &choice);
                for(int i = 0; i < num_appointments; i++) {
                    if(appointments[i].status == 1 && appointments[i].appointment_time == choice) {
                        appointments[i].status = 0;
                        printf("Appointment cancelled.\n");
                    }
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 4);

    return 0;
}