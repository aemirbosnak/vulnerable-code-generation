//FormAI DATASET v1.0 Category: File handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
  printf("Welcome to my happy file handling program!\n");

  FILE *fp;
  char filename[50], buffer[100], ch;
  int choice, num;

  do {
    printf("\nWhat do you want to do?\n1. Create a file\n2. Write to a file\n3. Read from a file\n4. Append to a file\n5. Exit\nYour choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1: // create a file
        printf("Enter the filename to create: ");
        scanf("%s", filename);

        fp = fopen(filename, "w");
        if (fp == NULL) {
          printf("Error creating file %s", filename);
          exit(0);
        }
        printf("File %s created successfully\n", filename);
        fclose(fp);
        break;

      case 2: // write to a file
        printf("Enter the filename to write to: ");
        scanf("%s", filename);

        fp = fopen(filename, "w");
        if (fp == NULL) {
          printf("Error opening file %s", filename);
          exit(0);
        }
        printf("Enter text to write to file: ");
        scanf(" %[^\n]", buffer);

        fputs(buffer, fp);
        fclose(fp);
        printf("Text written to file %s successfully\n", filename);
        break;

      case 3: // read from a file
        printf("Enter the filename to read from: ");
        scanf("%s", filename);

        fp = fopen(filename, "r");
        if (fp == NULL) {
          printf("Error opening file %s", filename);
          exit(0);
        }
        printf("Contents of file %s:\n", filename);

        while ((ch = getc(fp)) != EOF) {
          putchar(ch);
        }
        fclose(fp);
        break;

      case 4: // append to a file
        printf("Enter the filename to append to: ");
        scanf("%s", filename);

        fp = fopen(filename, "a");
        if (fp == NULL) {
          printf("Error opening file %s", filename);
          exit(0);
        }
        printf("Enter text to append to file: ");
        scanf(" %[^\n]", buffer);

        fputs(buffer, fp);
        fclose(fp);
        printf("Text appended to file %s successfully\n", filename);
        break;

      case 5: // exit
        printf("Goodbye!\n");
        break;

      default:
        printf("Invalid choice\n");
    }
  } while (choice != 5);

  return 0;
}