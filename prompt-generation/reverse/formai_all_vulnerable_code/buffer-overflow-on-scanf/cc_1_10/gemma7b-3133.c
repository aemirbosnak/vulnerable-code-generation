//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 5

typedef struct Appointment {
    char name[50];
    char email[50];
    char phone[20];
    char date[20];
    char time[20];
} Appointment;

int main() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    int year = tm->tm_year + 1900;
    int month = tm->tm_mon + 1;
    int day = tm->tm_mday;

    Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;

    // Display current date
    printf("Current Date: %d/%d/%d", month, day, year);

    // Loop to get appointments
    while (1) {
        // Get the appointment name, email, phone, date, and time
        printf("Enter your name: ");
        scanf("%s", appointments[numAppointments].name);

        printf("Enter your email address: ");
        scanf("%s", appointments[numAppointments].email);

        printf("Enter your phone number: ");
        scanf("%s", appointments[numAppointments].phone);

        printf("Enter the date of your appointment (dd/mm/yyyy): ");
        scanf("%s", appointments[numAppointments].date);

        printf("Enter the time of your appointment (hh:mm): ");
        scanf("%s", appointments[numAppointments].time);

        // Increment the number of appointments
        numAppointments++;

        // Check if the user wants to continue
        char continue_yn;
        printf("Do you want to continue? (y/n): ");
        scanf("%c", &continue_yn);

        // Break out of the loop if the user does not want to continue
        if (continue_yn == 'n') {
            break;
        }
    }

    // Print the appointments
    printf("Your appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("Name: %s\n", appointments[i].name);
        printf("Email: %s\n", appointments[i].email);
        printf("Phone: %s\n", appointments[i].phone);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
        printf("\n");
    }

    return 0;
}