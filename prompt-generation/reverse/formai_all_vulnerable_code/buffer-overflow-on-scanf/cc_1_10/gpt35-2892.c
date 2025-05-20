//FormAI DATASET v1.0 Category: Image Steganography ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *img, *secret, *output;
    char img_name[50], secret_name[50], output_name[50];
    int img_size, secret_size, i, j, k;
    printf("Enter the name of the image file: ");
    scanf("%s", img_name);
    printf("Enter the name of the secret file: ");
    scanf("%s", secret_name);
    printf("Enter the name of the output file: ");
    scanf("%s", output_name);

    // Open the image file in binary mode for reading
    img = fopen(img_name, "rb");
    if (!img) {
        printf("Failed to open image file.");
        return 1;
    }

    // Determine the size of the image file
    fseek(img, 0L, SEEK_END);
    img_size = ftell(img);
    fseek(img, 0L, SEEK_SET);

    // Open the secret file in binary mode for reading
    secret = fopen(secret_name, "rb");
    if (!secret) {
        printf("Failed to open secret file.");
        fclose(img);
        return 1;
    }

    // Determine the size of the secret file
    fseek(secret, 0L, SEEK_END);
    secret_size = ftell(secret);
    fseek(secret, 0L, SEEK_SET);

    // Check if the size of the secret file is too big to fit inside the image file
    if (secret_size > img_size / 8) {
        printf("Secret file is too big to fit inside the image file.");
        fclose(img);
        fclose(secret);
        return 1;
    }

    // Read the contents of the image file into a buffer
    char *img_buf = malloc(img_size);
    fread(img_buf, 1, img_size, img);

    // Read the contents of the secret file into a buffer
    char *secret_buf = malloc(secret_size);
    fread(secret_buf, 1, secret_size, secret);

    // Embed the secret message into the image buffer
    k = 0;
    for (i = 0; i < secret_size; i++) {
        char secret_byte = secret_buf[i];
        for (j = 0; j < 8; j++) {
            char img_byte = img_buf[k];
            int bit = (secret_byte >> j) & 1;
            img_buf[k++] = (img_byte & 0xFE) | bit;
        }
    }

    // Write the new image buffer to the output file
    output = fopen(output_name, "wb");
    fwrite(img_buf, 1, img_size, output);

    // Close all the files and free the buffers
    fclose(img);
    fclose(secret);
    fclose(output);
    free(img_buf);
    free(secret_buf);

    printf("Steganography completed successfully.");
    return 0;
}