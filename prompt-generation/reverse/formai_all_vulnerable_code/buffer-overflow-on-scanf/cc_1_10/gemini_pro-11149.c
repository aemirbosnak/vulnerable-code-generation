//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char email[50];
    char phone[20];
    char date[11];
    char time[11];
} appointment;

void add_appointment(appointment *appts, int *num_appts) {
    printf("Enter name: ");
    scanf(" %s", appts[*num_appts].name);

    printf("Enter email: ");
    scanf(" %s", appts[*num_appts].email);

    printf("Enter phone: ");
    scanf(" %s", appts[*num_appts].phone);

    printf("Enter date (YYYY-MM-DD): ");
    scanf(" %s", appts[*num_appts].date);

    printf("Enter time (HH:MM): ");
    scanf(" %s", appts[*num_appts].time);

    (*num_appts)++;
}

void print_appointments(appointment *appts, int num_appts) {
    printf("\nAppointments:\n");
    for (int i = 0; i < num_appts; i++) {
        printf("Name: %s\n", appts[i].name);
        printf("Email: %s\n", appts[i].email);
        printf("Phone: %s\n", appts[i].phone);
        printf("Date: %s\n", appts[i].date);
        printf("Time: %s\n\n", appts[i].time);
    }
}

void search_appointments(appointment *appts, int num_appts) {
    char search_term[50];
    printf("Enter search term: ");
    scanf(" %s", search_term);

    int found = 0;
    for (int i = 0; i < num_appts; i++) {
        if (strstr(appts[i].name, search_term) != NULL ||
            strstr(appts[i].email, search_term) != NULL ||
            strstr(appts[i].phone, search_term) != NULL ||
            strstr(appts[i].date, search_term) != NULL ||
            strstr(appts[i].time, search_term) != NULL) {
            printf("Name: %s\n", appts[i].name);
            printf("Email: %s\n", appts[i].email);
            printf("Phone: %s\n", appts[i].phone);
            printf("Date: %s\n", appts[i].date);
            printf("Time: %s\n\n", appts[i].time);
            found = 1;
        }
    }

    if (!found) {
        printf("No appointments found.\n");
    }
}

int main() {
    appointment appts[100];
    int num_appts = 0;

    int choice;
    do {
        printf("1. Add appointment\n");
        printf("2. Print appointments\n");
        printf("3. Search appointments\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                add_appointment(appts, &num_appts);
                break;
            case 2:
                print_appointments(appts, num_appts);
                break;
            case 3:
                search_appointments(appts, num_appts);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}