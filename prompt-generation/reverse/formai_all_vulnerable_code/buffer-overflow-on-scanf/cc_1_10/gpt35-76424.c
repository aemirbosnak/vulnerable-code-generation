//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: detailed
#include<stdio.h> 
#include<stdlib.h> 
#include<time.h>
struct appointment{
    int date;
    int month;
    int year;
    char name[50];
    int contact;
};
void cancel_appointment(struct appointment *app, int size){ //function to delete an appointment
    int i, flag=0;
    int choice;
    printf("Enter the appointment details to cancel:\n");
    printf("Enter date:");
    scanf("%d", &choice);
    for(i=0; i<size; i++){
        if(app[i].date==choice){ //checking if the entered date matches with any scheduled appointments
            printf("%s appointment on %d/%d/%d has been cancelled.\n", app[i].name, app[i].date, app[i].month, app[i].year);
            flag=1;
            for(int j=i+1;j<size;j++){ //to shift all the appointments after the cancelled appointment one position back
                app[j-1]=app[j];
            }
            size--;
            }
    }
    if(flag==0){
        printf("No appointments on this date to cancel!\n");
    }
}
void print_appointments(struct appointment *app, int size){ //function to view all the scheduled appointments
    int i;
    printf("-----------------------\n");
    for(i=0; i<size; i++){
        printf("%s's appointment on %d/%d/%d at %d has been scheduled\n", app[i].name, app[i].date, app[i].month, app[i].year, app[i].contact);
    }
    printf("-----------------------\n");
}
void schedule_appointment(struct appointment *app, int size){ //function to schedule an appointment
    printf("Enter the appointment details:\n");
    printf("Enter name:");
    scanf("%s", &app[size].name);
    printf("Enter date:");
    scanf("%d", &app[size].date);
    printf("Enter month:");
    scanf("%d", &app[size].month);
    printf("Enter year:");
    scanf("%d", &app[size].year);
    printf("Enter contact number:");
    scanf("%d", &app[size].contact);
    printf("%s's appointment on %d/%d/%d at %d has been scheduled successfully.\n", app[size].name, app[size].date, app[size].month, app[size].year, app[size].contact);
}
int main(){ //driver function
    struct appointment app[50];
    int choice, size=0;
    printf("Welcome to Appointment Scheduler.\n");
    while(1){
        printf("Choose an option:\n1.Schedule Appointment\n2.Cancel Appointment\n3.View Appointments\n4.Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                if(size<50){
                    schedule_appointment(app, size);
                    size++;
                }
                else{
                    printf("Maximum limit of appointments reached!\n");
                }
                break;
            case 2:
                if(size>0){
                    cancel_appointment(app, size);
                    }
                else{
                    printf("No appointments to cancel!\n");
                }
                break;
            case 3:
                if(size>0){
                    print_appointments(app, size);
                    }
                else{
                    printf("No appointments scheduled yet!\n");
                }
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid option selected. Please try again!\n");
                break;
        }
    }
    return 0;
}