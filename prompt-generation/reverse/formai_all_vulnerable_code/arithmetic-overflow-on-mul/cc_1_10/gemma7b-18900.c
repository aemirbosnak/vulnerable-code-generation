//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct Image
{
    int width, height;
    unsigned char *data;
} Image;

Image *load_image(char *filename)
{
    Image *image = malloc(sizeof(Image));
    image->width = image->height = 0;
    image->data = NULL;

    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        return NULL;
    }

    fscanf(file, "%d %d", &image->width, &image->height);
    image->data = malloc(image->width * image->height * 3);
    fread(image->data, image->width * image->height * 3, 1, file);
    fclose(file);

    return image;
}

void save_image(Image *image, char *filename)
{
    FILE *file = fopen(filename, "wb");
    if (file == NULL)
    {
        return;
    }

    fprintf(file, "%d %d\n", image->width, image->height);
    fwrite(image->data, image->width * image->height * 3, 1, file);
    fclose(file);
}

int main()
{
    Image *image = load_image("image.jpg");
    save_image(image, "image_edited.jpg");

    free(image->data);
    free(image);

    return 0;
}