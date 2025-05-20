//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[256];
    char time[256];
    char purpose[256];
} Appointment;

int main() {
    Appointment appointments[100];
    int numAppointments = 0;

    while (1) {
        printf("Welcome to the Appointment Scheduler!\n");
        printf("What would you like to do?\n");
        printf("1. Schedule an appointment\n");
        printf("2. View appointments\n");
        printf("3. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numAppointments >= 100) {
                    printf("Sorry, the schedule is full!\n");
                } else {
                    printf("Enter your name:\n");
                    scanf(" %s", appointments[numAppointments].name);

                    printf("Enter the time of your appointment:\n");
                    scanf(" %s", appointments[numAppointments].time);

                    printf("Enter the purpose of your appointment:\n");
                    scanf(" %[^\n]s", appointments[numAppointments].purpose);

                    numAppointments++;
                }
                break;
            case 2:
                if (numAppointments == 0) {
                    printf("The schedule is empty!\n");
                } else {
                    for (int i = 0; i < numAppointments; i++) {
                        printf("%s | %s | %s\n", appointments[i].name, appointments[i].time, appointments[i].purpose);
                    }
                }
                break;
            case 3:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}