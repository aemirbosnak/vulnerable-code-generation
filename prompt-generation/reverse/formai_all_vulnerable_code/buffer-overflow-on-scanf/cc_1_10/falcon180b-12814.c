//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define HASH_LEN 64

struct hash_data {
    char* input;
    char* output;
    int len;
};

void generate_hash(char* input, char* output, int len) {
    int i = 0;
    int j = 0;
    int hash_value = 0;
    int prime = 31;
    int temp = strlen(input);

    while (temp > 0) {
        hash_value += tolower(input[temp - 1]) * pow(prime, temp - 1);
        temp--;
    }

    i = 0;
    while (i < len) {
        j = hash_value % prime;
        output[i] = j + 'a';
        i++;
        hash_value /= prime;
    }
}

int main() {
    struct hash_data data;
    char input[100];
    char output[HASH_LEN];
    int len = 0;

    printf("Enter the input string: ");
    scanf("%s", input);

    len = strlen(input);

    data.input = input;
    data.output = output;
    data.len = len;

    generate_hash(data.input, data.output, data.len);

    printf("Input string: %s\n", data.input);
    printf("Hash value: %s\n", data.output);

    return 0;
}