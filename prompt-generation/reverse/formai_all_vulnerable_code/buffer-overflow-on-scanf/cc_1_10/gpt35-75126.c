//FormAI DATASET v1.0 Category: File handling ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Wait, what? File handling? I'm not ready for this!\n");

  // Initializing stuff
  char fileName[100], data[1000];
  FILE *fptr;

  // Prompting the user for file name and opening the file
  printf("Please enter the name of the file you want to create: ");
  scanf("%s", fileName);
  fptr = fopen(fileName, "w");

  // Checking if the file was opened successfully
  if (fptr == NULL) {
    printf("Something went wrong. I can't open the %s file\n", fileName);
    exit(0);
  }

  printf("Phew! File opened successfully\n");

  // Writing data to the file
  printf("Alright. What data should I put in %s? Type 'quit' to stop\n", fileName);
  while (1) {
    scanf("%s", data);
    if (strcmp(data, "quit") == 0) {
      break;
    } else {
      fprintf(fptr, "%s\n", data);
    }
  }

  printf("Done writing to the file. Time to close it\n");
  fclose(fptr);

  // Reopening the file in read mode and reading data from it
  printf("Now let's see what we wrote in %s file\n", fileName);
  fptr = fopen(fileName, "r");

  if (fptr == NULL) {
    printf("Huh? I can't open the %s file anymore\n", fileName);
    exit(0);
  }

  while (fgets(data, 1000, fptr)) {
    printf("%s", data);
  }

  printf("Okay that's enough. Let's close it one last time\n");
  fclose(fptr);

  printf("Whew! That was intense. I think I need a break. Bye!\n");
  return 0;
}