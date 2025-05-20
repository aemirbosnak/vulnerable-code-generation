//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Ada Lovelace
/* This is a program written in C for an appointment scheduler.
 * It allows the user to schedule new appointments, view existing 
 * appointments, and cancel appointments. The program uses an array 
 * of structures to hold information about each appointment, and 
 * also includes functions to handle user input and display data. */

#include <stdio.h>

/* define a struct to hold appointment data */
struct appointment {
    int day;
    int month;
    int year;
    char description[50];
};

/* define a function to get user input for a new appointment */
struct appointment get_appointment() {
    struct appointment appt;
    printf("Enter date (dd mm yyyy): ");
    scanf("%d %d %d", &appt.day, &appt.month, &appt.year);
    printf("Enter description (max 50 characters): ");
    scanf("%s", appt.description);
    return appt;
}

/* define a function to display an appointment */
void display_appointment(struct appointment appt) {
    printf("%02d/%02d/%4d - %s\n", appt.day, appt.month, appt.year, appt.description);
}

/* define a function to display all appointments */
void display_all_appointments(struct appointment appts[], int count) {
    printf("Appointments:\n");
    for (int i=0; i<count; i++) {
        display_appointment(appts[i]);
    }
}

/* define a function to find an appointment by date */
int find_appointment(struct appointment appts[], int count, int day, int month, int year) {
    for (int i=0; i<count; i++) {
        if (appts[i].day == day && appts[i].month == month && appts[i].year == year) {
            return i; /* return index of matching appointment */
        }
    }
    return -1; /* return -1 if no matching appointment found */
}

/* define a function to cancel an appointment */
void cancel_appointment(struct appointment appts[], int count) {
    int day, month, year, index;
    printf("Enter date of appointment to cancel (dd mm yyyy): ");
    scanf("%d %d %d", &day, &month, &year);
    index = find_appointment(appts, count, day, month, year);
    if (index == -1) {
        printf("No appointment found on that day.\n");
    } else {
        for (int i=index; i<count-1; i++) {
            appts[i] = appts[i+1]; /* shift appointments left to remove cancelled appointment */
        }
        printf("Appointment on %02d/%02d/%4d has been cancelled.\n", day, month, year);
    }
}

/* main program loop */
int main() {
    struct appointment appts[50];
    int count = 0;
    char choice;

    /* display menu and respond to user input */
    while (1) {
        printf("\nAppointment Scheduler\n");
        printf("1. Schedule a new appointment\n");
        printf("2. View existing appointments\n");
        printf("3. Cancel an appointment\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                if (count == 50) {
                    printf("Maximum number of appointments reached.\n");
                } else {
                    appts[count] = get_appointment();
                    count++;
                }
                break;
            case '2':
                display_all_appointments(appts, count);
                break;
            case '3':
                cancel_appointment(appts, count);
                count--;
                break;
            case '4':
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}