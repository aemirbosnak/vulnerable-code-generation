//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to take input from user for date and time
void getInput(int *day, int *month, int *year, int *hour, int *minute) {
    printf("Enter the date in dd/mm/yyyy format: ");
    scanf("%d/%d/%d", day, month, year);
    printf("Enter the time in HH:MM format (24 hour clock): ");
    scanf("%d:%d", hour, minute);
}

// Function to check if the given date and time is valid
int isValid(int day, int month, int year, int hour, int minute) {
    if (year < 2021) {
        return 0;
    }
    if (month < 1 || month > 12) {
        return 0;
    }
    if (day < 1 || day > 31) {
        return 0;
    }
    if (hour < 0 || hour > 23) {
        return 0;
    }
    if (minute < 0 || minute > 59) {
        return 0;
    }
    return 1;
}

// Function to generate a random appointment number
int generateAppointmentNumber() {
    srand(time(NULL));
    return rand() % 1000 + 1;
}

// Main function to schedule appointment
int main() {
    char name[50];
    int day, month, year, hour, minute, appointmentNo;

    printf("Welcome to our appointment scheduler!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Hi %s, please provide the following information to schedule your appointment.\n", name);

    // Get input from user
    getInput(&day, &month, &year, &hour, &minute);

    // Check if input is valid
    if (!isValid(day, month, year, hour, minute)) {
        printf("Invalid date/time provided. Exiting...\n");
        return 1;
    }

    // Generate appointment number and display confirmation
    appointmentNo = generateAppointmentNumber();
    printf("Congratulations %s, your appointment has been scheduled!\n", name);
    printf("Appointment details: \n");
    printf("Date: %d/%d/%d\n", day, month, year);
    printf("Time: %d:%d\n", hour, minute);
    printf("Appointment number: %d\n", appointmentNo);

    return 0;
}