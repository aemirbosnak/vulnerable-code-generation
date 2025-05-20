//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1000

// Function to convert input string to uppercase
void str_to_upper(char *str) {
    int i = 0;
    while (str[i]!= '\0') {
        str[i] = toupper(str[i]);
        i++;
    }
}

// Function to calculate hash value
unsigned long long hash(char *input) {
    unsigned long long hash_value = 0;
    int i = 0;
    while (input[i]!= '\0') {
        hash_value += (unsigned long long)input[i];
        i++;
    }
    return hash_value;
}

// Function to print hash value
void print_hash(unsigned long long hash_value) {
    char hash_str[17];
    sprintf(hash_str, "%llX", hash_value);
    printf("Hash value: %s\n", hash_str);
}

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter input string: ");
    scanf("%s", input);

    // Convert input string to uppercase
    str_to_upper(input);

    // Calculate hash value
    unsigned long long hash_value = hash(input);

    // Print hash value
    print_hash(hash_value);

    return 0;
}