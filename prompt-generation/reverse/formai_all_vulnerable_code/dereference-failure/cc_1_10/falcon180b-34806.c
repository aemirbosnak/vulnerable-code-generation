//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1000

void encrypt(char *input_file, char *output_file) {
    FILE *in_file, *out_file;
    char input_buffer[SIZE], output_buffer[SIZE];
    int i, j, key;
    char *key_str = "mysecretkey";

    in_file = fopen(input_file, "rb");
    if (in_file == NULL) {
        printf("Error: Input file not found.\n");
        exit(1);
    }

    out_file = fopen(output_file, "wb");
    if (out_file == NULL) {
        printf("Error: Output file could not be created.\n");
        exit(1);
    }

    key = strlen(key_str);
    while (fgets(input_buffer, SIZE, in_file)!= NULL) {
        for (i = 0; i < strlen(input_buffer); i++) {
            if (isalpha(input_buffer[i])) {
                output_buffer[i] = input_buffer[i] + key;
                if (output_buffer[i] > 'z') {
                    output_buffer[i] = output_buffer[i] - 26;
                } else if (output_buffer[i] < 'a') {
                    output_buffer[i] = output_buffer[i] + 26;
                }
            } else {
                output_buffer[i] = input_buffer[i];
            }
        }
        fputs(output_buffer, out_file);
    }

    fclose(in_file);
    fclose(out_file);
}

int main() {
    char input_file[100], output_file[100];

    printf("Enter the name of the input file: ");
    scanf("%s", input_file);

    printf("Enter the name of the output file: ");
    scanf("%s", output_file);

    encrypt(input_file, output_file);

    printf("File encrypted successfully!\n");

    return 0;
}