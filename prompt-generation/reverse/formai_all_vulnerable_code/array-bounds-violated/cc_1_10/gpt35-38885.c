//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("\n ★★★★★  Welcome to the C Natural Language Date Converter  ★★★★★\n");

  // month names with their integer values
  char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  int month_numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

  while (1) {
    printf("\n Please enter date in natural language (like January 1st, 1970): ");
    char input[30];
    fgets(input, 30, stdin);

    // removing '\n' character from end of the input
    input[strlen(input) - 1] = '\0';

    // splitting the input into day, month and year
    int day;
    char month_name[10];
    int year;
    sscanf(input, "%d %s, %d", &day, month_name, &year);

    // getting the integer value of month name
    int month_number;
    for (int i = 0; i < 12; i++) {
      if (strcmp(month_name, months[i]) == 0) {
        month_number = month_numbers[i];
        break;
      }
    }

    // printing the converted date
    printf("\n Converted date: %02d/%02d/%d \n", month_number, day, year);

    printf("\n Do you want to convert another date? (y/n): ");
    char choice;
    scanf("%c", &choice);
    if (choice != 'y' && choice != 'Y') {
      printf("\n ★★★★★  Thank you for using the C Natural Language Date Converter  ★★★★★\n");
      break;
    }
    // flushing input buffer
    while ((choice = getchar()) != '\n');
  }

  return 0;
}