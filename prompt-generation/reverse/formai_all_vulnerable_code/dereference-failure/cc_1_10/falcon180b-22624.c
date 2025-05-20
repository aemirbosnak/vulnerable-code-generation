//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

struct pixel {
    char symbol;
    int color;
};

typedef struct pixel Pixel;

void print_pixel(Pixel p) {
    printf("%c", p.symbol);
}

int main() {
    FILE *input_file;
    char input_filename[100];
    char *input_text = NULL;
    size_t input_size = 0;
    int input_width, input_height;
    Pixel *input_pixels;

    printf("Enter the input filename: ");
    scanf("%s", input_filename);

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    fseek(input_file, 0, SEEK_END);
    input_size = ftell(input_file);
    rewind(input_file);

    input_text = malloc(input_size + 1);
    if (input_text == NULL) {
        printf("Error: Could not allocate memory for input text.\n");
        exit(1);
    }

    fread(input_text, input_size, 1, input_file);
    fclose(input_file);

    input_width = MAX_WIDTH;
    input_height = MAX_HEIGHT;

    input_pixels = malloc(input_width * input_height * sizeof(Pixel));
    if (input_pixels == NULL) {
        printf("Error: Could not allocate memory for input pixels.\n");
        exit(1);
    }

    int x = 0, y = 0, i = 0;
    for (int j = 0; j < input_size; j++) {
        if (input_text[j] == '\n') {
            x = 0;
            y++;
        } else {
            Pixel p;
            p.symbol = input_text[j];
            p.color = 0;

            if (x >= input_width) {
                y++;
                x = 0;
            }

            input_pixels[i++] = p;
            x++;
        }
    }

    free(input_text);

    for (int j = 0; j < input_height; j++) {
        for (int k = 0; k < input_width; k++) {
            print_pixel(input_pixels[j * input_width + k]);
        }
        printf("\n");
    }

    free(input_pixels);

    return 0;
}