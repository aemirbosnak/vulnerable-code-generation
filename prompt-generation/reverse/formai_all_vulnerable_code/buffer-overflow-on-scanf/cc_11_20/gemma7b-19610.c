//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

int main() {
  double d_num, d_res, d_conv;
  char c_unit, c_res, c_conv;
  int i_conv;

  printf("Enter the number: ");
  scanf("%lf", &d_num);

  printf("Enter the conversion unit: ");
  scanf(" %c", &c_unit);

  printf("Enter the result unit: ");
  scanf(" %c", &c_res);

  switch (c_unit) {
    case 'm':
      i_conv = 1000;
      break;
    case 'kg':
      i_conv = 1000;
      break;
    case 'g':
      i_conv = 1000;
      break;
    case 'l':
      i_conv = 1000;
      break;
    case 'a':
      i_conv = 360;
      break;
  }

  switch (c_res) {
    case 'm':
      d_res = d_num * i_conv;
      break;
    case 'kg':
      d_res = d_num * i_conv;
      break;
    case 'g':
      d_res = d_num * i_conv;
      break;
    case 'l':
      d_res = d_num * i_conv;
      break;
    case 'a':
      d_res = d_num * i_conv;
      break;
  }

  d_conv = d_res * PI / 180;

  printf("The result is: %.2lf %s\n", d_res, c_res);
  printf("The converted angle is: %.2lf %s\n", d_conv, c_conv);

  return 0;
}