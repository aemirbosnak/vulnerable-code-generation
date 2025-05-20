//FormAI DATASET v1.0 Category: Image Steganography ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define BYTES_PER_PIXEL 3 //RGB values

int main() {
    char image_name[30], message[1000], ch;
    int img_size, bit_message_size, message_size, i, j, k, index_message = 0;
    FILE *img_pointer, *steganographic_img;
    unsigned char *image_data, *new_image_data;
    long int image_height, image_width;
    
    printf("Enter the name of image file: ");
    scanf("%s", image_name);
    
    printf("Enter the message to hide within image: ");
    scanf("%s", message);
    
    img_pointer = fopen(image_name, "rb");
    if(img_pointer == NULL) {
        printf("Error in opening the file");
        exit(1);
    }
    
    fseek(img_pointer, 0, SEEK_END);
    img_size = ftell(img_pointer);
    fseek(img_pointer, 0, SEEK_SET);
    
    image_data = (unsigned char*)malloc(img_size);
    new_image_data = (unsigned char*)malloc(img_size);
    fread(image_data, sizeof(unsigned char), img_size, img_pointer);
    fclose(img_pointer);
    
    printf("\nImage '%s' opened successfully of size %d bytes\n", image_name, img_size);
    
    printf("\nEnter the bit message size for steganography: ");
    scanf("%d", &bit_message_size);
    
    message_size = strlen(message);
    if(bit_message_size < message_size * 8) {
        printf("Message size is larger than steganographic bit size");
        exit(1);
    }

    for(i = 0; i < img_size; i++) {
        new_image_data[i] = image_data[i];
    }
    
    for(i = 0; i < img_size && index_message < message_size; i += BYTES_PER_PIXEL) {
        for(j = 0; j < BYTES_PER_PIXEL && index_message < message_size; j++) {
            ch = message[index_message];
            for(k = 0; k < bit_message_size; k++) {
                if(((ch >> k) & 1) == 1) {
                    new_image_data[i+j] |= 1 << k;
                }
                else{
                    new_image_data[i+j] &= ~(1 << k);
                }
                
            }
            index_message++;
        }
    }
    
    steganographic_img = fopen("steganographic_image.bmp", "wb");
    fwrite(new_image_data, sizeof(unsigned char), img_size, steganographic_img);
    fclose(steganographic_img);
    free(image_data);
    free(new_image_data);
    
    printf("\nSteganographic image created and stored as 'steganographic_image.bmp'\n");
    printf("\nThe hidden message was: %s\n", message);
    return 0;
}