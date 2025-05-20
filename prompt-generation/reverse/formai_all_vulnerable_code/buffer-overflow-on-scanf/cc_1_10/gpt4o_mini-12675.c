//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        return NULL;
    }

    char format[3];
    fscanf(file, "%s", format);
    if (strcmp(format, "P5") != 0) {
        fprintf(stderr, "Unsupported image format: %s\n", format);
        fclose(file);
        return NULL;
    }
    
    Image *image = (Image *)malloc(sizeof(Image));
    fscanf(file, "%d %d", &image->width, &image->height);
    int max_val;
    fscanf(file, "%d", &max_val);
    fgetc(file); // Eat the newline character

    image->data = (unsigned char *)malloc(image->width * image->height);
    fread(image->data, 1, image->width * image->height, file);
    fclose(file);
    return image;
}

void save_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Could not open file for writing");
        return;
    }

    fprintf(file, "P5\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, 1, image->width * image->height, file);
    fclose(file);
}

void adjust_brightness(Image *image, int adjustment) {
    for (int i = 0; i < image->width * image->height; i++) {
        int new_value = image->data[i] + adjustment;
        if (new_value > 255) new_value = 255;
        if (new_value < 0) new_value = 0;
        image->data[i] = (unsigned char)new_value;
    }
}

void invert_colors(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i] = 255 - image->data[i];
    }
}

void free_image(Image *image) {
    if (image) {
        free(image->data);
        free(image);
    }
}

void print_menu() {
    printf("\nSimple Image Editor\n");
    printf("1. Increase Brightness\n");
    printf("2. Decrease Brightness\n");
    printf("3. Invert Colors\n");
    printf("4. Save Image\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char input_filename[100], output_filename[100];
    printf("Enter the input PGM file name: ");
    scanf("%s", input_filename);
    
    Image *image = load_image(input_filename);
    if (!image) {
        return EXIT_FAILURE;
    }

    int choice, adjustment;
    while (1) {
        print_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter brightness adjustment (positive): ");
                scanf("%d", &adjustment);
                adjust_brightness(image, adjustment);
                printf("Brightness increased.\n");
                break;
            case 2:
                printf("Enter brightness adjustment (negative): ");
                scanf("%d", &adjustment);
                adjust_brightness(image, -adjustment);
                printf("Brightness decreased.\n");
                break;
            case 3:
                invert_colors(image);
                printf("Colors inverted.\n");
                break;
            case 4:
                printf("Enter the output PGM file name: ");
                scanf("%s", output_filename);
                save_image(output_filename, image);
                printf("Image saved as %s.\n", output_filename);
                break;
            case 5:
                free_image(image);
                printf("Exiting...\n");
                return EXIT_SUCCESS;
            default:
                printf("Invalid option, try again.\n");
        }
    }
}