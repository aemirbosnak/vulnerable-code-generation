//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUM_LENGTH 33
#define BIN_NUM_LENGTH (MAX_NUM_LENGTH + 1)

void print_binary(int num) {
    char binary_num[BIN_NUM_LENGTH];
    int i = 0;

    while (num > 0) {
        binary_num[i++] = num % 2 + '0';
        num /= 2;
    }

    printf("%s\n", binary_num);
}

int main() {
    char input[MAX_NUM_LENGTH];
    int num;
    int choice;

    do {
        printf("Enter a decimal number (0 to exit): ");
        fgets(input, MAX_NUM_LENGTH, stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        num = atoi(input);

        if (num == 0) {
            break;
        }

        printf("Choose conversion type:\n");
        printf("1. Decimal to binary\n");
        printf("2. Binary to decimal\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_binary(num);
                break;
            case 2:
                printf("Enter a binary number: ");
                fgets(input, MAX_NUM_LENGTH, stdin);

                // Remove newline character from input
                input[strcspn(input, "\n")] = '\0';

                num = atoi(input);

                printf("Decimal equivalent: %d\n", num);
                break;
            case 3:
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (1);

    return 0;
}