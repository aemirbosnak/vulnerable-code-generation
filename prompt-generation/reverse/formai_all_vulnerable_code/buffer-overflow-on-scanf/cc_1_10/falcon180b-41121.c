//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define NUM_COLORS 7

typedef struct {
    char *name;
    char *value;
} Property;

typedef struct {
    int width;
    int height;
    Property *properties;
} Image;

typedef struct {
    char *name;
    int value;
} Color;

Color colors[NUM_COLORS] = {{"Black", 0}, {"Red", 1}, {"Green", 2}, {"Yellow", 3}, {"Blue", 4}, {"Magenta", 5}, {"Cyan", 6}};

void print_image(Image *image) {
    int i, j;
    for(i=0; i<image->height; i++) {
        for(j=0; j<image->width; j++) {
            printf("%c", image->properties[i*MAX_WIDTH+j].value[0]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    char filename[100];
    char line[100];
    char *token;
    int i, j, k;
    Image image;
    Property *properties;
    Color color;

    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    fgets(line, 100, fp);
    token = strtok(line, " ");
    while(token!= NULL) {
        if(strcmp(token, "P6") == 0) {
            fgets(line, 100, fp);
            token = strtok(line, " ");
            image.width = atoi(token);
            token = strtok(NULL, " ");
            image.height = atoi(token);
            properties = (Property *)malloc(image.width*image.height*sizeof(Property));
            for(i=0; i<image.height; i++) {
                for(j=0; j<image.width; j++) {
                    fgets(line, 100, fp);
                    token = strtok(line, " ");
                    properties[i*MAX_WIDTH+j].name = strdup(token);
                    properties[i*MAX_WIDTH+j].value = strdup("0");
                }
            }
            break;
        }
        token = strtok(NULL, " ");
    }

    fclose(fp);

    for(i=0; i<image.height; i++) {
        for(j=0; j<image.width; j++) {
            color.name = strdup("Black");
            color.value = 0;
            for(k=0; k<NUM_COLORS; k++) {
                if(strcmp(colors[k].name, properties[i*MAX_WIDTH+j].value) == 0) {
                    color.name = strdup(colors[k].name);
                    color.value = k;
                    break;
                }
            }
            printf("%c", color.value+33);
        }
        printf("\n");
    }

    return 0;
}