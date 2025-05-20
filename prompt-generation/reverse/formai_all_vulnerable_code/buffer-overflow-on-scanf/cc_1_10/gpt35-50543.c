//FormAI DATASET v1.0 Category: Image Editor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXEL_VALUE 255
#define MIN_PIXEL_VALUE 0

typedef struct {
    int r;
    int g;
    int b;
} Pixel;

typedef struct {
    int w;
    int h;
    Pixel *data;
} Image;

void print_menu();
void print_image(Image img);
Pixel get_pixel();
Image create_image(int w, int h);
void save_image(Image img, char *filename);
Image load_image(char *filename);
Image flip_image(Image img, int flip_type);
Image invert_colors(Image img);
Image adjust_brightness(Image img, int brightness);
Image adjust_contrast(Image img, float contrast);

int main() {
    Image img;
    int option = -1;
    char filename[100];

    printf("Welcome to the C Image Editor!\n");

    do {
        print_menu();
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter the width and height of the image:\n");
                int w, h;
                scanf("%d %d", &w, &h);
                img = create_image(w, h);
                printf("Image created!\n");
                break;
            case 2:
                printf("Enter the filename to save the image (jpg or png):\n");
                scanf("%s", filename);
                save_image(img, filename);
                printf("Image saved as %s\n", filename);
                break;
            case 3:
                printf("Enter the filename to load the image:\n");
                scanf("%s", filename);
                img = load_image(filename);
                printf("Image loaded!\n");
                break;
            case 4:
                printf("Select the flip type:\n");
                printf("1. Flip horizontally\n");
                printf("2. Flip vertically\n");
                int flip_type;
                scanf("%d", &flip_type);
                img = flip_image(img, flip_type);
                printf("Image flipped!\n");
                break;
            case 5:
                img = invert_colors(img);
                printf("Colors inverted!\n");
                break;
            case 6:
                printf("Enter the brightness level (-255 to 255):\n");
                int brightness;
                scanf("%d", &brightness);
                img = adjust_brightness(img, brightness);
                printf("Brightness adjusted!\n");
                break;
            case 7:
                printf("Enter the contrast level (0.1 to 10):\n");
                float contrast;
                scanf("%f", &contrast);
                img = adjust_contrast(img, contrast);
                printf("Contrast adjusted!\n");
                break;
            case 8:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option, please try again\n");
                break;
        }
    } while(option != 8);

    free(img.data);
    return 0;
}

void print_menu() {
    printf("Select an option:\n");
    printf("1. Create a new image\n");
    printf("2. Save image\n");
    printf("3. Load image\n");
    printf("4. Flip image\n");
    printf("5. Invert colors\n");
    printf("6. Adjust brightness\n");
    printf("7. Adjust contrast\n");
    printf("8. Exit\n");
}

void print_image(Image img) {
    for(int i = 0; i < img.h; i++) {
        for(int j = 0; j < img.w; j++) {
            printf("(%d,%d,%d) ", img.data[i*img.w + j].r, img.data[i*img.w + j].g, img.data[i*img.w + j].b);
        }
        printf("\n");
    }
}

Pixel get_pixel() {
    Pixel p;
    printf("Enter the pixel values (r,g,b):\n");
    scanf("%d %d %d", &p.r, &p.g, &p.b);
    return p;
}

Image create_image(int w, int h) {
    Image img;
    img.w = w;
    img.h = h;
    img.data = (Pixel*)malloc(w*h*sizeof(Pixel));

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            img.data[i*w + j] = get_pixel();
        }
    }

    return img;
}

void save_image(Image img, char *filename) {
    FILE *f = fopen(filename, "wb");

    fprintf(f, "P3\n");
    fprintf(f, "%d %d\n", img.w, img.h);
    fprintf(f, "%d\n", MAX_PIXEL_VALUE);

    for(int i = 0; i < img.h; i++) {
        for(int j = 0; j < img.w; j++) {
            fprintf(f, "%d %d %d ", img.data[i*img.w + j].r, img.data[i*img.w + j].g, img.data[i*img.w + j].b);
        }
        fprintf(f, "\n");
    }

    fclose(f);
}

Image load_image(char *filename) {
    FILE *f = fopen(filename, "r");

    char magic_number[10];
    int w, h, max_value;

    fscanf(f, "%s\n", magic_number);
    fscanf(f, "%d %d\n", &w, &h);
    fscanf(f, "%d\n", &max_value);

    Image img = create_image(w, h);

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            fscanf(f, "%d %d %d ", &img.data[i*w + j].r, &img.data[i*w + j].g, &img.data[i*w + j].b);
        }
    }

    fclose(f);

    return img;
}

