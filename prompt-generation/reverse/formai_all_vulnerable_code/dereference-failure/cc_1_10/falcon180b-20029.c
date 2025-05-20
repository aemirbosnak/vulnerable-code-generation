//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_SIZE 1000
#define MAX_WIDTH 80
#define MAX_HEIGHT 80

typedef struct {
    char *data;
    int width;
    int height;
} Image;

typedef struct {
    int x;
    int y;
} Coord;

void readImage(Image *img, FILE *fp) {
    fseek(fp, 0L, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    img->data = (char*)malloc(size);
    fread(img->data, size, 1, fp);

    img->width = atoi(img->data);
    img->height = atoi(img->data + strlen(img->data) + 1);
}

void convert(Image *img, Coord *start, Coord *end) {
    int i, j, k;
    for(i=start->x; i<end->x; i++) {
        for(j=start->y; j<end->y; j++) {
            k = i + j * img->width;
            if(img->data[k] == '1') {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    Image img;
    Coord start, end;

    fp = fopen("image.bin", "rb");
    if(fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    readImage(&img, fp);
    fclose(fp);

    printf("Enter start coordinates (x y): ");
    scanf("%d %d", &start.x, &start.y);

    printf("Enter end coordinates (x y): ");
    scanf("%d %d", &end.x, &end.y);

    convert(&img, &start, &end);

    return 0;
}