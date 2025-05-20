//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: active
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LENGTH 1024
#define BINARY_CHAR '0'
#define HEX_CHAR 'A'
#define OCT_CHAR '0'

int main() {
    // initialize variables
    char binary[MAX_LENGTH];
    char hex[MAX_LENGTH];
    char oct[MAX_LENGTH];
    uint32_t number;

    // get the input from the user
    printf("Enter a number (0-255): ");
    scanf("%u", &number);

    // convert the number to binary
    sprintf(binary, "%08u", number);
    printf("Binary: %s\n", binary);

    // convert the number to hex
    sprintf(hex, "%04x", number);
    printf("Hex: %s\n", hex);

    // convert the number to oct
    sprintf(oct, "%03o", number);
    printf("Oct: %s\n", oct);

    // create a random number and convert it to binary, hex, and oct
    uint32_t random = rand() % 256;
    sprintf(binary, "%08u", random);
    sprintf(hex, "%04x", random);
    sprintf(oct, "%03o", random);

    // display the results
    printf("Binary: %s\n", binary);
    printf("Hex: %s\n", hex);
    printf("Oct: %s\n", oct);

    // ask the user for input and repeat the process
    printf("Would you like to convert another number? (y/n): ");
    char input;
    scanf(" %c", &input);
    if (input == 'y') {
        // repeat the process
        getchar(); // discard the newline character
        getchar(); // discard the newline character
        printf("Enter a number (0-255): ");
        scanf("%u", &number);
        sprintf(binary, "%08u", number);
        sprintf(hex, "%04x", number);
        sprintf(oct, "%03o", number);
        printf("Binary: %s\n", binary);
        printf("Hex: %s\n", hex);
        printf("Oct: %s\n", oct);
    }

    return 0;
}