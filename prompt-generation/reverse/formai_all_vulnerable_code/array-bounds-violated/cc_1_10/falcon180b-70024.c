//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char name[50];
    int id;
    time_t appointment_time;
} appointment;

void surrealist_appointment_scheduler() {
    int i, j, choice;
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    srand(time(NULL));

    printf("Welcome to the Surrealist Appointment Scheduler!\n");
    printf("Please enter the number of appointments you would like to schedule (up to 100): ");
    scanf("%d", &num_appointments);

    for (i = 0; i < num_appointments; i++) {
        appointments[i].id = i;
        appointments[i].appointment_time = time(NULL) + rand() % 86400; // random appointment time within the next 24 hours
        printf("Please enter the name of the person for appointment %d: ", i);
        scanf("%s", appointments[i].name);
    }

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. View appointments\n");
        printf("2. Schedule a new appointment\n");
        printf("3. Cancel an appointment\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (i = 0; i < num_appointments; i++) {
                    printf("%s has an appointment at %s on %s\n", appointments[i].name, ctime(&appointments[i].appointment_time));
                }
                break;
            case 2:
                if (num_appointments >= MAX_APPOINTMENTS) {
                    printf("Sorry, you cannot schedule any more appointments.\n");
                } else {
                    printf("Enter the name of the person for the new appointment: ");
                    scanf("%s", appointments[num_appointments].name);
                    appointments[num_appointments].id = num_appointments;
                    appointments[num_appointments].appointment_time = time(NULL) + rand() % 86400;
                    num_appointments++;
                    printf("Appointment scheduled for %s at %s on %s\n", appointments[num_appointments-1].name, ctime(&appointments[num_appointments-1].appointment_time));
                }
                break;
            case 3:
                printf("Enter the ID of the appointment you would like to cancel: ");
                scanf("%d", &i);
                if (i >= 0 && i < num_appointments) {
                    printf("Appointment canceled for %s\n", appointments[i].name);
                    num_appointments--;
                    for (j = i; j < num_appointments; j++) {
                        appointments[j] = appointments[j+1];
                    }
                } else {
                    printf("Invalid appointment ID\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

int main() {
    surrealist_appointment_scheduler();
    return 0;
}