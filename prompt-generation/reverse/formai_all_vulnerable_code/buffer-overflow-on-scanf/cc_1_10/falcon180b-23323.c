//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 20
#define MAX_EMAIL_LENGTH 50

struct appointment {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    time_t date_and_time;
};

void add_appointment(struct appointment *appointments[], int count) {
    printf("Enter name: ");
    scanf("%s", appointments[count]->name);

    printf("Enter phone number: ");
    scanf("%s", appointments[count]->phone_number);

    printf("Enter email: ");
    scanf("%s", appointments[count]->email);

    printf("Enter date and time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", appointments[count]->date_and_time);

    count++;
}

void view_appointments(struct appointment *appointments[], int count) {
    printf("Appointments:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", appointments[i]->name);
        printf("Phone number: %s\n", appointments[i]->phone_number);
        printf("Email: %s\n", appointments[i]->email);
        printf("Date and time: %s\n\n", ctime(&appointments[i]->date_and_time));
    }
}

void delete_appointment(struct appointment *appointments[], int count) {
    printf("Enter name to delete appointment: ");
    scanf("%s", appointments[count]->name);
    count--;
}

int main() {
    struct appointment *appointments[MAX_APPOINTMENTS];
    int count = 0;

    while (count < MAX_APPOINTMENTS) {
        printf("1. Add appointment\n2. View appointments\n3. Delete appointment\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment(appointments, count);
                break;
            case 2:
                view_appointments(appointments, count);
                break;
            case 3:
                delete_appointment(appointments, count);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}