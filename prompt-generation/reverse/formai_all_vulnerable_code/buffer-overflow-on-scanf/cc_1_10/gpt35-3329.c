//FormAI DATASET v1.0 Category: Syntax parsing ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {
  int happiness = 100, codeLines = 0, errors = 0;
  char name[20];

  printf("Hi there! What's your name?\n");
  scanf("%s", name);

  printf("Welcome, %s! Let's write some C code to make you happy :)\n", name);
  printf("What kind of program do you want to write?\n");

  char type[30];
  scanf("%s", type);

  printf("Great! Let's start with a simple %s program.\n", type);

  printf("Now let's write some code! Remember to smile :)\n");

  char line[100];
  FILE *fp = fopen("program.c", "w");

  while (strcmp(line, "done") != 0) {
    printf("> ");
    scanf(" %[^\n]", line);
    codeLines++;

    if (strstr(line, "error")) {
      errors++;
      printf("Oops! Don't worry, we'll fix the error together :)\n");
    }

    fprintf(fp, "%s\n", line);
  }

  printf("Congratulations, %s! You just wrote %d lines of C code!\n", name, codeLines);
  printf("And you only had %d error(s) - great job!\n", errors);

  fclose(fp);

  printf("Now let's compile the program...\n");

  system("gcc program.c -o program");

  printf("Done! Let's run the program and see the happy results :)\n");

  system("./program");

  printf("Wasn't that fun, %s? Let's write more C code and spread the happiness!\n", name);

  return 0;
}