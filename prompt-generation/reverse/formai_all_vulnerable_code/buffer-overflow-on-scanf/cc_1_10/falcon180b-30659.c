//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define HASH_LENGTH 32
#define HASH_CHAR_SET "0123456789abcdef"

typedef struct {
    char hash[HASH_LENGTH];
    int length;
} hash_t;

hash_t hash_file(char *filename) {
    FILE *file;
    hash_t result;
    char buffer[1024];
    int length = 0;

    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    result.length = 0;

    while (fgets(buffer, sizeof(buffer), file)!= NULL) {
        length += strlen(buffer);
        result.hash[result.length++] = buffer[0];
    }

    fclose(file);
    result.hash[result.length] = '\0';

    return result;
}

void hash_string(char *input, char *output) {
    hash_t hash;
    int i, j;

    hash = hash_file(input);

    for (i = 0, j = 0; i < HASH_LENGTH && j < strlen(hash.hash); i++, j++) {
        output[i] = hash.hash[j];
    }

    output[i] = '\0';
}

int main(int argc, char *argv[]) {
    char input[256];
    char output[HASH_LENGTH];

    printf("Enter a string to hash: ");
    scanf("%s", input);

    hash_string(input, output);

    printf("Hash: %s\n", output);

    return 0;
}