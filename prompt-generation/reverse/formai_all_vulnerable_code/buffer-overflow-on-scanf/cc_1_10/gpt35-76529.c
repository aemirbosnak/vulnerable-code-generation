//FormAI DATASET v1.0 Category: Image Steganography ; Style: decentralized
#include <stdio.h>

int main() {
    // define variables
    FILE *image_file, *secret_file, *output_file;
    char image_name[50], secret_name[50], output_name[50];
    unsigned char byte, image_data[1024], secret_data[1024], output_data[1024];
    int image_size, secret_size, output_size, i, j, n = 0;

    // get image name from user
    printf("Enter image file name (with ext): ");
    scanf("%s", image_name);

    // open image file
    image_file = fopen(image_name, "rb");

    // check if image file exists
    if (image_file == NULL) {
        printf("Unable to open image file.\n");
        return 1;
    }

    // get secret data name from user
    printf("Enter secret data file name (with ext): ");
    scanf("%s", secret_name);

    // open secret data file
    secret_file = fopen(secret_name, "rb");

    // check if secret data file exists
    if (secret_file == NULL) {
        printf("Unable to open secret data file.\n");
        return 1;
    }

    // get output name from user
    printf("Enter output image file name (with ext): ");
    scanf("%s", output_name);

    // read image data
    fseek(image_file, 0, SEEK_END);
    image_size = ftell(image_file);
    rewind(image_file);
    fread(image_data, 1, image_size, image_file);
    fclose(image_file);

    // read secret data
    fseek(secret_file, 0, SEEK_END);
    secret_size = ftell(secret_file);
    rewind(secret_file);
    fread(secret_data, 1, secret_size, secret_file);
    fclose(secret_file);

    // insert secret data into image data
    for (i = 0; i < image_size; i++) {
        byte = image_data[i];
        for (j = 0; j < 8; j++) {
            if (n < secret_size) {
                byte = (byte & 0xFE) | ((secret_data[n] >> j) & 0x01);
                n++;
            }
        }
        output_data[i] = byte;
    }

    // write output image file
    output_file = fopen(output_name, "wb");
    fwrite(output_data, 1, image_size, output_file);
    fclose(output_file);

    printf("Data hidden successfully.\n");

    return 0;
}