//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
    FILE *file;
    char input_file[50], output_file[50];

    printf("Enter the input image file name: ");
    scanf("%s", input_file);

    printf("Enter the output file name: ");
    scanf("%s", output_file);

    file = fopen(input_file, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    int width, height;
    fscanf(file, "%*s %d %d %*s", &width, &height);
    int pixel_count = width * height;
    unsigned char pixel_data[pixel_count];

    for (int i = 0; i < pixel_count; i++) {
        fread(&pixel_data[i], 1, 1, file);
    }

    fclose(file);

    file = fopen(output_file, "w");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    char ascii_chars[10] = {'.', ',', ':', '+', '*', '?', '$', '#', '@', ' '};

    for (int i = 0; i < pixel_count; i++) {
        int pixel_sum = (int) pixel_data[i] + (int) pixel_data[i+1] + (int) pixel_data[i+2];
        int ascii_index = pixel_sum / 25;
        fprintf(file, "%c", ascii_chars[ascii_index]);
        i += 2;
        if (i % width == 0) {
            fprintf(file, "\n");
        }
    }

    fclose(file);

    printf("Conversion complete.\n");
    return 0;
}