//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

  char input[1024];

  printf("Enter the path of your XML file:\n");
  scanf("%s", input);

  FILE *file = fopen(input, "r");

  if (file == NULL) {
    perror("Error opening file");
    return -1;
  }

  char *buffer;
  long length;

  fseek(file, 0, SEEK_END);
  length = ftell(file);
  fseek(file, 0, SEEK_SET);
  buffer = malloc(length);
  if (buffer) {
    fread(buffer, 1, length, file);
  }

  fclose(file);

  char *token;
  token = strtok(buffer, "<> \n");

  while (token != NULL) {

    if (strcmp(token, "title") == 0) {
      printf("This is a title\n");
      token = strtok(NULL, "<> \n");
      printf("Title is: %s\n", token);
    }

    else if (strcmp(token, "author") == 0) {
      printf("This is the author\n");
      token = strtok(NULL, "<> \n");
      printf("Author is: %s\n", token);
    }

    else if (strcmp(token, "year") == 0) {
      printf("This is the year\n");
      token = strtok(NULL, "<> \n");
      printf("Year is: %s\n", token);
    }

    else if (strcmp(token, "publisher") == 0) {
      printf("This is the publisher\n");
      token = strtok(NULL, "<> \n");
      printf("Publisher is: %s\n", token);
    }

    token = strtok(NULL, "<> \n");
  }

  free(buffer);

  return 0;
}