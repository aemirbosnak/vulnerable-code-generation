//Falcon2-11B DATASET v1.0 Category: Antivirus scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error opening file '%s'\n", argv[1]);
        return 1;
    }

    int size = 0;
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);

    char buffer[size + 1];
    fread(buffer, 1, size, file);
    fclose(file);

    buffer[size] = 0; // null-terminate the buffer

    FILE *output = fopen("output.txt", "w");
    if (output == NULL) {
        printf("Error opening output file 'output.txt'\n");
        return 1;
    }

    char *scanner = malloc(size * sizeof(char));
    memset(scanner, 0, size * sizeof(char)); // initialize to zero

    int i = 0;
    for (i = 0; i < size; i++) {
        if (buffer[i] == '\n' || buffer[i] == '\r') {
            int start = i - 1;
            while (start >= 0 && (buffer[start]!= '\n' && buffer[start]!= '\r')) {
                start--;
            }
            int end = i + 1;
            while (end < size && (buffer[end]!= '\n' && buffer[end]!= '\r')) {
                end++;
            }
            if (start < 0 || end > size - 1) {
                printf("Error scanning buffer\n");
                free(scanner);
                fclose(output);
                return 1;
            }
            int start_index = start - 1;
            int end_index = end - 1;
            for (int j = start_index; j < end_index; j++) {
                scanner[j] = buffer[j];
            }
            for (int j = start_index; j < end_index; j++) {
                if (scanner[j] == '=' || scanner[j] == '!') {
                    scanner[j] = 0; // mark as non-malicious
                    break;
                }
                if (scanner[j] == '<' || scanner[j] == '>') {
                    scanner[j] = 0; // mark as non-malicious
                    break;
                }
            }
        }
    }

    fwrite(scanner, 1, size, output);
    fclose(output);
    free(scanner);

    return 0;
}