//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25
#define CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-. :;!@#$%^&*()_-=+[{]}\\|;:'\",<.>/?`~"

int main(int argc, char *argv[]) {
    FILE *in_file, *out_file;
    char input_name[100], output_name[100];
    int i, j, k, x, y, value;
    unsigned char buffer[3];
    unsigned char *data;
    unsigned int size;

    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    strncpy(input_name, argv[1], sizeof(input_name));
    strncpy(output_name, argv[2], sizeof(output_name));

    in_file = fopen(input_name, "rb");
    if (in_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    fseek(in_file, 0, SEEK_END);
    size = ftell(in_file);
    fseek(in_file, 0, SEEK_SET);

    data = (unsigned char *) malloc(size);
    if (data == NULL) {
        printf("Error: Could not allocate memory.\n");
        fclose(in_file);
        return 1;
    }

    fread(data, 1, size, in_file);
    fclose(in_file);

    out_file = fopen(output_name, "w");
    if (out_file == NULL) {
        printf("Error: Could not open output file.\n");
        free(data);
        return 1;
    }

    for (i = 0; i < size; i += 3) {
        value = data[i] + data[i + 1] * 256 + data[i + 2] * 256 * 256;
        x = value % WIDTH;
        y = value / WIDTH;

        if (x >= WIDTH || y >= HEIGHT) {
            printf("Error: Image dimensions are too large.\n");
            fclose(out_file);
            free(data);
            return 1;
        }

        buffer[0] = CHARS[value % 63];
        buffer[1] = CHARS[(value / 63) % 63];
        buffer[2] = '\0';

        fprintf(out_file, "%s", buffer);
    }

    fclose(out_file);
    free(data);

    printf("Done.\n");

    return 0;
}