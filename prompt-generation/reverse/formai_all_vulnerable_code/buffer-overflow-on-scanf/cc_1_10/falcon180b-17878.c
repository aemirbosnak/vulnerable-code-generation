//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_LEN 100
#define MAX_FILE_LEN 1000000

// Function to encrypt a single character
char encrypt(char c, char key) {
    if (isalpha(c)) {
        if (isupper(c)) {
            return ((c + key - 65) % 26) + 65;
        } else {
            return ((c + key - 97) % 26) + 97;
        }
    } else {
        return c;
    }
}

// Function to decrypt a single character
char decrypt(char c, char key) {
    if (isalpha(c)) {
        if (isupper(c)) {
            return ((c - key - 65) % 26) + 65;
        } else {
            return ((c - key - 97) % 26) + 97;
        }
    } else {
        return c;
    }
}

int main() {
    char filename[MAX_FILE_LEN];
    char key[MAX_KEY_LEN];
    char buffer[MAX_FILE_LEN];
    FILE *file, *output_file;
    int c, i, j;

    // Get the filename and key from the user
    printf("Enter the filename: ");
    scanf("%s", filename);
    printf("Enter the encryption key: ");
    scanf("%s", key);

    // Open the input file and output file
    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }
    output_file = fopen("encrypted_file.txt", "wb");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(file);
        return 1;
    }

    // Encrypt the file contents and write to output file
    while ((c = fgetc(file))!= EOF) {
        buffer[i++] = encrypt(c, key[j % strlen(key)]);
        j++;
    }
    fwrite(buffer, i, 1, output_file);

    // Close the input and output files
    fclose(file);
    fclose(output_file);

    printf("File encrypted successfully!\n");
    return 0;
}