//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

struct appointment {
    char date[11];
    char time[6];
    char name[51];
    char phone[11];
    char email[51];
    struct appointment *next;
};

struct appointment *head = NULL;

// Function to validate user input for date
int validateDate(char *date) {
    int day, month, year;
    int leap = 0;
    if(strlen(date) != 10) {
        return 0;
    }
    if(date[2] != '/' || date[5] != '/') {
        return 0;
    }
    day = (date[0] - '0') * 10 + (date[1] - '0');
    month = (date[3] - '0') * 10 + (date[4] - '0');
    year = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');
    if(year % 4 == 0) {
        if(year % 100 == 0) {
            if(year % 400 == 0) {
                leap = 1;
            }
        }
        else {
            leap = 1;
        }
    }
    if(month < 1 || month > 12) {
        return 0;
    }
    if(day < 1 || day > 31) {
        return 0;
    }
    if(month == 2) {
        if(leap == 1) {
            if(day > 29) {
                return 0;
            }
        }
        else {
            if(day > 28) {
                return 0;
            }
        }
    }
    if(month == 4 || month == 6 || month == 9 || month == 11) {
        if(day > 30) {
            return 0;
        }
    }
    return 1;
}

// Function to validate user input for time
int validateTime(char *time) {
    int hour, minute;
    if(strlen(time) != 5) {
        return 0;
    }
    if(time[2] != ':') {
        return 0;
    }
    hour = (time[0] - '0') * 10 + (time[1] - '0');
    minute = (time[3] - '0') * 10 + (time[4] - '0');
    if(hour < 0 ||hour > 23) {
        return 0;
    }
    if(minute < 0 || minute > 59) {
        return 0;
    }
    return 1;
}

// Function to check if user has already scheduled an appointment for the given date and time
int checkAppointment(char *date, char *time) {
    struct appointment *current = head;
    while(current != NULL) {
        if(strcmp(current->date, date) == 0 && strcmp(current->time, time) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// Function to add a new appointment to the scheduler
void addAppointment() {
    char date[11];
    char time[6];
    char name[51];
    char phone[11];
    char email[51];
    struct appointment *newAppointment;
    newAppointment = (struct appointment*)malloc(sizeof(struct appointment));
    printf("Enter appointment date (DD/MM/YYYY): ");
    fflush(stdin);
    gets(date);
    if(validateDate(date) == 0) {
        printf("Invalid date format. Please enter date in DD/MM/YYYY format.\n");
        return;
    }
    printf("Enter appointment time (HH:MM): ");
    fflush(stdin);
    gets(time);
    if(validateTime(time) == 0) {
        printf("Invalid time format. Please enter time in HH:MM format.\n");
        return;
    }
    if(checkAppointment(date, time) == 1) {
        printf("Appointment already scheduled for the given date and time.\n");
        return;
    }
    printf("Enter your name: ");
    fflush(stdin);
    gets(name);
    printf("Enter your phone number: ");
    fflush(stdin);
    gets(phone);
    printf("Enter your email address: ");
    fflush(stdin);
    gets(email);
    strcpy(newAppointment->date, date);
    strcpy(newAppointment->time, time);
    strcpy(newAppointment->name, name);
    strcpy(newAppointment->phone, phone);
    strcpy(newAppointment->email, email);
    newAppointment->next = head;
    head = newAppointment;
    printf("Appointment scheduled successfully!\n");
}

// Function to delete an appointment from the scheduler
void deleteAppointment() {
    char date[11];
    char time[6];
    struct appointment *current = head;
    struct appointment *previous = NULL;
    printf("Enter appointment date to be deleted (DD/MM/YYYY): ");
    fflush(stdin);
    gets(date);
    printf("Enter appointment time to be deleted (HH:MM): ");
    fflush(stdin);
    gets(time);
    while(current != NULL) {
        if(strcmp(current->date, date) == 0 && strcmp(current->time, time) == 0) {
            if(previous == NULL) {
                head = current->next;
            }
            else {
                previous->next = current->next;
            }
            free(current);
            printf("Appointment deleted successfully!\n");
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("No appointment found for the given date and time.\n");
}

// Function to display all appointments in the scheduler
void displayAppointments() {
    struct appointment *current = head;
    if(current == NULL) {
        printf("No appointments scheduled yet.\n");
        return;
    }
    printf("Date\t\tTime\t\tName\t\tPhone\t\tEmail\n");
    while(current != NULL) {
        printf("%s\t%s\t%s\t%s\t%s\n", current->date, current->time, current->name, current->phone, current->email);
        current = current->next;
    }
}

// Function to display menu and get user input
int getMenuChoice() {
    int choice = 0;
    printf("\n**** Welcome to Appointment Scheduler ****\n\n");
    printf("Please select one of the following options:\n");
    printf("1. Schedule an appointment\n");
    printf("2. Delete an appointment\n");
    printf("3. Display all appointments\n");
    printf("4. Exit\n");
    while(choice < 1 || choice > 4) {
        printf("Enter your choice: ");
        fflush(stdin);
        scanf("%d", &choice);
    }
    return choice;
}

int main() {
    int choice;
    while(1) {
        choice = getMenuChoice();
        switch(choice) {
            case 1: addAppointment();
                    break;
            case 2: deleteAppointment();
                    break;
            case 3: displayAppointments();
                    break;
            case 4: exit(0);
        }
    }
    return 0;
}