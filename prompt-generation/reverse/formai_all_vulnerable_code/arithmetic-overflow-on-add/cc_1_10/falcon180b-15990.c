//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char email[MAX_LENGTH];
    char reason[MAX_LENGTH];
    time_t appointment_time;
} Appointment;

void print_appointment(Appointment appointment) {
    printf("Name: %s\n", appointment.name);
    printf("Phone: %s\n", appointment.phone);
    printf("Email: %s\n", appointment.email);
    printf("Reason: %s\n", appointment.reason);
    printf("Appointment Time: %s\n\n", ctime(&appointment.appointment_time));
}

int main() {
    int choice;
    char name[MAX_LENGTH], phone[MAX_LENGTH], email[MAX_LENGTH], reason[MAX_LENGTH];
    time_t appointment_time;

    do {
        printf("1. Schedule an appointment\n");
        printf("2. View appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter your name: ");
                scanf("%s", name);
                printf("Enter your phone number: ");
                scanf("%s", phone);
                printf("Enter your email: ");
                scanf("%s", email);
                printf("Enter the reason for your appointment: ");
                scanf("%s", reason);
                appointment_time = time(NULL) + 60*60*24*7; // One week from now
                break;
            case 2:
                system("clear"); // Clear the console
                printf("Appointment Schedule:\n\n");
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 3);

    return 0;
}