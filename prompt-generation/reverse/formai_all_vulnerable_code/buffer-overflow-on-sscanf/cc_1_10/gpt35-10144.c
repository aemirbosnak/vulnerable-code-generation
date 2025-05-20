//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: portable
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int monthToInt(char *month){
  // Convert month abbreviation to integer
  if(strcmp(month, "Jan") == 0){
    return 1;
  }else if(strcmp(month, "Feb") == 0){
    return 2;
  }else if(strcmp(month, "Mar") == 0){
    return 3;
  }else if(strcmp(month, "Apr") == 0){
    return 4;
  }else if(strcmp(month, "May") == 0){
    return 5;
  }else if(strcmp(month, "Jun") == 0){
    return 6;
  }else if(strcmp(month, "Jul") == 0){
    return 7;
  }else if(strcmp(month, "Aug") == 0){
    return 8;
  }else if(strcmp(month, "Sep") == 0){
    return 9;
  }else if(strcmp(month, "Oct") == 0){
    return 10;
  }else if(strcmp(month, "Nov") == 0){
    return 11;
  }else if(strcmp(month, "Dec") == 0){
    return 12;
  }else{
    return -1;
  }
}

void printErrorMessage(){
  printf("Error: invalid input. Please enter the date in the format of 'Day Month Year'.\n");
}

int main(){
  char input[20];
  char dayStr[3];
  char monthStr[4];
  char yearStr[5];
  int day;
  int month;
  int year;

  printf("****** Welcome to C Natural Language Date Converter ******\n");
  printf("Please enter the date in the format of 'Day Month Year'.\n");
  printf("Example: 31 Dec 2021\n");
  fgets(input, 20, stdin);

  // Parse input
  sscanf(input, "%s %s %s", dayStr, monthStr, yearStr);

  // Convert day string to integer
  day = atoi(dayStr);

  // Convert month string to integer
  month = monthToInt(monthStr);

  // Convert year string to integer
  year = atoi(yearStr);

  // Check for invalid input
  if(day < 1 || day > 31 || month < 1 || month > 12 || year < 1){
    printErrorMessage();
    return 1;
  }

  // Print converted date
  printf("The converted date is: %d/%d/%d\n", month, day, year);

  return 0;
}