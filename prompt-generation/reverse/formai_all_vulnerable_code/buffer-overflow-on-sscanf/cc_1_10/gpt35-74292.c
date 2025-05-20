//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 20

struct Appointment {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    int hour;
    int minute;
};

int count = 0;
struct Appointment appointments[MAX_APPOINTMENTS];

void menu();
void bookAppointment();
void displayAppointments();
int validateTime(int hour, int minute);
int validateDate(char date[]);
int isDuplicate(char name[], char date[], int hour, int minute);

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    do {
        printf("\n\n -----Appointment Scheduler Menu----- \n\n");
        printf("1. Book an appointment\n");
        printf("2. Display appointments\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: bookAppointment();
                    break;
            case 2: displayAppointments();
                    break;
            case 3: printf("\nThank you for using the Appointment Scheduler!");
                    exit(0);
            default: printf("\nInvalid choice! Please try again.");
                     break;
        }
    } while(choice != 3);
}

void bookAppointment() {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    int hour, minute;

    printf("\nEnter your name: ");
    scanf("%s", name);

    printf("Enter the date (MM/DD/YYYY): ");
    scanf("%s", date);

    printf("Enter the time (in 24 hour HH:MM format): ");
    scanf("%d:%d", &hour, &minute);

    // Validate time and date
    if(validateTime(hour, minute) && validateDate(date)) {
        if(!isDuplicate(name, date, hour, minute)) {
            strcpy(appointments[count].name, name);
            strcpy(appointments[count].date, date);
            appointments[count].hour = hour;
            appointments[count].minute = minute;
            count++;
            printf("\nAppointment booked successfully!\n");
        } else {
            printf("\nSorry, an appointment with the same details already exists! Please try again.\n");
        }
    } else {
        printf("\nInvalid time or date! Please try again.\n");
    }
}

void displayAppointments() {
    if(count == 0) {
        printf("\nNo appointments scheduled!\n");
    } else {
        printf("\n-------------Scheduled Appointments-------------\n");
        printf("%-20s %-15s %-10s\n", "Name", "Date", "Time");
        for(int i=0; i<count; i++) {
            printf("%-20s %-15s %02d:%02d\n", appointments[i].name, appointments[i].date, appointments[i].hour, appointments[i].minute);
        }
        printf("\nTotal number of appointments scheduled: %d\n", count);
    }
}

int validateTime(int hour, int minute) {
    if(hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59) {
        return 1;
    }
    return 0;
}

int validateDate(char date[]) {
    int month, day, year;
    if(sscanf(date, "%d/%d/%d", &month, &day, &year) == 3) {
        if(month>=1 && month<=12 && day>=1 && day<=31 && year>=2021) {
            return 1;
        }
    }
    return 0;
}

int isDuplicate(char name[], char date[], int hour, int minute) {
    for(int i=0; i<count; i++) {
        if(strcmp(name, appointments[i].name) == 0 && strcmp(date, appointments[i].date) == 0 && hour == appointments[i].hour && minute == appointments[i].minute) {
            return 1;
        }
    }
    return 0;
}