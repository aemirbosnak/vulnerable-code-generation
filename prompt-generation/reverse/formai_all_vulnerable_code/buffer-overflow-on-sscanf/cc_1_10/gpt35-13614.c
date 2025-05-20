//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: intelligent
#include<stdio.h>
#include<string.h>

#define JAN 1
#define FEB 2
#define MAR 3
#define APR 4
#define MAY 5
#define JUN 6
#define JUL 7
#define AUG 8
#define SEP 9
#define OCT 10
#define NOV 11
#define DEC 12

int days_in_month(int month, int year){
  if(month == APR || month == JUN || month == SEP || month == NOV)
    return 30;
  else if(month == FEB){
    if((year%4==0 && year%100 != 0) || (year%400==0))
      return 29;
    else
      return 28;
  }
  else
    return 31;
}

int count_days(int day, int month, int year){
  int count = 0;
  for(int i=1; i<year; i++){
    if ((i%4==0 && i%100 !=0) || (i%400==0))
      count += 366;
    else
      count += 365;
  }
  for(int i=1; i<month; i++){
    count += days_in_month(i, year);
  }
  count += day;
  return count;
}

void date_converter(char date_string[]){
  char month[4];
  int day, year, month_number;
  
  sscanf(date_string, "%d-%s-%d", &day, &month, &year);
  if(strcmp(month, "Jan")==0)
    month_number = JAN;
  else if(strcmp(month, "Feb")==0)
    month_number = FEB;
  else if(strcmp(month, "Mar")==0)
    month_number = MAR;
  else if(strcmp(month, "Apr")==0)
    month_number = APR;
  else if(strcmp(month, "May")==0)
    month_number = MAY;
  else if(strcmp(month, "Jun")==0)
    month_number = JUN;
  else if(strcmp(month, "Jul")==0)
    month_number = JUL;
  else if(strcmp(month, "Aug")==0)
    month_number = AUG;
  else if(strcmp(month, "Sep")==0)
    month_number = SEP;
  else if(strcmp(month, "Oct")==0)
    month_number = OCT;
  else if(strcmp(month, "Nov")==0)
    month_number = NOV;
  else if(strcmp(month, "Dec")==0)
    month_number = DEC;
  else{
    printf("Invalid Input. Please enter the date in Year-Mon-DD format.\n");
    return;
  }
  
  if(day > days_in_month(month_number, year)){
    printf("Invalid Input. Please enter the correct date.\n");
    return;
  }
  
  int total_days = count_days(day, month_number, year);
  printf("The date %s corresponds to %d days from the start of the year.\n", date_string, total_days);
}

int main(){
  char date_string[12];
  printf("Enter the date in Year-Mon-DD format: ");
  scanf("%s", date_string);
  date_converter(date_string);
  return 0;
}