//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Appointment {
    int id;
    char name[50];
    char date[20];
    char time[10];
    char purpose[100];
};

void createAppointment(struct Appointment *appt) {
    printf("Enter Appointment Details: \n");
    printf("Name: ");
    scanf("%s", appt->name);
    printf("Date (DD/MM/YYYY): ");
    scanf("%s", appt->date);
    printf("Time (HH:MM): ");
    scanf("%s", appt->time);
    printf("Purpose: ");
    scanf("%s", appt->purpose);
}

void viewAppointment(struct Appointment *appt) {
    printf("Here are the Appointment Details: \n");
    printf("Name: %s\n", appt->name);
    printf("Date: %s\n", appt->date);
    printf("Time: %s\n", appt->time);
    printf("Purpose: %s\n", appt->purpose);
}

int main() {
    int choice = 0;
    int numAppointments = 0;
    struct Appointment appointments[10];
    while(choice != 3) {
        printf("\n\n");
        printf("Welcome to the Appointment Scheduler! \n");
        printf("Select an option from the menu:\n");
        printf("1. Create an Appointment\n");
        printf("2. View an Appointment\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                if(numAppointments >= 10) {
                    printf("Sorry, you have reached the maximum number of Appointments that can be created.\n");
                    break;
                }
                createAppointment(&appointments[numAppointments]);
                appointments[numAppointments].id = numAppointments + 1;
                printf("Appointment Created Successfully with ID: %d\n", appointments[numAppointments].id);
                numAppointments++;
                break;
            case 2:
                if(numAppointments == 0) {
                    printf("Sorry, there are no Appointments created yet.\n");
                    break;
                }
                int id;
                printf("Enter Appointment ID: ");
                scanf("%d", &id);
                if(id > numAppointments || id < 1) {
                    printf("A valid Appointment ID is between 1 and %d", numAppointments);
                    break;
                }
                viewAppointment(&appointments[id-1]);
                break;
            case 3:
                printf("Exiting Appointment Scheduler...");
                break;
            default:
                printf("Invalid Choice. Please try again.\n");
        }
    }
    return 0;
}