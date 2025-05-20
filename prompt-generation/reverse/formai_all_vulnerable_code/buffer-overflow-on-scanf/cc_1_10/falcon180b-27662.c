//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

void encrypt(char* input_file, char* output_file, int key) {
    FILE* input = fopen(input_file, "r");
    FILE* output = fopen(output_file, "w");

    if (input == NULL || output == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char buffer[MAX_SIZE];
    int buffer_index = 0;

    while (fgets(buffer + buffer_index, MAX_SIZE - buffer_index, input)!= NULL) {
        buffer_index += strlen(buffer + buffer_index);

        if (buffer_index >= MAX_SIZE) {
            fwrite(buffer, MAX_SIZE, 1, output);
            buffer_index = 0;
        }
    }

    if (buffer_index > 0) {
        fwrite(buffer, buffer_index, 1, output);
    }

    fclose(input);
    fclose(output);
}

void decrypt(char* input_file, char* output_file, int key) {
    FILE* input = fopen(input_file, "r");
    FILE* output = fopen(output_file, "w");

    if (input == NULL || output == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char buffer[MAX_SIZE];
    int buffer_index = 0;

    while (fgets(buffer + buffer_index, MAX_SIZE - buffer_index, input)!= NULL) {
        buffer_index += strlen(buffer + buffer_index);

        if (buffer_index >= MAX_SIZE) {
            for (int i = 0; i < buffer_index; i++) {
                char c = buffer[i];
                if (isalpha(c)) {
                    if (isupper(c)) {
                        c = (char) ((c - 65 + key) % 26 + 65);
                    } else {
                        c = (char) ((c - 97 + key) % 26 + 97);
                    }
                }

                fputc(c, output);
            }

            buffer_index = 0;
        }
    }

    if (buffer_index > 0) {
        for (int i = 0; i < buffer_index; i++) {
            char c = buffer[i];
            if (isalpha(c)) {
                if (isupper(c)) {
                    c = (char) ((c - 65 + key) % 26 + 65);
                } else {
                    c = (char) ((c - 97 + key) % 26 + 97);
                }
            }

            fputc(c, output);
        }
    }

    fclose(input);
    fclose(output);
}

int main() {
    srand(time(NULL));
    int key = rand() % 26;

    char input_file[100];
    char output_file[100];

    printf("Enter input file name: ");
    scanf("%s", input_file);

    printf("Enter output file name: ");
    scanf("%s", output_file);

    encrypt(input_file, "encrypted", key);
    decrypt("encrypted", output_file, key);

    return 0;
}