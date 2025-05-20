//FormAI DATASET v1.0 Category: Image Steganography ; Style: calm
#include<stdio.h>

int main()
{
    char input_file[100], output_file[100], message[1000];
    FILE *in_file, *out_file;
    int image_size, message_size, i, j, lsb, count = 0, check = 0;

    //Take user input for input file name
    printf("Enter the input image file name: ");
    scanf("%s", input_file);

    //Open the input file in binary read mode
    in_file = fopen(input_file, "rb");

    //Check if file exists or not
    if(in_file == NULL)
    {
        printf("Error! %s file not found.\n", input_file);
        return 1;
    }

    //Take user input for message to be hidden
    printf("Enter the message to be hidden: ");
    scanf(" %[^\n]s", message);

    //Calculate the size of the message in bits
    message_size = strlen(message)*8;

    //Get the size of the input image
    fseek(in_file, 0, SEEK_END);
    image_size = ftell(in_file);
    rewind(in_file);

    //Check if the message can fit in the image or not
    if(image_size < message_size)
    {
        printf("Error! The message is too large to be hidden in this image.\n");
        return 1;
    }

    //Take user input for output file name
    printf("Enter the output image file name: ");
    scanf("%s", output_file);

    //Open the output file in binary write mode
    out_file = fopen(output_file, "wb");

    //Copy the first 54 bytes of input image header to the output image
    for(i = 0; i < 54; i++)
    {
        fputc(fgetc(in_file), out_file);
    }

    //Hide the message in the LSBs of the image pixels
    for(i = 54; i < image_size; i++)
    {
        lsb = message[count] & (1 << check); //Get the LSB of the character
        lsb = lsb >> check; //Shift the LSB to the rightmost bit
        j = fgetc(in_file); //Get the next pixel value from input image
        j = (j & 0xFE) | lsb; //Hide the LSB in the pixel value
        fputc(j, out_file); //Write the modified pixel value to output image
        check++;
        if(check == 8)
        {
            count++;
            check = 0;
        }
        if(count == strlen(message))
        {
            break;
        }
    }

    //Copy the rest of the input image to the output image
    while((j = fgetc(in_file)) != EOF)
    {
        fputc(j, out_file);
    }

    //Close both files
    fclose(in_file);
    fclose(out_file);

    printf("Message hidden successfully in %s file.\n", output_file);

    return 0;
}