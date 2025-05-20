//FormAI DATASET v1.0 Category: Image Editor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_COMMAND_LENGTH 256

typedef struct _pixel {
    int red;
    int green;
    int blue;
} Pixel;

typedef struct _image {
    int width;
    int height;
    Pixel *pixels;
} Image;

void print_menu(void);
/* Reads image data from file and returns a pointer to Image struct */
Image* read_image(char *filename);

/* Writes Pixel data to BMP file */
int write_image(Image *im, char *filename);

/* Frees Image struct memory */
void free_image(Image *im);

/* Applies grayscale effect to given Image */
void grayscale_effect(Image *im);

/* Applies sepia effect to given Image */
void sepia_effect(Image *im);

/* Helper function to parse field and value from a command string */
int parse_command(char *command, char **field, char **value);

/* Applies brightness adjustment to given Image */
void brightness_adjustment(Image *im, int value);

/* Applies contrast adjustment to given Image */
void contrast_adjustment(Image *im, int value);

int main(void) {
    char filename[MAX_FILENAME_LENGTH];
    Image *im = NULL;
    int quit = 0;

    while (!quit) {
        char command[MAX_COMMAND_LENGTH];
        char *field, *value;

        print_menu();
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        /* Strip newline character */
        command[strlen(command) - 1] = '\0';

        switch (tolower(command[0])) {
            case 'o': /* Open file */
                printf("Enter filename: ");
                fgets(filename, MAX_FILENAME_LENGTH, stdin);
                filename[strlen(filename) - 1] = '\0';
                im = read_image(filename);
                if (!im) {
                    printf("Failed to read image file.\n");
                }
                break;
            case 's': /* Save file */
                if (im) {
                    printf("Enter filename: ");
                    fgets(filename, MAX_FILENAME_LENGTH, stdin);
                    filename[strlen(filename) - 1] = '\0';
                    if (write_image(im, filename)) {
                        printf("Saved image to file.\n");
                    } else {
                        printf("Failed to save image.\n");
                    }
                } else {
                    printf("No image loaded.\n");
                }
                break;
            case 'g': /* Grayscale effect */
                if (im) {
                    grayscale_effect(im);
                    printf("Applied grayscale effect.\n");
                } else {
                    printf("No image loaded.\n");
                }
                break;
            case 'p': /* Sepia effect */
                if (im) {
                    sepia_effect(im);
                    printf("Applied sepia effect.\n");
                } else {
                    printf("No image loaded.\n");
                }
                break;
            case 'b': /* Brightness adjustment */
                if (im) {
                    if (parse_command(command + 1, &field, &value)) {
                        brightness_adjustment(im, atoi(value));
                        printf("Applied brightness adjustment.\n");
                    } else {
                        printf("Invalid command.\n");
                    }
                } else {
                    printf("No image loaded.\n");
                }
                break;
            case 'c': /* Contrast adjustment */
                if (im) {
                    if (parse_command(command + 1, &field, &value)) {
                        contrast_adjustment(im, atoi(value));
                        printf("Applied contrast adjustment.\n");
                    } else {
                        printf("Invalid command.\n");
                    }
                } else {
                    printf("No image loaded.\n");
                }
                break;
            case 'q': /* Quit */
                quit = 1;
                break;
            default:
                printf("Invalid command.\n");
        }
    }

    if (im) {
        free_image(im);
    }

    return 0;
}

void print_menu(void) {
    printf("\n----IMAGE EDITOR----\n");
    printf("[O]pen file\n");
    printf("[S]ave file\n");
    printf("[G]rayscale effect\n");
    printf("[P]Sepia effect\n");
    printf("[B]rightness adjustment\n");
    printf("[C]ontrast adjustment\n");
    printf("[Q]uit\n");
    printf("Enter command: ");
}

Image* read_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    Image *im = NULL;

    if (fp) {
        im = (Image*) malloc(sizeof(Image));
        if (im) {
            unsigned char header[54];
            fread(header, sizeof(unsigned char), 54, fp);
            im->width = *(int*)&header[18];
            im->height = *(int*)&header[22];
            int size = im->width * im->height;
            im->pixels = (Pixel*) malloc(sizeof(Pixel) * size);
            if (im->pixels) {
                for (int i = 0; i < size; i++) {
                    unsigned char pixel[3];
                    fread(pixel, sizeof(unsigned char), 3, fp);
                    im->pixels[i].blue = pixel[0];
                    im->pixels[i].green = pixel[1];
                    im->pixels[i].red = pixel[2];
                }
            } else {
                free(im);
                im = NULL;
            }
        }
        fclose(fp);
    }

    return im;
}

