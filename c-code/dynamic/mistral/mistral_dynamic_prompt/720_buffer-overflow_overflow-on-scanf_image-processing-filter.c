#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 2048

void process_image(char *filename, int filter_type) {
    FILE *file = fopen(filename, "r");
    char image_data[MAX_INPUT_SIZE];
    int data_size = fread(image_data, sizeof(char), MAX_INPUT_SIZE, file);

    if (file && data_size > 0) {
        printf("Processing image: %s\n", filename);

        // Vulnerable code starts here:
        scanf("%s", image_data + data_size);
        // Vulnerable code ends here

        // Rest of the code omitted for brevity to maintain the 50 lines limit.
    } else {
        printf("Error opening image file: %s\n", filename);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: filter_tool <image_file> <filter_type>\n");
        return 1;
    }

    process_image(argv[1], atoi(argv[2]));
    return 0;
}
