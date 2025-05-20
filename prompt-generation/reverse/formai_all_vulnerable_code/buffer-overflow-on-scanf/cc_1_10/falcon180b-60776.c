//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: Alan Turing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 1000

char *binary_to_decimal(char *binary) {
    int decimal = 0;
    int power = 0;
    char *decimal_str = malloc(MAX_SIZE * sizeof(char));
    char *ptr = decimal_str;

    while (*binary) {
        if (*binary == '1') {
            decimal += pow(2, power);
        }
        power++;
        binary++;
    }

    *ptr = '\0';
    sprintf(ptr, "%d", decimal);

    return decimal_str;
}

char *calculate_checksum(char *input) {
    int sum = 0;
    char *checksum_str = malloc(MAX_SIZE * sizeof(char));
    char *ptr = checksum_str;

    while (*input) {
        sum += *input;
        input++;
    }

    sum = (sum % 256) + 256;
    sum = (sum % 256);

    *ptr = '\0';
    sprintf(ptr, "%d", sum);

    return checksum_str;
}

int main() {
    char input[MAX_SIZE];
    char binary[MAX_SIZE];
    char decimal[MAX_SIZE];
    char checksum[MAX_SIZE];

    printf("Enter a string to calculate its checksum: ");
    scanf("%s", input);

    int i = 0;
    while (input[i]) {
        if (isalpha(input[i])) {
            input[i] = toupper(input[i]);
        }
        binary[i] = input[i] - 'A' + 1;
        i++;
    }

    char *decimal_str = binary_to_decimal(binary);
    char *checksum_str = calculate_checksum(binary);

    printf("Decimal representation: %s\n", decimal_str);
    printf("Checksum: %s\n", checksum_str);

    free(decimal_str);
    free(checksum_str);

    return 0;
}