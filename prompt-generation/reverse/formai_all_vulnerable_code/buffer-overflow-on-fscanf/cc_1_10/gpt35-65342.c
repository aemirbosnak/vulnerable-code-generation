//FormAI DATASET v1.0 Category: Image Editor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100 // Maximum length of file name
#define MAX_RGB_VALUE 255 // Maximum value of any RGB component
#define MAX_COMMAND_LENGTH 20 // Maximum length of a command

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

Pixel** create_image(int height, int width) {
    Pixel** image = malloc(height * sizeof(Pixel*));
    for (int i = 0; i < height; i++) {
        image[i] = malloc(width * sizeof(Pixel));
    }
    return image;
}

void free_image(Pixel** image, int height) {
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);
}

Pixel** read_image(char* filename, int* height, int* width) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Cannot open file %s\n", filename);
        return NULL;
    }

    char file_type[3];
    fscanf(file, "%s\n", file_type);
    if (strcmp(file_type, "P3") != 0) {
        printf("Error: Invalid file type!\n");
        fclose(file);
        return NULL;
    }

    fscanf(file, "%d %d\n", width, height);
    int max_value; // The maximum value of any RGB component should be MAX_RGB_VALUE
    fscanf(file, "%d\n", &max_value);

    Pixel** image = create_image(*height, *width);

    for (int i = 0; i < *height; i++) {
        for (int j = 0; j < *width; j++) {
            int red, green, blue;
            fscanf(file, "%d %d %d", &red, &green, &blue);
            image[i][j].red = (unsigned char)red;
            image[i][j].green = (unsigned char)green;
            image[i][j].blue = (unsigned char)blue;
        }
    }

    fclose(file);
    return image;
}

void write_image(char* filename, Pixel** image, int height, int width) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error: Cannot open file %s\n", filename);
        return;
    }

    fprintf(file, "P3\n");
    fprintf(file, "%d %d\n", width, height);
    fprintf(file, "%d\n", MAX_RGB_VALUE);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fprintf(file, "%d %d %d ", image[i][j].red, image[i][j].green, image[i][j].blue);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

Pixel** apply_greyscale(Pixel** image, int height, int width) {
    Pixel** new_image = create_image(height, width);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char grey = (unsigned char)((0.3 * image[i][j].red) + (0.59 * image[i][j].green) + (0.11 * image[i][j].blue));
            new_image[i][j].red = grey;
            new_image[i][j].green = grey;
            new_image[i][j].blue = grey;
        }
    }
    return new_image;
}

Pixel** apply_invert(Pixel** image, int height, int width) {
    Pixel** new_image = create_image(height, width);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            new_image[i][j].red = (unsigned char)(MAX_RGB_VALUE - image[i][j].red);
            new_image[i][j].green = (unsigned char)(MAX_RGB_VALUE - image[i][j].green);
            new_image[i][j].blue = (unsigned char)(MAX_RGB_VALUE - image[i][j].blue);
        }
    }
    return new_image;
}

Pixel** apply_flip_horizontal(Pixel** image, int height, int width) {
    Pixel** new_image = create_image(height, width);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            new_image[i][j] = image[i][width - j - 1];
        }
    }
    return new_image;
}

Pixel** apply_flip_vertical(Pixel** image, int height, int width) {
    Pixel** new_image = create_image(height, width);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            new_image[i][j] = image[height - i - 1][j];
        }
    }
    return new_image;
}

int main() {
    char filename[MAX_LEN];
    printf("Enter file name: ");
    scanf("%s", filename);

    int height, width;
    Pixel** image = read_image(filename, &height, &width);
    if (!image) {
        return 1;
    }

    char command[MAX_COMMAND_LENGTH];
    while (1) {
        printf("Enter command (greyscale, invert, flip horizontal, flip vertical, write, exit): ");
        scanf("%s", command);

        for (int i = 0; i < strlen(command); i++) {
            command[i] = tolower(command[i]);
        }

        if (strcmp(command, "greyscale") == 0) {
            image = apply_greyscale(image, height, width);
            printf("Applied greyscale filter\n");
        }
        else if (strcmp(command, "invert") == 0) {
            image = apply_invert(image, height, width);
            printf("Applied invert filter\n");
        }
        else if (strcmp(command, "flip") == 0) {
            printf("Flip horizontally or vertically (h/v)? ");
            char flip_direction;
            scanf(" %c", &flip_direction);
            if (flip_direction == 'h') {
                image = apply_flip_horizontal(image, height, width);
                printf("Applied flip horizontal filter\n");
            }
            else if (flip_direction == 'v') {
                image = apply_flip_vertical(image, height, width);
                printf("Applied flip vertical filter\n");
            }
            else {
                printf("Error: Invalid flip direction!\n");
            }
        }
        else if (strcmp(command, "write") == 0) {
            char new_filename[MAX_LEN];
            printf("Enter new file name: ");
            scanf("%s", new_filename);
            write_image(new_filename, image, height, width);
            printf("Wrote image to %s\n", new_filename);
        }
        else if (strcmp(command, "exit") == 0) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Error: Invalid command!\n");
        }
    }

    free_image(image, height);
    return 0;
}