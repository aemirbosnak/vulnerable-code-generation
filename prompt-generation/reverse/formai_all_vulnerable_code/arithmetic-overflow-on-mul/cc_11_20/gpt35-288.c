//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: decentralized
#include <stdio.h>
#include <string.h>

int main(){

  char dateInput[30], monthName[30], monthNum[3], year[5];
  int date, month, currYear, remYear, i, numMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  float numDays;

  printf("Please enter a date in natural language (dd mmm yyyy): ");
  fgets(dateInput, 30, stdin);

  sscanf(dateInput, "%d %s %s", &date, monthName, year);

  switch(monthName[0]) {
    case 'J':
      if(monthName[1] == 'a') {
        month = 1;
      } else if (monthName[2] == 'n') {
        month = 6;
      } else {
        month = 7;
      }
      break;
    case 'F':
      month = 2;
      break;
    case 'M':
      if(monthName[2] == 'r') {
        month = 3;
      } else {
        month = 5;
      }
      break;
    case 'A':
      if(monthName[1] == 'p') {
        month = 4;
      } else {
        month = 8;
      }
      break;
    case 'S':
      month = 9;
      break;
    case 'O':
      month = 10;
      break;
    case 'N':
      month = 11;
      break;
    case 'D':
      month = 12;
      break;
    default:
      printf("Input error: please enter a valid date format.");
      return 1;
  }

  currYear = atoi(year);

  if((currYear % 4 == 0 && currYear % 100 != 0) || currYear % 400 == 0) {
    numMonths[1] = 29; //Leap year has 29 days in February
  }

  numDays = (date - 1); //Starting from Jan 1

  for(i = 0; i < month - 1; i++) {
    numDays += numMonths[i];
  }

  numDays += (currYear - 1) * 365;

  remYear = currYear % 4;

  for(i = 0; i < remYear; i++) {
    if(i == 0 || i == 2) {
      numDays += 366; //Leap years every 4 years
    } else {
      numDays += 365;
    }
  }

  numDays += ((currYear - 1) / 4) - remYear / 4; //Extra leap years

  int daysSince1900 = (numDays - 693961); //Days between Jan 1, 1900 and Jan 1, 1970

  int secondsSince1970 = daysSince1900 * 24 * 60 * 60; //Seconds since Jan 1, 1970

  printf("%d", secondsSince1970);

  return 0;

}