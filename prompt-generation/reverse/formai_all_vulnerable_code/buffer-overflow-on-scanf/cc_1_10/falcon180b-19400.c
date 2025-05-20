//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_LENGTH 100

int main() {
    char num[MAX_NUM_LENGTH];
    char binary[MAX_NUM_LENGTH];
    int i = 0, j = 0;
    int num_length = 0, binary_length = 0;

    // Get the decimal number from the user
    printf("Enter a decimal number: ");
    scanf("%s", num);

    // Check if the input is valid
    if (strlen(num) == 0) {
        printf("Invalid input.\n");
        return 1;
    }

    // Convert the decimal number to binary
    while (num[i]!= '\0') {
        if (num[i] >= '0' && num[i] <= '9') {
            num_length++;
        } else {
            printf("Invalid input.\n");
            return 1;
        }
        i++;
    }

    // Initialize the binary number string with leading zeros
    for (j = 0; j < MAX_NUM_LENGTH - num_length; j++) {
        binary[j] = '0';
    }

    // Convert the decimal number to binary
    i = 0;
    while (num[i]!= '\0') {
        if (num[i] == '0') {
            binary[j] = '0';
        } else if (num[i] == '1') {
            binary[j] = '1';
        } else {
            printf("Invalid input.\n");
            return 1;
        }
        i++;
        j++;
    }

    printf("Binary: %s\n", binary);

    return 0;
}