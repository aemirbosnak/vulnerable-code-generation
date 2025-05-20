//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

typedef struct {
    char *filename;
    char *data;
    int size;
} Image;

void load_image(Image *img, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    img->size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    img->data = malloc(img->size + 1);
    if (!img->data) {
        printf("Error: Could not allocate memory for image data\n");
        exit(1);
    }

    fread(img->data, img->size, 1, fp);
    fclose(fp);

    img->filename = strdup(filename);
}

void save_image(Image *img, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error: Could not open file '%s' for writing\n", filename);
        exit(1);
    }

    fwrite(img->data, img->size, 1, fp);
    fclose(fp);
}

void print_image(Image *img) {
    printf("Filename: %s\n", img->filename);
    printf("Size: %d bytes\n", img->size);
    printf("Data:\n%s\n", img->data);
}

void free_image(Image *img) {
    free(img->data);
    free(img->filename);
    memset(img, 0, sizeof(Image));
}

int main() {
    Image img;

    load_image(&img, "test.txt");
    print_image(&img);

    char *data = strdup(img.data);
    char *pos = strchr(data, '\n');
    while (pos) {
        *pos = '\0';
        printf("Line: %s\n", data);
        pos = strchr(data, '\n');
    }

    save_image(&img, "test2.txt");
    print_image(&img);

    free_image(&img);

    return 0;
}