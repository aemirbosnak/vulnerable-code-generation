//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  char input[100];
  int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
  long long int result = 0;

  printf("Enter a hexadecimal number: ");
  scanf("%s", input);

  for (i = 0; input[i] != '\0'; i++) {
    switch (input[i]) {
      case '0':
        result += 0 * pow(16, i);
        break;
      case '1':
        result += 1 * pow(16, i);
        break;
      case '2':
        result += 2 * pow(16, i);
        break;
      case '3':
        result += 3 * pow(16, i);
        break;
      case '4':
        result += 4 * pow(16, i);
        break;
      case '5':
        result += 5 * pow(16, i);
        break;
      case '6':
        result += 6 * pow(16, i);
        break;
      case '7':
        result += 7 * pow(16, i);
        break;
      case '8':
        result += 8 * pow(16, i);
        break;
      case '9':
        result += 9 * pow(16, i);
        break;
      case 'A':
      case 'a':
        result += 10 * pow(16, i);
        break;
      case 'B':
      case 'b':
        result += 11 * pow(16, i);
        break;
      case 'C':
      case 'c':
        result += 12 * pow(16, i);
        break;
      case 'D':
      case 'd':
        result += 13 * pow(16, i);
        break;
      case 'E':
      case 'e':
        result += 14 * pow(16, i);
        break;
      case 'F':
      case 'f':
        result += 15 * pow(16, i);
        break;
      default:
        printf("Invalid hexadecimal digit %c", input[i]);
        return 0;
    }
  }

  printf("The decimal equivalent of %s is %lld\n", input, result);

  return 0;
}