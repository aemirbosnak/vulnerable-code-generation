//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int date;
    int time;
} appointment;

int main() {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;
    char choice;
    int date, time;

    do {
        printf("Welcome to the Post-Apocalyptic Appointment Scheduler!\n");
        printf("Please choose an option:\n");
        printf("1. Add an appointment\n");
        printf("2. Remove an appointment\n");
        printf("3. View appointments\n");
        printf("4. Quit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter the name of the appointment (up to %d characters):\n", MAX_NAME_LENGTH - 1);
                scanf("%s", appointments[num_appointments].name);
                printf("Enter the description of the appointment (up to %d characters):\n", MAX_DESCRIPTION_LENGTH - 1);
                scanf("%s", appointments[num_appointments].description);
                printf("Enter the date of the appointment (in the format YYYY-MM-DD):\n");
                scanf("%d", &appointments[num_appointments].date);
                printf("Enter the time of the appointment (in 24-hour format):\n");
                scanf("%d", &appointments[num_appointments].time);
                num_appointments++;
                break;
            case '2':
                printf("Enter the name of the appointment you want to remove:\n");
                scanf("%s", appointments[num_appointments - 1].name);
                num_appointments--;
                break;
            case '3':
                printf("Appointments:\n");
                for (int i = 0; i < num_appointments; i++) {
                    printf("%s\n%s\n%d-%d-%d %d:%d\n", appointments[i].name, appointments[i].description, appointments[i].date, appointments[i].date / 100, appointments[i].date % 100, appointments[i].time / 100, appointments[i].time % 100);
                }
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '4');

    return 0;
}