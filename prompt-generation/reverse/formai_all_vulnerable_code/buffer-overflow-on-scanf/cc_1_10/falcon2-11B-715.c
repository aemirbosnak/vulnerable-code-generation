//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int main() {
    // Read input file name
    char input_filename[100];
    printf("Enter input file name: ");
    scanf("%s", input_filename);

    // Open input file
    FILE *input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Read input file data
    unsigned char buffer[1024];
    int bytes_read = fread(buffer, 1, sizeof(buffer), input_file);
    if (bytes_read == 0) {
        printf("Error reading input file.\n");
        fclose(input_file);
        return 1;
    }

    // Encrypt data using SHA-256
    unsigned char encrypted_data[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, buffer, bytes_read);
    SHA256_Final(encrypted_data, &sha256);

    // Write encrypted data to output file
    char output_filename[100];
    printf("Enter output file name: ");
    scanf("%s", output_filename);
    FILE *output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }
    fwrite(encrypted_data, 1, SHA256_DIGEST_LENGTH, output_file);
    fclose(output_file);

    // Clean up
    fclose(input_file);

    printf("Encryption complete.\n");
    return 0;
}