//Falcon-180B DATASET v1.0 Category: Encryption ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    char input_buffer[1024];
    char output_buffer[1024];

    while (fgets(input_buffer, sizeof(input_buffer), input_file)!= NULL) {
        int input_buffer_len = strlen(input_buffer);
        int output_buffer_len = 0;

        for (int i = 0; i < input_buffer_len; i++) {
            char c = input_buffer[i];

            if (c >= 'a' && c <= 'z') {
                c -= 'a';
                c = (c + 13) % 26 + 'a';
            } else if (c >= 'A' && c <= 'Z') {
                c -= 'A';
                c = (c + 13) % 26 + 'A';
            }

            output_buffer[output_buffer_len++] = c;
        }

        output_buffer[output_buffer_len] = '\0';
        fputs(output_buffer, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Encryption successful!\n");

    return 0;
}