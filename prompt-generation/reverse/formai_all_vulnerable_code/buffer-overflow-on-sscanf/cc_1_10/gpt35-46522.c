//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

/*
Function to convert a month name to its equivalent numeric value
*/
int getMonthValue(char month[]){
  if(strcmp(month,"January")==0)
    return 1;
  else if(strcmp(month,"February")==0)
    return 2;
  else if(strcmp(month,"March")==0)
    return 3;
  else if(strcmp(month,"April")==0)
    return 4;
  else if(strcmp(month,"May")==0)
    return 5;
  else if(strcmp(month,"June")==0)
    return 6;
  else if(strcmp(month,"July")==0)
    return 7;
  else if(strcmp(month,"August")==0)
    return 8;
  else if(strcmp(month,"September")==0)
    return 9;
  else if(strcmp(month,"October")==0)
    return 10;
  else if(strcmp(month,"November")==0)
    return 11;
  else if(strcmp(month,"December")==0)
    return 12;
  else
    return -1;
}

/*
Function to convert a given date from natural language to its equivalent date format
*/
void convertToDate(char input[]){
  char day[3], month[10], year[5];
  int d,m,y;
  sscanf(input,"%s %s %s",day,month,year);  // Scanning input and storing day, month and year in their respective variables
  d = atoi(day);  // Converting day string to integer value
  m = getMonthValue(month);  // Converting month name to its equivalent numeric value
  y = atoi(year);  // Converting year string to integer value
  if(d>0 && d<=31 && m!=-1 && y>0 && y<=9999){  // Validating input
    printf("The converted date is: %02d/%02d/%04d",d,m,y);
  }
  else{
    printf("Invalid Input");
  }
}

int main(){
  char input[100];
  printf("Enter a date in natural language (e.g. \"June 17, 2022\"):\n");
  fgets(input,100,stdin);  // Reading input from user
  convertToDate(input);  // Calling function to convert input to date format
  return 0;
}