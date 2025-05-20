//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/*
This is a simple hash function that takes in a string input and returns a unique hash value.
It uses a combination of addition, subtraction, multiplication and XOR bitwise operation to
generate a unique hash value.

To understand how this hash function works, let's consider the following steps:
1. It first takes in a string input and computes its length.
2. It initializes a hash variable to zero.
3. It loops through each character of the input string and performs the following operations:
    a. Adds the ASCII value of the current character to the hash variable.
    b. Subtracts the ASCII value of the previous character from the hash variable.
    c. Multiplies the hash variable by the current character.
    d. Performs a logical XOR bitwise operation between the hash variable and the ASCII value of the current character.
4. Finally, it takes the modulo of the hash variable with a large prime number to ensure it falls within a certain range.

This hash function generates a unique hash value, but it is not collision-resistant. That is, there is a possibility
for different inputs to generate the same hash value. Therefore, it is not recommended for security purposes.

*/

unsigned long simple_hash(const char* input) {
    int len = strlen(input);
    unsigned long hash = 0;

    for (int i = 0; i < len; i++) {
        hash += input[i];
        if (i > 0) {
            hash -= input[i - 1];
            hash *= input[i];
            hash ^= input[i];
        }
    }

    return (hash % 4294967291); // Large prime number
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%[^\n]", input);

    unsigned long hash_value = simple_hash(input);

    printf("The hash value of \"%s\" is %lu\n", input, hash_value);

    return 0;
}