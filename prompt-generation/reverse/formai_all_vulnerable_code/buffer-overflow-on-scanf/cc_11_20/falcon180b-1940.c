//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LEN 50

struct appointment {
    char name[MAX_NAME_LEN];
    int year, month, day, hour, minute;
};

int main() {
    int num_appointments = 0;
    struct appointment appointments[MAX_APPOINTMENTS];

    while (1) {
        printf("Appointment Scheduler\n");
        printf("1. Add appointment\n");
        printf("2. Remove appointment\n");
        printf("3. View appointments\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_appointments >= MAX_APPOINTMENTS) {
                printf("Maximum number of appointments reached.\n");
            } else {
                printf("Enter name for appointment: ");
                scanf("%s", appointments[num_appointments].name);

                printf("Enter year: ");
                scanf("%d", &appointments[num_appointments].year);

                printf("Enter month: ");
                scanf("%d", &appointments[num_appointments].month);

                printf("Enter day: ");
                scanf("%d", &appointments[num_appointments].day);

                printf("Enter hour: ");
                scanf("%d", &appointments[num_appointments].hour);

                printf("Enter minute: ");
                scanf("%d", &appointments[num_appointments].minute);

                num_appointments++;
            }
            break;

        case 2:
            if (num_appointments == 0) {
                printf("No appointments to remove.\n");
            } else {
                printf("Enter name of appointment to remove: ");
                scanf("%s", appointments[num_appointments - 1].name);

                for (int i = 0; i < num_appointments - 1; i++) {
                    appointments[i] = appointments[i + 1];
                }

                num_appointments--;
            }
            break;

        case 3:
            if (num_appointments == 0) {
                printf("No appointments to view.\n");
            } else {
                for (int i = 0; i < num_appointments; i++) {
                    printf("Name: %s\n", appointments[i].name);
                    printf("Date: %d-%d-%d %d:%d\n\n", appointments[i].year, appointments[i].month, appointments[i].day, appointments[i].hour, appointments[i].minute);
                }
            }
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}