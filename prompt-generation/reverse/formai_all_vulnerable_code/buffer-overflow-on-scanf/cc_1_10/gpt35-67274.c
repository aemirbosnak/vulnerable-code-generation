//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* hexToDecimal(char *hex);
char* decimalToHex(char *decimal);

int main()
{
  int choice;
  char input[100];

  printf("Enter 1 to convert from Hexadecimal to Decimal\n");
  printf("Enter 2 to convert from Decimal to Hexadecimal\n");

  scanf("%d", &choice);
  printf("Enter the number to be converted: ");
  scanf("%s", input);

  if (choice == 1)
  {
    char *decimal = hexToDecimal(input);
    printf("Decimal value of %s is %s\n", input, decimal);
    free(decimal);
  }
  else if (choice == 2)
  {
    char *hex = decimalToHex(input);
    printf("Hexadecimal value of %s is %s\n", input, hex);
    free(hex);
  }
  else
  {
    printf("Invalid choice!\n");
  }

  return 0;
}

char* hexToDecimal(char *hex)
{
  int len = strlen(hex), dec = 0, base = 1;

  for (int i = len - 1; i >= 0; i--)
  {
    if (hex[i] >= '0' && hex[i] <= '9')
    {
      dec += (hex[i] - 48) * base;
      base *= 16;
    }
    else if (hex[i] >= 'A' && hex[i] <= 'F')
    {
      dec += (hex[i] - 55) * base;
      base *= 16;
    }
    else
    {
      printf("Invalid Hexadecimal Number!\n");
      exit(0);
    }
  }

  char *decimal = malloc(sizeof(char) * 100);
  sprintf(decimal, "%d", dec);
  return decimal;
}

char* decimalToHex(char *decimal)
{
  int dec = atoi(decimal);
  char *hex = malloc(sizeof(char) * 100);
  sprintf(hex, "%X", dec);
  return hex;
}