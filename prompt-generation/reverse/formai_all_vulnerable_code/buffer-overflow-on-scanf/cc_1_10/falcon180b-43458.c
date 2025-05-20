//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int is_binary(char *str) {
    int i = 0;
    while (str[i]) {
        if (!isdigit(str[i]) && str[i]!= '0' && str[i]!= '1') {
            return 0;
        }
        i++;
    }
    return 1;
}

int main() {
    char binary_str[MAX_LENGTH];
    char decimal_str[MAX_LENGTH];
    int choice = 0, i = 0;

    printf("Welcome to the Binary Converter\n");
    printf("1. Convert Binary to Decimal\n");
    printf("2. Convert Decimal to Binary\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the binary number: ");
            scanf("%s", binary_str);
            if (!is_binary(binary_str)) {
                printf("Invalid binary number\n");
                exit(0);
            }
            printf("The decimal equivalent is: %d\n", atoi(binary_str));
            break;
        case 2:
            printf("Enter the decimal number: ");
            scanf("%s", decimal_str);
            for (i = strlen(decimal_str) - 1; i >= 0; i--) {
                printf("%d", decimal_str[i] - '0');
            }
            printf("\n");
            break;
        default:
            printf("Invalid choice\n");
            exit(0);
    }

    return 0;
}