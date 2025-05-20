//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

struct appointment {
    char name[50];
    int date;
    int time;
};

int main() {
    int choice, i, j;
    char name[50];
    struct appointment appointments[MAX_APPOINTMENTS];

    printf("Welcome to the Appointment Scheduler!\n");
    printf("Please choose an option:\n");
    printf("1. Add an appointment\n");
    printf("2. View all appointments\n");
    printf("3. Delete an appointment\n");
    printf("4. Exit\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter date (dd/mm/yyyy): ");
            scanf("%d/%d/%d", &appointments[0].date, &appointments[0].date + 1, &appointments[0].date + 2);
            printf("Enter time (hh:mm): ");
            scanf("%d:%d", &appointments[0].time, &appointments[0].time + 1);
            printf("Appointment added!\n");
            break;

        case 2:
            printf("Appointments:\n");
            for(i = 0; i < MAX_APPOINTMENTS; i++) {
                if(appointments[i].date!= 0) {
                    printf("%s - %d/%d/%d %d:%d\n", appointments[i].name, appointments[i].date, appointments[i].date + 1, appointments[i].date + 2, appointments[i].time, appointments[i].time + 1);
                }
            }
            break;

        case 3:
            printf("Enter name to delete: ");
            scanf("%s", name);
            for(i = 0; i < MAX_APPOINTMENTS; i++) {
                if(strcmp(appointments[i].name, name) == 0) {
                    appointments[i].date = 0;
                    appointments[i].time = 0;
                    printf("Appointment deleted!\n");
                    break;
                }
            }
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}