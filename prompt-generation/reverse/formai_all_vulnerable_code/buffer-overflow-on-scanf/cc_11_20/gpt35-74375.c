//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Appointment {
    char name[30];
    int hour;
    int minute;
};

typedef struct Appointment appointment;

void main() {
    appointment appt[100];
    int count = 0;
    int choice = 0;
    printf("*** Welcome to Appointment Scheduler ***\n\n");
    while (choice != 4) {
        printf("\n1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter the name of the appointment: ");
                scanf("%s", appt[count].name);
                printf("Enter the hour (in 24-hour format): ");
                scanf("%d", &appt[count].hour);
                printf("Enter the minute: ");
                scanf("%d", &appt[count].minute);
                printf("\nAppointment added successfully!\n");
                count++;
                break;
            case 2:
                if(count == 0) {
                    printf("\nNo appointments found!\n");
                    break;
                }
                printf("\n*** Appointments List ***\n\n");
                for(int i = 0; i < count; i++) {
                    printf("Appointment %d\n", i+1);
                    printf("Name: %s\n", appt[i].name);
                    printf("Time: %d:%d\n\n", appt[i].hour, appt[i].minute);
                }
                break;
            case 3:
                if(count == 0) {
                    printf("\nNo appointments found!\n");
                    break;
                }
                printf("\nEnter the appointment number you want to delete: ");
                int delAppt;
                scanf("%d", &delAppt);
                if(delAppt < 1 || delAppt > count) {
                    printf("\nInvalid appointment number!\n");
                    break;
                }
                for(int i = delAppt-1; i < count-1; i++) {
                    strcpy(appt[i].name, appt[i+1].name);
                    appt[i].hour = appt[i+1].hour;
                    appt[i].minute = appt[i+1].minute;
                }
                count--;
                printf("\nAppointment deleted successfully!\n");
                break;
            case 4:
                printf("\nThank you for using Appointment Scheduler!\n");
                break;
            default:
                printf("\nInvalid choice! Try again.\n");
                break;
        }
    }
}