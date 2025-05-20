//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Patient{
    char name[50];
    int age;
    char gender;
    char contact[15];
    char email[50];
    char date[12];
    char problem[100];
};

int main()
{
    int choice, i, flag=0;
    char ch;
    struct Patient P[50];
    printf("\n\t*** Welcome to the Appointment Scheduler System ***\n\n");
    
    while(1)
    {
        printf("\nPlease choose an option:\n");
        printf("1. Add Patient Appointment\n");
        printf("2. View All Appointments\n");
        printf("3. Search for an Appointment\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter Patient Details\n");
                printf("----------------------\n");
                for(i=0;i<50;i++)
                {
                    if(P[i].age==0)
                    {
                        printf("\nName: ");
                        scanf("%s",P[i].name);
                        printf("Age: ");
                        scanf("%d",&P[i].age);
                        printf("Gender (M/F): ");
                        scanf(" %c",&P[i].gender);
                        printf("Contact Number: ");
                        scanf("%s",P[i].contact);
                        printf("Email ID: ");
                        scanf("%s",P[i].email);
                        printf("Date of Appointment (dd/mm/yyyy): ");
                        scanf("%s",P[i].date);
                        printf("Problem: ");
                        scanf("%s",P[i].problem);
                        flag = 1;
                        break;
                    }
                }
                if(flag==0)
                {
                    printf("\nSorry, Appointment Slots are full.");
                }
                break;
            
            case 2:
                printf("\nAll Appointments\n");
                printf("----------------\n");
                printf("Name\tAge\tGender\tContact\t\tEmail\t\tAppointment Date\t\tProblem\n");
                for(i=0;i<50;i++)
                {
                    if(P[i].age!=0)
                    {
                        printf("%s\t%d\t%c\t%s\t%s\t%s\t\t%s\n",P[i].name,P[i].age,P[i].gender,P[i].contact,P[i].email,P[i].date,P[i].problem);
                    }
                }
                break;

            case 3:
                printf("\nEnter the Name of the Patient: ");
                char pname[50];
                scanf("%s",pname);
                printf("\nMatched Appointment\n");
                printf("--------------------\n");
                printf("Name\tAge\tGender\tContact\t\tEmail\t\tAppointment Date\t\tProblem\n");
                for(i=0;i<50;i++)
                {
                    if(strcmp(P[i].name,pname)==0)
                    {
                        printf("%s\t%d\t%c\t%s\t%s\t%s\t\t%s\n",P[i].name,P[i].age,P[i].gender,P[i].contact,P[i].email,P[i].date,P[i].problem);
                        break;
                    }
                }
                if(i==50)
                {
                    printf("\nSorry! No appointments found with the name %s. Try another name\n",pname);
                }
                break;
            
            case 4:
                printf("\n\nThank you for using the Appointment Scheduler System. Visit Again!\n\n");
                exit(0);
            
            default:
                printf("\nSorry, Invalid Choice. Please Try Again.\n");
        }
    }
    return 0;
}