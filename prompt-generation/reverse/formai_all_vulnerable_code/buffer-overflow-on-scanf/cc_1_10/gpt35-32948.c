//FormAI DATASET v1.0 Category: Image Editor ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define WIDTH 1024
#define HEIGHT 768

//Struct to hold RGB pixel values
typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

Pixel image[HEIGHT][WIDTH];

//Function to create random noise effect
void randomNoise() {
    int i, j;
    srand(time(NULL));  //Seed for random number generation

    for(i=0; i<HEIGHT; i++) {
        for(j=0; j<WIDTH; j++) {
            image[i][j].r = rand()%256; //Random red value
            image[i][j].g = rand()%256; //Random green value
            image[i][j].b = rand()%256; //Random blue value
        }
    }
}

//Function to create grayscale image
void grayscale() {
    int i, j;
    unsigned char gray;

    for(i=0; i<HEIGHT; i++) {
        for(j=0; j<WIDTH; j++) {
            gray = (image[i][j].r + image[i][j].g + image[i][j].b)/3; //Average of RGB values
            image[i][j].r = gray;
            image[i][j].g = gray;
            image[i][j].b = gray;
        }
    }
}

//Function to create sepia effect
void sepia() {
    int i, j;
    unsigned char red, green, blue;

    for(i=0; i<HEIGHT; i++) {
        for(j=0; j<WIDTH; j++) {
            red = (image[i][j].r * 0.393) + (image[i][j].g * 0.769) + (image[i][j].b * 0.189);
            green = (image[i][j].r * 0.349) + (image[i][j].g * 0.686) + (image[i][j].b * 0.168);
            blue = (image[i][j].r * 0.272) + (image[i][j].g * 0.534) + (image[i][j].b * 0.131);

            image[i][j].r = (red > 255) ? 255 : red; //Limits the value to 255
            image[i][j].g = (green > 255) ? 255 : green;
            image[i][j].b = (blue > 255) ? 255 : blue;
        }
    }
}

//Function to create negative image
void negative() {
    int i, j;
    unsigned char r, g, b;

    for(i=0; i<HEIGHT; i++) {
        for(j=0; j<WIDTH; j++) {
            r = 255 - image[i][j].r; //Inverse of red value
            g = 255 - image[i][j].g; //Inverse of green value
            b = 255 - image[i][j].b; //Inverse of blue value

            image[i][j].r = r;
            image[i][j].g = g;
            image[i][j].b = b;
        }
    }
}

int main() {
    int option;

    printf("Enter option number:\n");
    printf("1. Random noise\n");
    printf("2. Grayscale\n");
    printf("3. Sepia\n");
    printf("4. Negative\n");

    scanf("%d", &option);

    switch(option) {
        case 1:
            randomNoise();
            break;

        case 2:
            grayscale();
            break;

        case 3:
            sepia();
            break;

        case 4:
            negative();
            break;

        default:
            printf("Invalid option\n");
    }

    //Code for image file output
    FILE *fp;
    char filename[] = "cyberpunk_image.ppm";
    fp = fopen(filename, "wb");

    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);

    int i, j;
    for(i=0; i<HEIGHT; i++)
        for(j=0; j<WIDTH; j++)
            fwrite(&image[i][j], 1, 3, fp);

    fclose(fp);

    return 0;
}