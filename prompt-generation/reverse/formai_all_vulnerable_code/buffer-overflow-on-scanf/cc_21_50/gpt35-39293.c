//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>

int main()
{
    //input year
    int year;
    printf("Enter a year to travel: ");
    scanf("%d",&year);

    //check for leap year
    int leap = 0;
    if(year%4 == 0)
    {
        if( year%100 == 0)
        {
            // year is divisible by 400, then it is a leap year
            if ( year%400 == 0)
                leap = 1;
            else
                leap = 0;
        }
        else
            leap = 1;
    }
    else
        leap = 0;

    //input travel year
    int travel_year;
    printf("Enter the year you want to travel to: ");
    scanf("%d",&travel_year);

    //if leap year then check for number of days in february
    int febDays;
    if(leap == 1)
        febDays = 29;
    else
        febDays = 28;

    //initialize variables
    int month = 1,day = 1;

    printf("Traveling through time...\n");

    //loop through years
    for(int i = year; i < travel_year; i++)
    {
        //loop through months
        for(int j=1;j<=12;j++)
        {
            //assign month with name
            char month_name[10];
            switch(j)
            {
                case 1: strcpy(month_name,"January");break;
                case 2: strcpy(month_name,"February");break;
                case 3: strcpy(month_name,"March");break;
                case 4: strcpy(month_name,"April");break;
                case 5: strcpy(month_name,"May");break;
                case 6: strcpy(month_name,"June");break;
                case 7: strcpy(month_name,"July");break;
                case 8: strcpy(month_name,"August");break;
                case 9: strcpy(month_name,"September");break;
                case 10: strcpy(month_name,"October");break;
                case 11: strcpy(month_name,"November");break;
                case 12: strcpy(month_name,"December");break;
            }

            //loop through days in month
            for(int k=1;k<=31;k++)
            {
                if((k==31) && ((j==4)||(j==6)||(j==9)||(j==11)))
                    break;
                if((k==29) && (j==2))
                    break;
                else if((k==30) && (j==2))
                    break;

                if(month == 13)
                {
                    month = 1;
                    day = 1;
                }

                //print date and time
                printf("%s %d, %d\n",month_name,day,i);
                day++;
                if(day == 32)
                {
                    day=1;
                    month++;
                }
            }
        }
    }
    return 0;
}