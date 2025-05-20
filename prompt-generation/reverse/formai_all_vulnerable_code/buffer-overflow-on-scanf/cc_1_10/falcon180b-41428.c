//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: lively
#include<stdio.h>
#include<stdlib.h>

//structure for appointment
struct appointment
{
    char name[100];
    char date[20];
    char time[20];
    char reason[200];
};

//function to add appointment
void add_appointment(struct appointment *app)
{
    printf("Enter name: ");
    scanf("%s",app->name);
    printf("Enter date: ");
    scanf("%s",app->date);
    printf("Enter time: ");
    scanf("%s",app->time);
    printf("Enter reason: ");
    scanf("%s",app->reason);
}

//function to display appointments
void display_appointments(struct appointment *app,int size)
{
    printf("\nAppointments:\n");
    for(int i=0;i<size;i++)
    {
        printf("\nName: %s\nDate: %s\nTime: %s\nReason: %s\n",app[i].name,app[i].date,app[i].time,app[i].reason);
    }
}

//main function
int main()
{
    int choice,size;
    struct appointment app[100];
    do
    {
        printf("\n\nAppointment Scheduler\n");
        printf("1.Add appointment\n2.Display appointments\n3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter size of appointment array: ");
                scanf("%d",&size);
                for(int i=0;i<size;i++)
                {
                    add_appointment(&app[i]);
                }
                break;
            case 2:
                display_appointments(app,size);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while(choice!=3);
    return 0;
}