//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 1000
#define MAX_NAME_LENGTH 50

struct appointment {
    char name[MAX_NAME_LENGTH];
    int date;
    int time;
};

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;
    int menu_choice = 0;

    while (menu_choice != 4) {
        printf("Appointment Scheduler Menu:\n");
        printf("1. Schedule Appointment\n");
        printf("2. Print Appointments\n");
        printf("3. Cancel Appointment\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &menu_choice);

        switch (menu_choice) {
            case 1:
                if (num_appointments == MAX_APPOINTMENTS) {
                    printf("Maximum number of appointments reached.\n");
                    break;
                }

                printf("Enter name: ");
                scanf("%s", appointments[num_appointments].name);
                printf("Enter date (MMDDYY): ");
                scanf("%d", &appointments[num_appointments].date);
                printf("Enter time (HHMM): ");
                scanf("%d", &appointments[num_appointments].time);
                num_appointments++;

                break;
            case 2:
                printf("Appointments:\n");
                for (int i = 0; i < num_appointments; i++) {
                    printf("%s - %d/%d/%d %d:%d\n",
                        appointments[i].name,
                        appointments[i].date % 100,
                        appointments[i].date / 100 % 100,
                        appointments[i].date / 10000,
                        appointments[i].time / 100,
                        appointments[i].time % 100);
                }

                break;
            case 3:
                printf("Enter name of appointment to cancel: ");
                char name_to_cancel[MAX_NAME_LENGTH];
                scanf("%s", name_to_cancel);
                int appointment_index = -1;

                for (int i = 0; i < num_appointments; i++) {
                    if (strcmp(appointments[i].name, name_to_cancel) == 0) {
                        appointment_index = i;
                        break;
                    }
                }

                if (appointment_index == -1) {
                    printf("Appointment not found.\n");
                } else {
                    for (int i = appointment_index; i < num_appointments - 1; i++) {
                        appointments[i] = appointments[i + 1];
                    }

                    num_appointments--;
                    printf("Appointment cancelled.\n");
                }

                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}