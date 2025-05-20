//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: funny
#include<stdio.h>

int main(){

	printf("Welcome to the magical world of image processing! Let's have some fun.\n");
	
	// Reading image
	printf("Enter the name of the image file: ");
	char file[100];
	scanf("%s", file);
	printf("Reading image %s...\n", file);
	
	// Flipping image
	printf("Would you like to flip the image horizontally or vertically? Enter 'H' for horizontal and 'V' for vertical: ");
	char flip_dir;
	scanf(" %c", &flip_dir);
	if(flip_dir == 'H'){
		printf("Flipping image %s horizontally...\n", file);
		// TODO: Implement horizontal flipping of image
	}
	else if(flip_dir == 'V'){
		printf("Flipping image %s vertically...\n", file);
		// TODO: Implement vertical flipping of image
	}
	else{
		printf("Invalid direction entered. Continuing with original image.\n");
	}
	
	// Adjusting brightness
	printf("The image looks a bit dull. Let's brighten it up! Enter a value between 1-10 for brightness adjustment: ");
	int brightness;
	scanf("%d", &brightness);
	if(brightness < 1 || brightness > 10){
		printf("Invalid brightness value entered. Brightness adjustment set to default value of 5.\n");
		brightness = 5;
	}
	printf("Adjusting brightness of image %s...\n", file);
	// TODO: Implement brightness adjustment of image
	
	// Adjusting contrast
	printf("Let's give the image some more pop! Enter a value between 1-10 for contrast adjustment: ");
	int contrast;
	scanf("%d", &contrast);
	if(contrast < 1 || contrast > 10){
		printf("Invalid contrast value entered. Contrast adjustment set to default value of 5.\n");
		contrast = 5;
	}
	printf("Adjusting contrast of image %s...\n", file);
	// TODO: Implement contrast adjustment of image
	
	printf("All set! Check out the updated image file %s.\n", file);
	
	return 0;
}