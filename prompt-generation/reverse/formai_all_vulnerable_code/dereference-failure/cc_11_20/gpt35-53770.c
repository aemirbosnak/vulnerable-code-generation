//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char date[15];
  printf("Ah, fair maiden, prithee tell me the date in natural language format: ");
  scanf("%[^\n]%*c", date);

  char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  char days[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

  // remove extra spaces
  char *token = strtok(date, " ");
  char formattedDate[3][10];
  int i = 0;
  while (token != NULL) {
    strcpy(formattedDate[i], token);
    token = strtok(NULL, " ");
    i++;
  }

  if (i == 3) {
    int day;
    int month;
    int year = atoi(formattedDate[2]);

    // determine day
    for (int j = 0; j < 7; j++) {
      if (strcmp(formattedDate[0], days[j]) == 0) {
        day = j;
        break;
      }
    }

    // determine month
    for (int j = 0; j < 12; j++) {
      if (strcmp(formattedDate[1], months[j]) == 0) {
        month = j;
        break;
      }
    }

    printf("Tis the day of %s, %s the %dth, in the year of our lord %d. \n", formattedDate[0], months[month], atoi(formattedDate[1]), year);
  }
  else if (i == 2) {
    int count = 0;
    for (int j = 0; j < 12; j++) {
      if (strcmp(formattedDate[0], months[j]) == 0) {
        printf("Tis the month of %s, ", formattedDate[0]);
        count++;
        break;
      }
    }

    if (count == 0) {
      printf("Thou hast not entered a month, my lady. Shall I compare thee to a summer's day? \n");
      exit(0);
    }

    int year = atoi(formattedDate[1]);
    if (year > 0) {
      printf("in the year of our lord %d.\n", year);
    }
    else {
      printf("but in what year?\n");
    }
  }
  else {
    printf("Prithee, fair maid, enter thine date in natural language. Shall I compare thee to a winter's day? \n");
  }
  return 0;
}