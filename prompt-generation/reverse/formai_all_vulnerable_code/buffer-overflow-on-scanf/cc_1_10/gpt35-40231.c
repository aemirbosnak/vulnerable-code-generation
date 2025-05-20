//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/* This program is a post-apocalyptic appointment scheduler. Due to the lack of advanced technology, it allows users to schedule appointments 
 * by visiting physical locations and writing their appointment details on a piece of paper. */

typedef struct appointment {
    char name[50];
    int day;
    char month[20];
    int year;
    char location[50];
} Appointment;

int main() {
    int choice;
    int num_appointments = 0;
    Appointment appointments[100];

    printf("Welcome to the Post-Apocalyptic Appointment Scheduler!\n");

    while(1) {
        printf("\n1. Schedule Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("\nEnter the name of the appointment: ");
            scanf("%s", appointments[num_appointments].name);

            printf("Enter the day of the appointment: ");
            scanf("%d", &appointments[num_appointments].day);

            printf("Enter the month of the appointment: ");
            scanf("%s", appointments[num_appointments].month);

            printf("Enter the year of the appointment: ");
            scanf("%d", &appointments[num_appointments].year);

            printf("Enter the location of the appointment: ");
            scanf("%s", appointments[num_appointments].location);

            printf("\nAppointment scheduled successfully!\n");

            num_appointments++;
        }
        else if(choice == 2) {
            if(num_appointments == 0) {
                printf("\nNo appointments scheduled.\n");
            }
            else {
                printf("\nYour scheduled appointments:\n");
                printf("----------------------------\n");

                for(int i = 0; i < num_appointments; i++) {
                    printf("Appointment %d:\n", i+1);
                    printf("Name: %s\n", appointments[i].name);
                    printf("Date: %d %s %d\n", appointments[i].day, appointments[i].month, appointments[i].year);
                    printf("Location: %s\n", appointments[i].location);
                    printf("\n");
                }
            }
        }
        else if(choice == 3) {
            printf("\nExiting program...\n");
            exit(0);
        }
        else {
            printf("\nInvalid choice. Try again.\n");
        }
    }

    return 0;
}