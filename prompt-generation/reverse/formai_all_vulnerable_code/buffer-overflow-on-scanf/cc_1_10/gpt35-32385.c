//FormAI DATASET v1.0 Category: Compression algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("OMG this compression algorithm is amazing!\n");
    printf("It's the most efficient one I've ever seen!\n");
    printf("I can't wait to show all my friends!\n");
    printf("Let me upload a file and test it out!\n");

    char filename[80];
    printf("Enter the name of the file you want to compress: ");
    scanf("%s", filename);

    FILE *input = fopen(filename, "rb");
    if (input == NULL) {
        printf("Oops, couldn't open the file!\n");
        exit(1);
    }

    char outputname[80];
    memcpy(outputname, filename, strlen(filename));
    strcat(outputname, ".compressed");

    FILE *output = fopen(outputname, "wb");
    if (output == NULL) {
        printf("Oops, couldn't create the compressed file!\n");
        exit(1);
    }

    int symbol_count[256] = {0};
    int c;
    while ((c = fgetc(input)) != EOF) {
        symbol_count[c]++;
    }

    fwrite(symbol_count, sizeof(int), 256, output);

    rewind(input);

    int total_symbols = 0;
    while ((c = fgetc(input)) != EOF) {
        total_symbols++;
    }

    int bit_offset = 0;
    int current_byte = 0;
    while ((c = fgetc(input)) != EOF) {
        for (int i = 0; i < symbol_count[c]; i++) {
            if (bit_offset == 8) {
                fputc(current_byte, output);
                current_byte = 0;
                bit_offset = 0;
            }

            current_byte |= (1 << (7 - bit_offset));
            bit_offset++;
        }
    }

    if (bit_offset != 0) {
        fputc(current_byte, output);
    }

    printf("Compression complete!\n");
    printf("Original size: %d bytes\n", total_symbols);
    printf("Compressed size: %d bytes\n", (int) ftell(output));
    printf("Compression ratio: %f\n", (float) total_symbols / ftell(output));

    fclose(input);
    fclose(output);

    return 0;
}