Image flip_image(Image img, int flip_type) {
    Image flipped_img = create_image(img.w, img.h);

    switch(flip_type) {
        case 1: // horizontal flip
            for(int i = 0; i < img.h; i++) {
                for(int j = 0; j < img.w; j++) {
                    flipped_img.data[i*img.w + j] = img.data[i*img.w + (img.w-1-j)];
                }
            }
            break;
        case 2: // vertical flip
            for(int i = 0; i < img.h; i++) {
                for(int j = 0; j < img.w; j++) {
                    flipped_img.data[i*img.w + j] = img.data[(img.h-1-i)*img.w + j];
                }
            }
            break;
        default:
            printf("Invalid flip type\n");
            break;
    }

    return flipped_img;
}

Image invert_colors(Image img) {
    Image inverted_img = create_image(img.w, img.h);

    for(int i = 0; i < img.h; i++) {
        for(int j = 0; j < img.w; j++) {
            inverted_img.data[i*img.w + j].r = MAX_PIXEL_VALUE - img.data[i*img.w + j].r;
            inverted_img.data[i*img.w + j].g = MAX_PIXEL_VALUE - img.data[i*img.w + j].g;
            inverted_img.data[i*img.w + j].b = MAX_PIXEL_VALUE - img.data[i*img.w + j].b;
        }
    }

    return inverted_img;
}

Image adjust_brightness(Image img, int brightness) {
    Image adjusted_img = create_image(img.w, img.h);

    for(int i = 0; i < img.h; i++) {
        for(int j = 0; j < img.w; j++) {
            adjusted_img.data[i*img.w + j].r = img.data[i*img.w + j].r + brightness;
            adjusted_img.data[i*img.w + j].g = img.data[i*img.w + j].g + brightness;
            adjusted_img.data[i*img.w + j].b = img.data[i*img.w + j].b + brightness;

            if(adjusted_img.data[i*img.w + j].r > MAX_PIXEL_VALUE) {
                adjusted_img.data[i*img.w + j].r = MAX_PIXEL_VALUE;
            } else if(adjusted_img.data[i*img.w + j].r < MIN_PIXEL_VALUE) {
                adjusted_img.data[i*img.w + j].r = MIN_PIXEL_VALUE;
            }

            if(adjusted_img.data[i*img.w + j].g > MAX_PIXEL_VALUE) {
                adjusted_img.data[i*img.w + j].g = MAX_PIXEL_VALUE;
            } else if(adjusted_img.data[i*img.w + j].g < MIN_PIXEL_VALUE) {
                adjusted_img.data[i*img.w + j].g = MIN_PIXEL_VALUE;
            }

            if(adjusted_img.data[i*img.w + j].b > MAX_PIXEL_VALUE) {
                adjusted_img.data[i*img.w + j].b = MAX_PIXEL_VALUE;
            } else if(adjusted_img.data[i*img.w + j].b < MIN_PIXEL_VALUE) {
                adjusted_img.data[i*img.w + j].b = MIN_PIXEL_VALUE;
            }
        }
    }

    return adjusted_img;
}

Image adjust_contrast(Image img, float contrast) {
    Image adjusted_img = create_image(img.w, img.h);

    for(int i = 0; i < img.h; i++) {
        for(int j = 0; j < img.w; j++) {
            adjusted_img.data[i*img.w + j].r = (contrast * (img.data[i*img.w + j].r - MAX_PIXEL_VALUE/2)) + MAX_PIXEL_VALUE/2;
            adjusted_img.data[i*img.w + j].g = (contrast * (img.data[i*img.w + j].g - MAX_PIXEL_VALUE/2)) + MAX_PIXEL_VALUE/2;
            adjusted_img.data[i*img.w + j].b = (contrast * (img.data[i*img.w + j].b - MAX_PIXEL_VALUE/2)) + MAX_PIXEL_VALUE/2;

            if(adjusted_img.data[i*img.w + j].r > MAX_PIXEL_VALUE) {
                adjusted_img.data[i*img.w + j].r = MAX_PIXEL_VALUE;
            } else if(adjusted_img.data[i*img.w + j].r < MIN_PIXEL_VALUE) {
                adjusted_img.data[i*img.w + j].r = MIN_PIXEL_VALUE;
            }

            if(adjusted_img.data[i*img.w + j].g > MAX_PIXEL_VALUE) {
                adjusted_img.data[i*img.w + j].g = MAX_PIXEL_VALUE;
            } else if(adjusted_img.data[i*img.w + j].g < MIN_PIXEL_VALUE) {
                adjusted_img.data[i*img.w + j].g = MIN_PIXEL_VALUE;
            }

            if(adjusted_img.data[i*img.w + j].b > MAX_PIXEL_VALUE) {
                adjusted_img.data[i*img.w + j].b = MAX_PIXEL_VALUE;
            } else if(adjusted_img.data[i*img.w + j].b < MIN_PIXEL_VALUE) {
                adjusted_img.data[i*img.w + j].b = MIN_PIXEL_VALUE;
            }
        }
    }

    return adjusted_img;
}