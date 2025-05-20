//FormAI DATASET v1.0 Category: Digital Diary ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct entry {
  int day;
  int month;
  int year;
  char notes[1000];
};

int main() {
  struct entry diary[365];
  int i, choice, num_entries = 0;
  char date[11];

  printf("Welcome to your Digital Diary!\n");

  do {
    printf("\nWhat would you like to do?\n");
    printf("1. Add an entry\n");
    printf("2. View all entries\n");
    printf("3. Search for entries\n");
    printf("4. Quit\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        if(num_entries == 365) {
          printf("\nSorry, you have reached the maximum number of entries!\n");
          break;
        }
        printf("\nEnter the date (dd/mm/yyyy): ");
        scanf("%s", date);
        sscanf(date, "%d/%d/%d", &diary[num_entries].day, &diary[num_entries].month, &diary[num_entries].year);
        printf("Enter your notes (max. 1000 characters):\n");
        scanf(" %[^\n]s", diary[num_entries].notes);
        num_entries++;
        break;
      case 2:
        if(num_entries == 0) {
          printf("\nYou have not added any entries yet.\n");
          break;
        }
        printf("\nAll entries:\n");
        for(i = 0; i < num_entries; i++) {
          printf("%02d/%02d/%d: %s\n", diary[i].day, diary[i].month, diary[i].year, diary[i].notes);
        }
        break;
      case 3:
        if(num_entries == 0) {
          printf("\nYou have not added any entries yet.\n");
          break;
        }
        printf("\nEnter the date you want to search for (dd/mm/yyyy): ");
        scanf("%s", date);
        int day, month, year;
        sscanf(date, "%d/%d/%d", &day, &month, &year);
        int found = 0;
        for(i = 0; i < num_entries; i++) {
          if(diary[i].day == day && diary[i].month == month && diary[i].year == year) {
            printf("%02d/%02d/%d: %s\n", diary[i].day, diary[i].month, diary[i].year, diary[i].notes);
            found = 1;
          }
        }
        if(!found) {
          printf("\nSorry, no entries found for the date entered.\n");
        }
        break;
      case 4:
        printf("\nThank you for using the Digital Diary. Goodbye!\n");
        break;
      default:
        printf("\nInvalid choice. Please enter a valid choice (1-4).\n");
    }
  } while(choice != 4);

  return 0;
}