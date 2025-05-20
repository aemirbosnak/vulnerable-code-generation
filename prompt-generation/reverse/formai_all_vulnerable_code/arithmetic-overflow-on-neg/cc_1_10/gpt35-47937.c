//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

void convertDate(char date[]) {
  int day, month, year;
  sscanf(date, "%d/%d/%d", &month, &day, &year); // parse the date string into day month and year

  printf("The date in natural language format is: ");

  // print month in natural language
  switch (month) {
    case 1:
      printf("January");
      break;
    case 2:
      printf("February");
      break;
    case 3:
      printf("March");
      break;
    case 4:
      printf("April");
      break;
    case 5:
      printf("May");
      break;
    case 6:
      printf("June");
      break;
    case 7:
      printf("July");
      break;
    case 8:
      printf("August");
      break;
    case 9:
      printf("September");
      break;
    case 10:
      printf("October");
      break;
    case 11:
      printf("November");
      break;
    case 12:
      printf("December");
      break;
    default:
      printf("Invalid month");
      exit(1);
  }

  // print day in natural language
  printf(" %d, ", day);

  // print year in natural language
  if (year < 0) {
    printf("%d BCE", -year);
  } else {
    printf("%d CE", year);
  }
}

int main(void) {
  char date[11];

  printf("Enter a date in the format MM/DD/YYYY: ");
  fgets(date, 11, stdin); // read input from user

  convertDate(date); // call function to convert and print the date in natural language

  return 0;
}