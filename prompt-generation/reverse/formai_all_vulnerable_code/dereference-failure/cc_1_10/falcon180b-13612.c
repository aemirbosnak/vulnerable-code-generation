//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), input_file)!= NULL) {
        char *color_code = strstr(line, "COLOR=");
        if (color_code!= NULL) {
            char *start = color_code + strlen("COLOR=");
            char *end = strchr(start, ',');
            *end = '\0';

            char hex_code[9];
            strcpy(hex_code, start);
            strcat(hex_code, "00");

            char red, green, blue;
            sscanf(hex_code, "#%02X%02X%02X", &red, &green, &blue);

            char rgb_code[10];
            sprintf(rgb_code, "RGB(%d,%d,%d)", red, green, blue);

            strcpy(color_code, rgb_code);
        }

        fprintf(output_file, "%s\n", line);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}