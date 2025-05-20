//FormAI DATASET v1.0 Category: File Encyptor ; Style: scientific
#include <stdio.h>
#include <string.h>

#define MAX_FILE_SIZE 100000

int main(){

    char input_file_name[100];
    printf("Please enter input file name: ");
    scanf("%s", input_file_name);

    // Open input file for reading
    FILE *input_file = fopen(input_file_name, "rb");

    // Check if file exists
    if(input_file == NULL){
        printf("Error: File does not exist\n");
        return -1;
    }

    char output_file_name[100];
    printf("Please enter output file name: ");
    scanf("%s", output_file_name);

    // Open output file for writing
    FILE *output_file = fopen(output_file_name, "wb");

    // Read input file into buffer
    char buffer[MAX_FILE_SIZE];
    int num_bytes = fread(buffer, 1, MAX_FILE_SIZE, input_file);

    // XOR encryption key
    char key[] = "encrypt";

    // XOR encryption algorithm
    for(int i=0; i<num_bytes; i++){
        buffer[i] = buffer[i] ^ key[i % strlen(key)];
    }

    // Write encrypted data to output file
    fwrite(buffer, 1, num_bytes, output_file);

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    printf("Encryption complete, saved to %s\n", output_file_name);

    return 0;
}