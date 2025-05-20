//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: genious
#include <stdio.h>

int main() {
  int date, month, year;
  printf("Enter date (1-31): ");
  scanf("%d", &date);
  printf("Enter month (1-12): ");
  scanf("%d", &month);
  printf("Enter year (yyyy format): ");
  scanf("%d", &year);

  if (month < 1 || month > 12) {
    printf("Invalid month!\n");
    return 0;
  }

  if (year < 1 || year > 9999) {
    printf("Invalid year!\n");
    return 0;
  }

  int is_leap_year = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

  if (date < 1 || date > 31) {
    printf("Invalid date!\n");
    return 0;
  } else if ((month == 4 || month == 6 || month == 9 || month == 11) && date > 30) {
    printf("Invalid date!\n");
    return 0;
  } else if (month == 2 && ((is_leap_year && date > 29) || (!is_leap_year && date > 28))) {
    printf("Invalid date!\n");
    return 0;
  }

  printf("The date is: ");

  switch (date) {
    case 1: printf("1st "); break;
    case 2: printf("2nd "); break;
    case 3: printf("3rd "); break;
    default: printf("%dth ", date); break;
  }

  switch (month) {
    case 1: printf("January"); break;
    case 2: printf("February"); break;
    case 3: printf("March"); break;
    case 4: printf("April"); break;
    case 5: printf("May"); break;
    case 6: printf("June"); break;
    case 7: printf("July"); break;
    case 8: printf("August"); break;
    case 9: printf("September"); break;
    case 10: printf("October"); break;
    case 11: printf("November"); break;
    case 12: printf("December"); break;
  }

  printf(", %d.\n", year);

  return 0;
}