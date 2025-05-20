//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//Function to display available slots
void available_slots(int slots[5][48]){
    int hour,minute;
    int count=0;
    printf("\nAvailable Time Slots:\n\n");
    for(hour=0;hour<5;hour++){
        for(minute=0;minute<48;minute++){
            if(slots[hour][minute]==0){
                printf("%02d:%02d-",hour+9,minute*30);
                while(slots[hour][minute]==0&&minute<48){
                    count++;
                    minute++;
                }
                printf("%02d:%02d\n",hour+9,(minute-1)*30+30);
                minute--;
            }
            count=0;
        }
    }
}

//Function to book appointment slot
void book_slot(int slots[5][48],char name[20],int hour,int minute){
    int i,count=0;
    int start=minute;
    printf("\nYour booking details:\n\n");
    printf("Name: %s\n",name);
    printf("Time slot: %02d:%02d - ",hour+9,minute*30);
    while(slots[hour][minute]==0&&minute<48){
        count++;
        minute++;
    }
    printf("%02d:%02d\n",hour+9,(minute-1)*30+30);
    for(i=start;i<minute;i++){
        slots[hour][i]=1;
    }
    printf("Booking Successful!\n");
}

int main(){
    int slots[5][48]={0};
    int choice,hour,minute;
    char name[20];
    printf("Welcome to the Appointment Scheduler!\n\n");
    while(1){
        printf("1. View available slots\n");
        printf("2. Book an appointment\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                available_slots(slots);
                break;
            case 2:
                printf("\nEnter your name: ");
                scanf("%s",name);
                printf("Enter the hour (9-13): ");
                scanf("%d",&hour);
                printf("Enter the minute (0 or 30): ");
                scanf("%d",&minute);
                if(hour>4||hour<0){
                    printf("\nInvalid hour!\n\n");
                    break;
                }
                if(minute!=0&&minute!=30){
                    printf("\nInvalid minute!\n\n");
                    break;
                }
                if(slots[hour][minute]==1){
                    printf("\nSlot already booked, please choose another slot!\n\n");
                    break;
                }
                book_slot(slots,name,hour,minute);
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid choice!\n\n");
        }
    }
    return 0;
}