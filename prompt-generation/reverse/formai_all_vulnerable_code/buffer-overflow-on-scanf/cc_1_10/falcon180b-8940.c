//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20
#define MAX_MESSAGE_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    time_t appointment_time;
} appointment_t;

int num_appointments = 0;
appointment_t appointments[MAX_APPOINTMENTS];

void add_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("I am sorry, my schedule is full. Please try again later.\n");
        return;
    }

    printf("Enter your name: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter your phone number: ");
    scanf("%s", appointments[num_appointments].number);

    printf("Enter your message: ");
    scanf("%s", appointments[num_appointments].message);

    printf("Enter the appointment time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", appointments[num_appointments].message);

    struct tm tm;
    strptime(appointments[num_appointments].message, "%Y-%m-%d %H:%M:%S", &tm);
    appointments[num_appointments].appointment_time = mktime(&tm);

    num_appointments++;
    printf("Appointment added successfully.\n");
}

void view_appointments() {
    if (num_appointments == 0) {
        printf("I am free as a bird. Would you like to schedule an appointment?\n");
    } else {
        printf("My schedule:\n");
        for (int i = 0; i < num_appointments; i++) {
            struct tm *tm = localtime(&appointments[i].appointment_time);
            char message[MAX_MESSAGE_LENGTH];
            strftime(message, MAX_MESSAGE_LENGTH, "%Y-%m-%d %H:%M:%S", tm);
            printf("%s - %s (%s)\n", appointments[i].name, appointments[i].number, message);
        }
    }
}

int main() {
    printf("Welcome to my appointment scheduler. How may I assist you?\n");

    char choice;
    while (1) {
        printf("A - Add appointment\n");
        printf("V - View appointments\n");
        printf("Q - Quit\n");
        printf("Please enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'A':
                add_appointment();
                break;
            case 'V':
                view_appointments();
                break;
            case 'Q':
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}