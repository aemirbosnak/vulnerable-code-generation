//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/md5.h>
#include <openssl/evp.h>

#define BLOCK_SIZE 1024
#define BLOCKS_PER_FILE 1000

int main() {
    // Open the original image file
    FILE* img_file = fopen("original_image.jpg", "rb");
    if (!img_file) {
        printf("Error opening the original image file.\n");
        return 1;
    }

    // Read the image file in blocks
    unsigned char block[BLOCK_SIZE];
    for (int i = 0; i < BLOCKS_PER_FILE; i++) {
        if (fread(block, 1, BLOCK_SIZE, img_file)!= BLOCK_SIZE) {
            printf("Error reading the image file.\n");
            return 1;
        }

        // Perform digital watermarking
        unsigned char* watermark = (unsigned char*)malloc(BLOCK_SIZE);
        memset(watermark, 0, BLOCK_SIZE);
        int j;
        for (j = 0; j < BLOCK_SIZE; j++) {
            watermark[j] = (BLOCK_SIZE - j) % 256;
        }

        // Hash the watermark
        EVP_MD_CTX* md_ctx = EVP_MD_CTX_new();
        EVP_DigestInit_ex(md_ctx, EVP_md5(), NULL);
        EVP_DigestUpdate(md_ctx, watermark, BLOCK_SIZE);
        unsigned char hash[EVP_MD_size(EVP_md5())];
        EVP_DigestFinal_ex(md_ctx, hash, NULL);

        // Insert the hash into the image block
        for (int k = 0; k < BLOCK_SIZE; k++) {
            block[k] = (block[k] & 0x0F) | (hash[k] & 0xF0);
        }

        // Write the modified block back to the image file
        if (fwrite(block, 1, BLOCK_SIZE, img_file)!= BLOCK_SIZE) {
            printf("Error writing the image file.\n");
            return 1;
        }
    }

    // Close the image file
    fclose(img_file);

    // Open the watermarked image file
    FILE* watermarked_img_file = fopen("watermarked_image.jpg", "wb");
    if (!watermarked_img_file) {
        printf("Error opening the watermarked image file.\n");
        return 1;
    }

    // Write the watermarked image to the file
    unsigned char* modified_block = (unsigned char*)malloc(BLOCK_SIZE);
    memset(modified_block, 0, BLOCK_SIZE);
    for (int i = 0; i < BLOCKS_PER_FILE; i++) {
        if (fread(modified_block, 1, BLOCK_SIZE, img_file)!= BLOCK_SIZE) {
            printf("Error reading the image file.\n");
            return 1;
        }
        for (int j = 0; j < BLOCK_SIZE; j++) {
            modified_block[j] = (modified_block[j] & 0xF0) | (block[j] & 0x0F);
        }
        if (fwrite(modified_block, 1, BLOCK_SIZE, watermarked_img_file)!= BLOCK_SIZE) {
            printf("Error writing the image file.\n");
            return 1;
        }
    }

    // Close the image file
    fclose(watermarked_img_file);
    fclose(img_file);

    printf("Digital watermarking example program in a decentralized style completed successfully.\n");
    return 0;
}