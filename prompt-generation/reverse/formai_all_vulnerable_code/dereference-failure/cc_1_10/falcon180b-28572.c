//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_COLOR_NAMES 100

typedef struct {
    char *name;
    int red;
    int green;
    int blue;
} Color;

int main(int argc, char *argv[]) {
    FILE *input_file;
    char line[MAX_LINE_LENGTH];
    Color *colors = NULL;
    int num_colors = 0;
    char output_filename[MAX_LINE_LENGTH];

    // Check for correct usage
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    // Open input file
    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: could not open input file '%s'.\n", argv[1]);
        return 1;
    }

    // Read color names and values from input file
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        char *name = strtok(line, " \t\n\r\f");
        int red = atoi(strtok(NULL, " \t\n\r\f"));
        int green = atoi(strtok(NULL, " \t\n\r\f"));
        int blue = atoi(strtok(NULL, " \t\n\r\f"));

        // Add color to array
        colors = realloc(colors, sizeof(Color) * ++num_colors);
        colors[num_colors - 1].name = strdup(name);
        colors[num_colors - 1].red = red;
        colors[num_colors - 1].green = green;
        colors[num_colors - 1].blue = blue;
    }

    // Close input file
    fclose(input_file);

    // Create output filename
    strcpy(output_filename, argv[2]);
    strcat(output_filename, ".h");

    // Open output file
    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error: could not open output file '%s'.\n", output_filename);
        return 1;
    }

    // Write header guard
    fprintf(output_file, "#ifndef %s_H\n#define %s_H\n\n", argv[2], argv[2]);

    // Write color definitions
    fprintf(output_file, "typedef enum {\n");
    for (int i = 0; i < num_colors; i++) {
        fprintf(output_file, "    %s = %d,\n", colors[i].name, i);
    }
    fprintf(output_file, "} Color;\n\n");

    // Write color array
    fprintf(output_file, "extern Color colors[%d];\n", num_colors);

    // Write footer
    fprintf(output_file, "#endif // %s_H\n", argv[2]);

    // Close output file
    fclose(output_file);

    return 0;
}