//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 20
#define MAX_TIME_LENGTH 20
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    char time[MAX_TIME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, the maximum number of appointments has been reached.\n");
        return;
    }

    printf("Enter the name of the appointment: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter the date of the appointment (mm/dd/yyyy): ");
    scanf("%s", appointments[num_appointments].date);

    printf("Enter the time of the appointment (hh:mm am/pm): ");
    scanf("%s", appointments[num_appointments].time);

    printf("Enter a description of the appointment: ");
    scanf("%s", appointments[num_appointments].description);

    num_appointments++;
}

void view_appointments() {
    if (num_appointments == 0) {
        printf("No appointments found.\n");
        return;
    }

    printf("Name\tDate\tTime\tDescription\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s\t%s\t%s\t%s\n", appointments[i].name, appointments[i].date, appointments[i].time, appointments[i].description);
    }
}

int main() {
    srand(time(NULL));

    int choice;

    do {
        printf("Appointment Scheduler\n");
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_appointment();
            break;
        case 2:
            view_appointments();
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}