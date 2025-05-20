//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: all-encompassing
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int num_of_slots = 10; // number of available appointment slots per day

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[50];
    char phone[15];
    Date date;
    int slot;
} Appointment;

Appointment appointments[31][10]; // array to store appointments for each day

void printMenu() {
    printf("Appointment Scheduler\n");
    printf("1. View appointments\n");
    printf("2. Add appointment\n");
    printf("3. Cancel appointment\n");
    printf("4. Exit\n");
}

void printAppointments(Date date) {
    printf("Appointments for %d/%d/%d\n", date.month, date.day, date.year);
    printf("Time\tName\tPhone\n");
    for (int i = 0; i < num_of_slots; i++) {
        printf("%d\t", i+9); // print time slot (9am-6pm)
        if(appointments[date.day-1][i].name[0]=='\0') {
            printf("Available\n"); // no appointment in this slot
        }
        else {
            printf("%s\t%s\n", appointments[date.day-1][i].name, appointments[date.day-1][i].phone); // print appointment information
        }
    }
    printf("\n");
}

void addAppointment() {
    Date date;
    int slot;
    char name[50];
    char phone[15];

    printf("Enter date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &date.month, &date.day, &date.year);

    if(date.month < 1 || date.month > 12 || date.day < 1 || date.day > 31 || date.year < 2021) { // check if date is valid
        printf("Invalid date\n");
        return;
    }

    printAppointments(date); // display available slots
    printf("Enter time slot (9-18): ");
    scanf("%d", &slot);

    if(slot < 9 || slot > 18) { // check if time slot is valid
        printf("Invalid time slot\n");
        return;
    }
    else if(appointments[date.day-1][slot-9].name[0]!='\0') { // check if time slot is already booked
        printf("Slot already booked\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter phone number: ");
    scanf("%s", phone);

    Appointment newAppointment = { .date = date, .slot = slot-9 }; // subtract 9 from slot to store as array index
    strcpy(newAppointment.name, name);
    strcpy(newAppointment.phone, phone);

    appointments[date.day-1][slot-9] = newAppointment; // add new appointment to array
    printf("Appointment added successfully\n\n");
}

void cancelAppointment() {
    Date date;
    int slot;

    printf("Enter date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &date.month, &date.day, &date.year);

    if(date.month < 1 || date.month > 12 || date.day < 1 || date.day > 31 || date.year < 2021) { // check if date is valid
        printf("Invalid date\n");
        return;
    }

    printAppointments(date); // display appointments for selected date
    printf("Enter time slot (9-18): ");
    scanf("%d", &slot);

    if(slot < 9 || slot > 18) { // check if time slot is valid
        printf("Invalid time slot\n");
        return;
    }
    else if(appointments[date.day-1][slot-9].name[0]=='\0') { // check if no appointment in this slot
        printf("There is no appointment in this slot\n");
        return;
    }

    appointments[date.day-1][slot-9].name[0] = '\0'; // delete appointment from array
    printf("Appointment cancelled successfully\n\n");
}

int main() {
    int option = 0;

    while (option != 4) {
        printMenu();
        printf("Enter an option: ");
        scanf("%d", &option);

        switch(option) {
            case 1: {
                Date date;
                printf("Enter date (mm/dd/yyyy): ");
                scanf("%d/%d/%d", &date.month, &date.day, &date.year);
                if(date.month < 1 || date.month > 12 || date.day < 1 || date.day > 31 || date.year < 2021) { // check if date is valid
                    printf("Invalid date\n");
                }
                else {
                    printAppointments(date);
                }
                break;
            }
            case 2: {
                addAppointment();
                break;
            }
            case 3: {
                cancelAppointment();
                break;
            }
            case 4: {
                printf("Exiting program\n");
                break;
            }
            default: {
                printf("Invalid option\n");
                break;
            }
        }
    }

    return 0;
}