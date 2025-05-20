//FormAI DATASET v1.0 Category: Image Editor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// function to display the menu
void display_menu() {
    printf("----------------- Welcome to Image Editor --------------------\n");
    printf("Select an option from the following menu:\n");
    printf("1. Load image\n");
    printf("2. Crop image\n");
    printf("3. Rotate image\n");
    printf("4. Invert image\n");
    printf("5. Brighten image\n");
    printf("6. Darken image\n");
    printf("7. Save image\n");
    printf("8. Exit\n");
}

// function for loading image
void load_image(char* filename) {
    printf("Loading image from file %s...\n", filename);
    // actual code for loading image goes here
}

// function for cropping image
void crop_image() {
    printf("Cropping image...\n");
    // actual code for cropping image goes here
}

// function for rotating image
void rotate_image() {
    printf("Rotating image...\n");
    // actual code for rotating image goes here
}

// function for inverting image
void invert_image() {
    printf("Inverting image...\n");
    // actual code for inverting image goes here
}

// function for brightening image
void brighten_image() {
    printf("Brightening image...\n");
    // actual code for brightening image goes here
}

// function for darkening image
void darken_image() {
    printf("Darkening image...\n");
    // actual code for darkening image goes here
}

// function for saving image
void save_image() {
    printf("Saving image...\n");
    // actual code for saving image goes here
}

int main() {
    char filename[100];
    int option;

    while (1) {
        display_menu();
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter filename: ");
                scanf("%s", filename);
                load_image(filename);
                break;
            case 2:
                crop_image();
                break;
            case 3:
                rotate_image();
                break;
            case 4:
                invert_image();
                break;
            case 5:
                brighten_image();
                break;
            case 6:
                darken_image();
                break;
            case 7:
                save_image();
                break;
            case 8:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option selected. Please try again.\n");
        }
    }
    return 0;
}