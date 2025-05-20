//FormAI DATASET v1.0 Category: Image Steganography ; Style: satisfied
#include<stdio.h>
#include<math.h>

int main()
{
    FILE *image, *image_out;
    char image_name[100], image_out_name[100], text_to_hide[5000], extract_text[5000];
    int width, height, bit_depth, total_pixels, size, i, j, k, index, count;
    int image_data[1000][1000], image_data_out[1000][1000], buffer[8], hidden_text_size, image_text_size;
    int x, y, hide_text_index, image_index, temp, image_char, binary_value, binary_index;
    int extracted_text_length, extracted_text_binary[100000], ascii_char, power, z;
    int hide_text_length_binary[32], hide_text_binary[1000000], hide_text_index_binary[32];
    int max_size, sum, max_size_binary[32], text_size_binary[32], temp_index, temp_binary;
    char hide_text_length_char[32], image_text_length_char[32];
    float mse, psnr;
    
    // Taking input of original image file name from user
    printf("Enter the name of the original image file (with extension): ");
    scanf("%s", image_name);
    
    // Reading original image file
    image = fopen(image_name, "r");
    
    // If file doesn't exist
    if(image == NULL)
    {
        printf("Error: File not found.");
        return 0;
    }
    
    // Reading image header information
    fscanf(image, "P3\n%d %d\n%d\n", &width, &height, &bit_depth);
    total_pixels = width * height;
    
    // Reading image pixel data
    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            fscanf(image, "%d %d %d", &image_data[i][j], &image_data[i][j+1],
            &image_data[i][j+2]);
        }
    }
    
    fclose(image);
    
    // Taking input of text to hide
    printf("\nEnter the text to hide (with less than 5000 characters)\n");
    getchar(); // To clear input buffer before getting new input
    scanf("%[^\n]s", text_to_hide);
    
    // Converting hide text size to binary
    i = 0;
    while(total_pixels > pow(2,i))
    {
        i++;
    }
    max_size = pow(2, i) - 1;
    size = strlen(text_to_hide);
    i = 0;
    while(size > pow(2,i))
    {
        i++;
    }
    if(i > log2(max_size))
    {
        printf("Error: Text too large to hide in the given image size.");
        return 0;
    }
    hide_text_length_binary[0] = i;
    for(j = 1; j < i+1; j++)
    {
        hide_text_length_binary[j] = size % 2;
        size = size / 2;
    }
    for(j = i+1; j < 32; j++)
    {
        hide_text_length_binary[j] = 0;
    }
    
    // Converting hide text to binary
    hide_text_index = 0;
    for(i = 0; i < strlen(text_to_hide); i++)
    {
        binary_value = (int)text_to_hide[i];
        for(j = 7; j >= 0; j--)
        {
            buffer[j] = binary_value % 2;
            binary_value = binary_value / 2;
        }
        for(j = 0; j < 8; j++)
        {
            hide_text_binary[hide_text_index] = buffer[j];
            hide_text_index++;
        }
    }
    hide_text_length_binary[0] = hide_text_length_binary[0] + 48;
    
    // Opening output file to write the stego image data
    printf("\nEnter the name of the output image file (with extension): ");
    scanf("%s", image_out_name);
    image_out = fopen(image_out_name, "w+");
    
    // Writing header information of the stego image file
    fprintf(image_out, "P3\n%d %d\n%d\n", width, height, bit_depth);
    
    // Hiding text in the image
    image_index = 0;
    hide_text_index = 0;
    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            if(hide_text_index < 32)
            {
                temp = hide_text_length_binary[hide_text_index];
                temp_binary = temp;
                temp_binary = temp_binary - 48;
                image_data_out[i][j] = image_data[i][j] - (image_data[i][j] % 2);
                image_data_out[i][j] = image_data_out[i][j] + temp_binary;
                hide_text_index++;
            }
            else if(hide_text_index >= 32 && hide_text_index < strlen(text_to_hide)*8+32)
            {
                temp_binary = hide_text_binary[hide_text_index-32];
                image_data_out[i][j] = image_data[i][j] - (image_data[i][j] % 2);
                image_data_out[i][j] = image_data_out[i][j] + temp_binary;
                hide_text_index++;
            }
            else
            {
                image_data_out[i][j] = image_data[i][j];
            }
            fprintf(image_out, "%d %d %d ", image_data_out[i][j], image_data_out[i][j+1],
            image_data_out[i][j+2]);
            j = j+2;
        }
        fprintf(image_out, "\n");
    }
    
    // Calculating PSNR value
    mse = 0;
    sum = 0;
    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            for(k = 0; k < 3; k++)
            {
                sum = sum + pow((image_data[i][j+k] - image_data_out[i][j+k]), 2);
            }
        }
    }
    mse = sum/(3 * total_pixels);
    psnr = 10 * log10(pow(bit_depth, 2)/mse);
    
    printf("\nData successfully hidden in the image.\n");
    printf("MSE: %f\n", mse);
    printf("PSNR: %f\n", psnr);
    
    fclose(image_out);
    
    // Extracting text from the stego image
    image_out = fopen(image_out_name, "r");
    fscanf(image_out, "P3\n%d %d\n%d\n", &width, &height, &bit_depth);
    total_pixels = width * height;
    image_text_size = 0;
    hide_text_index = 0;
    binary_index = 0;
    extracted_text_length = 0;
    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            if(hide_text_index < 32)
            {
                hide_text_length_char[hide_text_index] = image_data_out[i][j] % 2 + 48;
                hide_text_index++;
                if(hide_text_index == 32)
                {
                    hide_text_length_char[32] = '\0';
                    for(k = 31; k >= 0; k--)
                    {
                        hide_text_index_binary[binary_index] = hide_text_length_char[k] - 48;
                        binary_index++;
                    }
                }
            }
            else if(extracted_text_length < pow(2, hide_text_index_binary[0])-1 && hide_text_index >= 32)
            {
                image_char = image_data_out[i][j] % 2;
                extracted_text_binary[binary_index] = image_char;
                binary_index++;
                extracted_text_length = extracted_text_length + pow(2, binary_index-hide_text_index-binary_index-1)
                                         * image_char;
                if(extracted_text_length/8 > image_text_size)
                {
                    image_text_length_char[0] = extracted_text_length/8 + 48;
                    image_text_size++;
                    temp_index = image_text_size * 8 - 1;
                    for(k = temp_index; k >= (image_text_size-1)*8; k--)
                    {
                        image_text_length_char[k-(image_text_size-1)*8+1] = 
                        extracted_text_binary[k] + 48;
                    }
                }
                if(extracted_text_length/8 == image_text_size)
                {
                    temp_index = (image_text_size-1)*8;
                    text_size_binary[temp_index+binary_index-hide_text_index-binary_index] = 
                    extracted_text_binary[binary_index-1];
                }
            }
        }
    }
    fclose(image_out);
    
    // Converting extracted text size from binary to decimal
    for(i = 0; i < image_text_size*8; i++)
    {
        power = image_text_size*8 - i - 1;
        ascii_char = text_size_binary[i] * pow(2, power);
        image_text_size = image_text_size + ascii_char;
    }
    
    // Converting extracted text from binary to ASCII
    extract_text[0] = '\0'; 
    index = 0;
    count = 0;
    for(i = (hide_text_index+32)*3; i < height*width*3; i++)
    {
        if(count >= image_text_size)
        {
            break;
        }
        if((i-(hide_text_index+32)*3) % 8 == 0)
        {
            ascii_char = 0;
            for(j = i+7; j >= i; j--)
            {
                ascii_char = ascii_char + image_data_out[(j / (width*3))][(j % (width*3))/3] % 2 
                * pow(2, 7 - (j % 8)); 
            }
            if(ascii_char == '\0')
            {
                break;
            }
            extract_text[index] = ascii_char;
            index++;
            extract_text[index] = '\0';
            count++;
        }
    }
    
    printf("\nExtracted Text:\n%s", extract_text);
    
    return 0;
}