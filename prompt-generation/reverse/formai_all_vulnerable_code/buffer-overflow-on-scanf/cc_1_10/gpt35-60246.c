//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Appointment {
    char name[50];
    char date[20];
    char time[20];
};

struct Appointment appts[50];
int num_appts = 0;

void print_appts() {
    printf("\nAPPOINTMENTS:\n");
    for (int i = 0; i < num_appts; i++) {
        printf("Appointment %d:\n", i+1);
        printf("Name: %s\n", appts[i].name);
        printf("Date: %s\n", appts[i].date);
        printf("Time: %s\n", appts[i].time);
    }
}

void create_appt() {
    char name[50];
    char date[20];
    char time[20];
    printf("\nEnter name: ");
    scanf("%s", name);
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", date);
    printf("Enter time (hh:mm): ");
    scanf("%s", time);
    strcpy(appts[num_appts].name, name);
    strcpy(appts[num_appts].date, date);
    strcpy(appts[num_appts].time, time);
    num_appts++;
}

void delete_appt() {
    int index;
    printf("\nEnter the number of the appointment to delete: ");
    scanf("%d", &index);
    if (index > 0 && index <= num_appts) {
        for (int i = index-1; i < num_appts; i++) {
            appts[i] = appts[i+1];
        }
        num_appts--;
    }
    else {
        printf("Invalid appointment number.\n");
    }
}

int main() {
    int option = 0;
    while (option != 4) {
        printf("\nAPPOINTMENT SCHEDULER\n");
        printf("1. View Appointments\n");
        printf("2. Create Appointment\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                print_appts();
                break;
            case 2:
                create_appt();
                break;
            case 3:
                delete_appt();
                break;
            case 4:
                printf("Exiting...");
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    }
    return 0;
}