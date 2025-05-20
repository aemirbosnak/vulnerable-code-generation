//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    time_t start_time;
    time_t end_time;
} Appointment;

void print_menu() {
    printf("\nAppointment Scheduler\n");
    printf("---------------------\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    int num_appointments = 0;
    Appointment appointments[MAX_APPOINTMENTS];

    while(1) {
        print_menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_appointments >= MAX_APPOINTMENTS) {
                    printf("Cannot add more appointments.\n");
                    break;
                }

                printf("Enter appointment ID: ");
                scanf("%d", &appointments[num_appointments].id);

                printf("Enter name: ");
                scanf("%s", appointments[num_appointments].name);

                printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
                scanf("%s", appointments[num_appointments].start_time);

                printf("Enter end time (YYYY-MM-DD HH:MM:SS): ");
                scanf("%s", appointments[num_appointments].end_time);

                num_appointments++;
                break;

            case 2:
                if(num_appointments == 0) {
                    printf("No appointments found.\n");
                    break;
                }

                printf("\nID\tName\tStart Time\tEnd Time\n");
                for(int i = 0; i < num_appointments; i++) {
                    printf("%d\t%s\t%s\t%s\n", appointments[i].id, appointments[i].name, appointments[i].start_time, appointments[i].end_time);
                }
                break;

            case 3:
                if(num_appointments == 0) {
                    printf("No appointments found.\n");
                    break;
                }

                printf("Enter appointment ID to delete: ");
                scanf("%d", &appointments[num_appointments-1].id);
                appointments[num_appointments-1] = appointments[0];
                num_appointments--;
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}