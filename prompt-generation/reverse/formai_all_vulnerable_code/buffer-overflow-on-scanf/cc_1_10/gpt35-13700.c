//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to check if a year is a leap year
int isLeapYear(int year) {
  if(year % 4 == 0) {
    if( year % 100 == 0) {
      if ( year % 400 == 0) {
        return 1; // it is a leap year
      }
      else {
        return 0; // it is not a leap year
      }
    }
    else {
      return 1; // it is a leap year
    }
  }
  else {
    return 0; // it is not a leap year
  }
}

// function to get the number of days in a month
int getDaysInMonth(int month, int year) {
  switch(month) {
    case 1 : return 31;
    case 2 : if(isLeapYear(year) == 1) {
              return 29;
            }
            else {
              return 28;
            }
    case 3 : return 31;
    case 4 : return 30;
    case 5 : return 31;
    case 6 : return 30;
    case 7 : return 31;
    case 8 : return 31;
    case 9 : return 30;
    case 10: return 31;
    case 11: return 30;
    case 12: return 31;
  }
  return 0;
}

// function to convert date from text to numeric
int convertDate(char *date) {
  int len = strlen(date), i = 0, year = 0, month = 0, day = 0;
  
  // extracting year, month and day from the date string
  while(date[i] != '\0' && date[i] != '/') {
    year = year * 10 + (date[i] - '0');
    i++;
  }
  i++;
  while(date[i] != '\0' && date[i] != '/') {
    month = month * 10 + (date[i] - '0');
    i++;
  }
  i++;
  while(date[i] != '\0' && date[i] != '/') {
    day = day * 10 + (date[i] - '0');
    i++;
  }
  
  // converting date to a single number
  int dateNumber = 0;
  for(i = 1; i < year; i++) {
    if(isLeapYear(i) == 1) {
      dateNumber += 366;
    }
    else {
      dateNumber += 365;
    }
  }
  for(i = 1; i < month; i++) {
    dateNumber += getDaysInMonth(i, year);
  }
  dateNumber += day;
  
  return dateNumber;
}

// function to convert date from numeric to text
char* convertToDate(int dateNumber) {
  int year = 1, month = 1, days = 0;
  for(year = 1; days < dateNumber; year++) {
    if(isLeapYear(year) == 1) {
      days += 366;
    }
    else {
      days += 365;
    }
  }
  year--;
  days -= isLeapYear(year) ? 366 : 365;
  for(month = 1; days + getDaysInMonth(month, year) < dateNumber; month++) {
    days += getDaysInMonth(month, year);
  }
  days = dateNumber - days;
  
  char *date = (char*) malloc(sizeof(char) * 11);
  sprintf(date, "%02d/%02d/%04d", month, days, year);
  return date;
}

// main function to convert date from one format to another
int main() {
  char* inputDate = (char*) malloc(sizeof(char) * 11);
  printf("Enter date in format MM/DD/YYYY : ");
  scanf("%s", inputDate);
  
  // converting date to numeric format
  int dateNumber = convertDate(inputDate);
  
  printf("Date in numeric format: %d\n", dateNumber);
  
  // converting date from numeric format to text
  char* outputDate = convertToDate(dateNumber);
  
  printf("Date in text format: %s\n", outputDate);
  
  free(inputDate);
  free(outputDate);
  
  return 0;
}