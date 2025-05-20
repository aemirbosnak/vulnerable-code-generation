//FormAI DATASET v1.0 Category: Digital Diary ; Style: detailed
#include <stdio.h>
#include <string.h>

int main() {
  char username[20], password[20], action[10], fileName[30];
  FILE *fp;
  printf("Welcome to your digital diary!\n");

  do {
    printf("\nPlease choose an action to perform: \n");
    printf("1. Create Diary Entry\n");
    printf("2. View Diary Entries\n");
    printf("3. Delete Diary Entry\n");
    printf("4. Exit\n");

    scanf("%s", action);
    
    if (strcmp(action, "1") == 0) {
      printf("Enter your username: ");
      scanf("%s", username);

      printf("Enter your password: ");
      scanf("%s", password);

      printf("Enter the name of the file where you want to save your entry: ");
      scanf("%s", fileName);

      fp = fopen(fileName, "w");
      if (fp != NULL) {
        printf("\nPlease enter the contents of your diary entry: \n");
        char diaryEntry[1000];
        getchar(); // to clear input buffer
        fgets(diaryEntry, 1000, stdin);

        fputs(diaryEntry, fp);
        fclose(fp);

        printf("Diary entry saved successfully!\n");
      } else {
        printf("Invalid filename or operation failed. Try again later.\n");
      }

    } else if (strcmp(action, "2") == 0) {
      printf("Enter your username: ");
      scanf("%s", username);

      printf("Enter your password: ");
      scanf("%s", password);

      printf("Enter the name of the file you wish to view: ");
      scanf("%s", fileName);

      fp = fopen(fileName, "r");
      if (fp != NULL) {
        char c = fgetc(fp);
        while (c != EOF) {
          printf("%c", c);
          c = fgetc(fp);
        }
        fclose(fp);
      } else {
        printf("Invalid filename or operation failed. Try again later.\n");
      }

    } else if (strcmp(action, "3") == 0) {
      printf("Enter your username: ");
      scanf("%s", username);

      printf("Enter your password: ");
      scanf("%s", password);

      printf("Enter the name of the file you wish to delete: ");
      scanf("%s", fileName);

      if (remove(fileName) == 0) {
        printf("Diary entry deleted successfully!\n");
      } else {
        printf("Invalid filename or operation failed. Try again later.\n");
      }

    } else if (strcmp(action, "4") == 0) {
      printf("Exiting digital diary...\n");
      break;
    } else {
      printf("Invalid option chosen. Please try again.\n");
    }

  } while (strcmp(action, "4") != 0);

  return 0;
}