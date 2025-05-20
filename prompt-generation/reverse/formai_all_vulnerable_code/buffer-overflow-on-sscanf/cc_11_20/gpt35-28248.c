//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: imaginative
#include <stdio.h>

int main() {
  char date[11]; // To store the date in string format
  int day, month, year; // To store the converted date values

  // User input
  printf("Enter a date in the format MM/DD/YYYY: ");
  scanf("%s", date);

  // Converting the date string into integers
  sscanf(date, "%d/%d/%d", &month, &day, &year);

  // Printing the converted date in natural language format
  printf("The date in natural language format is: ");

  switch(month) {
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
  }

  printf(" %d, %d\n", day, year);

  return 0;
}