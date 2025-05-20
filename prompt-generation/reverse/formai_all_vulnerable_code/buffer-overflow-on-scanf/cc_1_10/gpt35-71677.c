//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void chex_convert(char str[20]) {
  int len = strlen(str);

  // Reverse the string before conversion
  for(int i = 0; i < len / 2; i++) {
    char temp = str[i];
    str[i] = str[len - i - 1];
    str[len - i - 1] = temp;
  }

  int res = 0;

  // Convert hexadecimal string to decimal
  for(int i = 0; i < len; i++) {
    int val;
    if(str[i] >= '0' && str[i] <= '9') {
      val = str[i] - '0';
    } else {
      val = str[i] - 'A' + 10;
    }
    res += val * (1 << (4 * i));
  }

  // Print the result in binary
  printf("Binary: ");

  for(int i = 31; i >= 0; i--) {
    printf("%d", (res >> i) & 1);
    if(i % 8 == 0) {
      printf(" ");
    }
  }

  printf("\n");
}

int main() {
  char hex[20];
  printf("Enter a hexadecimal number: ");
  scanf("%s", hex);

  // If input is not a hexadecimal number, exit program
  for(int i = 0; i < strlen(hex); i++) {
    if((hex[i] < '0' || hex[i] > '9') && (hex[i] < 'A' || hex[i] > 'F')) {
      printf("Invalid input!\n");
      return 0;
    }
  }

  chex_convert(hex);

  return 0;
}