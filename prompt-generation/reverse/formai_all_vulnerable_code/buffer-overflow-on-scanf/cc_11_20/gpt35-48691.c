//FormAI DATASET v1.0 Category: Data recovery tool ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define FILENAME_SIZE 100
#define NOT_FOUND "File not found."

int main()
{
    char filename[FILENAME_SIZE], signature[BLOCK_SIZE], magic_no[9];
    int file_size, block_count = 0, block_found = 0;

    printf("Enter the file name: ");
    scanf("%s", filename);

    FILE *input = fopen(filename, "r");
    if (input == NULL) {
        printf("%s", NOT_FOUND);
        return 1;
    }

    while (!feof(input)) {
        if (block_found) {
            break;
        }

        fread(signature, BLOCK_SIZE, 1, input);

        if (feof(input)) {
            break;
        }

        if (signature[0] == 'C' && signature[1] == 'D') {
            memcpy(magic_no, signature + 512 - 8, 8);
            if (strcmp(magic_no, "CDRECOVERY") == 0) {
                block_found = 1;
            }
        }

        block_count++;
    }

    fclose(input);

    if (!block_found) {
        printf("CD Recovery signature not found.\n");
        return 1;
    }

    printf("CD Recovery signature found in block %d\n", block_count);

    printf("Enter file size in bytes: ");
    scanf("%d", &file_size);

    int num_blocks = file_size / BLOCK_SIZE + 1;

    FILE *output = fopen("recovered_file.txt", "wb");
    if (output == NULL) {
        printf("Error creating output file.");
        return 1;
    }

    input = fopen(filename, "r");
    if (input == NULL) {
        printf("%s", NOT_FOUND);
        return 1;
    }

    fseek(input, (block_count - num_blocks) * BLOCK_SIZE, SEEK_SET);

    for (int i = 0; i < num_blocks; i++) {
        fread(signature, BLOCK_SIZE, 1, input);
        fwrite(signature, BLOCK_SIZE, 1, output);
    }

    fclose(input);
    fclose(output);

    printf("File recovered successfully.\n");

    return 0;
}