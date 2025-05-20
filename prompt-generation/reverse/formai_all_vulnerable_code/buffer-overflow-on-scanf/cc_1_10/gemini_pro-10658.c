//GEMINI-pro DATASET v1.0 Category: File handling ; Style: retro
/*
  ______ __     ___  ___  _____  _   _ ______ _________ _____ _____  
 |  ____|\ \   / / ||__ \|  __ \| \ | ||  ____|__   __|__  /|  __ \|
 | |__   \ \ / /| | /  \| |__) ||  \| || |__     | |    / / | |  | |
 |  __|   \  / | | |   |  ___/ | . ` ||  __|    | |   / /  | |  | |
 | |____   \/ /  | |   | |    | |\  || |____   | |  / /   | |__| |
 |______|  / /   |_|   |_|    |_| \_||______|  |_| /_/    |_____/ 
         /_/                                                     
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 100

int main() {
  /* Welcome the user */
  printf("Welcome to the Retro File Handler 2000!\n");
  printf("Please enter the name of the file you want to open: ");

  /* Get the file name from the user */
  char filename[MAX_LINE_LENGTH];
  scanf("%s", filename);

  /* Open the file */
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file!\n");
    return EXIT_FAILURE;
  }

  /* Read the lines from the file */
  char lines[MAX_LINES][MAX_LINE_LENGTH];
  int line_count = 0;
  while (fgets(lines[line_count], MAX_LINE_LENGTH, file) != NULL) {
    line_count++;
  }

  /* Close the file */
  fclose(file);

  /* Print the lines from the file */
  printf("\nHere are the lines from the file:\n");
  for (int i = 0; i < line_count; i++) {
    printf("%s", lines[i]);
  }

  /* Say goodbye to the user */
  printf("\nThank you for using the Retro File Handler 2000!\n");

  return EXIT_SUCCESS;
}