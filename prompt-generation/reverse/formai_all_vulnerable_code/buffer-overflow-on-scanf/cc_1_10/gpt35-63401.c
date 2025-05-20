//FormAI DATASET v1.0 Category: Image Editor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    int width, height;
    printf("Welcome to the Shape-Shifting Image Editor!\n\n");
    printf("Please select an operation:\n");
    printf("1. Resize the image\n");
    printf("2. Invert the colors\n");
    printf("3. Rotate the image\n");
    printf("4. Blur the image\n");
    printf("5. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            printf("Please enter the original width and height of the image: ");
            scanf("%d %d", &width, &height);
            printf("Please enter the new width and height of the image: ");
            int new_width, new_height;
            scanf("%d %d", &new_width, &new_height);
            // Code to resize image
            printf("Image resized successfully!\n");
            break;
        }
        case 2: {
            printf("Please enter the name of the image file to invert: ");
            char filename[256];
            scanf("%s", filename);
            // Code to read and invert image colors
            printf("Image inverted successfully!\n");
            break;
        }
        case 3: {
            printf("Please enter the name of the image file to rotate: ");
            char filename[256];
            scanf("%s", filename);
            printf("Please enter the number of degrees to rotate the image (90, 180, 270): ");
            int degrees;
            scanf("%d", &degrees);
            // Code to rotate image
            printf("Image rotated successfully!\n");
            break;
        }
        case 4: {
            printf("Please enter the name of the image file to blur: ");
            char filename[256];
            scanf("%s", filename);
            printf("Please enter the blur radius (1-10): ");
            int radius;
            scanf("%d", &radius);
            // Code to apply blur filter to image
            printf("Image blurred successfully!\n");
            break;
        }
        case 5: {
            printf("Goodbye!\n");
            exit(0);
        }
        default: {
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}