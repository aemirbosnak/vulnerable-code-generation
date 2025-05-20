//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 256
#define HEIGHT 256
#define MAX_VALUE 256
#define THRESHOLD 0.5

struct Pixel {
    int x, y;
    int value;
};

int main(int argc, char** argv) {
    if(argc!= 3) {
        printf("Usage: %s <input_image> <output_image>\n", argv[0]);
        return 1;
    }

    FILE* input_file = fopen(argv[1], "rb");
    if(input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE* output_file = fopen(argv[2], "wb");
    if(output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    int x, y;
    int value;
    while(fscanf(input_file, "%d %d %d", &x, &y, &value)!= EOF) {
        // Apply digital watermarking algorithm
        if(value > THRESHOLD * MAX_VALUE) {
            value -= (int)(THRESHOLD * MAX_VALUE / 2);
        } else {
            value += (int)(THRESHOLD * MAX_VALUE / 2);
        }
        fprintf(output_file, "%d %d %d\n", x, y, value);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}