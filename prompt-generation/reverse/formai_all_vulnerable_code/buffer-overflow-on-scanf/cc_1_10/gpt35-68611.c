//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: lively
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct appointment {
    char name[50];
    int day;
    int month;
    int year;
    int hour;
    int minute;
};

int main() {
    struct appointment appts[100];
    int num_appts = 0;

    while (true) {
        int choice;
        printf("\nWelcome to the Appointment Scheduler!\n");
        printf("1. Add an appointment\n");
        printf("2. List all appointments\n");
        printf("3. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            struct appointment new_appt;
            printf("\nEnter the details of the new appointment.\n");
            printf("Name: ");
            scanf("%s", new_appt.name);
            printf("Date (DD/MM/YYYY): ");
            scanf("%d/%d/%d", &new_appt.day, &new_appt.month, &new_appt.year);
            printf("Time (HH:MM): ");
            scanf("%d:%d", &new_appt.hour, &new_appt.minute);
            appts[num_appts++] = new_appt;
            printf("New appointment added!\n");
        } else if (choice == 2) {
            printf("\nList of all appointments:\n");
            for (int i = 0; i < num_appts; i++) {
                printf("%s - %02d/%02d/%04d %02d:%02d\n", 
                       appts[i].name, 
                       appts[i].day, 
                       appts[i].month, 
                       appts[i].year, 
                       appts[i].hour, 
                       appts[i].minute);
            }
        } else if (choice == 3) {
            printf("\nGoodbye!\n");
            exit(0);
        } else {
            printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}