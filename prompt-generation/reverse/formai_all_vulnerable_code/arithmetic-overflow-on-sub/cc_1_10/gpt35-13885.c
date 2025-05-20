//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: enthusiastic
#include<stdio.h>
#include<string.h>

//Defining structure for appointment
struct Appointment{
    char title[50];
    char date[20];
    char time[10];
};

int main(){
    int choice = 0;
    int count = 0;
    
    struct Appointment appointments[1000];
    printf("Welcome to Appointment Scheduler!\n");

    while(choice!=4){
        printf("\nChoose an option:\n");
        printf("1. Schedule an Appointment\n");
        printf("2. View all Appointments\n");
        printf("3. Modify an Appointment\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch(choice){

            //Adding a new appointment
            case 1:
                printf("\nEnter Appointment Title: ");
                scanf("%s", appointments[count].title);

                printf("\nEnter Appointment Date (dd/mm/yyyy): ");
                scanf("%s",appointments[count].date);

                printf("\nEnter Appointment Time (hh:mm): ");
                scanf("%s", appointments[count].time);

                printf("\nAppointment Scheduled Successfully!");
                count++;
                break;

            //Viewing all appointments
            case 2:
                printf("\nAll Appointments:\n");

                for(int i=0;i<count;i++){
                   printf("%d. Title: %s, Date: %s, Time: %s\n", i+1, appointments[i].title, appointments[i].date, appointments[i].time);    
                }
                
                break;

            //Modifying an appointment
            case 3:
                printf("\nEnter the appointment you want to modify: ");
                int modifyIndex;
                scanf("%d", &modifyIndex);
                modifyIndex--;

                printf("\nEnter Updated Appointment Title: ");
                scanf("%s", appointments[modifyIndex].title);

                printf("\nEnter Updated Appointment Date (dd/mm/yyyy): ");
                scanf("%s",appointments[modifyIndex].date);

                printf("\nEnter Updated Appointment Time (hh:mm): ");
                scanf("%s", appointments[modifyIndex].time);
                
                printf("\nAppointment Modified Successfully!");
                break;

            //Exiting the program
            case 4:
                printf("\nThank you for using Appointment Scheduler!\n");
                break;

            //Invalid choice
            default:
                printf("\nInvalid choice. Please try again.");
                break;
        }

    }

    return 0;
}