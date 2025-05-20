//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the color codes for the image
#define BLACK 1
#define RED 2
#define GREEN 3
#define BLUE 4
#define YELLOW 5
#define CYAN 6
#define MAGENTA 7

// Define the size of the image
#define IMAGE_SIZE 10

// Define the RGB color of each pixel in the image
static const unsigned char rgb[] = {
	BLACK,
	RED,
	GREEN,
	BLUE,
	YELLOW,
	CYAN,
	MAGENTA
};

// Function to draw a pixel in the image
void drawPixel(int x, int y, int color) {
	// Get the RGB color of the pixel
	int r = rgb[color * 7 / 2];
	int g = rgb[color * 7 / 2 + 1];
	int b = rgb[color * 7 / 2 + 2];

	// Print the pixel to the screen
	printf("Pixel (%d, %d) is %d, %d, %d\n", x, y, r, g, b);
}

int main() {
	// Create an image of size IMAGE_SIZE x IMAGE_SIZE
	int image[IMAGE_SIZE][IMAGE_SIZE];

	// Draw a pixel in the top-left corner of the image
	drawPixel(0, 0, 0);

	// Draw a pixel in the top-right corner of the image
	drawPixel(0, IMAGE_SIZE - 1, 1);

	// Draw a pixel in the bottom-left corner of the image
	drawPixel(IMAGE_SIZE - 1, 0, 2);

	// Draw a pixel in the bottom-right corner of the image
	drawPixel(IMAGE_SIZE - 1, IMAGE_SIZE - 1, 3);

	// Draw a pixel in the center of the image
	drawPixel(IMAGE_SIZE / 2, IMAGE_SIZE / 2, 4);

	// Draw a pixel in the top-left corner of the image
	drawPixel(0, 0, 5);

	// Draw a pixel in the top-right corner of the image
	drawPixel(0, IMAGE_SIZE - 1, 6);

	// Draw a pixel in the bottom-left corner of the image
	drawPixel(IMAGE_SIZE - 1, 0, 7);

	// Draw a pixel in the bottom-right corner of the image
	drawPixel(IMAGE_SIZE - 1, IMAGE_SIZE - 1, 8);

	// Draw a pixel in the center of the image
	drawPixel(IMAGE_SIZE / 2, IMAGE_SIZE / 2, 9);

	return 0;
}