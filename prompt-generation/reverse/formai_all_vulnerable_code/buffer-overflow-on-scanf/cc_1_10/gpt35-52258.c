//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: funny
#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("Welcome to the image processing tool!\n");
    printf("Please enter the name of the image file you want to edit: ");

    char filename[100];
    scanf("%s", filename);

    // Opening the given file
    FILE* file = fopen(filename, "r");

    if(file == NULL) {
        printf("Oops! Unable to open file. Please make sure the file exists.\n");
        printf("Tip: Make sure the file name is correct and the file is not currently in use!\n");
        exit(0);
    }
    else {
        printf("File opened successfully!\n");
        printf("Please enter the task you want to perform:\n");
        printf("1. Flip the image\n");
        printf("2. Change brightness\n");
        printf("3. Change contrast\n");
        printf("Enter your choice (1/2/3): ");

        int choice;
        scanf("%d", &choice);
        printf("\nWait...processing your request...\n");

        // Processing the given task
        switch(choice) {
            case 1:
                printf("Flipping image...\n");
                // Code to flip the image
                break;
            case 2:
                printf("Changing brightness...\n");
                // Code to change brightness
                break;
            case 3:
                printf("Changing contrast...\n");
                // Code to change contrast
                break;
            default:
                printf("Invalid choice. Try again!\n");
                break;
        }
    }

    printf("\nDone processing your request! Thank you for using our tool!\n");
    return 0;
}