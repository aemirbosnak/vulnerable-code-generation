//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

void morse_encode(char *input, char *output) {
    char *morse_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.- ";
    int i = 0, j = 0;

    while (input[i]!= '\0') {
        if (isalpha(input[i])) {
            output[j++] = toupper(input[i]);
        } else if (isdigit(input[i])) {
            output[j++] = '0' + (input[i] - '0');
        } else {
            output[j++] = '.';
        }

        i++;
    }

    output[j] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    char input_buffer[MAX_LENGTH];
    char *output_buffer = malloc(MAX_LENGTH * sizeof(char));

    while (fgets(input_buffer, MAX_LENGTH, input_file)!= NULL) {
        morse_encode(input_buffer, output_buffer);
        fprintf(stdout, "%s", output_buffer);
    }

    fclose(input_file);
    free(output_buffer);

    return 0;
}