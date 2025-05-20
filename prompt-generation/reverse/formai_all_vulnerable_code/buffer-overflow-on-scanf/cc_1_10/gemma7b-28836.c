//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  // Declare variables
  char name[20], entry[200], date[20], time[20];
  int choice, i, day, month, year;

  // Initialize the digital diary
  printf("Welcome to your digital diary.\n");
  printf("Please create a username: ");
  scanf("%s", name);
  printf("Please create a password: ");
  scanf("%s", entry);

  // Main loop
  do
  {
    // Display options
    printf("\nOptions:");
    printf("1. Write an entry\n");
    printf("2. Read entries\n");
    printf("3. Exit\n");

    // Get user input
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
      case 1:
        // Get entry details
        printf("Enter the date (DD/MM/YY): ");
        scanf("%s", date);
        printf("Enter the time (HH:MM): ");
        scanf("%s", time);
        printf("Enter your entry: ");
        scanf("%s", entry);

        // Store entry
        FILE *fp = fopen("diary.txt", "a");
        fprintf(fp, "%s %s %s %s - %s\n", name, date, time, entry);
        fclose(fp);

        break;
      case 2:
        // Read entries
        fp = fopen("diary.txt", "r");
        while (fscanf(fp, "%s %s %s %s - %s\n", name, date, time, entry) != EOF)
        {
          printf("%s %s %s %s - %s\n", name, date, time, entry);
        }
        fclose(fp);

        break;
      case 3:
        // Exit
        printf("Thank you for using your digital diary. Goodbye.\n");
        break;
      default:
        // Invalid input
        printf("Invalid choice. Please try again.\n");
    }

  } while (choice != 3);

  return 0;
}