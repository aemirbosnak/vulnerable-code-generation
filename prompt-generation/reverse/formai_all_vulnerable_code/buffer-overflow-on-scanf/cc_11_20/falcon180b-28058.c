//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 1000

int main() {
    char input[MAX_SIZE];
    int i, j, k, len, count;
    char ch;

    printf("Enter a string: ");
    scanf("%s", input);
    len = strlen(input);

    // Count the number of words in the input string
    count = 0;
    for (i = 0; i < len; i++) {
        if (isspace(input[i])) {
            count++;
        }
    }

    // Reverse the input string
    for (i = 0, j = len - 1; i < j; i++, j--) {
        ch = input[i];
        input[i] = input[j];
        input[j] = ch;
    }

    // Convert the string to uppercase
    for (i = 0; i < len; i++) {
        input[i] = toupper(input[i]);
    }

    // Print the reversed and uppercased string
    printf("Reversed and uppercased string: %s\n", input);

    // Count the number of vowels in the input string
    count = 0;
    for (i = 0; i < len; i++) {
        if (input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U') {
            count++;
        }
    }

    // Print the number of vowels in the input string
    printf("Number of vowels: %d\n", count);

    return 0;
}