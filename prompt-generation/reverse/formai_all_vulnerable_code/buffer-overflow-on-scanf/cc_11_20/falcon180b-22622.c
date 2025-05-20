//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ENCRYPT 1
#define DECRYPT 2

int main()
{
  char input[1000];
  FILE *fp;
  int choice;

  printf("Enter the file name: ");
  scanf("%s", input);

  printf("Enter the mode: ");
  scanf("%d", &choice);

  if (choice == ENCRYPT)
  {
    fp = fopen(input, "r");
    if (fp == NULL)
    {
      printf("File not found.\n");
      exit(1);
    }

    char ch;
    while ((ch = fgetc(fp))!= EOF)
    {
      if (isalpha(ch))
      {
        ch = toupper(ch);
        ch = ch + 13;
        if (ch > 'Z')
        {
          ch = ch - 26;
        }
        printf("%c", ch);
      }
      else
      {
        printf("%c", ch);
      }
    }

    fclose(fp);
  }
  else if (choice == DECRYPT)
  {
    fp = fopen(input, "r");
    if (fp == NULL)
    {
      printf("File not found.\n");
      exit(1);
    }

    char ch;
    while ((ch = fgetc(fp))!= EOF)
    {
      if (isalpha(ch))
      {
        ch = toupper(ch);
        ch = ch - 13;
        if (ch < 'A')
        {
          ch = ch + 26;
        }
        printf("%c", ch);
      }
      else
      {
        printf("%c", ch);
      }
    }

    fclose(fp);
  }
  else
  {
    printf("Invalid mode.\n");
    exit(1);
  }

  return 0;
}