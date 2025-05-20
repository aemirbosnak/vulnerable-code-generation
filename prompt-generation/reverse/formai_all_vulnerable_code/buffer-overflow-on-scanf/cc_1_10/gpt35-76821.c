//FormAI DATASET v1.0 Category: File Encyptor ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILE_NAME_SIZE 100
#define MAX_BUFFER_SIZE 500

int main(){

    char input_file_name[MAX_FILE_NAME_SIZE];
    char output_file_name[MAX_FILE_NAME_SIZE];
    char encryption_key[MAX_BUFFER_SIZE];

    //Prompt user for input file name
    printf("Enter the name of the file to be encrypted: ");
    scanf("%s", input_file_name);

    //Prompt user for output file name
    printf("Enter the name of the output file: ");
    scanf("%s", output_file_name);

    //Prompt user for encryption key
    printf("Enter the encryption key: ");
    scanf("%s", encryption_key);

    //Open input file for reading
    FILE* input_file = fopen(input_file_name, "rb");
    if (input_file == NULL) {
        printf("Error opening file %s\n", input_file_name);
        return 1;
    }

    //Open output file for writing
    FILE* output_file = fopen(output_file_name, "wb");
    if (output_file == NULL) {
        printf("Error creating file %s\n", output_file_name);
        return 1;
    }

    //Read input file
    char buffer[MAX_BUFFER_SIZE];
    int bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), input_file)) > 0) {

        //Encrypt the buffer using the encryption key
        for (int i = 0; i < bytes_read; i++) {
            buffer[i] ^= encryption_key[i % strlen(encryption_key)];
        }

        //Write encrypted data to output file
        fwrite(buffer, 1, bytes_read, output_file);
    }

    //Close input and output files
    fclose(input_file);
    fclose(output_file);

    printf("File has been encrypted successfully\n");

    return 0;
}