//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
  char buffer[MAX_BUFFER_SIZE];
  FILE *fp;
  int tcases;
  char unit_from, unit_to;
  float temp;

  fp = fopen("temperature.txt", "r");
  fscanf(fp, "%d", &tcases);

  for (int i = 0; i < tcases; i++)
  {
    fscanf(fp, "%c %c %f", &unit_from, &unit_to, &temp);

    switch (unit_from)
    {
      case 'C':
        switch (unit_to)
        {
          case 'F':
            temp = (temp * 1.8) + 32;
            break;
          case 'K':
            temp = temp + 273.15;
            break;
        }
        break;
      case 'F':
        switch (unit_to)
        {
          case 'C':
            temp = (temp - 32) * 5 / 9;
            break;
          case 'K':
            temp = (temp - 32) * 5 / 9 + 273.15;
            break;
        }
        break;
      case 'K':
        switch (unit_to)
        {
          case 'C':
            temp = temp - 273.15;
            break;
          case 'F':
            temp = (temp - 273.15) * 9 / 5 + 32;
            break;
        }
        break;
    }

    printf("%f", temp);
  }

  fclose(fp);
  return 0;
}