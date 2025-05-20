//FormAI DATASET v1.0 Category: File Encyptor ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILENAME_LEN 256
#define MAX_KEY_LEN 32

int main(int argc, char *argv[]){
    char input_filename[MAX_FILENAME_LEN], output_filename[MAX_FILENAME_LEN];
    char key[MAX_KEY_LEN];
    FILE *input_file_ptr, *output_file_ptr;
    size_t bytes_read;
    int i;

    /* Retrieve input filename from user */
    printf("Enter input filename: ");
    scanf("%s", input_filename);

    /* Retrieve output filename from user */
    printf("\nEnter output filename: ");
    scanf("%s", output_filename);

    /* Retrieve encryption key from user */
    printf("\nEnter encryption key: ");
    scanf("%s", key);

    /* Open input file in read mode */
    input_file_ptr = fopen(input_filename, "rb");
    if(input_file_ptr == NULL){
        printf("\nInput file could not be opened!");
        return 1;
    }

    /* Open output file in write mode */
    output_file_ptr = fopen(output_filename, "wb");
    if(output_file_ptr == NULL){
        printf("\nOutput file could not be opened!");
        fclose(input_file_ptr);
        return 1;
    }

    /* Read file in 512 byte chunks and encrypt the data */
    unsigned char buffer[512];
    while((bytes_read = fread(buffer, 1, 512, input_file_ptr)) > 0){
        for(i = 0; i < bytes_read; i++)
            buffer[i] ^= key[i % strlen(key)];
        fwrite(buffer, 1, bytes_read, output_file_ptr);
    }

    /* Close input and output files */
    fclose(input_file_ptr);
    fclose(output_file_ptr);

    printf("\nFile encryption successful!");

    return 0;
}