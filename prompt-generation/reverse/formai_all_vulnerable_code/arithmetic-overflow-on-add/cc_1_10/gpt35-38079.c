//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: portable
#include<stdio.h>
#include<stdlib.h>

/* Struct to hold the watermark information */
typedef struct {
    char message[20];   // Message to be encoded as watermark
    int x_pos;          // X-coordinate of the watermark position
    int y_pos;          // Y-coordinate of the watermark position
} water_mark;

/* Definition of function to add watermark to the image */
void add_watermark(char* input_image, char* output_image, water_mark* wm);

/* Implementation of function to add watermark to the image */
void add_watermark(char* input_image, char* output_image, water_mark* wm)
{
    FILE* fp_in;        // Pointer to input image file
    FILE* fp_out;       // Pointer to output image file
    fp_in = fopen(input_image, "rb");   // Open input image file in read-binary mode
    fp_out = fopen(output_image, "wb"); // Open output image file in write-binary mode

    /* Read the header information of input image file and write to output image file */
    char header_buffer[54];
    fread(header_buffer, sizeof(char), 54, fp_in);
    fwrite(header_buffer, sizeof(char), 54, fp_out);

    /* Add the watermark message at the specified position */
    int i, j;
    char temp;  // Temporary variable to hold a single pixel value
    int count = 0;  // Counter variable for looping through the message characters
    while(count < sizeof(wm->message))
    {
        fseek(fp_in, (wm->y_pos*i + wm->x_pos)*3, SEEK_SET);  // Move the file pointer to the watermark position
        fread(&temp, sizeof(char), 1, fp_in);  // Read the pixel value at the watermark position
        temp = temp | (1<<7);   // Set the most significant bit of the pixel value to 1 to mark it as a watermark pixel
        fseek(fp_out, (wm->y_pos*i + wm->x_pos)*3, SEEK_SET); // Move the file pointer to the same position in output image file
        fwrite(&temp, sizeof(char), 1, fp_out); // Write the modified pixel value to the output image file
        i++;
        if(i > 640)
        {
            i = 0;
            j++;
        }
        if(j > 480)
            break;
    }

    /* Close the input and output image files */
    fclose(fp_in);
    fclose(fp_out);
}

/* Main function */
int main()
{
    water_mark wm = {"SAMPLE WATERMARK", 500, 200};  // Example watermark message and position
    char* input_image = "input.bmp";    // Example input image file path
    char* output_image = "output.bmp";  // Example output image file path
    add_watermark(input_image, output_image, &wm);   // Add watermark to input image and save as output image
    return 0;
}