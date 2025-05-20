//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Romeo and Juliet
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

struct Appointment {
    char description[100];
    int day;
    char month[20];
    int year;
    char time[10];
};

bool isLeapYear(int year) { // function to check leap year
    if(((year % 400) == 0) || (((year % 4) == 0) && ((year % 100) != 0))) {
        return true;
    }
    return false;
}

bool isDateValid(int day, char* month, int year) { // function to validate date
    int monthNo;

    if(strcmp(month, "January") == 0) {
        monthNo = 1;
    } else if(strcmp(month, "February") == 0) {
        monthNo = 2;
    } else if(strcmp(month, "March") == 0) {
        monthNo = 3;
    } else if(strcmp(month, "April") == 0) {
        monthNo = 4;
    } else if(strcmp(month, "May") == 0) {
        monthNo = 5;
    } else if(strcmp(month, "June") == 0) {
        monthNo = 6;
    } else if(strcmp(month, "July") == 0) {
        monthNo = 7;
    } else if(strcmp(month, "August") == 0) {
        monthNo = 8;
    } else if(strcmp(month, "September") == 0) {
        monthNo = 9;
    } else if(strcmp(month, "October") == 0) {
        monthNo = 10;
    } else if(strcmp(month, "November") == 0) {
        monthNo = 11;
    } else if(strcmp(month, "December") == 0) {
        monthNo = 12;
    } else {
        return false;
    }

    int maxDays;

    if(monthNo == 2) { // February month
        if(isLeapYear(year)) {
            maxDays = 29;
        } else {
            maxDays = 28;
        }
    } else if(monthNo == 4 || monthNo == 6 || monthNo == 9 || monthNo == 11) { // months with 30 days
        maxDays = 30;
    } else { // months with 31 days
        maxDays = 31;
    }

    if(day < 1 || day > maxDays) {
        return false;
    }

    return true;
}

void printAppointment(struct Appointment* appointment) { // function to print appointment details
    printf("\nYour appointment is scheduled on %d-%s-%d at %s\n", appointment->day, appointment->month, appointment->year, appointment->time);
    printf("\nAppointment description: %s\n", appointment->description);
}

int main() {
    struct Appointment appointment;

    printf("Enter date of appointment (dd-Month-yyyy): ");
    scanf("%d-%s-%d", &appointment.day, appointment.month, &appointment.year);

    while(!isDateValid(appointment.day, appointment.month, appointment.year)) { // validate date input
        printf("\nInvalid Date!\n");
        printf("Enter date of appointment (dd-Month-yyyy): ");
        scanf("%d-%s-%d", &appointment.day, appointment.month, &appointment.year);
    }

    printf("Enter time of appointment (HH:MM AM/PM): ");
    scanf("%s", appointment.time);

    printf("Enter description of appointment: ");
    getchar(); // to consume enter key stroke
    fgets(appointment.description, 100, stdin);

    printAppointment(&appointment); // print appointment details
    return 0;
}