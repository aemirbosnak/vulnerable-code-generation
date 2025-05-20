//FormAI DATASET v1.0 Category: File handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *file;
  char filename[50];
  char word[50];
  int choice, count = 0;

  printf("Welcome to the Text File Manager!\n\n");

  while(1) {
    printf("Please select an option:\n");
    printf("1. Create a new text file\n");
    printf("2. Read an existing text file\n");
    printf("3. Write to an existing text file\n");
    printf("4. Count the number of words in a text file\n");
    printf("5. Exit\n");

    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("\nEnter the name of the file to create: ");
        scanf("%s", filename);

        file = fopen(filename, "w");

        if(file == NULL) {
          printf("\nError creating file! Please try again.\n\n");
          break;
        }

        printf("\nFile created successfully!\n\n");
        fclose(file);
        break;

      case 2:
        printf("\nEnter the name of the file to read: ");
        scanf("%s", filename);

        file = fopen(filename, "r");

        if(file == NULL) {
          printf("\nError opening file! Please make sure the file exists.\n\n");
          break;
        }

        printf("\nThe contents of %s are:\n\n", filename);

        while(fscanf(file, "%s", word) == 1) {
          printf("%s ", word);
        }

        printf("\n\n");
        fclose(file);
        break;

      case 3:
        printf("\nEnter the name of the file to write to: ");
        scanf("%s", filename);

        file = fopen(filename, "a+");

        if(file == NULL) {
          printf("\nError opening file! Please make sure the file exists.\n\n");
          break;
        }

        printf("\nEnter the text you wish to write: ");

        while(scanf("%s", word) == 1) {
          fprintf(file, "%s ", word);
        }

        printf("\n\n");

        fclose(file);
        break;

      case 4:
        printf("\nEnter the name of the file to count words in: ");
        scanf("%s", filename);

        file = fopen(filename, "r");

        if(file == NULL) {
          printf("\nError opening file! Please make sure the file exists.\n\n");
          break;
        }

        while(fscanf(file, "%s", word) == 1) {
          count++;
        }

        printf("\n%s contains %d words.\n\n", filename, count);

        fclose(file);
        break;

      case 5:
        printf("\nThank you for using the Text File Manager!\n");
        exit(0);

      default:
        printf("\nInvalid choice! Please select an option between 1 and 5.\n\n");
        break;
    }
  }

  return 0;
}