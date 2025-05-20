//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"

void encrypt(char* input, char* output) {
    int i, j, k, n;
    char key[strlen(KEY)];
    strcpy(key, KEY);

    n = strlen(input);
    for (i = 0, j = 0; i < n; i++, j++) {
        if (j == strlen(key)) {
            j = 0;
        }
        output[i] = input[i] ^ key[j];
    }
    output[n] = '\0';
}

void decrypt(char* input, char* output) {
    int i, j, k, n;
    char key[strlen(KEY)];
    strcpy(key, KEY);

    n = strlen(input);
    for (i = 0, j = 0; i < n; i++, j++) {
        if (j == strlen(key)) {
            j = 0;
        }
        output[i] = input[i] ^ key[j];
    }
    output[n] = '\0';
}

int main() {
    FILE* input_file = fopen("input.txt", "r");
    FILE* output_file = fopen("output.txt", "w");
    char input[1024], output[1024];
    int input_size;

    if (input_file == NULL || output_file == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    while ((input_size = fread(input, sizeof(char), 1024, input_file)) > 0) {
        encrypt(input, output);
        fwrite(output, sizeof(char), strlen(output), output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully!\n");

    return 0;
}