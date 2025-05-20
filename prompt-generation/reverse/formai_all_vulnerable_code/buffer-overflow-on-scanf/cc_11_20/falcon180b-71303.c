//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int date;
    int time;
} Appointment;

int main() {
    int numAppointments = 0;
    Appointment appointments[MAX_APPOINTMENTS];

    while (1) {
        printf("Appointment Scheduler\n");
        printf("1. Add appointment\n");
        printf("2. Delete appointment\n");
        printf("3. View appointments\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (numAppointments >= MAX_APPOINTMENTS) {
                printf("Cannot add more appointments.\n");
                break;
            }

            printf("Enter name of appointment: ");
            scanf("%s", appointments[numAppointments].name);

            printf("Enter description of appointment: ");
            scanf("%s", appointments[numAppointments].description);

            printf("Enter date (YYYY-MM-DD): ");
            scanf("%d", &appointments[numAppointments].date);

            printf("Enter time (HH:MM): ");
            scanf("%d", &appointments[numAppointments].time);

            numAppointments++;
            break;

        case 2:
            if (numAppointments == 0) {
                printf("No appointments to delete.\n");
                break;
            }

            printf("Enter index of appointment to delete: ");
            int index;
            scanf("%d", &index);

            if (index < 0 || index >= numAppointments) {
                printf("Invalid index.\n");
                break;
            }

            memmove(&appointments[index], &appointments[index + 1], sizeof(Appointment) * (numAppointments - index - 1));
            numAppointments--;
            break;

        case 3:
            if (numAppointments == 0) {
                printf("No appointments to view.\n");
                break;
            }

            printf("Appointments:\n");
            for (int i = 0; i < numAppointments; i++) {
                printf("%s - %s (%d-%d-%d %d:%d)\n", appointments[i].name, appointments[i].description, appointments[i].date, appointments[i].date / 100, appointments[i].date % 100, appointments[i].time / 100, appointments[i].time % 100);
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