//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct appointment {
    char name[20];
    char date[12];
    char time[6];
};

int main() {
    struct appointment appointments[10];
    int numAppointments = 0;
    int choice = 0;
    
    do {
        printf("Welcome to Appointment Scheduler!\n");
        printf("Choose an option:\n");
        printf("1. Add an appointment\n");
        printf("2. View appointments\n");
        printf("3. Quit\n");
    
        scanf("%d", &choice);
    
        switch (choice) {
            case 1:
                if (numAppointments >= 10) {
                    printf("Maximum number of appointments reached.\n");
                } else {
                    struct appointment newAppointment;
                    printf("Enter name: ");
                    scanf("%s", newAppointment.name);
                    printf("Enter date (mm/dd/yyyy): ");
                    scanf("%s", newAppointment.date);
                    printf("Enter time (hh:mm): ");
                    scanf("%s", newAppointment.time);
                    appointments[numAppointments] = newAppointment;
                    numAppointments++;
                }
                break;
            case 2:
                if (numAppointments == 0) {
                    printf("No appointments.\n");
                } else {
                    printf("Appointments:\n");
                    for (int i = 0; i < numAppointments; i++) {
                        printf("%s on %s at %s\n", appointments[i].name, appointments[i].date, appointments[i].time);
                    }
                }
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
    
    return 0;
}