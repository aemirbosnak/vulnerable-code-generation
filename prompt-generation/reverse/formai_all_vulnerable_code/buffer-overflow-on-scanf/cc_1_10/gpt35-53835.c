//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[30];
    char phone[11];
    int appointment_date;
    int appointment_time;
} Appointment;

Appointment appointment_list[MAX_SIZE];
int num_appointments;

void add_appointment();
void delete_appointment();
void edit_appointment();
void print_appointments();
int check_availability(int date, int time);

int main() {
    int choice;

    do {
        printf("\nWelcome to the appointment scheduler!\n");
        printf("1. Add an appointment\n");
        printf("2. Delete an appointment\n");
        printf("3. Edit an appointment\n");
        printf("4. View appointments\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;

            case 2:
                delete_appointment();
                break;

            case 3:
                edit_appointment();
                break;

            case 4:
                print_appointments();
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Please enter a valid choice!\n");
        }
    } while (1);

    return 0;
}

void add_appointment() {
    char name[30];
    char phone[11];
    int date, time;

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter phone number: ");
    scanf("%s", phone);

    printf("Enter appointment date (DDMMYY): ");
    scanf("%d", &date);

    printf("Enter appointment time (HHMM): ");
    scanf("%d", &time);

    if (check_availability(date, time)) {
        strcpy(appointment_list[num_appointments].name, name);
        strcpy(appointment_list[num_appointments].phone, phone);
        appointment_list[num_appointments].appointment_date = date;
        appointment_list[num_appointments].appointment_time = time;

        printf("Appointment added!\n");
        num_appointments++;
    } else {
        printf("Appointment slot not available!\n");
    }
}

void delete_appointment() {
    int index, date, time;
    char confirm;

    printf("Enter appointment index to delete (starting from 0): ");
    scanf("%d", &index);

    printf("Are you sure you want to delete this appointment? (y/n): ");
    scanf(" %c", &confirm);

    if (confirm == 'y' || confirm == 'Y') {
        date = appointment_list[index].appointment_date;
        time = appointment_list[index].appointment_time;

        for (int i = index; i < num_appointments - 1; i++) {
            appointment_list[i] = appointment_list[i + 1];
        }

        num_appointments--;
        printf("Appointment deleted!\n");

        // check if slot is now available and print message
        if (check_availability(date, time)) {
            printf("Slot is now available for new appointments.\n");
        }
    } else {
        printf("Deletion cancelled.\n");
    }
}

void edit_appointment() {
    int index, date, time;
    char confirm;

    printf("Enter appointment index to edit (starting from 0): ");
    scanf("%d", &index);

    printf("This is the current appointment:\n");
    printf("Name: %s\n", appointment_list[index].name);
    printf("Phone: %s\n", appointment_list[index].phone);
    printf("Date: %d\n", appointment_list[index].appointment_date);
    printf("Time: %d\n", appointment_list[index].appointment_time);

    printf("Are you sure you want to edit this appointment? (y/n): ");
    scanf(" %c", &confirm);

    if (confirm == 'y' || confirm == 'Y') {
        date = appointment_list[index].appointment_date;
        time = appointment_list[index].appointment_time;

        printf("Enter new name (or press enter to keep old name): ");
        scanf("%s", appointment_list[index].name);

        printf("Enter new phone number (or press enter to keep old number): ");
        scanf("%s", appointment_list[index].phone);

        printf("Enter new appointment date (DDMMYY) (or enter 0 to keep old date): ");
        scanf("%d", &date);

        if (date != 0) {
            if (!check_availability(date, time)) {
                printf("Appointment slot not available!\n");
                return;
            }

            appointment_list[index].appointment_date = date;
        }

        printf("Enter new appointment time (HHMM) (or enter 0 to keep old time): ");
        scanf("%d", &time);

        if (time != 0) {
            if (!check_availability(date, time)) {
                printf("Appointment slot not available!\n");
                return;
            }

            appointment_list[index].appointment_time = time;
        }

        printf("Appointment updated!\n");

        // check if slot is now available and print message
        if (check_availability(date, time)) {
            printf("Slot is now available for new appointments.\n");
        }
    } else {
        printf("Edit cancelled.\n");
    }
}

void print_appointments() {
    if (num_appointments == 0) {
        printf("No appointments scheduled.\n");
    } else {
        printf("Scheduled appointments:\n");
        printf("Index    Name                      Phone          Date      Time\n");

        for (int i = 0; i < num_appointments; i++) {
            printf("%-8d %-25s %-13s %08d %04d\n", i, appointment_list[i].name, appointment_list[i].phone, appointment_list[i].appointment_date, appointment_list[i].appointment_time);
        }
    }
}

int check_availability(int date, int time) {
    for (int i = 0; i < num_appointments; i++) {
        if (appointment_list[i].appointment_date == date && appointment_list[i].appointment_time == time) {
            return 0;
        }
    }

    return 1;
}