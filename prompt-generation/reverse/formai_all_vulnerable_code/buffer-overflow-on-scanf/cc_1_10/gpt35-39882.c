//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to embed a digital watermark into an image */
void embed_watermark(char *image_file, char *watermark) {

    FILE* fp_read;
    FILE* fp_write;
    char *buffer;
    unsigned int image_length;
    unsigned int watermark_length;
    unsigned int i, j;

    /* Open the image file for reading in binary mode */
    fp_read = fopen(image_file, "rb");

    /* Calculate the length of the image file */
    fseek(fp_read, 0L, SEEK_END);
    image_length = ftell(fp_read);
    rewind(fp_read);

    /* Allocate memory to store the contents of the image file */
    buffer = (char*) malloc(image_length * sizeof(char));

    /* Read the contents of the image file into the buffer */
    fread(buffer, image_length, 1, fp_read);

    /* Close the image file */
    fclose(fp_read);

    /* Open the output file for writing in binary mode */
    fp_write = fopen("watermarked_image.bmp", "wb");

    /* Write the first 54 bytes of the image file to the output file */
    fwrite(buffer, 54, 1, fp_write);

    /* Get the length of the watermark */
    watermark_length = strlen(watermark);

    /* Embed the watermark into the image file */
    j=0;
    for (i=54; i<image_length; i+=3) {
        buffer[i] = buffer[i] ^ watermark[j % watermark_length];
        j++;
    }

    /* Write the contents of the buffer to the output file */
    fwrite(buffer, image_length, 1, fp_write);

    /* Close the output file */
    fclose(fp_write);

    /* Free the memory allocated for the buffer */
    free(buffer);

    printf("Watermark embedded successfully.\n");

}

/* Function to extract a digital watermark from an image */
void extract_watermark(char *image_file) {

    FILE* fp_read;
    char *buffer;
    unsigned int image_length;
    unsigned int i, j, k;
    char watermark[1000];

    /* Open the image file for reading in binary mode */
    fp_read = fopen(image_file, "rb");

    /* Calculate the length of the image file */
    fseek(fp_read, 0L, SEEK_END);
    image_length = ftell(fp_read);
    rewind(fp_read);

    /* Allocate memory to store the contents of the image file */
    buffer = (char*) malloc(image_length * sizeof(char));

    /* Read the contents of the image file into the buffer */
    fread(buffer, image_length, 1, fp_read);

    /* Close the image file */
    fclose(fp_read);

     j=0;
     k=0;
    for (i=54; i<image_length; i+=3) {
         int temp = buffer[i] ^ (rand() % 256);
         watermark[j++] = temp;
         k++;
         if (k == 1000)
             break;
     }
     watermark[j] = '\0';

     printf("The watermark embedded in the image is: %s\n", watermark);

    /* Free the memory allocated for the buffer */
    free(buffer);
}


int main(void) {

    char image_file[100];
    char watermark[1000];
    int choice;

    printf("Enter the name of the image file to be watermarked: ");
    scanf("%s", image_file);

    printf("Enter the digital watermark to be embedded: ");
    scanf("%s", watermark);

    while(1) {
        printf("\nSelect an option: \n");
        printf("[1] Embed Watermark\n");
        printf("[2] Extract Watermark\n");
        printf("[3] Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                embed_watermark(image_file, watermark);
                break;
            case 2:
                extract_watermark("watermarked_image.bmp");
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }
    }

    return 0;
}