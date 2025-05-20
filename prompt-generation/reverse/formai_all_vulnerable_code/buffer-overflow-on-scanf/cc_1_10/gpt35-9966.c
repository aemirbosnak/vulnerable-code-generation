//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: excited
#include <stdio.h>
#include <stdlib.h>

struct appointment {
    int day;
    int month;
    int year;
    int hour;
    int minute;
    char description[50];
};

int main() {
    int num_appointments = 0;
    struct appointment appointments[20];

    while (1) {
        // Display menu options
        printf("\n------- Appointment Scheduler -------\n");
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Exit\n");
        printf("-------------------------------------\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        // Handle menu options
        switch (choice) {
            case 1:
                // Get input from user
                printf("\nEnter date and time in format DD MM YYYY HH MM: ");
                scanf("%d %d %d %d %d", &appointments[num_appointments].day, &appointments[num_appointments].month, &appointments[num_appointments].year, &appointments[num_appointments].hour, &appointments[num_appointments].minute);
                printf("Enter appointment description: ");
                scanf("%s", appointments[num_appointments].description);

                // Increment number of appointments
                num_appointments++;

                printf("\nAppointment added!\n");
                break;
            case 2:
                // Display appointments
                printf("\n-------- Appointments (%d) --------\n", num_appointments);
                printf("Date\t\tTime\t\tDescription\n");

                for (int i = 0; i < num_appointments; i++) {
                    printf("%02d/%02d/%04d\t%02d:%02d\t\t%s\n", appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].hour, appointments[i].minute, appointments[i].description);
                }

                printf("-----------------------------------\n");
                break;
            case 3:
                // Exit program
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    }

    return 0;
}