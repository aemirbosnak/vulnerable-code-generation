//FormAI DATASET v1.0 Category: Image Editor ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Pixel {
    unsigned char red, green, blue;
};

void load_image(FILE* fp, struct Pixel* image, int width, int height) {
    fread(image, sizeof(struct Pixel), width * height, fp);
}

void save_image(FILE* fp, struct Pixel* image, int width, int height) {
    fwrite(image, sizeof(struct Pixel), width * height, fp);
}

void grayscale(struct Pixel* image, int width, int height) {
    for(int i = 0; i < width * height; i++) {
        unsigned char gray = 0.3 * image[i].red + 0.59 * image[i].green + 0.11 * image[i].blue;
        image[i].red = gray;
        image[i].green = gray;
        image[i].blue = gray;
    }
}

void sepia(struct Pixel* image, int width, int height) {
    for(int i = 0; i < width * height; i++) {
        unsigned char originalRed = image[i].red;
        unsigned char originalGreen = image[i].green;
        unsigned char originalBlue = image[i].blue;
        
        image[i].red = (0.393 * originalRed) + (0.769 * originalGreen) + (0.189 * originalBlue);
        image[i].green = (0.349 * originalRed) + (0.686 * originalGreen) + (0.168 * originalBlue);
        image[i].blue = (0.272 * originalRed) + (0.534 * originalGreen) + (0.131 * originalBlue);

        image[i].red = image[i].red > 255 ? 255 : image[i].red;
        image[i].green = image[i].green > 255 ? 255 : image[i].green;
        image[i].blue = image[i].blue > 255 ? 255 : image[i].blue;
    }
}

int main() {
    FILE* fp = fopen("image.ppm", "r");
    
    if(!fp) {
        printf("Error: Unable to open file!\n");
        return 1;
    }
    
    char magic_number[5];
    fscanf(fp, "%s", magic_number);
    
    if(strcmp(magic_number, "P6")) {
        printf("Error: Invalid image format!\n");
        fclose(fp);
        return 1;
    }
    
    int width, height;
    fscanf(fp, "%d %d", &width, &height);
    
    int max_color;
    fscanf(fp, "%d", &max_color);

    struct Pixel* image = malloc(width * height * sizeof(struct Pixel));
    
    if(!image) {
        printf("Error: Unable to allocate memory!\n");
        fclose(fp);
        return 1;
    }

    load_image(fp, image, width, height);

    fclose(fp);
    
    grayscale(image, width, height);

    fp = fopen("grayscale.ppm", "w");
    
    if(!fp) {
        printf("Error: Unable to create file!\n");
        free(image);
        return 1;
    }
    
    fprintf(fp, "P6\n%d %d\n%d\n", width, height, max_color);

    save_image(fp, image, width, height);
        
    fclose(fp);

    sepia(image, width, height);

    fp = fopen("sepia.ppm", "w");
    
    if(!fp) {
        printf("Error: Unable to create file!\n");
        free(image);
        return 1;
    }
    
    fprintf(fp, "P6\n%d %d\n%d\n", width, height, max_color);

    save_image(fp, image, width, height);
        
    fclose(fp);

    free(image);
    
    return 0;
}