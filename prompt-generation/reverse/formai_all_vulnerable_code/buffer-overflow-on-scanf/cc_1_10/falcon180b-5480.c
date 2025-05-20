//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 20
#define MAX_EMAIL_LEN 50

struct appointment {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    char email[MAX_EMAIL_LEN];
    time_t start_time;
    time_t end_time;
    int duration;
    char notes[MAX_NAME_LEN];
};

struct appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    char name[MAX_NAME_LEN], phone[MAX_PHONE_LEN], email[MAX_EMAIL_LEN], notes[MAX_NAME_LEN];
    time_t start_time, end_time;
    int duration;

    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter phone: ");
    scanf("%s", phone);
    printf("Enter email: ");
    scanf("%s", email);
    printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", &start_time);
    printf("Enter end time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", &end_time);
    printf("Enter duration (in minutes): ");
    scanf("%d", &duration);
    printf("Enter notes: ");
    scanf("%s", notes);

    strcpy(appointments[num_appointments].name, name);
    strcpy(appointments[num_appointments].phone, phone);
    strcpy(appointments[num_appointments].email, email);
    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].end_time = end_time;
    appointments[num_appointments].duration = duration;
    strcpy(appointments[num_appointments].notes, notes);

    num_appointments++;
}

void view_appointments() {
    printf("Name\tPhone\tEmail\tStart Time\tEnd Time\tDuration\tNotes\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s\t%s\t%s\t%s\t%s\t%d\t%s\n", appointments[i].name, appointments[i].phone, appointments[i].email, ctime(&appointments[i].start_time), ctime(&appointments[i].end_time), appointments[i].duration, appointments[i].notes);
    }
}

void delete_appointment() {
    int appt_num;

    printf("Enter appointment number to delete: ");
    scanf("%d", &appt_num);

    if (appt_num >= 0 && appt_num < num_appointments) {
        num_appointments--;
        for (int i = appt_num; i < num_appointments; i++) {
            memcpy(&appointments[i], &appointments[i+1], sizeof(struct appointment));
        }
    } else {
        printf("Invalid appointment number.\n");
    }
}

int main() {
    printf("Appointment Scheduler\n");
    while (1) {
        printf("\n1. Add appointment\n2. View appointments\n3. Delete appointment\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                delete_appointment();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}