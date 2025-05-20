//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

void itoa(int n, char *s) {
    int i = 0;
    s[0] = '\0';
    while (n) {
        int digit = n % 10;
        n /= 10;
        s[i++] = digit + '0';
    }
    s[i] = '\0';
}

int main() {
    int img_width, img_height;
    printf("Enter image width: ");
    scanf("%d", &img_width);

    printf("Enter image height: ");
    scanf("%d", &img_height);

    int **img_data = (int **)malloc(img_height * sizeof(int *));
    for (int h = 0; h < img_height; h++) {
        img_data[h] = (int *)malloc(img_width * sizeof(int));
    }

    printf("Enter image data (separated by commas): ");
    char img_data_str[MAX_WIDTH * MAX_HEIGHT];
    scanf("%s", img_data_str);

    int pixel_count = 0;
    for (int h = 0; h < img_height; h++) {
        for (int w = 0; w < img_width; w++) {
            img_data[h][w] = atoi(&img_data_str[pixel_count++]);
        }
    }

    char **ascii_art = (char **)malloc(img_height * sizeof(char *));
    for (int h = 0; h < img_height; h++) {
        ascii_art[h] = (char *)malloc(img_width * sizeof(char));
    }

    for (int h = 0; h < img_height; h++) {
        for (int w = 0; w < img_width; w++) {
            int pixel_value = img_data[h][w];
            ascii_art[h][w] = (pixel_value >= 128) ? 'X' : ' ';
        }
    }

    printf("Your ASCII art:\n");
    for (int h = 0; h < img_height; h++) {
        for (int w = 0; w < img_width; w++) {
            printf("%c ", ascii_art[h][w]);
        }
        printf("\n");
    }

    free(img_data);
    free(ascii_art);

    return 0;
}