//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

struct Appointment {
    char name[50];
    char date[20];
    char time[20];
} appt;

void scheduleAppointment() {
    FILE *fptr;
    fptr = fopen("appointments.txt", "a");

    if (fptr == NULL) {
        printf("Error creating appointment file!\n");
        exit(1);
    }

    printf("Enter name: ");
    scanf("%s", appt.name);
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", appt.date);
    printf("Enter time (hh:mm): ");
    scanf("%s", appt.time);

    fprintf(fptr, "%s %s %s\n", appt.name, appt.date, appt.time);
    printf("Appointment successfully scheduled!\n");
    fclose(fptr);
}

int main() {
    int choice;
    printf("***Appointment Scheduler***\n");

    while(1) {
        printf("\nOptions:\n1. Schedule appointment\n2. Quit\nYour choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                scheduleAppointment();
                break;
            case 2: 
                printf("Exiting program...\n");
                exit(0);
            default: 
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}