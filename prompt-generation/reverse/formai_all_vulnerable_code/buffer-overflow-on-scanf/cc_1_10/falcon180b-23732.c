//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    struct tm appointment_date;
    int appointment_time;
} Appointment;

int num_appointments = 0;
Appointment appointments[MAX_APPOINTMENTS];

void add_appointment() {
    if (num_appointments == MAX_APPOINTMENTS) {
        printf("Sorry, no more appointments can be added.\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    printf("Enter your name: ");
    scanf("%s", name);

    char date_str[MAX_DATE_LENGTH];
    printf("Enter the appointment date (YYYY-MM-DD): ");
    scanf("%s", date_str);

    int time;
    printf("Enter the appointment time (HH:MM): ");
    scanf("%d", &time);

    struct tm appointment_date;
    strptime(date_str, "%Y-%m-%d", &appointment_date);

    appointments[num_appointments].name[0] = '\0';
    strcpy(appointments[num_appointments].name, name);
    appointments[num_appointments].appointment_date = appointment_date;
    appointments[num_appointments].appointment_time = time;

    num_appointments++;
    printf("Appointment added successfully.\n");
}

void view_appointments() {
    if (num_appointments == 0) {
        printf("No appointments found.\n");
        return;
    }

    printf("Name\tAppointment Date\tAppointment Time\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s\t%s\t\t%d\n", appointments[i].name, ctime(&appointments[i].appointment_date.tm_sec), appointments[i].appointment_time);
    }
}

int main() {
    printf("Welcome to the appointment scheduler!\n");

    char choice;
    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                add_appointment();
                break;
            case '2':
                view_appointments();
                break;
            case '3':
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}