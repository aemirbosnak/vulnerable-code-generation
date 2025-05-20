//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

struct Appointment {
    int day, month, year;
    char name[20];
    char time[10];
};

struct Appointment schedule[20];

int appointments = 0; //Number of appointments scheduled

void addAppointment() {
    printf("\nEnter Name: ");
    scanf("%s", schedule[appointments].name);
    
    printf("Enter Date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &schedule[appointments].day, &schedule[appointments].month, &schedule[appointments].year);
    
    printf("Enter Time (hh:mm AM/PM): ");
    scanf("%s", schedule[appointments].time);
    
    printf("\nAppointment with %s on %d/%d/%d at %s is scheduled successfully!\n", schedule[appointments].name, schedule[appointments].day, schedule[appointments].month, schedule[appointments].year, schedule[appointments].time);
    appointments++;
}

void viewAppointments() {
    printf("\n%-20s\t%10s\t%10s\n", "Name", "Date", "Time");
    printf("-------------------------------------------\n");
    for(int i=0; i<appointments; i++) {
        printf("%-20s\t%2d/%2d/%4d\t%8s\n", schedule[i].name, schedule[i].day, schedule[i].month, schedule[i].year, schedule[i].time);
    }
    printf("\n");
}

int main() {
    printf("Welcome to Appointment Scheduler!\n\n");
    
    while(1) {
        printf("Select an option:\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Exit\n");
        printf("Option: ");
        
        int option;
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                addAppointment();
                break;
            
            case 2:
                viewAppointments();
                break;
            
            case 3:
                printf("\nThanks for using Appointment Scheduler!\n");
                exit(0);
            
            default:
                printf("\nInvalid option, please try again!\n");
                break;
        }
    }
    
    return 0;
}