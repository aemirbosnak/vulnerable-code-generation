//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: medieval
#include <stdio.h>
#include <string.h>

// function to check if a year is a leap year or not
int isLeapYear(int year) {
  if (year % 4 == 0) {
    if (year % 100 == 0) {
      if (year % 400 == 0)
        return 1;
      else
        return 0;
    } else
      return 1;
  } else
    return 0;
}

// function to get the number of days in a month
int getDaysInMonth(int month, int year) {
  if (month == 2) {
    if (isLeapYear(year))
      return 29;
    else
      return 28;
  } else if (month == 4 || month == 6 || month == 9 || month == 11)
    return 30;
  else
    return 31;
}

// function to convert a month number to its corresponding name
char* getMonthName(int month) {
  char* monthNames[12] = {"January", "February", "March", "April",
                          "May", "June", "July", "August",
                          "September", "October", "November", "December"};
  return monthNames[month-1];
}

// function to convert a date into natural language
char* getDateInWords(int day, int month, int year) {
  // determine the number of days in the month
  int daysInMonth = getDaysInMonth(month, year);

  // check if the date is valid
  if (day < 1 || day > daysInMonth) {
    return "Invalid date!";
  }

  // convert the date into natural language
  char* str = malloc(100 * sizeof(char));
  sprintf(str, "%d%s of %s, %d", day, (day%10==1)?"st":(day%10==2)?"nd":(day%10==3)?"rd":"th", getMonthName(month), year);

  return str;
}

int main() {
  printf("Please enter a valid date in the format dd mm yyyy:\n");

  int day, month, year;
  scanf("%d %d %d", &day, &month, &year);

  char* dateInWords = getDateInWords(day, month, year);

  printf("%s\n", dateInWords);

  return 0;
}