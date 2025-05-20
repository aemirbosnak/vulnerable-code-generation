//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: satisfied
#include <stdio.h>

#define MAX_PIXEL_VALUE 255

int main(){
    int width, height, max;
    char magic_number[3];
    
    printf("Please Enter the Image Width: ");
    scanf("%d", &width);
    printf("Please Enter the Image Height: ");
    scanf("%d", &height);
    printf("Please Enter the Maximum Pixel Value: ");
    scanf("%d", &max);
    printf("Please Enter the Image Magic Number (P5/P6): ");
    scanf("%s", magic_number);
    
    if (width <= 0 || height <= 0 || max <= 0 || max > MAX_PIXEL_VALUE){
        printf("Invalid Input! Please make sure all input values are greater than 0 and maximum pixel value is between 0 and %d.\n", MAX_PIXEL_VALUE);
        return 0;
    }
    
    // Allocate memory for image data
    unsigned char *img_data = (unsigned char*) calloc(width * height * 3, sizeof(unsigned char));
    
    // Read Image Data from File
    int pixel;
    for (int i=0;i<width*height*3;i++){
        if (magic_number[1] == '5'){
            // For P5 Images (Grayscale)
            pixel = fgetc(stdin);
            img_data[i] = pixel;
        }
        else if (magic_number[1] == '6'){
            // For P6 Images (RGB)
            pixel = fgetc(stdin);
            img_data[i] = pixel;
        }
        else{
            printf("Invalid Input! Please make sure the Image Magic Number is P5 or P6.\n");
            return 0;
        }
    }
    
    // Flip Image
    printf("Flipping the Image...\n");
    for (int j=0;j<height;j++){
        for (int i=0;i<width;i++){
            for (int channel=0;channel<3;channel++){
                int idx = (j*width + i)*3 + channel;
                int flipped_idx = ((height-j-1)*width + i)*3 + channel;
                unsigned char temp = img_data[idx];
                img_data[idx] = img_data[flipped_idx];
                img_data[flipped_idx] = temp;
            }
        }
    }
    
    // Change Brightness and Contrast
    float brightness_change, contrast_change;
    printf("Enter Brightness Change (-255 to 255): ");
    scanf("%f", &brightness_change);
    printf("Enter Contrast Change (0 to 10): ");
    scanf("%f", &contrast_change);
    
    printf("Adjusting Image Brightness and Contrast...\n");
    for (int i=0;i<width*height*3;i++){
        float pixel_normalized = img_data[i]/(float)max;
        
        // Adjust Brightness
        pixel_normalized += brightness_change/255.0;
        
        // Adjust Contrast
        pixel_normalized -= 0.5; // Make the midpoint 0
        pixel_normalized *= contrast_change;
        pixel_normalized += 0.5;
        
        // Clamp pixel value between 0 and 1
        pixel_normalized = pixel_normalized < 0 ? 0 : pixel_normalized > 1 ? 1 : pixel_normalized;
        img_data[i] = (unsigned char)(pixel_normalized * max);
    }
    
    // Write Image Data to File
    printf("Writing Data to File...\n");
    printf("P%s\n", magic_number+1);
    printf("%d %d\n", width, height);
    printf("%d\n", max);
    fwrite(img_data, sizeof(unsigned char), width*height*3, stdout);
    
    // Free memory
    free(img_data);
    
    return 0;
}