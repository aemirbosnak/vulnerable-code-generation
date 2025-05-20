//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100 // Maximum number of appointments

typedef struct Appointment {
    char name[30];
    char date[20];
    char time[20];
    char reason[50];
} appointment;

// Global Variables
appointment appointments[MAX];
int num_appointments = 0;

// Function prototypes
void menu();
void add_appointment();
void list_appointments();
void search_appointment();
void delete_appointment();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice = 0;

    do {
        printf("Welcome to the Appointment Scheduler!\n\n");
        printf("1. Add Appointment\n");
        printf("2. List Appointments\n");
        printf("3. Search for Appointment\n");
        printf("4. Delete Appointment\n");
        printf("5. Exit\n");

        printf("\nPlease enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                list_appointments();
                break;
            case 3:
                search_appointment();
                break;
            case 4:
                delete_appointment();
                break;
            case 5:
                printf("Thank you for using the Appointment Scheduler!\n\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n\n");
        }
    } while (choice != 5);
}

void add_appointment() {
    if (num_appointments >= MAX) {
        printf("Sorry, you have reached the maximum number of appointments.\n\n");
        return;
    }

    printf("Please enter the following information:\n");

    printf("Name: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Date (MM/DD/YYYY): ");
    scanf("%s", appointments[num_appointments].date);

    printf("Time (HH:MM AM/PM): ");
    scanf("%s", appointments[num_appointments].time);

    printf("Reason for Appointment: ");
    scanf("%s", appointments[num_appointments].reason);

    num_appointments++;

    printf("Appointment added successfully!\n\n");
}

void list_appointments() {
    if (num_appointments == 0) {
        printf("No appointments to display.\n\n");
        return;
    }

    printf("List of Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s\n", appointments[i].name);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
        printf("Reason: %s\n\n", appointments[i].reason);
    }
}

void search_appointment() {
    if (num_appointments == 0) {
        printf("No appointments to search.\n\n");
        return;
    }

    char name[30];
    printf("Please enter the name of the appointment you want to search: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(name, appointments[i].name) == 0) {
            found = 1;

            printf("%s\n", appointments[i].name);
            printf("Date: %s\n", appointments[i].date);
            printf("Time: %s\n", appointments[i].time);
            printf("Reason: %s\n\n", appointments[i].reason);

            break;
        }
    }

    if (!found) {
        printf("Appointment not found.\n\n");
    }
}

void delete_appointment() {
    if (num_appointments == 0) {
        printf("No appointments to delete.\n\n");
        return;
    }

    char name[30];
    printf("Please enter the name of the appointment you want to delete: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(name, appointments[i].name) == 0) {
            found = 1;

            for (int j = i; j < num_appointments - 1; j++) {
                strcpy(appointments[j].name, appointments[j + 1].name);
                strcpy(appointments[j].date, appointments[j + 1].date);
                strcpy(appointments[j].time, appointments[j + 1].time);
                strcpy(appointments[j].reason, appointments[j + 1].reason);
            }

            num_appointments--;
            printf("Appointment deleted successfully!\n\n");

            break;
        }
    }

    if (!found) {
        printf("Appointment not found.\n\n");
    }
}