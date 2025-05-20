//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: shape shifting
#include <stdio.h>

void shift(int *ptr)
{
  int i;
  for(i = 0; i < *ptr; i++)
    printf(" ");
  *ptr += 2;
}

int main()
{
  int temp, conv, shift_count = 0;
  char choice;
  printf("Enter the temperature: ");
  scanf("%d", &temp);
  printf("Enter the conversion type (C/F): ");
  scanf(" %c", &choice);
  switch(choice)
  {
    case 'C':
      conv = (temp - 32) * 5/9;
      printf("The temperature in Celsius is: %d\n", conv);
      break;
    case 'F':
      conv = (temp * 9/5) + 32;
      printf("The temperature in Fahrenheit is: %d\n", conv);
      break;
    default:
      printf("Invalid choice\n");
  }
  printf("Would you like to convert another temperature (Y/N)? ");
  scanf(" %c", &choice);
  while(choice == 'Y')
  {
    shift(&shift_count);
    printf("\n");
    shift(&shift_count);
    printf("Enter the temperature: ");
    scanf("%d", &temp);
    shift(&shift_count);
    printf("Enter the conversion type (C/F): ");
    scanf(" %c", &choice);
    shift(&shift_count);
    switch(choice)
    {
      case 'C':
        conv = (temp - 32) * 5/9;
        shift(&shift_count);
        printf("The temperature in Celsius is: %d\n", conv);
        break;
      case 'F':
        conv = (temp * 9/5) + 32;
        shift(&shift_count);
        printf("The temperature in Fahrenheit is: %d\n", conv);
        break;
      default:
        shift(&shift_count);
        printf("Invalid choice\n");
    }
    shift(&shift_count);
    printf("Would you like to convert another temperature (Y/N)? ");
    scanf(" %c", &choice);
  }
  return 0;
}