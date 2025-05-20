//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

struct Appointment {
    int day;
    int month;
    int year;
    char description[100];
};

struct Appointment appointments[MAX_APPOINTMENTS];
int num_of_appointments = 0;

bool is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int days_in_month(int month, int year) {
    switch(month) {
        case 2:
            if (is_leap_year(year))
                return 29;
            else 
                return 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

void print_appointments() {
    printf("Appointments:\n");
    for (int i = 0; i < num_of_appointments; i++) {
        printf("%d/%d/%d - %s\n", appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].description);
    }
}

void add_appointment() {
    if (num_of_appointments == MAX_APPOINTMENTS) { // check if we've reached max number of appointments
        printf("Sorry, you cannot schedule any more appointments.\n");
        return;
    }

    struct Appointment new_appointment;

    printf("Enter date (dd/mm/yyyy):\n");
    scanf("%d/%d/%d", &new_appointment.day, &new_appointment.month, &new_appointment.year);

    if (new_appointment.day < 1 || new_appointment.day > days_in_month(new_appointment.month, new_appointment.year) \
        || new_appointment.month < 1 || new_appointment.month > 12 \
        || new_appointment.year < 2021) { // basic input validation
        printf("Invalid date.\n");
        return;
    }

    printf("Enter description:\n");
    scanf(" %[^\n]s", new_appointment.description); // read full line of input including spaces

    appointments[num_of_appointments++] = new_appointment; // add new appointment to array and increment num_of_appointments
    printf("Appointment scheduled successfully.\n");
}

void remove_appointment() {
    printf("Enter date of appointment to remove (dd/mm/yyyy):\n");

    int day, month, year;
    scanf("%d/%d/%d", &day, &month, &year);

    for (int i = 0; i < num_of_appointments; i++) { // loop through appointments to see if there's a match
        if (appointments[i].day == day && appointments[i].month == month && appointments[i].year == year) {
            for (int j = i; j < num_of_appointments - 1; j++) { // shift appointments left to fill gap
                appointments[j] = appointments[j + 1];
            }
            num_of_appointments--; // decrement num_of_appointments
            printf("Appointment removed successfully.\n");
            return;
        }
    }

    printf("No matching appointment found.\n");
}

int main() {
    int option;

    do {
        printf("\nAppointment Scheduler\n");
        printf("====================\n");
        printf("1. Add appointment\n");    
        printf("2. Remove appointment\n");
        printf("3. View appointments\n");
        printf("4. Exit\n");
        printf("Enter option:\n");

        scanf("%d", &option);

        switch (option) {
            case 1:
                add_appointment();
                break;
            case 2:
                remove_appointment();
                break;
            case 3:
                print_appointments();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while(option != 4);

    return 0;
}