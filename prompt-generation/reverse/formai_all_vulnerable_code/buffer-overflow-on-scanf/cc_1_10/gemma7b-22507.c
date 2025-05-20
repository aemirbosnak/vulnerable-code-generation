//Gemma-7B DATASET v1.0 Category: File Encyptor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define MAX_FILE_SIZE 1024

int main()
{
  char file_name[MAX_FILE_SIZE];
  char key[MAX_FILE_SIZE];
  int file_size, i, j, k, l, m, n, o;
  long int seed;

  printf("Enter file name:");
  scanf("%s", file_name);

  printf("Enter key:");
  scanf("%s", key);

  FILE *fp = fopen(file_name, "r");
  if (fp == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }

  file_size = fread(NULL, 1, 0, fp);
  rewind(fp);

  seed = rand() % 1000000;
  for (i = 0; i < file_size; i++)
  {
    k = seed % 256;
    l = (k + 1) % 256;
    key[i] = (key[i] - 128) ^ l;
  }

  fclose(fp);

  fp = fopen(file_name, "w");
  if (fp == NULL)
  {
    printf("Error writing to file.\n");
    return 1;
  }

  for (i = 0; i < file_size; i++)
  {
    fprintf(fp, "%c", key[i]);
  }

  fclose(fp);

  printf("File encrypted.\n");

  return 0;
}