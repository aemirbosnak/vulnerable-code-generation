//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

int main(int argc, char *argv[]) {
    FILE *in_file, *out_file;
    char input_buffer[MAX_LINE_LENGTH];
    char output_buffer[MAX_LINE_LENGTH];
    int key = 0;
    int i, j, k;

    if (argc!= 4) {
        printf("Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return 1;
    }

    in_file = fopen(argv[1], "r");
    if (in_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    out_file = fopen(argv[2], "w");
    if (out_file == NULL) {
        printf("Error opening output file.\n");
        fclose(in_file);
        return 1;
    }

    key = atoi(argv[3]);

    while (fgets(input_buffer, MAX_LINE_LENGTH, in_file)!= NULL) {
        for (i = 0, j = 0; input_buffer[i]!= '\0'; i++) {
            if (isalpha(input_buffer[i])) {
                output_buffer[j++] = (char) ((input_buffer[i] - 'a' + key) % 26 + 'a');
            } else {
                output_buffer[j++] = input_buffer[i];
            }
        }
        output_buffer[j] = '\0';
        fputs(output_buffer, out_file);
    }

    fclose(in_file);
    fclose(out_file);

    return 0;
}