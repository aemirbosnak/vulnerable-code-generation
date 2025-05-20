//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX 100//maximum number of appointments
#define DAYS 7//number of days in a week

struct appointment{
    char name[50];
    int day;
    int month;
    int year;
    int hour;
    int minute;
    int duration;
};

struct appointment schedule[MAX];

void main(){
    int choice,i,j,k,l;
    char ch;
    printf("\nWelcome to the Appointment Scheduler\n");
    printf("------------------------------------\n");
    while(1){
        system("clear");
        printf("\n1.Add Appointment\n2.Delete Appointment\n3.View Schedule\n4.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter name: ");
                scanf("%s",schedule[0].name);
                printf("Enter day(1-7): ");
                scanf("%d",&schedule[0].day);
                printf("Enter month(1-12): ");
                scanf("%d",&schedule[0].month);
                printf("Enter year(YYYY): ");
                scanf("%d",&schedule[0].year);
                printf("Enter time(HH:MM): ");
                scanf("%d:%d",&schedule[0].hour,&schedule[0].minute);
                printf("Enter duration(in minutes): ");
                scanf("%d",&schedule[0].duration);
                break;
            case 2:
                printf("\nEnter the name of the appointment you want to delete: ");
                scanf("%s",ch);
                for(i=0;i<MAX;i++){
                    if(strcmp(schedule[i].name,ch)==0){
                        for(j=i;j<MAX-1;j++){
                            schedule[j]=schedule[j+1];
                        }
                        break;
                    }
                }
                printf("\nAppointment deleted successfully\n");
                break;
            case 3:
                printf("\nSchedule for the week:\n");
                printf("------------------------------------\n");
                printf("Day\tTime\tAppointment\n");
                for(i=0;i<DAYS;i++){
                    printf("%d\t",i+1);
                    for(j=0;j<MAX;j++){
                        if(schedule[j].day==i+1){
                            printf("%s\t",schedule[j].name);
                            printf("%02d:%02d - ",schedule[j].hour,schedule[j].minute);
                            printf("%02d:%02d\n",schedule[j].hour+schedule[j].duration/60,(schedule[j].duration%60));
                        }
                    }
                }
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice\n");
        }
    }
}