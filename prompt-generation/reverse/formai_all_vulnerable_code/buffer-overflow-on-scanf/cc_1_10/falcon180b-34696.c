//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
  int choice;
  char input[100];
  char hex[100];
  char bin[100];
  char output[100];

  printf("Welcome to the Color Code Converter!\n");
  printf("Please select the type of color code you want to convert:\n");
  printf("1. Hexadecimal to RGB\n");
  printf("2. RGB to Hexadecimal\n");
  printf("3. RGB to Binary\n");
  printf("4. Binary to RGB\n");
  scanf("%d",&choice);

  switch(choice)
  {
    case 1:
      printf("Enter the hexadecimal color code: ");
      scanf("%s",input);
      sprintf(output,"RGB: %d, %d, %d",hex[0],hex[1],hex[2]);
      printf("%s\n",output);
      break;

    case 2:
      printf("Enter the RGB color code: ");
      scanf("%s",input);
      sprintf(hex,"%02X%02X%02X",input[0],input[1],input[2]);
      printf("Hexadecimal: %s\n",hex);
      break;

    case 3:
      printf("Enter the RGB color code: ");
      scanf("%s",input);
      sprintf(bin,"%010d",input[0]);
      sprintf(bin,"%010d",input[1]);
      sprintf(bin,"%010d",input[2]);
      printf("Binary: %s\n",bin);
      break;

    case 4:
      printf("Enter the binary color code: ");
      scanf("%s",input);
      sprintf(output,"RGB: %d, %d, %d",bin[0],bin[1],bin[2]);
      printf("%s\n",output);
      break;

    default:
      printf("Invalid choice!\n");
  }

  return 0;
}