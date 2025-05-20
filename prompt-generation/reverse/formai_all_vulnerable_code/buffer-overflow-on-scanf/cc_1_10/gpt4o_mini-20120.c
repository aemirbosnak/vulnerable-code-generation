//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Let's paint a funny picture with our photo editor!

#define MAX_SIZE 100

// A delightful structure to handle our image data
typedef struct {
    char name[50];
    int width;
    int height;
    char pixelData[MAX_SIZE][MAX_SIZE]; // Assuming a max image size of 100x100
} Image;

// Function declarations
void greetUser();
void createImage(Image *img);
void editImage(Image *img);
void displayImage(const Image *img);
void saveImage(const Image *img);
void addFunnyFilter(Image *img);
void eraseFunnyFilter(Image *img);
void thankUser();

int main() {
    greetUser();

    Image img;
    createImage(&img);

    int choice;
    while(1) {
        printf("\nHello Picasso! What would you like to do?\n");
        printf("1. Edit Image\n2. Display Image\n3. Save Image\n4. Add Funny Filter\n5. Remove Funny Filter\n6. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                editImage(&img);
                break;
            case 2:
                displayImage(&img);
                break;
            case 3:
                saveImage(&img);
                break;
            case 4:
                addFunnyFilter(&img);
                break;
            case 5:
                eraseFunnyFilter(&img);
                break;
            case 6:
                thankUser();
                exit(0);
            default:
                printf("Oops! That's not a number for a menu option. Try again, maestro!\n");
        }
    }
    return 0;
}

void greetUser() {
    printf("Welcome to the Wacky Wonderland Image Editor!\n");
}

void createImage(Image *img) {
    printf("Let's make a picture! What's its name? ");
    scanf("%s", img->name);
    
    printf("What's the width of '%s'? (max %d): ", img->name, MAX_SIZE);
    scanf("%d", &img->width);
    
    printf("Now, what's the height of '%s'? (max %d): ", img->name, MAX_SIZE);
    scanf("%d", &img->height);

    // Fill the pixel data with a simple pattern to start
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->pixelData[i][j] = (i + j) % 2 ? 'X' : 'O'; // Alternating pattern
        }
    }

    printf("Image '%s' created with dimensions %dx%d!\n", img->name, img->width, img->height);
}

void editImage(Image *img) {
    printf("Editing image '%s'... (Not like a magician would though! Ha!)\n", img->name);
    int x, y;
    char newPixel;
    
    printf("Enter coordinates (x y) to change pixel value (0 to %d) (0 to %d): ", img->width - 1, img->height - 1);
    scanf("%d %d", &x, &y);
    
    if (x < 0 || x >= img->width || y < 0 || y >= img->height) {
        printf("Whoa! You just tried to edit outside the image! That's not allowed!\n");
    } else {
        printf("What value should the pixel be changed to? ");
        scanf(" %c", &newPixel);
        
        img->pixelData[y][x] = newPixel;
        printf("Pixel at (%d, %d) changed to '%c'! Artistic touch, no?\n", x, y, newPixel);
    }
}

void displayImage(const Image *img) {
    printf("\n--- Displaying Image '%s' ---\n", img->name);
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            printf("%c ", img->pixelData[i][j]);
        }
        printf("\n");
    }
}

void saveImage(const Image *img) {
    printf("Saving image '%s'... Aah, too much pressure!\n", img->name);
    FILE *file = fopen("saved_image.txt", "w");
    if (file) {
        fprintf(file, "Image Name: %s\nDimensions: %dx%d\nPixel Data:\n", img->name, img->width, img->height);
        for (int i = 0; i < img->height; i++) {
            for (int j = 0; j < img->width; j++) {
                fprintf(file, "%c ", img->pixelData[i][j]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
        printf("Image '%s' saved successfully! Enjoy reading it in 'saved_image.txt'.\n", img->name);
    } else {
        printf("Oops! Failed to save your image. Maybe you ran out of disk space from all those cat pictures!\n");
    }
}

void addFunnyFilter(Image *img) {
    printf("Adding a Funny Filter to '%s'! Get ready for laughs and giggles...\n", img->name);
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->pixelData[i][j] = (img->pixelData[i][j] == 'X') ? 'Y' : 'Z'; // Switch from X -> Y and O -> Z
        }
    }
    printf("Funny filter added! Your picture has transformed into a comedy sketch!\n");
}

void eraseFunnyFilter(Image *img) {
    printf("Removing the Funny Filter from '%s'... Back to business!\n", img->name);
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->pixelData[i][j] = (img->pixelData[i][j] == 'Y') ? 'X' : 'O'; // Switch back Y -> X and Z -> O
        }
    }
    printf("Funny filter removed! Your picture is now serious again...\n");
}

void thankUser() {
    printf("Thank you for using the Wacky Wonderland Image Editor! Your artistic journey is appreciated!\n");
}