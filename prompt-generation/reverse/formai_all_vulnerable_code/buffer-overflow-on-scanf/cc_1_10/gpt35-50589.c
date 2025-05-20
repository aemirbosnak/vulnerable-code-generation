//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to generate random number for token
int generateToken(){
    srand(time(0));
    return (rand()%100);
}

//Structure to store appointment details
struct appointment{
    int tokenNum;
    char name[50];
    int age;
    char gender;
    char problem[100];
    char date[20];
    char time[10];
};

//Function to display appointment details
void display(struct appointment a){
    printf("\n\n");
    printf("Token Number : %d\n",a.tokenNum);
    printf("Name : %s\n",a.name);
    printf("Age : %d\n",a.age);
    printf("Gender : %c\n",a.gender);
    printf("Problem : %s\n",a.problem);
    printf("Date : %s\n",a.date);
    printf("Time : %s\n",a.time);
    printf("\n\n");
}

int main(){

    int choice = 0;
    struct appointment ap[100];
    int count = 0;

    printf("******** Welcome to our Appointment System ********\n\n");

    while(1){

        printf("1. Book Appointment\n");
        printf("2. Display Appointment\n");
        printf("3. Exit Appointment System\n");

        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                printf("\n\n");
                printf("******** Book Appointment ********\n\n");

                //Taking inputs
                printf("Enter your Name : ");
                scanf("%s",ap[count].name);

                printf("Enter your Age : ");
                scanf("%d",&ap[count].age);

                printf("Enter your Gender : ");
                scanf(" %c",&ap[count].gender);

                printf("Enter your Problem : ");
                scanf("%s",ap[count].problem);

                printf("Enter Date (dd/mm/yyyy) : ");
                scanf("%s",ap[count].date);

                printf("Enter Time (hh:mm) : ");
                scanf("%s",ap[count].time);

                //Generating token
                ap[count].tokenNum = generateToken();

                printf("\n\n");
                printf("Your Token Number is : %d\n",ap[count].tokenNum);
                printf("\n\n");

                count++;
                break;

            case 2:
                printf("\n\n");
                printf("******** Display Appointment ********\n\n");

                //Displaying all appointments
                for(int i=0;i<count;i++){
                    display(ap[i]);
                }

                break;

            case 3:
                printf("\n\n");
                printf("******** Thank You! ********\n\n");
                exit(0);

            default:
                printf("\n\n");
                printf("Invalid choice! Please enter a valid choice.\n\n");

        }

    }

    return 0;

}