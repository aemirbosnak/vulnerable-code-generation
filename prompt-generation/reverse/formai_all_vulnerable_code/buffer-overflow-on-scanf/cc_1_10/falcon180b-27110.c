//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
#define CHECKSUM_LENGTH 4

int main() {
    char input[MAX_LENGTH];
    char checksum[CHECKSUM_LENGTH];
    int length;
    int i, j;
    int sum = 0;

    // Prompt user for input
    printf("Enter input string: ");
    scanf("%s", input);

    // Calculate length of input string
    length = strlen(input);

    // Initialize checksum array
    for (i = 0; i < CHECKSUM_LENGTH; i++) {
        checksum[i] = 0;
    }

    // Calculate checksum
    for (i = 0; i < length; i++) {
        sum += input[i];
    }

    // Convert sum to hexadecimal
    for (i = 0; i < CHECKSUM_LENGTH; i++) {
        j = sum % 16;
        if (j < 10) {
            checksum[i] = j + '0';
        } else {
            checksum[i] = j - 10 + 'A';
        }
        sum /= 16;
    }

    // Print checksum
    printf("Checksum: ");
    for (i = 0; i < CHECKSUM_LENGTH; i++) {
        printf("%c", checksum[i]);
    }
    printf("\n");

    return 0;
}