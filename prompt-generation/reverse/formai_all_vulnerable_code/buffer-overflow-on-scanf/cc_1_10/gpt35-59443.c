//FormAI DATASET v1.0 Category: Binary Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayMenu();
void binaryToDecimal();
void decimalToBinary();
int reverse(int num);

int main() {
  displayMenu();

  return 0;
}

void displayMenu() {
	int response;

	printf("Choose an option:\n");
	printf("-------------------\n");
	printf("1. Convert binary to decimal\n");
	printf("2. Convert decimal to binary\n");
	printf("3. Exit program\n");

	printf("Selection: ");
	scanf("%d", &response);

	switch(response) {
    case 1:
      binaryToDecimal();
      break;
    case 2:
      decimalToBinary();
      break;
    case 3:
      printf("Exiting program...\n");
      exit(0);
    default:
      printf("Invalid selection. Please try again.\n");
      displayMenu();
  }
}

void binaryToDecimal() {
	char binary[20];
	int decimal = 0;

	printf("Enter binary number to convert: ");
	scanf("%s", binary);

	for (int i = 0; i < strlen(binary); ++i) {
		if (binary[i] == '1') {
			decimal += pow(2, strlen(binary) - i - 1);
		} else if (binary[i] != '0') {
			printf("Invalid binary number.\n");
			binaryToDecimal();
			return;
		}
	}

	printf("Decimal: %d\n", decimal);

	displayMenu();
}

void decimalToBinary() {
	int decimal;
	int binary[20];
	int index = 0;

	printf("Enter decimal number to convert: ");
	scanf("%d", &decimal);

	while (decimal != 0) {
		binary[index++] = decimal % 2;
		decimal /= 2;
	}

	printf("Binary: ");
	for (int i = index - 1; i >= 0; --i) {
		printf("%d", binary[i]);
	}
	printf("\n");

	displayMenu();
}

int reverse(int num) {
	int reversedNum = 0;

	while (num != 0) {
		reversedNum = reversedNum * 10 + num % 10;
		num /= 10;
	}

	return reversedNum;
}