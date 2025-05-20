//FormAI DATASET v1.0 Category: Image Editor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct pixel {
    int r, g, b;
};

struct image {
    int width, height;
    struct pixel** pixels;
};

// function prototypes
void print_menu();
struct image* create_image(int width, int height);
void destroy_image(struct image* img);
void print_image(struct image* img);

int main() {
    int choice, width, height;
    struct image* img = NULL;

    printf("Welcome to the C Image Editor!\n");

    while (1) {
        print_menu();
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (img) {
                    printf("Image already exists. Please delete the current image before creating a new one.\n");
                    break;
                }
                printf("Enter width of image: ");
                scanf("%d", &width);
                if (width <= 0) {
                    printf("Width must be a positive integer.\n");
                    break;
                }
                printf("Enter height of image: ");
                scanf("%d", &height);
                if (height <= 0) {
                    printf("Height must be a positive integer.\n");
                    break;
                }
                img = create_image(width, height);
                printf("Image created.\n");
                break;
            case 2:
                if (!img) {
                    printf("No image exists. Please create an image first.\n");
                    break;
                }
                print_image(img);
                break;
            case 3:
                if (!img) {
                    printf("No image exists. Please create an image first.\n");
                    break;
                }
                destroy_image(img);
                img = NULL;
                printf("Image deleted.\n");
                break;
            case 4:
                if (!img) {
                    printf("No image exists. Please create an image first.\n");
                    break;
                }
                printf("Enter x coordinate of pixel to edit: ");
                int x;
                scanf("%d", &x);
                if (x < 0 || x >= img->width) {
                    printf("Invalid x coordinate.\n");
                    break;
                }
                printf("Enter y coordinate of pixel to edit: ");
                int y;
                scanf("%d", &y);
                if (y < 0 || y >= img->height) {
                    printf("Invalid y coordinate.\n");
                    break;
                }
                printf("Enter new red value (0-255): ");
                int r;
                scanf("%d", &r);
                if (r < 0 || r > 255) {
                    printf("Invalid red value.\n");
                    break;
                }
                printf("Enter new green value (0-255): ");
                int g;
                scanf("%d", &g);
                if (g < 0 || g > 255) {
                    printf("Invalid green value.\n");
                    break;
                }
                printf("Enter new blue value (0-255): ");
                int b;
                scanf("%d", &b);
                if (b < 0 || b > 255) {
                    printf("Invalid blue value.\n");
                    break;
                }
                img->pixels[y][x].r = r;
                img->pixels[y][x].g = g;
                img->pixels[y][x].b = b;
                printf("Pixel edited.\n");
                break;
            case 5:
                if (!img) {
                    printf("No image exists. Please create an image first.\n");
                    break;
                }
                printf("Enter filename to save image: ");
                char filename[50];
                scanf("%s", filename);
                FILE* fp;
                fp = fopen(filename, "w");
                if (!fp) {
                    printf("Error opening file.\n");
                    break;
                }
                fprintf(fp, "P3\n%d %d\n255\n", img->width, img->height);
                for (int i = 0; i < img->height; i++) {
                    for (int j = 0; j < img->width; j++) {
                        fprintf(fp, "%d %d %d ", img->pixels[i][j].r, img->pixels[i][j].g, img->pixels[i][j].b);
                    }
                    fprintf(fp, "\n");
                }
                fclose(fp);
                printf("Image saved as %s.\n", filename);
                break;
            case 6:
                printf("Exiting C Image Editor.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}

void print_menu() {
    printf("1. Create a new image\n");
    printf("2. Print current image\n");
    printf("3. Delete current image\n");
    printf("4. Edit a pixel in current image\n");
    printf("5. Save current image to file\n");
    printf("6. Exit\n");
}

struct image* create_image(int width, int height) {
    struct image* img = (struct image*)malloc(sizeof(struct image));
    img->width = width;
    img->height = height;
    img->pixels = (struct pixel**)malloc(height * sizeof(struct pixel*));
    for (int i = 0; i < height; i++) {
        img->pixels[i] = (struct pixel*)malloc(width * sizeof(struct pixel));
        for (int j = 0; j < width; j++) {
            img->pixels[i][j] = (struct pixel){0, 0, 0};
        }
    }
    return img;
}

void destroy_image(struct image* img) {
    for (int i = 0; i < img->height; i++) {
        free(img->pixels[i]);
    }
    free(img->pixels);
    free(img);
}

void print_image(struct image* img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            printf("(%d, %d, %d) ", img->pixels[i][j].r, img->pixels[i][j].g, img->pixels[i][j].b);
        }
        printf("\n");
    }
}