//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct appointment{
    char name[30];
    int day;
    int month;
    int year;
    char venue[50];
};

void create_appointment(struct appointment *a){
    fflush(stdin);
    printf("Enter name: ");
    gets(a->name);
    printf("Enter date of appointment (dd/mm/yyyy): ");
    scanf("%d/%d/%d",&(a->day), &(a->month), &(a->year));
    fflush(stdin);
    printf("Enter venue: ");
    gets(a->venue);
}

void display_appointment(struct appointment a){
    printf("\nName: %s",a.name);
    printf("\nDate of appointment (dd/mm/yyyy): %d/%d/%d",a.day,a.month,a.year);
    printf("\nVenue: %s",a.venue);
}

void search_appointment(char *name, struct appointment *a, int n){
    int i,flag=0;
    for(i=0;i<n;i++)
    {
        if(strcmp(name,a[i].name)==0)
        {
            display_appointment(a[i]);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\nAppointment not found.");
    }
}

void update_appointment(char *name, struct appointment *a, int n){
    int i,flag=0;
    for(i=0;i<n;i++)
    {
        if(strcmp(name,a[i].name)==0)
        {
            flag=1;
            printf("\nEnter updated appointment details: ");
            create_appointment(&a[i]);
            printf("\nAppointment updated successfully.");
        }
    }
    if(flag==0)
    {
        printf("\nAppointment not found.");
    }
}

void delete_appointment(char *name, struct appointment *a, int *n){
    int i,flag=0;
    for(i=0;i<(*n);i++)
    {
        if(strcmp(name,a[i].name)==0)
        {
            flag=1;
            (*n)--;
            while(i<(*n))
            {
                a[i]=a[i+1];
                i++;
            }
            printf("\nAppointment deleted successfully.");
        }
    }
    if(flag==0)
    {
        printf("\nAppointment not found.");
    }
}

main()
{
    struct appointment a[50];
    int n=0,ch;
    char name[30];
    
    while(1)
    {
        printf("\n\nAppointment Scheduler Menu:\n");
        printf("1. Add Appointment\n2. Search appointment\n3. Update appointment\n4. Delete appointment\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1: 
                create_appointment(&a[n]);
                n++;
                printf("\nAppointment added successfully.");
                break;
                
            case 2:
                fflush(stdin);
                printf("Enter name: ");
                gets(name);
                search_appointment(name,a,n);
                break;
                
            case 3:
                fflush(stdin);
                printf("Enter name: ");
                gets(name);
                update_appointment(name,a,n);
                break;
                
            case 4:
                fflush(stdin);
                printf("Enter name: ");
                gets(name);
                delete_appointment(name,a,&n);
                break;
                
            case 5:
                exit(0);
                
            default:
                printf("\nInvalid input!");
        }
    }
}