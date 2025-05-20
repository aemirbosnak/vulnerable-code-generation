//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_LENGTH 32

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <encrypt/decrypt> <key>\n", argv[0]);
        return 1;
    }

    char *mode = argv[1];
    char *key = argv[2];

    if (strlen(key) > MAX_KEY_LENGTH) {
        printf("Error: Key length must be less than or equal to %d\n", MAX_KEY_LENGTH);
        return 1;
    }

    int key_int = 0;
    for (int i = 0; i < strlen(key); i++) {
        key_int += key[i];
    }

    srand(time(NULL) + key_int);

    char *input_file = "input.txt";
    char *output_file = "output.txt";

    FILE *input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error: Could not open input file\n");
        return 1;
    }

    FILE *output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error: Could not open output file\n");
        fclose(input);
        return 1;
    }

    int ch;
    while ((ch = fgetc(input))!= EOF) {
        if (mode[0] == 'e') {
            ch ^= key_int;
        } else if (mode[0] == 'd') {
            ch ^= (key_int * 2);
        }

        fprintf(output, "%c", ch);
    }

    fclose(input);
    fclose(output);

    printf("Encryption/Decryption complete!\n");

    return 0;
}