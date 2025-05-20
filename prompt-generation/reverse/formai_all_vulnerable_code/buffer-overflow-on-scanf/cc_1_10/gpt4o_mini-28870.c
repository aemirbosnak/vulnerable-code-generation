//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image* load_image(const char *filename);
void save_image(const char *filename, Image *img);
void convert_to_grayscale(Image *img);
void free_image(Image *img);
void print_menu();
void process_choice(int choice, Image **img);

int main() {
    Image *img = NULL;
    int choice;

    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        process_choice(choice, &img);

        if (choice == 4) {
            break; // Exit the editor
        }
    }

    free_image(img);
    return 0;
}

Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file for reading");
        return NULL;
    }

    char format[3];
    fscanf(file, "%2s", format);
    if (strcmp(format, "P5") != 0) {
        fclose(file);
        fprintf(stderr, "Unsupported format. Please use a PGM (binary) file.\n");
        return NULL;
    }

    Image *img = (Image *)malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    int max_val;
    fscanf(file, "%d", &max_val);
    fgetc(file); // Read the newline character after max_val

    img->data = (unsigned char *)malloc(img->width * img->height);
    fread(img->data, 1, img->width * img->height, file);
    fclose(file);
    return img;
}

void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Could not open file for writing");
        return;
    }

    fprintf(file, "P5\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, 1, img->width * img->height, file);
    fclose(file);
}

void convert_to_grayscale(Image *img) {
    // Since PGM is already grayscale, this is just for demonstration.
    printf("Converting image to grayscale (image is already grayscale).\n");
}

void free_image(Image *img) {
    if (img) {
        free(img->data);
        free(img);
    }
}

void print_menu() {
    printf("\n--- Retro Image Editor ---\n");
    printf("1. Load Image\n");
    printf("2. Convert to Grayscale\n");
    printf("3. Save Image\n");
    printf("4. Exit\n");
}

void process_choice(int choice, Image **img) {
    char filename[256];

    switch (choice) {
        case 1:
            printf("Enter the filename to load: ");
            scanf("%s", filename);
            *img = load_image(filename);
            if (*img) {
                printf("Image loaded successfully!\n");
            }
            break;
        case 2:
            if (*img) {
                convert_to_grayscale(*img);
            } else {
                printf("No image loaded.\n");
            }
            break;
        case 3:
            if (*img) {
                printf("Enter the filename to save: ");
                scanf("%s", filename);
                save_image(filename, *img);
                printf("Image saved successfully!\n");
            } else {
                printf("No image loaded.\n");
            }
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice, please try again.\n");
    }
}