int write_image(Image *im, char *filename) {
    FILE *fp = fopen(filename, "wb");
    int success = 0;

    if (fp) {
        unsigned char header[54] = {
            0x42, 0x4D, /* BMP file signature */
            0x6E, 0xEB, 0x0D, 0x00, /* File size (need to fill in later) */
            0x00, 0x00, /* Reserved */
            0x00, 0x00, /* Reserved */
            0x36, 0x00, 0x00, 0x00, /* Data offset */
            0x28, 0x00, 0x00, 0x00, /* Header size */
            0x00, 0x02, 0x00, 0x00, /* Image width (need to fill in later) */
            0x00, 0x02, 0x00, 0x00, /* Image height (need to fill in later) */
            0x01, 0x00, /* Number of color planes */
            0x18, 0x00, /* Bits per pixel */
            0x00, 0x00, 0x00, 0x00, /* Compression method */
            0x00, 0x0D, 0xEB, 0x1C, /* Image size (need to fill in later) */
            0x00, 0x00, 0x00, 0x00, /* X pixels per meter */
            0x00, 0x00, 0x00, 0x00, /* Y pixels per meter */
            0x00, 0x00, 0x00, 0x00, /* Number of palette colors */
            0x00, 0x00, 0x00, 0x00 /* Important colors */
        };
        *(int*)&header[2] = 54 + (im->width * im->height * 3);
        *(int*)&header[18] = im->width;
        *(int*)&header[22] = im->height;
        *(int*)&header[34] = im->width * im->height * 3;
        fwrite(header, sizeof(unsigned char), 54, fp);

        for (int i = 0; i < im->width * im->height; i++) {
            unsigned char pixel[3];
            pixel[0] = im->pixels[i].blue;
            pixel[1] = im->pixels[i].green;
            pixel[2] = im->pixels[i].red;
            fwrite(pixel, sizeof(unsigned char), 3, fp);
        }

        fclose(fp);
        success = 1;
    }

    return success;
}

void free_image(Image *im) {
    if (im->pixels) {
        free(im->pixels);
    }
    free(im);
}

void grayscale_effect(Image *im) {
    for (int i = 0; i < im->width * im->height; i++) {
        int gray = (im->pixels[i].red + im->pixels[i].green + im->pixels[i].blue) / 3;
        im->pixels[i].red = gray;
        im->pixels[i].green = gray;
        im->pixels[i].blue = gray;
    }
}

void sepia_effect(Image *im) {
    for (int i = 0; i < im->width * im->height; i++) {
        int intensity = (im->pixels[i].red + im->pixels[i].green + im->pixels[i].blue) / 3;
        int sepia_red = (int)(intensity * 0.393 + im->pixels[i].green * 0.769 + im->pixels[i].blue * 0.189);
        int sepia_green = (int)(intensity * 0.349 + im->pixels[i].red * 0.686 + im->pixels[i].blue * 0.168);
        int sepia_blue = (int)(intensity * 0.272 + im->pixels[i].red * 0.534 + im->pixels[i].green * 0.131);
        im->pixels[i].red = sepia_red > 255 ? 255 : sepia_red;
        im->pixels[i].green = sepia_green > 255 ? 255 : sepia_green;
        im->pixels[i].blue = sepia_blue > 255 ? 255 : sepia_blue;
    }
}

int parse_command(char *command, char **field, char **value) {
    const char *delim = " ";
    char *ptr = strtok(command, delim);
    if (!ptr) return 0;
    *field = ptr;
    ptr = strtok(NULL, delim);
    if (!ptr) return 0;
    *value = ptr;
    return 1;
}

void brightness_adjustment(Image *im, int value) {
    for (int i = 0; i < im->width * im->height; i++) {
        int red = im->pixels[i].red + value;
        int green = im->pixels[i].green + value;
        int blue = im->pixels[i].blue + value;
        im->pixels[i].red = red > 255 ? 255 : red < 0 ? 0 : red;
        im->pixels[i].green = green > 255 ? 255 : green < 0 ? 0 : green;
        im->pixels[i].blue = blue > 255 ? 255 : blue < 0 ? 0 : blue;
    }
}

void contrast_adjustment(Image *im, int value) {
    double factor = (259.0 * (value + 255.0)) / (255.0 * (259.0 - value));
    for (int i = 0; i < im->width * im->height; i++) {
        int red = (int)((double)im->pixels[i].red * factor - 128.0 + 128.0);
        int green = (int)((double)im->pixels[i].green * factor - 128.0 + 128.0);
        int blue = (int)((double)im->pixels[i].blue * factor - 128.0 + 128.0);
        im->pixels[i].red = red > 255 ? 255 : red < 0 ? 0 : red;
        im->pixels[i].green = green > 255 ? 255 : green < 0 ? 0 : green;
        im->pixels[i].blue = blue > 255 ? 255 : blue < 0 ? 0 : blue;
    }
}