//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

struct appointment {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    int date;
    int time;
};

void schedule_appointment(struct appointment* appointments, int num_appointments) {
    int choice;
    printf("Welcome to the appointment scheduler!\n");
    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Schedule an appointment\n");
        printf("2. View appointments\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            if (num_appointments >= MAX_APPOINTMENTS) {
                printf("Sorry, no more appointments available.\n");
            } else {
                printf("Enter your name:\n");
                scanf("%s", appointments[num_appointments].name);
                printf("Enter your phone number:\n");
                scanf("%s", appointments[num_appointments].phone);
                printf("Enter the date (YYYY-MM-DD):\n");
                scanf("%d", &appointments[num_appointments].date);
                printf("Enter the time (HH:MM):\n");
                scanf("%d", &appointments[num_appointments].time);
                num_appointments++;
            }
        } else if (choice == 2) {
            printf("\nAppointments:\n");
            for (int i = 0; i < num_appointments; i++) {
                printf("%s - %s - %d/%d/%d %d:%d\n",
                        appointments[i].name,
                        appointments[i].phone,
                        appointments[i].date / 10000,
                        (appointments[i].date % 10000) / 100,
                        appointments[i].date % 100,
                        appointments[i].time / 100,
                        appointments[i].time % 100);
            }
        } else if (choice == 3) {
            exit(0);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    srand(time(NULL));

    schedule_appointment(appointments, num_appointments);

    return 0;
}