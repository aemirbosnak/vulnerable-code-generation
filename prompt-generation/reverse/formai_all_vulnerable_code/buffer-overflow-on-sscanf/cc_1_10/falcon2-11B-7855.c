//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char filename[100];
    char encrypted_filename[100];
    int key;

    printf("Enter the name of the file to encrypt: ");
    fgets(filename, sizeof(filename), stdin);

    // Get the encryption key from user
    printf("Enter the encryption key: ");
    fgets(encrypted_filename, sizeof(encrypted_filename), stdin);

    if(sscanf(encrypted_filename, "%d", &key)!= 1) {
        printf("Invalid key format!\n");
        return 1;
    }

    // Open the file to be encrypted
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Allocate memory for the encrypted file name
    char *encrypted_file_name = (char*)malloc(sizeof(char) * (strlen(filename) + 1));
    if(encrypted_file_name == NULL) {
        printf("Memory allocation failed!\n");
        fclose(file);
        return 1;
    }

    // Read the file to be encrypted line by line
    while(fgets(filename, sizeof(filename), file)!= NULL) {
        // Read characters from the line
        char line[100];
        strncpy(line, filename, sizeof(line));
        line[strcspn(line, "\n")] = '\0';

        // Encrypt each character by adding the key
        for(int i = 0; i < strlen(line); i++) {
            char c = line[i];
            line[i] = (char)((c + key) % 256);
        }

        // Write the encrypted line to the encrypted file
        fputs(line, encrypted_file_name);
    }

    // Close the file being encrypted
    fclose(file);

    // Free the memory allocated for the encrypted file name
    free(encrypted_file_name);

    // Display a success message
    printf("File encrypted successfully!\n");

    return 0;
}