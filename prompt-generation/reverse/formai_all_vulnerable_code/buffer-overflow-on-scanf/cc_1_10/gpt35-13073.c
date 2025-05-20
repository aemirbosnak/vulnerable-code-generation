//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_APPOINTMENTS 10

typedef struct{
    char name[30];
    char email[50];
    char date[11];
    char time[6];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];

int total_appointments = 0;

void add_appointment(){
    if(total_appointments == MAX_APPOINTMENTS){
        printf("All appointment slots are filled up. Please try again later.\n");
        return;
    }

    printf("Enter your name: ");
    scanf("%s", appointments[total_appointments].name);

    printf("Enter your email address: ");
    scanf("%s", appointments[total_appointments].email);

    printf("Enter the date of your appointment (dd-mm-yyyy): ");
    scanf("%s", appointments[total_appointments].date);

    printf("Enter the time of your appointment (hh:mm): ");
    scanf("%s", appointments[total_appointments].time);

    total_appointments++;

    printf("Appointment added successfully.\n");
}

void list_appointments(){
    if(total_appointments == 0){
        printf("No appointments to show.\n");
        return;
    }

    printf("List of all appointments:\n\n");
    printf("----------------------------------------------------------\n");
    printf("Name\t\tEmail\t\tDate\t\tTime\n");
    printf("----------------------------------------------------------\n");

    for(int i=0; i<total_appointments; i++){
        printf("%s\t%s\t%s\t%s\n",
            appointments[i].name,
            appointments[i].email,
            appointments[i].date,
            appointments[i].time
        );
    }

    printf("----------------------------------------------------------\n");
}

int main(){
    int choice;

    while(1){
        printf("\nWelcome to the appointment scheduler.\n");
        printf("1. Add an appointment\n");
        printf("2. List all appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_appointment();
                break;
            case 2:
                list_appointments();
                break;
            case 3:
                printf("\nThank you for using the appointment scheduler.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
                break;
        }
    }

    return 0;
}