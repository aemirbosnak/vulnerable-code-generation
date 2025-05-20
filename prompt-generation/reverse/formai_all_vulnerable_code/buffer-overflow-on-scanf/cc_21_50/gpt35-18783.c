//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: happy
#include <stdio.h>

int main() {
  int day, month, year;
  
  printf("Welcome to the Date Converter Program! Let's convert a date to natural language!\n");
  printf("Please enter the day: ");
  scanf("%d", &day);
  
  printf("Please enter the month: ");
  scanf("%d", &month);
  
  printf("Please enter the year: ");
  scanf("%d", &year);
  
  printf("\n");
  
  // Check if date is valid
  if (month < 1 || month > 12) {
    printf("Invalid month entered.\n");
    return 0;
  }
  
  if (day < 1 || day > 31) {
    printf("Invalid day entered.\n");
    return 0;
  }
  
  if (year < 0) {
    printf("Invalid year entered.\n");
    return 0;
  }
  
  // Convert month number to string
  char* monthString;
  
  switch (month) {
    case 1:
      monthString = "January";
      break;
    case 2:
      monthString = "February";
      break;
    case 3:
      monthString = "March";
      break;
    case 4:
      monthString = "April";
      break;
    case 5:
      monthString = "May";
      break;
    case 6:
      monthString = "June";
      break;
    case 7:
      monthString = "July";
      break;
    case 8:
      monthString = "August";
      break;
    case 9:
      monthString = "September";
      break;
    case 10:
      monthString = "October";
      break;
    case 11:
      monthString = "November";
      break;
    case 12:
      monthString = "December";
      break;
    default:
      printf("Invalid month entered.\n");
      return 0;
  }
  
  // Convert day number to string
  char* dayString;
  
  switch (day) {
    case 1:
      dayString = "first";
      break;
    case 2:
      dayString = "second";
      break;
    case 3:
      dayString = "third";
      break;
    // continue for other special cases
    default:
      dayString = "th";
      break;
  }
  
  // Determine suffix for day
  if (day == 11 || day == 12 || day == 13) {
    dayString = "th";
  } else {
    switch (day % 10) {
      case 1:
        dayString = "st";
        break;
      case 2:
        dayString = "nd";
        break;
      case 3:
        dayString = "rd";
        break;
      default:
        dayString = "th";
        break;
    }
  }
  
  // Print natural language date
  printf("%s %d%s, %d\n", monthString, day, dayString, year);
  
  return 0;
}