//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* struct to hold appointment details */
struct Appointment {
    char name[50];
    char date[20];
    char time[20];
};

/* function to display menu options */
void display_menu() {
    printf("Appointment Scheduler\n");
    printf("1. Add Appointment\n");
    printf("2. Show Appointments\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    struct Appointment appointment_list[100]; // array to store appointments
    int appointment_count = 0; // counter to keep track of number of appointments
    
    while(1) {
        display_menu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nEnter Name: ");
                scanf("%s", appointment_list[appointment_count].name);
                printf("Enter Date (dd/mm/yyyy): ");
                scanf("%s", appointment_list[appointment_count].date);
                printf("Enter Time (hh:mm): ");
                scanf("%s", appointment_list[appointment_count].time);
                printf("\nAppointment added successfully!\n");
                appointment_count++;
                break;
            case 2:
                printf("\nAppointment List:\n");
                printf("Name\t\tDate\t\tTime\n");
                for(int i=0; i<appointment_count; i++) {
                    printf("%s\t\t%s\t\t%s\n", appointment_list[i].name, appointment_list[i].date, appointment_list[i].time);
                }
                break;
            case 3:
                printf("\nThank you for using our system!\n");
                exit(0); // terminate program
            default:
                printf("\nInvalid choice. Please enter a valid option from the menu.\n");
                break;
        }
    }
    
    return 0;
}