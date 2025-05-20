//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: visionary
#include <stdio.h>
#include <string.h>

void dateConverter(char input[20]) {
  int day = 0, month = 0, year = 0;
  char *monthString;

  sscanf(input, "%d %s %d", &day, monthString, &year);

  //convert month string to number
  if(strcmp(monthString, "January") == 0) {
    month = 1;
  } else if(strcmp(monthString, "February") == 0) {
    month = 2;
  } else if(strcmp(monthString, "March") == 0) {
    month = 3;
  } else if(strcmp(monthString, "April") == 0) {
    month = 4;
  } else if(strcmp(monthString, "May") == 0) {
    month = 5;
  } else if(strcmp(monthString, "June") == 0) {
    month = 6;
  } else if(strcmp(monthString, "July") == 0) {
    month = 7;
  } else if(strcmp(monthString, "August") == 0) {
    month = 8;
  } else if(strcmp(monthString, "September") == 0) {
    month = 9;
  } else if(strcmp(monthString, "October") == 0) {
    month = 10;
  } else if(strcmp(monthString, "November") == 0) {
    month = 11;
  } else if(strcmp(monthString, "December") == 0) {
    month = 12;
  } else {
    printf("Invalid input. Please enter in format: dd Month (with capital letter) yyyy\n");
    return;
  }

  //validate input
  if(day < 1 || day > 31) {
    printf("Invalid day. Please enter a number between 1 and 31.\n");
    return;
  }

  if(year < 0 || year > 9999) {
    printf("Invalid year. Please enter a number between 0 and 9999.\n");
    return;
  }

  //print output
  printf("%02d/%02d/%d", month, day, year);
}

int main(void) {
  char input[20];

  printf("Please enter a date in the format: dd Month (with capital letter) yyyy \n");
  fgets(input, 20, stdin);

  //remove newline character at the end of the input string
  input[strcspn(input, "\n")] = 0;

  dateConverter(input);

  return 0;
}