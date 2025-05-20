//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void getDate(char*);
void printDate(int, int, int);

int main(){
   char dateStr[30];

   printf("Enter Date in DD/MM/YYYY format: ");
   scanf("%s",dateStr);

   getDate(dateStr);

   return 0;
}

void getDate(char *dateStr){
   int day=0, month=0, year=0;
   char delim[] = "/";

   char *ptr = strtok(dateStr, delim);
   int i=0;
   while(ptr != NULL){
      i++;
      if(i==1){
         day=atoi(ptr);
      }else if(i==2){
         month=atoi(ptr);
      }else{
         year=atoi(ptr);
      }
      ptr = strtok(NULL, delim);
   }
   printDate(day, month, year);
}

void printDate(int day, int month, int year){

   //Check if year is leap year
   int isLeapYear = 0;
   if(year%4==0){
      if(year%100==0){
         if(year%400==0)
            isLeapYear=1;
      }else{
         isLeapYear=1;
      }
   }

   //Check if date is valid
   int isValid=1;
   if(month<1 || month>12){
      isValid=0;
   }else if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12){
      if(day<1 || day>31){
         isValid=0;
      }
   }else if(month==4 || month==6 || month==9 || month==11){
      if(day<1 || day>30){
         isValid=0;
      }
   }else if(month==2){
      if(isLeapYear){
         if(day<1 || day>29){
            isValid=0;
         }
      }else{
         if(day<1 || day>28){
            isValid=0;
         }
      }
   }

   if(isValid){
      switch(month){
         case 1:
            printf("January %d, %d", day, year);
            break;
         case 2:
            printf("February %d, %d", day, year);
            break;
         case 3:
            printf("March %d, %d", day, year);
            break;
         case 4:
            printf("April %d, %d", day, year);
            break;
         case 5:
            printf("May %d, %d", day, year);
            break;
         case 6:
            printf("June %d, %d", day, year);
            break;
         case 7:
            printf("July %d, %d", day, year);
            break;
         case 8:
            printf("August %d, %d", day, year);
            break;
         case 9:
            printf("September %d, %d", day, year);
            break;
         case 10:
            printf("October %d, %d", day, year);
            break;
         case 11:
            printf("November %d, %d", day, year);
            break;
         case 12:
            printf("December %d, %d", day, year);
            break;
      }
   }else{
      printf("Invalid Date!");
   }
}