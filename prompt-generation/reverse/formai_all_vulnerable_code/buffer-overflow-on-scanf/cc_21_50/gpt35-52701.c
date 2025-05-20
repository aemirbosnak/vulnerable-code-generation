//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Ken Thompson
#include<stdio.h>
#include<string.h>

void main(){

    //Initialize array with number of days in each month
    int days_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    //Define variables to store user input
    int day, month, year;
    
    printf("Please enter a date (dd/mm/yyyy)\n");
    scanf("%d/%d/%d",&day,&month,&year);
    
    //Check if year is a leap year
    if((year%4==0 && year%100!=0) || year%400==0){
        days_in_month[1] = 29;
    }
    
    //Validate user input
    if(year<=0 || month<=0 || month>12 || day<=0 || day>days_in_month[month-1]){
        printf("Invalid date\n");
    }else{
        //Calculate the number of days since January 1, 0001
        int total_days = 0;
        for(int i=1; i<year; i++){
            if((i%4==0 && i%100!=0) || i%400==0){
                total_days += 366;
            }else{
                total_days += 365;
            }
        }
        for(int i=0; i<month-1; i++){
            total_days += days_in_month[i];
        }
        total_days += day;
        
        //Calculate the day of the week
        int day_of_week = (total_days-1) % 7; //0=Sunday, 1=Monday, ..., 6=Saturday
        
        //Output the result
        printf("%d/%d/%d is a ",day,month,year);
        switch(day_of_week){
            case 0:
                printf("Sunday\n");
                break;
            case 1:
                printf("Monday\n");
                break;
            case 2:
                printf("Tuesday\n");
                break;
            case 3:
                printf("Wednesday\n");
                break;
            case 4:
                printf("Thursday\n");
                break;
            case 5:
                printf("Friday\n");
                break;
            case 6:
                printf("Saturday\n");
                break;
        }
    }
}