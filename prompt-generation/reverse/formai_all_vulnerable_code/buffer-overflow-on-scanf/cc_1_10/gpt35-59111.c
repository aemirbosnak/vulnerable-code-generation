//FormAI DATASET v1.0 Category: Binary Converter ; Style: ultraprecise
#include <stdio.h>

void decimalToBinary(int num) {
   int binaryNum[32];
   int i = 0;
   while (num > 0) {
      binaryNum[i] = num % 2;
      num = num / 2;
      i++;
   }
   for (int j = i - 1; j >= 0; j--)
      printf("%d", binaryNum[j]);
}

int binaryToDecimal(long long n) {
   int decimalNumber = 0, i = 0, remainder;
   while (n != 0) {
      remainder = n % 10;
      n /= 10;
      decimalNumber += remainder * pow(2, i);
      ++i;
   }
   return decimalNumber;
}

int main() {
   int choice, num;
   long long binaryNum;

   do {
      printf("\nBinary Converter Menu:\n");
      printf("1. Decimal to Binary\n");
      printf("2. Binary to Decimal\n");
      printf("3. Exit\n");

      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice) {
         case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &num);
            printf("Binary Conversion: ");
            decimalToBinary(num);
            break;
         case 2:
            printf("Enter a binary number: ");
            scanf("%lld", &binaryNum);
            int decimalNum = binaryToDecimal(binaryNum);
            printf("Decimal Conversion: %d", decimalNum);
            break;
         case 3:
            printf("Exiting program...");
            break;
         default:
            printf("Invalid choice. Try again.\n");
      }
   } while (choice != 3);
   return 0;
}