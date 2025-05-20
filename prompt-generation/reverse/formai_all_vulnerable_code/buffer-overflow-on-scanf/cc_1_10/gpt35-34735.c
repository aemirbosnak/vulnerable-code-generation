//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Appointment {
    int day;
    int month;
    int year;
    char time[6];
    char name[30];
} Appointment;

int main() {
    int choice, count = 0;
    char input;
    Appointment appointments[50];

    printf("*** Appointment Scheduler ***\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Schedule an appointment\n");
        printf("2. View all appointments\n");
        printf("3. Cancel an appointment\n");
        printf("4. Exit\n");

        scanf("%d", &choice);
        getchar(); // Flush the input buffer

        switch(choice) {
            case 1:
                printf("\nEnter appointment details:\n");
                printf("Name: ");
                fgets(appointments[count].name, 30, stdin);

                printf("Date (dd/mm/yyyy): ");
                scanf("%d/%d/%d", &appointments[count].day, &appointments[count].month, &appointments[count].year);
                getchar(); // Flush the input buffer

                printf("Time (hh:mm): ");
                fgets(appointments[count].time, 6, stdin);

                printf("Appointment scheduled!\n");
                count++;
                break;

            case 2:
                printf("\nAll appointments:\n");
                for (int i = 0; i < count; i++) {
                    printf("%d. %s - %d/%d/%d at %s", i+1, appointments[i].name, appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].time);
                }
                break;

            case 3:
                printf("\nEnter the number of the appointment to cancel: ");
                int cancel_num;
                scanf("%d", &cancel_num);
                getchar(); // Flush the input buffer

                if (cancel_num > count || cancel_num <= 0) {
                    printf("Invalid appointment number!");
                } else {
                    for (int i = cancel_num-1; i < count; i++) {
                        appointments[i] = appointments[i+1];
                    }
                    printf("Appointment cancelled!");
                    count--;
                }
                break;

            case 4:
                printf("\nThank you for using Appointment Scheduler.\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }

    return 0;
}