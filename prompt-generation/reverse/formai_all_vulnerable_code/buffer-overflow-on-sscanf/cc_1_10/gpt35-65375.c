//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: synchronous
#include<stdio.h>
#include<string.h>

//Defining a structure for appointment
struct appointment{
    char name[50];
    char date[20];
    char time[20];
    char venue[100];
};

//Function to display all the appointments
void displayAppointments(struct appointment a[], int n){
    printf("All appointments: \n");
    for(int i=0;i<n;i++){
        printf("Appointment %d: \n",i+1);
        printf("Name: %s\n",a[i].name);
        printf("Date: %s\n",a[i].date);
        printf("Time: %s\n",a[i].time);
        printf("Venue: %s\n",a[i].venue);
    }
}

//Function to check if a particular date is valid
int isValidDate(char *date){
    int day, month, year;
    sscanf(date,"%d/%d/%d",&day,&month,&year);
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 2021)
        return 0;
    return 1;
}

//Function to check if a particular time is valid
int isValidTime(char *time){
    int hour, min;
    sscanf(time,"%d:%d",&hour,&min);
    if (hour < 0 || hour > 23 || min < 0 || min > 59)
        return 0;
    return 1;
}

int main(){

    int choice, n=0;
    struct appointment a[50];
    char tempDate[20];
    char tempTime[20];

    while(1){
        printf("\n1. Add an appointment\n2. Display all appointments\n3. Exit\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){

            //Case to add a new appointment
            case 1:
                printf("Enter details for appointment %d:\n",(n+1));
                printf("Enter name: ");
                scanf(" %[^\n]s",&a[n].name);
                printf("Enter date (in format dd/mm/yyyy): ");
                scanf(" %[^\n]s",&tempDate);

                while(!isValidDate(tempDate)){
                    printf("Invalid date. Please enter a valid date (in format dd/mm/yyyy): ");
                    scanf(" %[^\n]s",&tempDate);
                }

                strcpy(a[n].date,tempDate);
                printf("Enter time (in format hh:mm): ");
                scanf(" %[^\n]s",&tempTime);

                while(!isValidTime(tempTime)){
                    printf("Invalid time. Please enter a valid time (in format hh:mm): ");
                    scanf(" %[^\n]s",&tempTime);
                }

                strcpy(a[n].time,tempTime);
                printf("Enter venue: ");
                scanf(" %[^\n]s",&a[n].venue);
                n++;
                break;

            //Case to display all the appointments
            case 2:
                displayAppointments(a,n);
                break;

            //Case to exit the program
            case 3:
                exit(0);

            //Default case when an invalid choice is entered
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
                break;
        }
    }
    return 0;
}