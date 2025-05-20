//FormAI DATASET v1.0 Category: File handling ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp;
  char filename[50];
  int choice, num, count = 0;

  printf("Enter the name of the file: ");
  scanf("%s", filename);

  fp = fopen(filename, "w+");

  if (fp == NULL) {
    printf("Sorry, can't create the file.\n");
    exit(1);
  } else {
    printf("File created successfully.\n");
  }

  printf("What do you want to do with the file?\n");
  printf("1. Add numbers to the file.\n");
  printf("2. Read numbers from the file.\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("How many numbers do you want to add?\n");
      scanf("%d", &num);

      for (int i = 0; i < num; i++) {
        int number;
        printf("Enter number %d: ", i+1);
        scanf("%d", &number);
        fprintf(fp, "%d ", number);
        count++;
      }
      printf("%d numbers added successfully.\n", count);
      break;

    case 2:
      printf("Numbers in the file are:\n");

      while(!feof(fp)) {
        int number;
        fscanf(fp, "%d", &number);
        printf("%d\n", number);
      }
      break;

    default:
      printf("Invalid choice.\n");
      break;
  }

  fclose(fp);

  return 0;
}