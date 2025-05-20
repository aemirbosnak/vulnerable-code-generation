//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct appointment{
    char name[30];
    char date[30];
    char time[30];
};

int main(){
    
    struct appointment appointments[50];
    int num_appointments = 0;

    printf("Welcome to the Appointment Scheduler!\n\n");

    while(1){

        //display menu options to the user
        printf("Enter 1 to schedule a new appointment\n");
        printf("Enter 2 to view existing appointments\n");
        printf("Enter 3 to exit the program\n\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1){

            printf("Enter the name for the appointment: ");
            scanf("%s", appointments[num_appointments].name);

            printf("Enter the date for the appointment (dd/mm/yyyy): ");
            scanf("%s", appointments[num_appointments].date);

            printf("Enter the time for the appointment (hh:mm): ");
            scanf("%s", appointments[num_appointments].time);

            num_appointments++;
            printf("\nAppointment scheduled successfully!\n\n");

        }else if(choice == 2){

            if(num_appointments == 0){
                printf("\nThere are no scheduled appointments.\n\n");
            }else{
                printf("\n%-20s %-20s %-20s\n", "Name", "Date", "Time");
                for(int i=0; i<num_appointments; i++){
                    printf("%-20s %-20s %-20s\n", appointments[i].name, appointments[i].date, appointments[i].time);
                }
                printf("\n");
            }

        }else if(choice == 3){
            printf("\nThank you for using the Appointment Scheduler!\n");
            return 0;
        }else{
            printf("\nInvalid choice. Please try again.\n\n");
        }
    }

    return 0;
}