//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: protected
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 10

void print_menu();
void convert_to_hexadecimal(char *input);
void convert_to_decimal(char *input);
void convert_to_binary(char *input);

int main() {
    char input[MAX_INPUT_LENGTH];
    int choice;
    do {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%s", input);
                convert_to_hexadecimal(input);
                break;
            case 2:
                printf("Enter a hexadecimal number: ");
                scanf("%s", input);
                convert_to_decimal(input);
                break;
            case 3:
                printf("Enter a decimal number: ");
                scanf("%s", input);
                convert_to_binary(input);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    } while (choice != 4);

    return 0;
}

void print_menu() {
    printf("Please select an option:\n\n");
    printf("1. Convert decimal to hexadecimal\n");
    printf("2. Convert hexadecimal to decimal\n");
    printf("3. Convert decimal to binary\n");
    printf("4. Exit program\n\n");
    printf("Enter your choice: ");
}

void convert_to_hexadecimal(char *input) {
    int decimal_num = atoi(input);
    char hexadecimal_num[MAX_INPUT_LENGTH];
    int index = 0;

    while (decimal_num != 0) {
        int remainder = decimal_num % 16;
        if (remainder < 10) {
            hexadecimal_num[index++] = remainder + 48;
        } else {
            hexadecimal_num[index++] = remainder + 55;
        }
        decimal_num /= 16;
    }

    printf("The hexadecimal equivalent is: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hexadecimal_num[i]);
    }
    printf("\n\n");
}

void convert_to_decimal(char *input) {
    int decimal_num = 0;
    int length = strlen(input);
    int base = 1;

    for (int i = length - 1; i >= 0; i--) {
        if (input[i] >= '0' && input[i] <= '9') {
            decimal_num += (input[i] - 48) * base;
            base *= 16;
        } else if (input[i] >= 'A' && input[i] <= 'F') {
            decimal_num += (input[i] - 55) * base;
            base *= 16;
        } else if (input[i] >= 'a' && input[i] <= 'f') {
            decimal_num += (input[i] - 87) * base;
            base *= 16;
        }
    }

    printf("The decimal equivalent is: %d\n\n", decimal_num);
}

void convert_to_binary(char *input) {
    int decimal_num = atoi(input);
    int binary_num[MAX_INPUT_LENGTH];
    int index = 0;

    while (decimal_num != 0) {
        binary_num[index++] = decimal_num % 2;
        decimal_num /= 2;
    }

    printf("The binary equivalent is: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary_num[i]);
    }
    printf("\n\n");
}