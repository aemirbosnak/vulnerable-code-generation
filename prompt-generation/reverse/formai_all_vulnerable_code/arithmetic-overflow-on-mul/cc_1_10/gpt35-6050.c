//FormAI DATASET v1.0 Category: Image Editor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
   int r;
   int g;
   int b;
} Pixel;

typedef struct {
   int width;
   int height;
   Pixel *data;
} Image;

void print_menu() {
    printf("\n\n");
    printf("Please enter the number of the operation you want to perform:\n");
    printf("1. Read image from file.\n");
    printf("2. Save image to file.\n");
    printf("3. Invert colors.\n");
    printf("4. Convert to grayscale.\n");
    printf("5. Rotate 90 degrees.\n");
    printf("6. Flip horizontally.\n");
    printf("7. Flip vertically.\n");
    printf("8. Exit program.\n");
}

void read_image(Image *img, char *filename) {
    FILE *infile;
    int i, j;

    infile = fopen(filename, "rb");
    if (infile == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }

    fread(&img->width, sizeof(int), 1, infile);
    fread(&img->height, sizeof(int), 1, infile);
    img->data = (Pixel *) malloc(img->width * img->height * sizeof(Pixel));

    for (i=0; i<img->height; i++) {
        for (j=0; j<img->width; j++) {
            fread(&img->data[i*img->width+j], sizeof(Pixel), 1, infile);
        }
    }

    fclose(infile);
}

void save_image(Image *img, char *filename) {
    FILE *outfile;
    int i, j;

    outfile = fopen(filename, "wb");
    if (outfile == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    fwrite(&img->width, sizeof(int), 1, outfile);
    fwrite(&img->height, sizeof(int), 1, outfile);

    for (i=0; i<img->height; i++) {
        for (j=0; j<img->width; j++) {
            fwrite(&img->data[i*img->width+j], sizeof(Pixel), 1, outfile);
        }
    }

    fclose(outfile);
}

void invert_colors(Image *img) {
    int i, j;

    for (i=0; i<img->height; i++) {
        for (j=0; j<img->width; j++) {
            img->data[i*img->width+j].r = 255 - img->data[i*img->width+j].r;
            img->data[i*img->width+j].g = 255 - img->data[i*img->width+j].g;
            img->data[i*img->width+j].b = 255 - img->data[i*img->width+j].b;
        }
    }
}

void convert_to_grayscale(Image *img) {
    int i, j, gray;

    for (i=0; i<img->height; i++) {
        for (j=0; j<img->width; j++) {
            gray = (img->data[i*img->width+j].r + img->data[i*img->width+j].g + img->data[i*img->width+j].b) / 3;
            img->data[i*img->width+j].r = gray;
            img->data[i*img->width+j].g = gray;
            img->data[i*img->width+j].b = gray;
        }
    }
}

void rotate_90_degrees(Image *img) {
    int i, j;
    Pixel *new_pixels;

    new_pixels = (Pixel *) malloc(img->width * img->height * sizeof(Pixel));

    for (i=0; i<img->height; i++) {
        for (j=0; j<img->width; j++) {
            new_pixels[(img->width-j-1)*img->height+i] = img->data[i*img->width+j];
        }
    }

    free(img->data);
    img->data = new_pixels;
    img->width ^= img->height ^= img->width ^= img->height;
}

void flip_horizontally(Image *img) {
    int i, j;
    Pixel tmp;

    for (i=0; i<img->height; i++) {
        for (j=0; j<img->width/2; j++) {
            tmp = img->data[i*img->width+j];
            img->data[i*img->width+j] = img->data[i*img->width+(img->width-j-1)];
            img->data[i*img->width+(img->width-j-1)] = tmp;
        }
    }
}

void flip_vertically(Image *img) {
    int i, j;
    Pixel tmp;

    for (i=0; i<img->height/2; i++) {
        for (j=0; j<img->width; j++) {
            tmp = img->data[i*img->width+j];
            img->data[i*img->width+j] = img->data[(img->height-i-1)*img->width+j];
            img->data[(img->height-i-1)*img->width+j] = tmp;
        }
    }
}

int main(int argc, char *argv[]) {
    int choice;
    char filename[100];
    Image img;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter filename: ");
                scanf("%s", filename);
                read_image(&img, filename);
                break;
            case 2:
                printf("Enter filename: ");
                scanf("%s", filename);
                save_image(&img, filename);
                break;
            case 3:
                invert_colors(&img);
                break;
            case 4:
                convert_to_grayscale(&img);
                break;
            case 5:
                rotate_90_degrees(&img);
                break;
            case 6:
                flip_horizontally(&img);
                break;
            case 7:
                flip_vertically(&img);
                break;
            case 8:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    free(img.data);
    return 0;
}