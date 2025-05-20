//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main() {
    char* monthNames[12] = {
        "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
    };

    char* dayNames[7] = {
        "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
    };

    int year = 2022;
    int month = 5;
    int day = 15;

    printf("Welcome to the Cheerful Appointment Scheduler!\n");
    printf("Today is %s %s, %d.\n", monthNames[month-1], dayNames[day], year);

    printf("Enter the appointment time (HH:MM AM/PM): ");
    char time[6];
    scanf("%s", time);

    time_t appointmentTime = strptime(time, "%I:%M %p", NULL);
    char* appointmentDate = ctime(&appointmentTime);

    printf("Your appointment is scheduled for %s.\n", appointmentDate);

    printf("Enter the event name: ");
    char eventName[100];
    scanf("%s", eventName);

    printf("Enter the contact information (name, email, phone): ");
    char contactInfo[100][100];
    scanf("%s %s %s", contactInfo[0], contactInfo[1], contactInfo[2]);

    printf("Do you want to save this appointment? (y/n): ");
    char saveAppointment[1];
    scanf("%s", saveAppointment);

    if (tolower(*saveAppointment) == 'y') {
        printf("Appointment saved!\n");
    } else {
        printf("Appointment not saved.\n");
    }

    return 0;
}