//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: peaceful
#include <stdio.h>

int main() {
    // Define variables
    FILE *input_file, *output_file;
    char input_filename[20], output_filename[20];
    int width, height;
    unsigned char buffer[3];
 
    // Get input image filename from user
    printf("Enter input image filename: ");
    scanf("%s", input_filename);

    // Get desired width and height from user
    printf("Enter width: ");
    scanf("%d", &width);
    printf("Enter height: ");
    scanf("%d", &height);

    // Open input file in binary mode
    input_file = fopen(input_filename, "rb");

    // Check if file was opened successfully
    if (!input_file) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open output file in write mode
    sprintf(output_filename, "%s.txt", input_filename);
    output_file = fopen(output_filename, "w");

    // Check if file was opened successfully
    if (!output_file) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Write ASCII art header to output file
    fprintf(output_file, "/* ASCII art generated from %s */\n\n", input_filename);
    fprintf(output_file, "#include <stdio.h>\n");
    fprintf(output_file, "#define WIDTH %d\n", width);
    fprintf(output_file, "#define HEIGHT %d\n\n", height);
    fprintf(output_file, "int main() {\n");
    fprintf(output_file, "    unsigned char image[HEIGHT][WIDTH] = {\n");

    // Loop through each pixel in the input image
    for (int i = 0; i < height; i++) {
        fprintf(output_file, "        {");

        for (int j = 0; j < width; j++) {
            // Read next 3 bytes from file (RGB values)
            fread(buffer, sizeof(unsigned char), 3, input_file);

            // Convert RGB values to grayscale
            unsigned char gray = 0.2989 * buffer[0] + 0.5870 * buffer[1] + 0.1140 * buffer[2];

            // Map grayscale value to ASCII character
            char c = ' ';

            if (gray >= 0 && gray < 25) {
                c = '@';
            } else if (gray >= 25 && gray < 50) {
                c = '#';
            } else if (gray >= 50 && gray < 75) {
                c = '*';
            } else if (gray >= 75 && gray < 100) {
                c = '+';
            } else if (gray >= 100 && gray < 125) {
                c = '=';
            } else if (gray >= 125 && gray < 150) {
                c = '-';
            } else if (gray >= 150 && gray < 175) {
                c = ':';
            } else if (gray >= 175 && gray < 200) {
                c = '.';
            } else if (gray >= 200 && gray < 225) {
                c = ' ';
            } else if (gray >= 225 && gray <= 255) {
                c = ' ';
            }

            // Write ASCII character to output file
            fprintf(output_file, "%c", c);
        }

        fprintf(output_file, "}");

        // Write comma at the end of each row except the last one
        if (i < height - 1) {
            fprintf(output_file, ",");
        }

        fprintf(output_file, "\n");
     }

    // Write ASCII art footer to output file
    fprintf(output_file, "    };\n\n");
    fprintf(output_file, "    // Print ASCII art\n");
    fprintf(output_file, "    for (int i = 0; i < HEIGHT; i++) {\n");
    fprintf(output_file, "        for (int j = 0; j < WIDTH; j++) {\n");
    fprintf(output_file, "            printf(\"%c \", image[i][j]);\n");
    fprintf(output_file, "        }\n");
    fprintf(output_file, "        printf(\"\\n\");\n");
    fprintf(output_file, "    }\n");

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    // Print success message
    printf("ASCII art saved to %s\n", output_filename);

    return 0;
}