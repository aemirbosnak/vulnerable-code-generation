//FormAI DATASET v1.0 Category: File Encyptor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BUFFER_LENGTH 512

int main(int argc, char *argv[]) {
    char filename[MAX_FILENAME_LENGTH];
    char password[MAX_BUFFER_LENGTH];
    char confirm_password[MAX_BUFFER_LENGTH];
    FILE *fp_in, *fp_out;
    int password_match = 0;

    // Prompt for filename
    printf("Enter filename: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);

    // Remove newline character from filename
    filename[strlen(filename) - 1] = '\0';

    // Open input file for reading
    fp_in = fopen(filename, "rb");

    if (fp_in == NULL) {
        printf("Error: Could not open file %s for reading\n", filename);
        exit(1);
    }

    // Prompt for password and ensure it matches confirmation
    while (!password_match) {
        printf("Enter password: ");
        fgets(password, MAX_BUFFER_LENGTH, stdin);

        printf("Confirm password: ");
        fgets(confirm_password, MAX_BUFFER_LENGTH, stdin);

        // Remove newline characters from password and confirmation
        password[strlen(password) - 1] = '\0';
        confirm_password[strlen(confirm_password) - 1] = '\0';

        if (strcmp(password, confirm_password) == 0) {
            password_match = 1;
        } else {
            printf("Error: Passwords do not match\n");
        }
    }

    // Open output file for writing
    fp_out = fopen(strcat(filename, ".enc"), "wb");

    if (fp_out == NULL) {
        printf("Error: Could not open file %s for writing\n", filename);
        exit(1);
    }

    // Encrypt file by XOR-ing each byte with password character
    int password_length = strlen(password);
    unsigned char buffer[MAX_BUFFER_LENGTH];
    int bytes_read = 0;

    while ((bytes_read = fread(buffer, sizeof(char), MAX_BUFFER_LENGTH, fp_in)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            buffer[i] ^= password[i % password_length];
        }

        fwrite(buffer, sizeof(char), bytes_read, fp_out);
    }

    // Close files
    fclose(fp_in);
    fclose(fp_out);

    printf("File encrypted successfully!\n");

    return 0;
}