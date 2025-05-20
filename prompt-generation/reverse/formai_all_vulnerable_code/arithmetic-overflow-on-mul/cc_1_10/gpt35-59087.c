//FormAI DATASET v1.0 Category: Image Editor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the amazing C Image Editor program!\n");
    printf("Please enter the name of your input file:\n");

    char input_file[100];
    scanf("%s", input_file);

    FILE* input_ptr = fopen(input_file, "rb");

    if (input_ptr == NULL) {
        printf("Error: Cannot open input file.\n");
        return 1;
    }

    printf("Please enter the name of your output file:\n");

    char output_file[100];
    scanf("%s", output_file);

    FILE* output_ptr = fopen(output_file, "wb");

    if (output_ptr == NULL) {
        printf("Error: Cannot open output file.\n");
        return 1;
    }

    // Read the header of the input file
    unsigned char header_info[54];
    fread(header_info, sizeof(unsigned char), 54, input_ptr);

    // Modify the header if necessary

    // Read the image data
    int width = *(int*)&header_info[18];
    int height = *(int*)&header_info[22];
    int bit_depth = *(int*)&header_info[28];

    int size = width * height * bit_depth / 8;
    unsigned char* image_data = (unsigned char*)malloc(size);

    fread(image_data, sizeof(unsigned char), size, input_ptr);

    // Edit the image_data here

    // Write the header and image data to the output file
    fwrite(header_info, sizeof(unsigned char), 54, output_ptr);
    fwrite(image_data, sizeof(unsigned char), size, output_ptr);

    fclose(input_ptr);
    fclose(output_ptr);

    printf("Your image has been successfully edited and saved to %s!\n", output_file);

    return 0;
}