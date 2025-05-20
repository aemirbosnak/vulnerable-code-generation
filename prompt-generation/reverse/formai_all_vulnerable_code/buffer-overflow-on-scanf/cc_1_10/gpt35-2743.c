//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold appointment details
struct Appointment {
    char name[100];
    char date[20];
    char time[20];
};

// Function to add a new appointment
void addAppointment(struct Appointment *app, int *total) {
    printf("Enter name: ");
    scanf("%s", app[*total].name);
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", app[*total].date);
    printf("Enter time (hh:mm): ");
    scanf("%s", app[*total].time);
    (*total)++;
}

// Function to search for an appointment by name or date
void searchAppointment(struct Appointment *app, int total) {
    char search[100];
    printf("Enter name or date to search for: ");
    scanf("%s", search);
    for (int i = 0; i < total; i++) {
        if (strcmp(app[i].name, search) == 0 || strcmp(app[i].date, search) == 0) {
            printf("Appointment found!\n");
            printf("Name: %s\nDate: %s\nTime: %s\n", app[i].name, app[i].date, app[i].time);
            return;
        }
    }
    printf("No appointments found.\n");
}

// Function to delete an appointment by name or date
void deleteAppointment(struct Appointment *app, int *total) {
    char search[100];
    printf("Enter name or date of appointment to delete: ");
    scanf("%s", search);
    for (int i = 0; i < *total; i++) {
        if (strcmp(app[i].name, search) == 0 || strcmp(app[i].date, search) == 0) {
            for (int j = i; j < *total - 1; j++) {
                strcpy(app[j].name, app[j+1].name);
                strcpy(app[j].date, app[j+1].date);
                strcpy(app[j].time, app[j+1].time);
            }
            (*total)--;
            printf("Appointment deleted.\n");
            return;
        }
    }
    printf("Appointment not found.\n");
}

int main() {
    struct Appointment appointments[100];
    int total = 0;
    int choice;
    while (1) {
        printf("\nAppointment scheduler:\n");
        printf("1. Add appointment\n");
        printf("2. Search appointment\n");
        printf("3. Delete appointment\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addAppointment(appointments, &total);
                break;
            case 2:
                searchAppointment(appointments, total);
                break;
            case 3:
                deleteAppointment(appointments, &total);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}