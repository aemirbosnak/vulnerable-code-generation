//FormAI DATASET v1.0 Category: File Encyptor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_BUFFER_SIZE 1024

void encryptFile(char* input_file, char* output_file, char* key) {
    FILE *fp_in, *fp_out;
    unsigned char buffer[MAX_BUFFER_SIZE];
    size_t bytes_read;
    int i, j;
    long key_len = strlen(key);

    fp_in = fopen(input_file, "rb");
    if (fp_in == NULL) {
        printf("[ERROR] Could not open file %s for reading.\n", input_file);
        exit(1);
    }

    fp_out = fopen(output_file, "wb");
    if (fp_out == NULL) {
        printf("[ERROR] Could not open file %s for writing.\n", output_file);
        exit(1);
    }

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), fp_in)) != 0) {
        for (i = 0, j = 0; i < bytes_read; ++i, ++j) {
            if (j == key_len) {
                j = 0;
            }
            buffer[i] ^= key[j];
        }
        fwrite(buffer, 1, bytes_read, fp_out);
    }

    fclose(fp_in);
    fclose(fp_out);

    printf("[INFO] %s has been encrypted and written to %s using key '%s'.\n", input_file, output_file, key);
}

int main() {
    char input_file[MAX_FILENAME_LENGTH], output_file[MAX_FILENAME_LENGTH], key[MAX_FILENAME_LENGTH];

    printf("Enter input file name: ");
    scanf("%s", input_file);

    printf("Enter output file name: ");
    scanf("%s", output_file);

    printf("Enter encryption key: ");
    scanf("%s", key);

    encryptFile(input_file, output_file, key);

    return 0;
}