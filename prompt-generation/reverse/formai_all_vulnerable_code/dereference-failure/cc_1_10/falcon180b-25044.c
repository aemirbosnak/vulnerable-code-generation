//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main(int argc, char *argv[]) {
    FILE *file_in, *file_out;
    char filename[100];
    char ch;
    int key, i, j;
    time_t t;

    // Get the filename and key from the user
    printf("Enter the filename: ");
    scanf("%s", filename);
    printf("Enter the key: ");
    scanf("%d", &key);

    // Open the input file
    file_in = fopen(filename, "rb");
    if (file_in == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Get the size of the input file
    fseek(file_in, 0, SEEK_END);
    long filesize = ftell(file_in);
    rewind(file_in);

    // Allocate memory for the input file
    char *input = malloc(filesize + 1);
    if (input == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }

    // Read the input file into memory
    fread(input, 1, filesize, file_in);
    fclose(file_in);

    // Encrypt the input file
    for (i = 0; i < filesize; i++) {
        ch = input[i];
        if (isalpha(ch)) {
            ch = toupper(ch);
            ch = (ch + key - 65) % 26 + 65;
        }
        else if (isdigit(ch)) {
            ch = ch + key - 48;
        }
        else {
            ch = ch;
        }
        input[i] = ch;
    }

    // Save the encrypted file
    time(&t);
    sprintf(filename, "%s_%d_%ld.enc", filename, key, t);
    file_out = fopen(filename, "wb");
    if (file_out == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }
    fwrite(input, 1, filesize, file_out);
    fclose(file_out);

    // Free the memory
    free(input);

    printf("File encrypted and saved as %s.\n", filename);

    return 0;
}