//FormAI DATASET v1.0 Category: Unit converter ; Style: artistic
#include <stdio.h>

int main() {
  // Artistic Unit Converter Program

  printf("\n");

  printf("           * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
  printf("           *                                                     *\n");
  printf("           *                ARTISTIC UNIT CONVERTER               *\n");
  printf("           *                                                     *\n");
  printf("           * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");

  printf("\n");

  float input_num, output_num;
  char input_unit[10], output_unit[10];

  printf("Enter the number you want to convert: ");
  scanf("%f", &input_num);

  printf("\n");

  printf("Enter the unit of the input number: ");
  scanf("%s", input_unit);

  printf("\n");

  printf("Enter the unit you want to convert to: ");
  scanf("%s", output_unit);

  printf("\n");

  // Temperature units
  if (strcmp(input_unit, "celsius") == 0 && strcmp(output_unit, "fahrenheit") == 0) {
    output_num = (input_num * 1.8) + 32;
    printf("%.2f degrees celsius is equal to %.2f degrees fahrenheit\n", input_num, output_num);
  } else if (strcmp(input_unit, "fahrenheit") == 0 && strcmp(output_unit, "celsius") == 0) {
    output_num = (input_num - 32) / 1.8;
    printf("%.2f degrees fahrenheit is equal to %.2f degrees celsius\n", input_num, output_num);
  } else {
    printf("Invalid conversion, please try again with valid units\n");
  }

  printf("\n");

  printf("           * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
  printf("           *                                                     *\n");
  printf("           *               THANK YOU FOR USING OUR                *\n");
  printf("           *                ARTISTIC UNIT CONVERTER               *\n");
  printf("           *                                                     *\n");
  printf("           * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");

  printf("\n");

  return 0;
}