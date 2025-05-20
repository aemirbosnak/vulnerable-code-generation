//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main()
{
  printf("Greetings, traveler! Welcome to the Medieval C Metadata Extractor!\n\n");

  printf("Please enter the name of a text file you wish to extract metadata from: ");

  char filename[50];
  scanf("%s", filename);

  FILE *fp;
  fp = fopen(filename, "r");

  if(fp == NULL)
  {
    printf("I'm sorry, noble one, but I could not find the requested file.\n\n");
    return 1;
  }

  printf("Hark! The Metadata we found is as follows:\n\n");

  char line[255];

  while(fgets(line, 255, fp))
  {
    if(strstr(line, "Author:"))
    {
      printf("Author: ");
      for(int i=7; i<strlen(line); i++)
      {
        printf("%c", line[i]);
      }
      printf("\n");
    }

    if(strstr(line, "Title:"))
    {
      printf("Title: ");
      for(int i=6; i<strlen(line); i++)
      {
        printf("%c", line[i]);
      }
      printf("\n");
    }

    if(strstr(line, "Date:"))
    {
      printf("Date: ");
      for(int i=5; i<strlen(line); i++)
      {
        printf("%c", line[i]);
      }
      printf("\n");
    }

    if(strstr(line, "Keywords:"))
    {
      printf("Keywords: ");
      for(int i=9; i<strlen(line); i++)
      {
        printf("%c", line[i]);
      }
      printf("\n");
    }
  }

  fclose(fp);

  printf("\nWe hope the extracted metadata serves you well on thy quests!\n");

  return 0;
}