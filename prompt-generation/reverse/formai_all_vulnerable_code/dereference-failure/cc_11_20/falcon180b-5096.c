//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000
#define KEY_SIZE 8

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 2;
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        return 3;
    }

    char key[KEY_SIZE];
    strcpy(key, argv[3]);

    int key_index = 0;
    int file_size = 0;
    char file_buffer[MAX_FILE_SIZE];
    char encrypted_buffer[MAX_FILE_SIZE];

    while (!feof(input_file)) {
        int bytes_read = fread(file_buffer, sizeof(char), MAX_FILE_SIZE, input_file);
        if (bytes_read == 0) {
            break;
        }

        for (int i = 0; i < bytes_read; i++) {
            char c = toupper(file_buffer[i]);
            if (isalpha(c)) {
                c = c + key_index % 26;
                if (!isalpha(c)) {
                    c = 'A';
                }
            } else if (isdigit(c)) {
                c = c + key_index % 10;
                if (!isdigit(c)) {
                    c = '0';
                }
            }

            encrypted_buffer[file_size] = c;
            file_size++;
        }

        fwrite(encrypted_buffer, sizeof(char), file_size, output_file);
        file_size = 0;

        key_index = (key_index + 1) % (KEY_SIZE * 2);
    }

    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully.\n");

    return 0;
}