//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int check_leap_year(int year){
  return ((year%4==0&&year%100!=0)||year%400==0)?1:0;
}

int days_in_month(int month, int year){
  int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  if(month==2){
    if(check_leap_year(year))
        return 29;
    else
        return 28;
  }
  else
    return days[month-1];
}

void convert_to_date(int days, int year){
  int month=1;
  while(days>days_in_month(month,year)){
    days-=days_in_month(month,year);
    month++;
  }
  printf("The date is: %d-%d-%d\n", days, month, year);
}

void convert_to_days(int date, int month, int year){
  int days=date;
  for(int i=1;i<month;i++)
    days+=days_in_month(i, year);
  printf("Number of days: %d\n",days);
}

int main(){
  int choice=0;
  printf("Welcome to the Date Converter\n");
  printf("1. Convert days to date\n");
  printf("2. Convert date to days\n");
  printf("Enter your choice: ");
  scanf("%d",&choice);
  if(choice==1){
    int year,days;
    printf("Enter the number of days: ");
    scanf("%d",&days);
    printf("Enter the year: ");
    scanf("%d",&year);
    convert_to_date(days,year);
  }
  else if(choice==2){
    int date,month,year;
    printf("Enter the date: ");
    scanf("%d",&date);
    printf("Enter the month: ");
    scanf("%d",&month);
    printf("Enter the year: ");
    scanf("%d",&year);
    convert_to_days(date,month,year);
  }
  else{
    printf("Invalid choice!\n");
  }
  return 0;
}