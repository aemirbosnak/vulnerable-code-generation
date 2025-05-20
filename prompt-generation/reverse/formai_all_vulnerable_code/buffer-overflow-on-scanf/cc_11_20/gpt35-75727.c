//FormAI DATASET v1.0 Category: Digital Diary ; Style: irregular
#include <stdio.h>

int main() {
  int day = 0;
  char notes[50][100];

  printf("--==Welcome to Your Digital Diary==--\n");

  while(1) {
    printf("Which day would you like to view or edit? (Enter 0 to exit)\n");
    scanf("%d", &day);

    if (day == 0) {
      printf("--==Thank you for using Your Digital Diary==--\n");
      break;
    }

    if (notes[day][0] == '\0') {
      printf("You have no notes for Day %d. Would you like to add some? (Y/N)\n", day);
      char response;

      while (1) {
        scanf(" %c", &response);
        if (response == 'Y' || response == 'y') {
          printf("Enter your notes for Day %d (max 100 characters):\n", day);
          scanf(" %[^\n]s", notes[day]);
          break;
        } else if (response == 'N' || response == 'n') {
          break;
        } else {
          printf("Please enter Y or N.\n");
        }
      }

    } else {
      printf("Your notes for Day %d:\n%s\n", day, notes[day]);
      printf("Would you like to edit your notes? (Y/N)\n");

      char response;
      while (1) {
        scanf(" %c", &response);
        if (response == 'Y' || response == 'y') {
          printf("Enter your updated notes for Day %d (max 100 characters):\n", day);
          scanf(" %[^\n]s", notes[day]);
          break;
        } else if (response == 'N' || response == 'n') {
          break;
        } else {
          printf("Please enter Y or N.\n");
        }
      }
    }
  }

  return 0;
}