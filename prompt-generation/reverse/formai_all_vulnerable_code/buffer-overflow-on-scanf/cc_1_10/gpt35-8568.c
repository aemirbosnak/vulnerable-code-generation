//FormAI DATASET v1.0 Category: Image Editor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_COMMAND_LENGTH 100

typedef struct {
    int width;
    int height;
    unsigned char* pixels;
} Image;

bool is_valid_image(Image* image);
void print_menu();
void print_image(Image* image);
int get_int_input(char* message);
void get_filename(char* filename);
Image* load_image(char* filename);
void save_image(char* filename, Image* image);
void free_image(Image* image);
Image* copy_image(Image* image);
void invert_colors(Image* image);
void flip_horizontally(Image* image);
void flip_vertically(Image* image);

int main() {
    char filename[MAX_FILENAME_LENGTH];
    Image* image = NULL;

    while (true) {
        print_menu();

        char command[MAX_COMMAND_LENGTH];
        scanf("%s", command);

        if (strcmp(command, "0") == 0) {
            break;
        }
        else if (strcmp(command, "1") == 0) {
            get_filename(filename);
            image = load_image(filename);
        }
        else if (strcmp(command, "2") == 0) {
            if (is_valid_image(image)) {
                get_filename(filename);
                save_image(filename, image);
            }
            else {
                printf("No image loaded.\n");
            }
        }
        else if (strcmp(command, "3") == 0) {
            if (is_valid_image(image)) {
                print_image(image);
            }
            else {
                printf("No image loaded.\n");
            }
        }
        else if (strcmp(command, "4") == 0) {
            if (is_valid_image(image)) {
                Image* copy = copy_image(image);
                invert_colors(copy);
                print_image(copy);
                free_image(copy);
            }
            else {
                printf("No image loaded.\n");
            }
        }
        else if (strcmp(command, "5") == 0) {
            if (is_valid_image(image)) {
                flip_horizontally(image);
                print_image(image);
            }
            else {
                printf("No image loaded.\n");
            }
        }
        else if (strcmp(command, "6") == 0) {
            if (is_valid_image(image)) {
                flip_vertically(image);
                print_image(image);
            }
            else {
                printf("No image loaded.\n");
            }
        }
        else {
            printf("Invalid command.\n");
        }
    }

    if (is_valid_image(image)) {
        free_image(image);
    }

    return 0;
}

bool is_valid_image(Image* image) {
    return (image != NULL);
}

void print_menu() {
    printf("0 - Quit\n");
    printf("1 - Load image\n");
    printf("2 - Save image\n");
    printf("3 - View image\n");
    printf("4 - Invert colors\n");
    printf("5 - Flip horizontally\n");
    printf("6 - Flip vertically\n");
}

void print_image(Image* image) {
    printf("Width: %d\n", image->width);
    printf("Height: %d\n", image->height);
    printf("Pixels:\n");

    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            printf("%d, ", image->pixels[i * image->width + j]);
        }
        printf("\n");
    }
}

int get_int_input(char* message) {
    int input;
    printf("%s", message);
    scanf("%d", &input);
    return input;
}

void get_filename(char* filename) {
    printf("Enter filename: ");
    scanf("%s", filename);
}

Image* load_image(char* filename) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Unable to open file.\n");
        return NULL;
    }

    // Read image dimensions
    int width, height;
    fscanf(file, "%d %d", &width, &height);

    // Allocate memory for image pixels
    unsigned char* pixels = (unsigned char*) malloc(width * height * sizeof(unsigned char));

    // Read image pixels
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel;
            fscanf(file, "%d", &pixel);
            pixels[i * width + j] = (unsigned char) pixel;
        }
    }

    // Close file
    fclose(file);

    // Create image structure
    Image* image = (Image*) malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = pixels;

    return image;
}

void save_image(char* filename, Image* image) {
    FILE* file = fopen(filename, "w");

    if (file == NULL) {
        printf("Unable to open file.\n");
        return;
    }

    // Write image dimensions
    fprintf(file, "%d %d\n", image->width, image->height);

    // Write image pixels
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            fprintf(file, "%d ", image->pixels[i * image->width + j]);
        }
        fprintf(file, "\n");
    }

    // Close file
    fclose(file);

    printf("Image saved as %s.\n", filename);
}

void free_image(Image* image) {
    free(image->pixels);
    free(image);
}

Image* copy_image(Image* image) {
    Image* copy = (Image*) malloc(sizeof(Image));
    copy->width = image->width;
    copy->height = image->height;
    copy->pixels = (unsigned char*) malloc(copy->width * copy->height * sizeof(unsigned char));
    memcpy(copy->pixels, image->pixels, copy->width * copy->height * sizeof(unsigned char));
    return copy;
}

void invert_colors(Image* image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            image->pixels[i * image->width + j] = 255 - image->pixels[i * image->width + j];
        }
    }
}

void flip_horizontally(Image* image) {
    unsigned char temp;
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width/2; j++) {
            temp = image->pixels[i * image->width + j];
            image->pixels[i * image->width + j] = image->pixels[i * image->width + (image->width - j - 1)];
            image->pixels[i * image->width + (image->width - j - 1)] = temp;
        }
    }
}

void flip_vertically(Image* image) {
    unsigned char temp;
    for (int i = 0; i < image->height/2; i++) {
        for (int j = 0; j < image->width; j++) {
            temp = image->pixels[i * image->width + j];
            image->pixels[i * image->width + j] = image->pixels[(image->height - i - 1) * image->width + j];
            image->pixels[(image->height - i - 1) * image->width + j] = temp;
        }
    }
}