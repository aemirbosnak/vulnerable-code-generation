//FormAI DATASET v1.0 Category: File Encyptor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_SIZE 100
#define MAX_BUFFER_SIZE 1024

int main() {
    char file_name[MAX_FILE_NAME_SIZE];
    char buffer[MAX_BUFFER_SIZE];
    int key;
    int i, n, c;

    printf("Welcome to the ultimate File Encryptor!\n");
    printf("Please enter the name of the file you would like to encrypt: ");
    scanf("%s", file_name);

    FILE *fp;
    fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("Could not open file.\n");
        exit(1);
    }

    printf("Please enter a key value for encryption: ");
    scanf("%d", &key);

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a random string of characters to prepend to the original file name
    char random_string[10];
    for (i = 0; i < 10; i++) {
        random_string[i] = (char) (rand() % 26 + 65); // generate a random uppercase letter
    }

    // Create a new file with the encrypted contents
    char new_file_name[MAX_FILE_NAME_SIZE];
    strcpy(new_file_name, random_string);
    strcat(new_file_name, "-encrypted-");
    strcat(new_file_name, file_name);

    FILE *fp_encrypted;
    fp_encrypted = fopen(new_file_name, "wb");

    while ((n = fread(buffer, 1, MAX_BUFFER_SIZE, fp)) > 0) {

        // Encrypt the buffer
        for (i = 0; i < n; i++) {
            buffer[i] = buffer[i] ^ key;
        }

        // Write the encrypted buffer to the new file
        fwrite(buffer, 1, n, fp_encrypted);
    }

    // Close the files
    fclose(fp);
    fclose(fp_encrypted);

    printf("File successfully encrypted as %s!\n", new_file_name);

    return 0;
}