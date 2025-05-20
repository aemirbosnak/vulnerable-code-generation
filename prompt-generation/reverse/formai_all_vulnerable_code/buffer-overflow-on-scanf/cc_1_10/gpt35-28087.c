//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct appointment {
    char name[50];
    char date[20];
    char time[10];
};

void display_appointments(struct appointment a[], int n) {
    printf("\nName\tDate\tTime\n"); 
    for(int i=0; i<n; i++) {
        printf("%s\t%s\t%s\n", a[i].name, a[i].date, a[i].time);
    }
}

void add_appointment(struct appointment a[], int n) {
    printf("\nEnter name: ");
    scanf("%s", a[n].name);
    printf("Enter date (DD/MM/YYYY): ");
    scanf("%s", a[n].date);
    printf("Enter time (24-hr format): ");
    scanf("%s", a[n].time);
}

void delete_appointment(struct appointment a[], int n) {
    char name[50];
    printf("\nEnter name of appointment to be deleted: ");
    scanf("%s", name);
    int index = -1;
    for(int i=0; i<n; i++) {
        if(strcmp(a[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("Appointment not found.\n");
    } else {
        for(int i=index; i<n-1; i++) {
            a[i] = a[i+1];
        }
        printf("Appointment deleted successfully.\n");
    }
}

int main() {
    struct appointment appointments[100];
    int n = 0;
    char choice;

    do {
        printf("\nAppointment Scheduler Menu:\n");
        printf("------------------------------\n");
        printf("1. Display all appointments\n");
        printf("2. Add a new appointment\n");
        printf("3. Delete an appointment\n");
        printf("4. Exit\n");
        printf("\nEnter your choice (1-4): ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                display_appointments(appointments, n);
                break;
            case '2':
                add_appointment(appointments, n);
                n++;
                printf("Appointment added successfully.\n");
                break;
            case '3':
                delete_appointment(appointments, n);
                n--;
                break;
            case '4':
                printf("Thank you for using Appointment Scheduler.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    } while(choice != '4');

    return 0;
}