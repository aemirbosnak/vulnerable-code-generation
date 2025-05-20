//Gemma-7B DATASET v1.0 Category: Antivirus scanner ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scan_files(char *);

int main()
{
  char filename[256];

  printf("Enter the filename: ");
  scanf("%s", filename);

  scan_files(filename);

  return 0;
}

void scan_files(char *filename)
{
  FILE *fp;
  char buffer[4096];
  int i, j, k, flag = 0;

  fp = fopen(filename, "r");
  if (fp == NULL)
  {
    printf("Error opening file.\n");
    return;
  }

  while (fgets(buffer, 4096, fp) != NULL)
  {
    for (i = 0; i < 4096; i++)
    {
      for (j = 0; j < 256; j++)
      {
        if (buffer[i] == filename[j])
        {
          flag = 1;
          break;
        }
      }
    }

    if (flag)
    {
      printf("Warning: File contains suspicious data.\n");
    }

    flag = 0;
  }

  fclose(fp);
}