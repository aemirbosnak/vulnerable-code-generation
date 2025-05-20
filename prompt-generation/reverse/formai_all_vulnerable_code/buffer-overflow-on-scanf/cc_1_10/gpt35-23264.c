//FormAI DATASET v1.0 Category: Binary Converter ; Style: genious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void decimal_to_binary(int decimal_num, int binary_arr[]) {
    int i = 0;
    while (decimal_num > 0) {
        binary_arr[i] = decimal_num % 2;
        decimal_num = decimal_num / 2;
        i++;
    }
    binary_arr[i] = -1; // mark the end with -1
}

int binary_to_decimal(int binary_arr[]) {
    int decimal_num = 0;
    int i = 0;
    int bit = 1;
    while (binary_arr[i] != -1) {
        decimal_num += binary_arr[i] * bit;
        bit *= 2;
        i++;
    }
    return decimal_num;
}

void print_binary_arr(int binary_arr[]) {
   int i = 0;
   printf("Binary representation: ");
   while (binary_arr[i] != -1) {
      printf("%d", binary_arr[i]);
      i++;
   }
   printf("\n");
}

void print_decimal_num(int decimal_num) {
   printf("Decimal number: %d\n", decimal_num);
}

int main() {
   int decimal_num;
   int binary_arr[32]; // maximum 32 bits
   
   printf("Enter a decimal number to convert to binary: ");
   scanf("%d", &decimal_num);
   
   decimal_to_binary(decimal_num, binary_arr);
   print_binary_arr(binary_arr);
   
   printf("Enter a binary number to convert to decimal (as string): ");
   char binary_str[33]; // maximum 32 bits + 1 null character
   scanf("%s", binary_str);
   int len = strlen(binary_str);
   for (int i = 0; i < len; i++) {
      if (binary_str[i] == '0') {
         binary_arr[len-1-i] = 0;
      } else if (binary_str[i] == '1') {
         binary_arr[len-1-i] = 1;
      } else {
         printf("Invalid binary string\n");
         return 1;
      }
   }
   binary_arr[len] = -1;
   int decimal_num2 = binary_to_decimal(binary_arr);
   print_decimal_num(decimal_num2);
   
   return 0;
}