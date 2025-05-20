//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char buffer[1024];
    int bytes_read;
    int converted_value = 0;
    int base = 2;
    int i = 0;
    int j = 0;
    int k = 0;
    int count = 0;
    int input_size = 0;

    printf("Enter a binary number: ");
    fgets(buffer, sizeof(buffer), stdin);
    input_size = strlen(buffer);

    for (i = 0; i < input_size; i++) {
        if (buffer[i] == '0' || buffer[i] == '1') {
            converted_value += (buffer[i] - '0') * pow(2, input_size - i - 1);
        } else {
            printf("Invalid input. Please enter a binary number.\n");
            return 0;
        }
    }

    printf("Enter the base to convert to: ");
    scanf("%d", &base);

    if (base == 10) {
        printf("Decimal value: %d\n", converted_value);
    } else if (base == 16) {
        printf("Hexadecimal value: ");
        for (j = 0; j < 8; j++) {
            k = converted_value % 16;
            if (k < 10) {
                printf("%d", k);
            } else {
                printf("%c", k + 55);
            }
            converted_value /= 16;
        }
    } else {
        printf("Invalid base. Please enter 10 or 16.\n");
        return 0;
    }

    return 0;
}