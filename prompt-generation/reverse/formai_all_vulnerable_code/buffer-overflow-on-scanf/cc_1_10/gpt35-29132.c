//FormAI DATASET v1.0 Category: Image Editor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 100

void menu() {
    printf("--------------------\n");
    printf("|     MAIN MENU    |\n");
    printf("--------------------\n");
    printf("| 1. Load Image    |\n");
    printf("| 2. Crop Image    |\n");
    printf("| 3. Rotate Image  |\n");
    printf("| 4. Flip Image    |\n");
    printf("| 5. Save Image    |\n");
    printf("| 6. Exit          |\n");
    printf("--------------------\n");
}

void load_image(char *filename) {
    printf("Loading image from %s\n", filename);
    // Your image loading code here
}

void crop_image() {
    printf("Cropping image...\n");
    // Your image cropping code here
}

void rotate_image() {
    printf("Rotating image...\n");
    // Your image rotating code here
}

void flip_image() {
    printf("Flipping image...\n");
    // Your image flipping code here
}

void save_image(char *filename) {
    printf("Saving image to %s\n", filename);
    // Your image saving code here
}

int main() {
    int choice;
    char filename[MAX_FILENAME_SIZE];

    do {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter image filename: ");
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
                flip_image();
                break;
            case 5:
                printf("Enter image filename: ");
                scanf("%s", filename);
                save_image(filename);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);

    return 0;
}