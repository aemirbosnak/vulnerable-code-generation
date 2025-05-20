//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct appointment{
    int date;
    int month;
    int year;
    int hour;
    int minute;
    char name[50];
    char description[200];
};

struct appointment app[10];
int count = 0;

void createAppointment(){
    if(count<10){
        printf("Enter date (DD): ");
        scanf("%d",&app[count].date);
        printf("Enter month (MM): ");
        scanf("%d",&app[count].month);
        printf("Enter year (YYYY): ");
        scanf("%d",&app[count].year);
        printf("Enter hour (HH): ");
        scanf("%d",&app[count].hour);
        printf("Enter minute (MM): ");
        scanf("%d",&app[count].minute);
        printf("Enter name: ");
        scanf("%s",app[count].name);
        printf("Enter description: ");
        scanf("%s",app[count].description);
        printf("Appointment has been created successfully.\n");
        count++;
    }
    else{
        printf("Maximum limit of appointments reached.\n");
    }
}

void viewAppointments(){
    if(count==0){
        printf("No appointments to display.\n");
    }
    else{
        printf("List of appointments:\n");
        printf("S.No\t DATE\tTIME\t\t NAME\t\t DESCRIPTION\n");
        for(int i=0;i<count;i++){
            printf("%d\t%02d-%02d-%d\t%02d:%02d\t\t%s\t\t%s\n",
            i+1,app[i].date,app[i].month,app[i].year,app[i].hour,app[i].minute,app[i].name,app[i].description);
        }
    }
}

void findAppointment(){
    int date,month,year,c=0;
    printf("Enter date (DD): ");
    scanf("%d",&date);
    printf("Enter month (MM): ");
    scanf("%d",&month);
    printf("Enter year (YYYY): ");
    scanf("%d",&year);
    for(int i=0;i<count;i++){
        if(app[i].date==date && app[i].month==month && app[i].year==year){
            c++;
            printf("Appointment %d:\n",c);
            printf("Date: %02d-%02d-%d\n", app[i].date, app[i].month, app[i].year);
            printf("Time: %02d:%02d\n", app[i].hour, app[i].minute);
            printf("Name: %s\n", app[i].name);
            printf("Description: %s\n", app[i].description);
        }
    }
    if(c==0){
        printf("No appointment found for the entered date.\n");
    }
}

void deleteAppointment(){
    int n;
    printf("Enter the appointment number to delete: ");
    scanf("%d",&n);
    if(n<=count){
        for(int i=n-1;i<count-1;i++){
            app[i]=app[i+1];
        }
        count--;
        printf("Appointment has been deleted successfully.\n");
    }
    else{
        printf("Invalid appointment number.\n");
    }
}

int main(){
    int choice;
    while(1){
        printf("\nAppointment Scheduler\n");
        printf("------------------------\n");
        printf("1. Create Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Find an Appointment\n");
        printf("4. Delete an Appointment\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: createAppointment();
                    break;
            case 2: viewAppointments();
                    break;
            case 3: findAppointment();
                    break;
            case 4: deleteAppointment();
                    break;
            case 5: exit(0);
            default: printf("Invalid choice. Please choose again.\n");
        }
    }
    return 0;
}