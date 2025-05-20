//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HISTORY 10

char history[MAX_HISTORY][256];

int hist_pos = 0;

void add_history(char *cmd)
{
  if (hist_pos >= MAX_HISTORY)
  {
    hist_pos = MAX_HISTORY - 1;
  }
  strcpy(history[hist_pos++], cmd);
}

void show_history()
{
  for (int i = 0; i < hist_pos; i++)
  {
    printf("%s\n", history[i]);
  }
}

int main()
{
  char cmd[256];

  while (1)
  {
    printf("$ ");
    scanf("%s", cmd);

    add_history(cmd);

    if (strcmp(cmd, "exit") == 0)
    {
      break;
    }

    system(cmd);
  }

  show_history();

  return 0;
}