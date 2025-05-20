#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define TABLE_SIZE 256

void encrypt(char *input, char *output) {
    static char table[TABLE_SIZE];
    static int initialized = 0;

    if (!initialized) {
        for (int i = 0; i < TABLE_SIZE; ++i)
            table[i] = (char)(i + 'A' - 13);
        for (int i = 'a'; i <= 'z'; ++i)
            table[i] = (char)(i + 17);
        for (int i = '0'; i <= '9'; ++i)
            table[i] = (char)(i + 4);
        initialized = 1;
    }

    for (int i = 0; input[i]; ++i)
        output[i] = table[(int)input[i]];
}

int main(int argc, char *argv[]) {
    char input[1024], output[1024];

    if (argc != 2) {
        printf("Usage: %s <string to encrypt>\n", argv[0]);
        return 1;
    }

    strcpy(input, argv[1]);
    encrypt(input, output);
    printf("%s\n", output);

    return 0;
}
