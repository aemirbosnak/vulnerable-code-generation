//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define DAYS_IN_WEEK 7

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[15];
    char email[50];
    time_t appointment_time;
    bool is_booked;
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void print_menu() {
    printf("\nAppointment Scheduler Menu:\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Cancel Appointment\n");
    printf("4. Exit\n");
}

void add_appointment() {
    char name[MAX_NAME_LENGTH], phone[15], email[50];
    time_t appointment_time;
    bool is_booked = false;

    printf("\nEnter name: ");
    scanf("%s", name);

    printf("Enter phone number: ");
    scanf("%s", phone);

    printf("Enter email: ");
    scanf("%s", email);

    printf("Enter appointment time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", &appointment_time);

    for (int i = 0; i < num_appointments; i++) {
        if (appointments[i].is_booked) {
            if (appointments[i].appointment_time == appointment_time) {
                printf("\nAppointment already booked at that time.\n");
                return;
            }
        }
    }

    strcpy(appointments[num_appointments].name, name);
    strcpy(appointments[num_appointments].phone, phone);
    strcpy(appointments[num_appointments].email, email);
    appointments[num_appointments].appointment_time = appointment_time;
    appointments[num_appointments].is_booked = true;
    num_appointments++;

    printf("\nAppointment added successfully.\n");
}

void view_appointments() {
    if (num_appointments == 0) {
        printf("\nNo appointments found.\n");
        return;
    }

    printf("\nAppointment List:\n");
    printf("Name\tPhone\tEmail\tAppointment Time\n");

    for (int i = 0; i < num_appointments; i++) {
        printf("%s\t%s\t%s\t%s\n", appointments[i].name, appointments[i].phone, appointments[i].email, ctime(&appointments[i].appointment_time));
    }
}

void cancel_appointment() {
    int index;

    printf("\nEnter appointment index to cancel: ");
    scanf("%d", &index);

    if (index >= num_appointments ||!appointments[index].is_booked) {
        printf("\nInvalid appointment index.\n");
        return;
    }

    appointments[index].is_booked = false;
    printf("\nAppointment cancelled successfully.\n");
}

int main() {
    srand(time(NULL));

    printf("\nWelcome to the Appointment Scheduler!\n");
    printf("Press any key to continue...\n");
    getchar();

    while (true) {
        print_menu();

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                cancel_appointment();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}