//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Cyberpunk
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

int main() {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;
    char choice;

    do {
        system("clear");
        printf("Cyberpunk Appointment Scheduler\n");
        printf("---------------------------------\n");

        printf("1. Schedule an appointment\n");
        printf("2. View appointments\n");
        printf("3. Exit\n");

        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                if (num_appointments == MAX_APPOINTMENTS) {
                    printf("Sorry, no more appointments available.\n");
                } else {
                    printf("Enter name: ");
                    scanf(" %s", appointments[num_appointments].name);

                    printf("Enter phone number: ");
                    scanf(" %s", appointments[num_appointments].phone_number);

                    time_t now = time(NULL);
                    appointments[num_appointments].appointment_time = now + 60*60*24*7; // one week from now
                    num_appointments++;

                    printf("Appointment scheduled for %s at %s.\n", appointments[num_appointments-1].name, ctime(&appointments[num_appointments-1].appointment_time));
                }
                break;

            case '2':
                if (num_appointments == 0) {
                    printf("No appointments scheduled.\n");
                } else {
                    printf("Upcoming appointments:\n");
                    for (int i = 0; i < num_appointments; i++) {
                        printf("%s: %s (%s)\n", appointments[i].name, ctime(&appointments[i].appointment_time), appointments[i].phone_number);
                    }
                }
                break;

            case '3':
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice!= '3');

    return 0;
}