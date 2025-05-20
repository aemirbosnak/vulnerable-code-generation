//FormAI DATASET v1.0 Category: File Encyptor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILE_NAME 100
#define MAX_BUFF_SIZE 1024

void encrypt(char file_name[MAX_FILE_NAME]){
    FILE *file_ptr;
    char *buffer;
    long file_size;

    // Open the input file and get its size
    file_ptr = fopen(file_name, "rb"); // Open file as binary read-only
    fseek(file_ptr, 0, SEEK_END); // Go to end of file
    file_size = ftell(file_ptr); // Get current position (which is the size of the file)
    rewind(file_ptr); // Go back to beginning of file
	
    // Allocate memory for the buffer that will hold the file contents
    buffer = (char*) malloc(file_size * sizeof(char));

    // Read file contents into buffer
    fread(buffer, sizeof(char), file_size, file_ptr);

    // Encrypt file contents using simple XOR encryption
    for(int i = 0; i < file_size; i++){
        buffer[i] ^= 0xFF; // XOR with mask FF
    }

    // Open output file for writing
    char encrypted_file_name[MAX_FILE_NAME];
    strcpy(encrypted_file_name, file_name);
    strcat(encrypted_file_name, ".enc");
    FILE *encrypted_file_ptr = fopen(encrypted_file_name, "wb"); // Open file as binary write-only

    // Write encrypted contents to output file
    fwrite(buffer, sizeof(char), file_size, encrypted_file_ptr);

    // Close files and free memory
    fclose(file_ptr);
    fclose(encrypted_file_ptr);
    free(buffer);

    printf("File successfully encrypted!\n");
}

void decrypt(char file_name[MAX_FILE_NAME]){
    FILE *file_ptr;
    char *buffer;
    long file_size;

    // Open the input file and get its size
    file_ptr = fopen(file_name, "rb"); // Open file as binary read-only
    fseek(file_ptr, 0, SEEK_END); // Go to end of file
    file_size = ftell(file_ptr); // Get current position (which is the size of the file)
    rewind(file_ptr); // Go back to beginning of file

    // Allocate memory for the buffer that will hold the file contents
    buffer = (char*) malloc(file_size * sizeof(char));

    // Read file contents into buffer
    fread(buffer, sizeof(char), file_size, file_ptr);

    // Decrypt file contents using simple XOR encryption
    for(int i = 0; i < file_size; i++){
        buffer[i] ^= 0xFF; // XOR with mask FF
    }

    // Open output file for writing
    char decrypted_file_name[MAX_FILE_NAME];
    strcpy(decrypted_file_name, file_name);
    strcat(decrypted_file_name, ".dec");
    FILE *decrypted_file_ptr = fopen(decrypted_file_name, "wb"); // Open file as binary write-only

    // Write decrypted contents to output file
    fwrite(buffer, sizeof(char), file_size, decrypted_file_ptr);

    // Close files and free memory
    fclose(file_ptr);
    fclose(decrypted_file_ptr);
    free(buffer);

    printf("File successfully decrypted!\n");
}

int main(){
    char file_name[MAX_FILE_NAME];
    int choice;
    printf("Enter file name: ");
    scanf("%s", file_name);
    printf("Choose an option:\n1.Encrypt\n2.Decrypt\n");
    scanf("%d", &choice);

    if(choice == 1){
        encrypt(file_name);
    }
    else if(choice == 2){
        decrypt(file_name);
    }
    else{
        printf("Invalid choice.\n");
    }

    return 0;
}