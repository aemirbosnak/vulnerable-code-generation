//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>

int main()
{
   int date, month, year;
   printf("Enter Date in DD/MM/YYYY format: ");
   scanf("%d/%d/%d",&date,&month,&year);
   if(date<1 || date>31 || month<1 || month>12)
   {
      printf("Invalid Date!!!");
      exit(0);
   }

   /*Checking for Leap Year*/
   if((year%4==0 && year%100!=0) || year%400==0)
   {
      printf("This is a Leap Year. \n");
   }

   /*Calculating Weekday*/
   int century_code, year_code, month_code, week_day;  
   century_code = (year/100)%4;
   year_code = year%100;
   month_code = (month==1)?0:(month==2)?3:(month==3)?3:(month==4)?-1:(month==5)?1:(month==6)?4:(month==7)?6:(month==8)?2:(month==9)?5:(month==10)?0:(month==11)?3:(month==12)?5:-1;

   if(year>=1700 && year<=1799)
   {
      year_code -= 4;
   }
   else if(year>=1800 && year<=1899)
   {
      year_code -= 2;
   }
   else if(year>=1900 && year<=1999)
   {
      year_code += 0;
   }
   else if(year>=2000 && year<=2099)
   {
      year_code += 2;
   }
   else
   {
      printf("Invalid Year!!!");
      exit(0);
   }

   week_day = (date + month_code + year_code + century_code)%7;
   char days[7][20] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
   printf("The day of the entered date is: %s",days[week_day]);
   return 0;
}