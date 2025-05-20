//FormAI DATASET v1.0 Category: Date and time ; Style: cheerful
#include <stdio.h>
#include <time.h>

int main() {
  time_t now;
  time(&now);

  printf("Welcome to the date and time program!\n");
  printf("Today's date and time is:\n");

  char date_str[50], time_str[50];
  strftime(date_str, sizeof(date_str), "%Y-%m-%d", localtime(&now));
  strftime(time_str, sizeof(time_str), "%H:%M:%S", localtime(&now));

  printf("%s %s\n\n", date_str, time_str);

  printf("What's your favorite day of the week? (1 for Monday, 7 for Sunday)\n");
  
  int day_choice;
  scanf("%d", &day_choice);

  if (day_choice < 1 || day_choice > 7) {
    printf("I'm sorry, that's not a valid day choice. Goodbye!\n");
    return 0;
  }

  printf("\nYour chosen day, ");

  switch(day_choice) {
    case 1:
      printf("Monday");
      break;
    case 2:
      printf("Tuesday");
      break;
    case 3:
      printf("Wednesday");
      break;
    case 4:
      printf("Thursday");
      break;
    case 5:
      printf("Friday");
      break;
    case 6:
      printf("Saturday");
      break;
    case 7:
      printf("Sunday");
      break;
  }

  printf(", is a great day!\n");
  printf("Here's the date and time again, just in case you forgot:\n");
  printf("%s %s\n\n", date_str, time_str);

  printf("Thanks for using the date and time program! Goodbye!\n");

  return 0;
}