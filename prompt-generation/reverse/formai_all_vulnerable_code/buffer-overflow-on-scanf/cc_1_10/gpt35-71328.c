//FormAI DATASET v1.0 Category: File Synchronizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  printf("Welcome to the C File Synchronizer!\n");

  char file1[100], file2[100];
  int choice;

  printf("Enter the path to the first file: ");
  fgets(file1, 100, stdin);
  file1[strcspn(file1, "\n")] = '\0'; // remove newline character from input

  printf("Enter the path to the second file: ");
  fgets(file2, 100, stdin);
  file2[strcspn(file2, "\n")] = '\0';

  printf("Choose an option:\n");
  printf("1. Sync from first file to second file.\n");
  printf("2. Sync from second file to first file.\n");
  printf("> ");

  scanf("%d", &choice);
  getchar(); // remove newline character from buffer

  if (choice == 1) {
    FILE *f1 = fopen(file1, "r");
    FILE *f2 = fopen(file2, "w");

    if (f1 == NULL) {
      printf("Could not open file \"%s\"!\n", file1);
      return 1;
    }

    if (f2 == NULL) {
      printf("Could not open file \"%s\"!\n", file2);
      return 1;
    }

    char c;
    while ((c = fgetc(f1)) != EOF) {
      fputc(c, f2);
    }

    printf("Sync from \"%s\" to \"%s\" successful!\n", file1, file2);
    
    fclose(f1);
    fclose(f2);
  }
  else if (choice == 2) {
    FILE *f1 = fopen(file1, "w");
    FILE *f2 = fopen(file2, "r");

    if (f1 == NULL) {
      printf("Could not open file \"%s\"!\n", file1);
      return 1;
    }

    if (f2 == NULL) {
      printf("Could not open file \"%s\"!\n", file2);
      return 1;
    }

    char c;
    while ((c = fgetc(f2)) != EOF) {
      fputc(c, f1);
    }

    printf("Sync from \"%s\" to \"%s\" successful!\n", file2, file1);
    
    fclose(f1);
    fclose(f2);
  }
  else {
    printf("Invalid choice!\n");
    return 1;
  }

  return 0;
}