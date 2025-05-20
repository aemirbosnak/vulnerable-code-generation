//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

typedef struct {
    char name[50];
    int start_time;
    int end_time;
} Appointment;

void display_menu() {
    printf("\nAppointment Scheduler\n");
    printf("----------------------\n");
    printf("1. Add Appointment\n");
    printf("2. Display Appointments\n");
    printf("3. Exit\n");
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_appointments < MAX_APPOINTMENTS) {
                    printf("Enter name: ");
                    scanf("%s", appointments[num_appointments].name);
                    printf("Enter start time: ");
                    scanf("%d", &appointments[num_appointments].start_time);
                    printf("Enter end time: ");
                    scanf("%d", &appointments[num_appointments].end_time);
                    num_appointments++;
                } else {
                    printf("Maximum number of appointments reached.\n");
                }
                break;

            case 2:
                printf("\nAppointments:\n");
                for (int i = 0; i < num_appointments; i++) {
                    printf("\nName: %s", appointments[i].name);
                    printf("\nStart Time: %d", appointments[i].start_time);
                    printf("\nEnd Time: %d", appointments[i].end_time);
                }
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}