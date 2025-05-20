//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 1000
#define KEY_LENGTH 16

int main() {
    char file_name[MAX_FILE_NAME];
    char key[KEY_LENGTH];
    FILE *input_file, *output_file;
    int i, j, key_index;

    printf("Enter the file name: ");
    scanf("%s", file_name);

    printf("Enter the encryption key: ");
    scanf("%s", key);

    input_file = fopen(file_name, "rb");
    if (input_file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    output_file = fopen("encrypted_file.bin", "wb");
    if (output_file == NULL) {
        printf("Error: Could not create output file.\n");
        exit(1);
    }

    for (i = 0; i < strlen(file_name); i++) {
        if (file_name[i] == '.') {
            strcat(file_name, "_encrypted");
            break;
        }
    }

    printf("Encrypting file: %s\n", file_name);

    while ((fgetc(input_file))!= EOF) {
        key_index = 0;
        for (i = 0; i < strlen(file_name); i++) {
            if (file_name[i] == '.') {
                break;
            }
            key_index = (key_index + (int)file_name[i]) % KEY_LENGTH;
        }
        j = 0;
        while (j < strlen(key)) {
            key_index = (key_index + (int)key[j]) % KEY_LENGTH;
            j++;
        }
        fputc((int)fgetc(input_file) ^ (int)key[key_index], output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully.\n");

    return 0;
}