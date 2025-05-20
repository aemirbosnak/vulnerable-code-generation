//FormAI DATASET v1.0 Category: Image Editor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void menu();
void openImage();
void saveImage();
void resizeImage();
void rotateImage();
void invertImage();
void grayscaleImage();

int main()
{
    menu();
    return 0;
}

void menu()
{
    int choice;
    printf("*** Welcome to Brave Image Editor ***\n\n");
    printf("1. Open an Image\n");
    printf("2. Save the Image\n");
    printf("3. Resize the Image\n");
    printf("4. Rotate the Image\n");
    printf("5. Invert Colors\n");
    printf("6. Convert to Grayscale\n");
    printf("0. Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 0:
            printf("\nThank you for using Brave Image Editor.\n");
            break;
        case 1:
            openImage();
            break;
        case 2:
            saveImage();
            break;
        case 3:
            resizeImage();
            break;
        case 4:
            rotateImage();
            break;
        case 5:
            invertImage();
            break;
        case 6:
            grayscaleImage();
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            menu();
    }
}

void openImage()
{
    char filename[100];
    printf("\nEnter the filename of the image you want to open: ");
    scanf("%s", filename);
    printf("\nOpening %s...\n", filename);
    // code to open the image
    menu();
}

void saveImage()
{
    char filename[100];
    printf("\nEnter the filename you want to save the image as: ");
    scanf("%s", filename);
    printf("\nSaving the image as %s...\n", filename);
    // code to save the image
    menu();
}

void resizeImage()
{
    int newWidth, newHeight;
    printf("\nEnter the new width of the image: ");
    scanf("%d", &newWidth);
    printf("\nEnter the new height of the image: ");
    scanf("%d", &newHeight);
    printf("\nResizing the image to %dx%d...\n", newWidth, newHeight);
    // code to resize the image
    menu();
}

void rotateImage()
{
    int degrees;
    printf("\nEnter the number of degrees you want to rotate the image (90, 180, 270): ");
    scanf("%d", &degrees);
    printf("\nRotating the image by %d degrees...\n", degrees);
    // code to rotate the image
    menu();
}

void invertImage()
{
    printf("\nInverting the colors of the image...\n");
    // code to invert the colors of the image
    menu();
}

void grayscaleImage()
{
    printf("\nConverting the image to grayscale...\n");
    // code to convert the image to grayscale
    menu();
}