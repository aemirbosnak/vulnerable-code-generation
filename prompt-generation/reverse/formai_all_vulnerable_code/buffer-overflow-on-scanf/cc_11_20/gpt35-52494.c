//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int month, day, year;
  printf("Welcome to the Date Converter program!\n");
  printf("Please enter the month (1-12): ");
  scanf("%d", &month);
  printf("Please enter the day (1-31): ");
  scanf("%d", &day);
  printf("Please enter the year: ");
  scanf("%d", &year);
  printf("You entered the date %d-%d-%d.\n", month, day, year);

  switch (month) {
    case 1:
      printf("January %d, %d\n", day, year);
      break;
    case 2:
      printf("February %d, %d\n", day, year);
      break;
    case 3:
      printf("March %d, %d\n", day, year);
      break;
    case 4:
      printf("April %d, %d\n", day, year);
      break;
    case 5:
      printf("May %d, %d\n", day, year);
      break;
    case 6:
      printf("June %d, %d\n", day, year);
      break;
    case 7:
      printf("July %d, %d\n", day, year);
      break;
    case 8:
      printf("August %d, %d\n", day, year);
      break;
    case 9:
      printf("September %d, %d\n", day, year);
      break;
    case 10:
      printf("October %d, %d\n", day, year);
      break;
    case 11:
      printf("November %d, %d\n", day, year);
      break;
    case 12:
      printf("December %d, %d\n", day, year);
      break;
    default:
      printf("Invalid month, please try again.\n");
      exit(1);
  }

  return 0;
}