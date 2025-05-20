//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: satisfied
/* This program is an appointment scheduler that allows users to schedule appointments with a particular doctor, view their scheduled appointments, and cancel appointments if needed. */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct appointment{
    char name[20];
    int age;
    char doctor[20];
    char date[20];
};

int main(){
    int choice;
    struct appointment app[10];
    int n=0;
    do{
        printf("\nMenu:\n");
        printf("1. Schedule an Appointment\n");
        printf("2. View Scheduled Appointments\n");
        printf("3. Cancel an Appointment\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            {
                printf("\nEnter Patient Name: ");
                scanf("%s",&app[n].name);
                printf("\nEnter Patient Age: ");
                scanf("%d",&app[n].age);
                printf("\nEnter Doctor name: ");
                scanf("%s",&app[n].doctor);
                printf("\nEnter Date of appointment: ");
                scanf("%s",&app[n].date);
                printf("\nAppointment Scheduled Successfully!\n");
                n++;
                break;
            }
            case 2:
            {
                int i;
                printf("\n\tName\t\tAge\tDoctor\t\tDate\n");
                for(i=0;i<n;i++){
                    printf("\t%s\t\t%d\t%s\t\t%s\n",app[i].name,app[i].age,app[i].doctor,app[i].date);
                }
                break;
            }
            case 3:
            {
                char pname[20],pdate[20],pdoctor[20];
                int i,j;
                printf("\nEnter Patient Name: ");
                scanf("%s",&pname);
                printf("\nEnter Appointment Date: ");
                scanf("%s",&pdate);
                printf("\nEnter Doctor Name: ");
                scanf("%s",&pdoctor);
                for(i=0;i<n;i++){
                    if((strcmp(pname,app[i].name)==0)&&(strcmp(pdate,app[i].date)==0)&&
                    (strcmp(pdoctor,app[i].doctor)==0)){
                        printf("\nAppointment for %s on %s with Dr.%s has been cancelled\n",app[i].name,app[i].date,app[i].doctor);
                        for(j=i+1;j<n;j++){
                            app[j-1]=app[j];
                        }
                        n--;
                    }
                }
                break;
            }
            case 4:
            {
                printf("\nExiting program...\n");
                exit(0);
                break;
            }
            default:
            {
                printf("\nInvalid Choice, please enter a valid choice.\n");
                break;
            }
        }
    }while(choice!=4);
    return 0;
}