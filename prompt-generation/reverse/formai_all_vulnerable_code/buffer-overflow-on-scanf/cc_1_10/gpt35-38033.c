//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: multivariable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct appointment {
    char name[50];
    char date[20];
    char time[20];
};

void addAppointment(struct appointment arr[], int *num_appointments) {
    printf("Enter name: ");
    scanf("%s", arr[*num_appointments].name);
    printf("Enter date (MM/DD/YYYY): ");
    scanf("%s", arr[*num_appointments].date);
    printf("Enter time (HH:MM AM/PM): ");
    scanf("%s", arr[*num_appointments].time);
    *num_appointments += 1;
}

void printAppointments(struct appointment arr[], int num_appointments) {
    printf("%-15s %-15s %-15s\n", "Name", "Date", "Time");
    printf("--------------------------------------\n");
    for(int i=0; i<num_appointments; i++) {
        printf("%-15s %-15s %-15s\n", arr[i].name, arr[i].date, arr[i].time);
    }
}

void searchAppointments(struct appointment arr[], int num_appointments) {
    printf("Enter name to search: ");
    char search_name[50];
    scanf("%s", search_name);
    int search_count = 0;
    for(int i=0; i<num_appointments; i++) {
        if(strcmp(search_name, arr[i].name) == 0) {
            printf("%-15s %-15s %-15s\n", arr[i].name, arr[i].date, arr[i].time);
            search_count++;
        }
    }
    if(search_count == 0) {
        printf("No appointments found for %s\n", search_name);
    }
}

int main() {
    struct appointment appointments[50];
    int num_appointments = 0;
    int choice;
    do {
        printf("\nAppointment Scheduler Menu\n");
        printf("--------------------------\n");
        printf("1. Add Appointment\n");
        printf("2. Print Appointments\n");
        printf("3. Search Appointments\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                if(num_appointments < 50) {
                    addAppointment(appointments, &num_appointments);
                }
                else {
                    printf("Appointment scheduler is full!\n");
                }
                break;
            case 2:
                if(num_appointments > 0) {
                    printAppointments(appointments, num_appointments);
                }
                else {
                    printf("No appointments found!\n");
                }
                break;
            case 3:
                if(num_appointments > 0) {
                    searchAppointments(appointments, num_appointments);
                }
                else {
                    printf("No appointments found!\n");
                }
                break;
            case 4:
                printf("Exiting appointment scheduler...\n");
                break;
            default:
                printf("Invalid choice, please try again!\n");
        }
    } while(choice != 4);
    return 0;
}