//FormAI DATASET v1.0 Category: Image Editor ; Style: Alan Touring
#include <stdio.h>

// function declarations
void grayscale(int image[100][100], int rows, int cols);
void invert(int image[100][100], int rows, int cols);
void flip_horizontal(int image[100][100], int rows, int cols);
void flip_vertical(int image[100][100], int rows, int cols);

// main function
int main()
{
    int rows, cols, choice;
    int image[100][100];

    // take input from user - rows and columns of the image
    printf("Enter number of rows in the image: ");
    scanf("%d", &rows);
    printf("Enter number of columns in the image: ");
    scanf("%d", &cols);

    // take input from user - the image matrix
    printf("Enter the image matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &image[i][j]);
        }
    }

    // display menu to the user
    printf("\nImage Editor - Menu:\n");
    printf("1. Convert image to grayscale\n");
    printf("2. Invert the image\n");
    printf("3. Flip the image horizontally\n");
    printf("4. Flip the image vertically\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    // based on user choice, call respective function and display the result
    switch (choice)
    {
    case 1:
        grayscale(image, rows, cols);
        break;
    case 2:
        invert(image, rows, cols);
        break;
    case 3:
        flip_horizontal(image, rows, cols);
        break;
    case 4:
        flip_vertical(image, rows, cols);
        break;
    default:
        printf("Invalid choice.\n");
    }

    return 0;
}

// function to convert image to grayscale
void grayscale(int image[100][100], int rows, int cols)
{
    int gray_image[100][100];

    // convert each pixel to grayscale by taking average of RGB values
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int red = (image[i][j] >> 16) & 0xFF;
            int green = (image[i][j] >> 8) & 0xFF;
            int blue = image[i][j] & 0xFF;
            int gray = (red + green + blue) / 3;
            gray_image[i][j] = (gray << 16) + (gray << 8) + gray;
        }
    }

    // display the grayscale image
    printf("\nGrayscale Image:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%06X ", gray_image[i][j]);
        }
        printf("\n");
    }
}

// function to invert the image
void invert(int image[100][100], int rows, int cols)
{
    int inverted_image[100][100];

    // invert each pixel by subtracting its RGB value from 0xFFFFFF
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            inverted_image[i][j] = 0xFFFFFF - image[i][j];
        }
    }

    // display the inverted image
    printf("\nInverted Image:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%06X ", inverted_image[i][j]);
        }
        printf("\n");
    }
}

// function to flip the image horizontally
void flip_horizontal(int image[100][100], int rows, int cols)
{
    int flipped_image[100][100];

    // flip each row of the image to create horizontal flip
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            flipped_image[i][j] = image[i][cols - j - 1];
        }
    }

    // display the flipped image
    printf("\nHorizontally Flipped Image:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%06X ", flipped_image[i][j]);
        }
        printf("\n");
    }
}

// function to flip the image vertically
void flip_vertical(int image[100][100], int rows, int cols)
{
    int flipped_image[100][100];

    // flip each column of the image to create vertical flip
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            flipped_image[i][j] = image[rows - i - 1][j];
        }
    }

    // display the flipped image
    printf("\nVertically Flipped Image:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%06X ", flipped_image[i][j]);
        }
        printf("\n");
    }
}