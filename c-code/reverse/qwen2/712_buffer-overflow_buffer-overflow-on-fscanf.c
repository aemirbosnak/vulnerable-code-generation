#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 256

void process_image(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char format[3];
    int width, height, maxval;
    fscanf(file, "%s %d %d %d", format, &width, &height, &maxval);
    fclose(file);

    // Simulate processing
    printf("Processing image: %s\n", filename);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter the PGM image filename: ");
    scanf("%255s", filename); // Limit input length to prevent buffer overflow

    int choice;
    printf("Choose an operation:\n1. Convert to grayscale\n2. Rotate 90 degrees clockwise\n3. Flip horizontally\n4. Invert colors\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            process_image(filename);
            break;
        case 2:
            process_image(filename);
            break;
        case 3:
            process_image(filename);
            break;
        case 4:
            process_image(filename);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}
