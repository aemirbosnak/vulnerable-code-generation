//FormAI DATASET v1.0 Category: Image Classification system ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the input image dimensions
#define IMG_HEIGHT 28
#define IMG_WIDTH 28
#define IMG_PIXELS (IMG_HEIGHT * IMG_WIDTH)

// define the number of output classes
#define NUM_CLASSES 10

int main()
{
    // create an array to hold the input image
    int image[IMG_PIXELS];
    
    // read in the input image file
    FILE *image_file = fopen("input_image.txt", "r");
    
    if (image_file == NULL)
    {
        printf("Error: Failed to open input image file\n");
        return 1;
    }
    
    for (int i = 0; i < IMG_PIXELS; i++)
    {
        fscanf(image_file, "%d", &image[i]);
    }
    
    fclose(image_file);
    
    // create an array to hold the output probabilities for each class
    double output_probs[NUM_CLASSES];
    
    // initialize the output probabilities to 0.0
    memset(output_probs, 0, sizeof(output_probs));
    
    // classify the input image
    for (int class = 0; class < NUM_CLASSES; class++)
    {
        for (int i = 0; i < IMG_PIXELS; i++)
        {
            if (image[i] == class)
            {
                output_probs[class]++;
            }
        }

        output_probs[class] /= IMG_PIXELS;
    }
    
    // print out the output probabilities
    printf("Output probabilities:\n");
    
    for (int class = 0; class < NUM_CLASSES; class++)
    {
        printf("    Class %d: %f\n", class, output_probs[class]);
    }
    
    // return success status
    return 0;
}