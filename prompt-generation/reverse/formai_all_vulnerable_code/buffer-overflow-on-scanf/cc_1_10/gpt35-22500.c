//FormAI DATASET v1.0 Category: String manipulation ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Function to calculate the sum of digits in a numeric string */
int sum_of_digits(char *str) {
    int sum = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            sum += str[i] - '0';
        }
    }
    return sum;
}

/* Function to calculate the product of digits in a numeric string */
int product_of_digits(char *str) {
    int product = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            product *= str[i] - '0';
        }
    }
    return product;
}

/* Function to reverse a string */
void reverse_string(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main() {
    char input_string[100];
    int choice;
    printf("Enter a string: ");
    scanf("%s", input_string);
    printf("\nChoose an operation:\n");
    printf("1. Calculate the sum of digits in the string\n");
    printf("2. Calculate the product of digits in the string\n");
    printf("3. Reverse the string\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            int sum = sum_of_digits(input_string);
            printf("The sum of digits in the string is: %d\n", sum);
            break;
        }
        case 2: {
            int product = product_of_digits(input_string);
            printf("The product of digits in the string is: %d\n", product);
            break;
        }
        case 3: {
            reverse_string(input_string);
            printf("The reversed string is: %s\n", input_string);
            break;
        }
        case 4: {
            exit(0);
        }
        default: {
            printf("Invalid choice.\n");
            exit(1);
        }
    }
    return 0;
}