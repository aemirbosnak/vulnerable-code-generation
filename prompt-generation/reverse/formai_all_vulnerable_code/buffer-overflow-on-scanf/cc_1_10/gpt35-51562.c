//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate leap year
int isLeap(int year)
{
  if (year % 4 != 0)
    return 0;
  else if (year % 400 == 0)
    return 1;
  else if (year % 100 == 0)
    return 0;
  else
    return 1;
}

// Function to convert date to days
int dateToDays(int d, int m, int y)
{
  int days = d;

  switch (m - 1)
  {
    case 11:
      days += 30;
    case 10:
      days += 31;
    case 9:
      days += 30;
    case 8:
      days += 31;
    case 7:
      days += 31;
    case 6:
      days += 30;
    case 5:
      days += 31;
    case 4:
      days += 30;
    case 3:
      days += 31;
    case 2:
      days += isLeap(y) ? 29 : 28;
    case 1:
      days += 31;
  }

  return days;
}

// Function to convert days to date
void daysToDate(int days, int *d, int *m, int *y)
{
  int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  *y = (days / 365);
  *d = days - (*y * 365);

  // Check for leap year
  if (*d > 59 && isLeap(*y))
    *d = (*d) - 1;

  *m = 0;

  // Calculate month and day
  while (*d > monthDays[*m])
  {
    *d = (*d) - monthDays[*m];

    if (*m == 1 && isLeap(*y))
      (*d)--;

    (*m)++;
  }
}

// Function to print a date
void printDate(int d, int m, int y)
{
  printf("%d-%d-%d", d, m, y);
}

// Main function
int main()
{
  int d, m, y;

  // Example date (in YYYY-MM-DD format)
  char date[11] = {'\0'};
  printf("Enter a date in this format (YYYY-MM-DD): ");
  scanf("%s", date);

  // Extract day, month, and year from the date string
  char *ptr = strtok(date, "-");
  y = atoi(ptr);
  ptr = strtok(NULL, "-");
  m = atoi(ptr);
  ptr = strtok(NULL, "-");
  d = atoi(ptr);

  // Convert date to days
  int days = dateToDays(d, m, y);

  // Print the number of days
  printf("%d days since 01-01-0000\n", days);

  // Convert days back to date
  daysToDate(days, &d, &m, &y);

  // Print the date in DD-MM-YYYY format
  printf("The date is: ");
  printDate(d, m, y);

  return 0;
}