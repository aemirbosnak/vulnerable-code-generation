//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: authentic
#include <stdio.h> //Include standard input/output header file
#include <time.h> //Include time header file
#include <stdlib.h> //Include standard library header file

void generateTime(int* d,int* m,int* y,int* hh,int* mm,int* ss){ //function to generate random date and time
    
    int minYear=1900; //minimum year to generate date from 
    int maxYear=2100; //maximum year to generate date till
    int rangeYear=maxYear-minYear+1; //range of years between minYear and maxYear
    *y=minYear+rand()%rangeYear; //generate year between minYear and maxYear
    
    int monthDays[]={31,28,31,30,31,30,31,31,30,31,30,31}; //array to keep the days in months
    int leapYear=0; //take leap year as 0 initially
    
    if(*y%4==0){ //if the year is divisible by 4 
        if(*y%100==0){ //if the year is divisible by 100
            if(*y%400==0) //if the year is divisible by 400
                leapYear=1; //set leap year as 1
        }
        else
            leapYear=1; //set leap year as 1
    }
    
    if(leapYear==1) //if the year is leap year
        monthDays[1]=29; //set number of days in month of february to 29
    
    int minMonth=1; //minimum month
    int maxMonth=12; //maximum month
    int rangeMonth=maxMonth-minMonth+1; //range of months
    
    *m=minMonth+rand()%rangeMonth; //generate random month
    
    int numOfDays=monthDays[*m-1]; //generate number of days in the generated month
    
    int minDays=1; //minimum number of days in the month
    int maxDays=numOfDays; //maximum number of days in the month
    int rangeDays=maxDays-minDays+1; //range of number of days
    
    *d=minDays+rand()%rangeDays; //generate random day in the month
    
    int minHour=0; //minimum hour
    int maxHour=23; //maximum hour
    int rangeHour=maxHour-minHour+1; //range of hours
    
    *hh=minHour+rand()%rangeHour; //generate random hour
    
    int minMinute=0; //minimum minute
    int maxMinute=59; //maximum minute
    int rangeMinute=maxMinute-minMinute+1; //range of minutes
    
    *mm=minMinute+rand()%rangeMinute; //generate random minute
    
    int minSecond=0; //minimum second
    int maxSecond=59; //maximum second
    int rangeSecond=maxSecond-minSecond+1; //range of seconds
    
    *ss=minSecond+rand()%rangeSecond; //generate random second
}

int main(){
    int date,month,year,hour,minute,second; //declare variables for date and time
    
    srand(time(0)); //seed the random number generator with the current time
    
    generateTime(&date,&month,&year,&hour,&minute,&second); //generate random date and time using the function
    
    printf("Welcome to the Time Travel Simulator\n\n"); //welcome message
    
    printf("The current date and time is:\n"); //display the current date and time
    printf("%d/%d/%d %d:%d:%d",date,month,year,hour,minute,second);
    
    int choice; //variable to store the user's choice
    
    do{ //do while loop to keep the program running until user exits
        
        printf("\n\nWhat would you like to do?\n"); //ask user for choice
        
        printf("1. Time Travel to the past\n");
        printf("2. Time Travel to the future\n");
        printf("3. Exit\n");
        
        printf("\nEnter your choice: ");
        scanf("%d",&choice); //store the user's choice
        
        switch(choice){ //switch case statement to handle user's choice
            
            case 1:{ //if user chooses to time travel to past
                
                printf("\nHow many years back would you like to travel? "); //ask user for years to travel back
                int yearsBack;
                scanf("%d",&yearsBack); //store the years to travel back
                
                year=year-yearsBack; //subtract the years to travel back from the current year
                
                generateTime(&date,&month,&year,&hour,&minute,&second); //generate random date and time using the function
                
                printf("\nYou have traveled back %d years.\n",yearsBack); //display message
                
                printf("\nYou have arrived on:\n"); //display the new date and time
                printf("%d/%d/%d %d:%d:%d",date,month,year,hour,minute,second);
                
                break;
            }
            case 2:{ //if user chooses to time travel to future
                
                printf("\nHow many years ahead would you like to travel? "); //ask user for years to travel ahead
                int yearsAhead;
                scanf("%d",&yearsAhead); //store the years to travel ahead
                
                year=year+yearsAhead; //add the years to travel ahead to the current year
                
                generateTime(&date,&month,&year,&hour,&minute,&second); //generate random date and time using the function
                
                printf("\nYou have traveled ahead %d years.\n",yearsAhead); //display message
                
                printf("\nYou have arrived on:\n"); //display the new date and time
                printf("%d/%d/%d %d:%d:%d",date,month,year,hour,minute,second);
                
                break;
            }
            case 3:{ //if user chooses to exit
                printf("\nThank you for using the Time Travel Simulator!\n"); //exit message
                break; //break the loop
            }
            default: //if user enters a wrong choice
                printf("\nPlease enter a valid choice.\n"); //display error message
        }
        
    }while(choice!=3); //loop until user chooses to exit
    
    return 0; //return 0 to exit the program
}