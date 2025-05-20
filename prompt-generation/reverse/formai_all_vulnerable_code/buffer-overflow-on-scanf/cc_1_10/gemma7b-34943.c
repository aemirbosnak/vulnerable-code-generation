//Gemma-7B DATASET v1.0 Category: Checksum Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int num1, num2, num3;
  char str1[100], str2[100], str3[100];

  printf("Welcome to the Cosmic Checksum Calculator!\n");
  printf("Please enter the first number: ");
  scanf("%d", &num1);

  printf("Please enter the second number: ");
  scanf("%d", &num2);

  printf("Please enter the third number: ");
  scanf("%d", &num3);

  printf("Please enter the first string: ");
  scanf("%s", str1);

  printf("Please enter the second string: ");
  scanf("%s", str2);

  printf("Please enter the third string: ");
  scanf("%s", str3);

  int checksum1 = checksum(num1);
  int checksum2 = checksum(num2);
  int checksum3 = checksum(num3);
  int checksumStr1 = checksumStr(str1);
  int checksumStr2 = checksumStr(str2);
  int checksumStr3 = checksumStr(str3);

  int totalChecksum = checksum1 + checksum2 + checksum3 + checksumStr1 + checksumStr2 + checksumStr3;

  printf("The total checksum is: %d\n", totalChecksum);

  return 0;
}

int checksum(int num)
{
  int sum = 0;
  while (num)
  {
    int digit = num % 10;
    sum += digit;
    num /= 10;
  }
  return sum;
}

int checksumStr(char *str)
{
  int sum = 0;
  while (*str)
  {
    int digit = *str - '0';
    sum += digit;
    str++;
  }
  return sum;
}