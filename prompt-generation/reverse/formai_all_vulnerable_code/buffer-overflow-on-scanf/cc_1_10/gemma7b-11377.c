//Gemma-7B DATASET v1.0 Category: Database querying ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_NAME_LENGTH 255

int main()
{
  char name[MAX_NAME_LENGTH];
  printf("Enter your name: ");
  scanf("%s", name);

  FILE *fp = fopen("database.txt", "r");
  if (fp == NULL)
  {
    perror("Error opening file");
    exit(1);
  }

  char query[MAX_NAME_LENGTH];
  printf("Enter your query: ");
  scanf("%s", query);

  int result = search(fp, name, query);
  if (result)
  {
    printf("Found!\n");
  } else
  {
    printf("Not found.\n");
  }

  fclose(fp);
  return 0;
}

int search(FILE *fp, char *name, char *query)
{
  char line[MAX_NAME_LENGTH];
  while (fgets(line, MAX_NAME_LENGTH, fp) != NULL)
  {
    if (strstr(line, name) && strstr(line, query))
    {
      return 1;
    }
  }

  return 0;
}