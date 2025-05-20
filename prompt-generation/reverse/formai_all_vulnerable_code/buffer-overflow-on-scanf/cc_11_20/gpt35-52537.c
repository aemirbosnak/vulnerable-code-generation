//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: energetic
#include <stdio.h>

int main() {
  int day, month, year = 0;

  printf("Enter a date in the format DD/MM/YYYY: ");
  scanf("%d/%d/%d", &day, &month, &year);

  // Check for valid input
  if (day < 1 || day > 31 || month < 1 || month > 12) {
    printf("Invalid date!\n");
    return 1;
  }

  // Let's start with the day
  char* dayStr;
  switch (day) {
    case 1:
      dayStr = "1st";
      break;
    case 2:
      dayStr = "2nd";
      break;
    case 3:
      dayStr = "3rd";
      break;
    default:
      dayStr = "%dth";
  }

  // Handle the month
  char* monthStr;
  switch (month) {
    case 1:
      monthStr = "January";
      break;
    case 2:
      monthStr = "February";
      break;
    case 3:
      monthStr = "March";
      break;
    case 4:
      monthStr = "April";
      break;
    case 5:
      monthStr = "May";
      break;
    case 6:
      monthStr = "June";
      break;
    case 7:
      monthStr = "July";
      break;
    case 8:
      monthStr = "August";
      break;
    case 9:
      monthStr = "September";
      break;
    case 10:
      monthStr = "October";
      break;
    case 11:
      monthStr = "November";
      break;
    default:
      monthStr = "December";
  }

  printf("%s %s, %d\n", monthStr, dayStr, year);

  return 0;
}