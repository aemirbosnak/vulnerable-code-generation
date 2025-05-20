//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int startTime;
    int endTime;
    char description[100];
} Appointment;

int main() {
    Appointment appointments[10];

    int numAppointments = 0;
    int choice = 0;
    int index = 0;

    while (1) {
        printf("Appointment Scheduler\n");
        printf("1. Add Appointment\n");
        printf("2. Delete Appointment\n");
        printf("3. View Appointments\n");
        printf("4. Quit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter appointment name:\n");
                scanf("%s", appointments[index].name);

                printf("Enter start time (HH:MM):\n");
                scanf("%d", &appointments[index].startTime);

                printf("Enter end time (HH:MM):\n");
                scanf("%d", &appointments[index].endTime);

                printf("Enter description:\n");
                scanf("%s", appointments[index].description);

                numAppointments++;
                break;

            case 2:
                printf("Enter appointment index:\n");
                scanf("%d", &index);

                if (index >= numAppointments) {
                    printf("Invalid index!\n");
                } else {
                    printf("Deleting appointment %d...\n", index);
                    memmove(appointments, appointments + 1, (numAppointments - 1) * sizeof(Appointment));
                    numAppointments--;
                }
                break;

            case 3:
                if (numAppointments == 0) {
                    printf("No appointments found!\n");
                } else {
                    printf("Appointments:\n");
                    for (int i = 0; i < numAppointments; i++) {
                        printf("%d. %s: %s\n", i + 1, appointments[i].name, appointments[i].description);
                    }
                }
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}