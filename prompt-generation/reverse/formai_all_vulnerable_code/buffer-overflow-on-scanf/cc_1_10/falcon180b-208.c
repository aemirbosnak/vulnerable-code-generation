//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 16
#define MAX_FILE_SIZE 100000

void encrypt_file(FILE *input_file, FILE *output_file, char *key) {
    int key_index = 0, file_index = 0;
    char buffer[MAX_FILE_SIZE];
    while (fgets(buffer, MAX_FILE_SIZE, input_file)!= NULL) {
        for (int i = 0; i < strlen(buffer); i++) {
            if (buffer[i] == '\n') {
                fprintf(output_file, "%s\n", buffer);
                file_index = 0;
            }
            else {
                buffer[i] += key[key_index % strlen(key)];
                key_index++;
                file_index++;
            }
        }
    }
    if (file_index > 0) {
        fprintf(output_file, "%s", buffer);
    }
}

void decrypt_file(FILE *input_file, FILE *output_file, char *key) {
    int key_index = 0, file_index = 0;
    char buffer[MAX_FILE_SIZE];
    while (fgets(buffer, MAX_FILE_SIZE, input_file)!= NULL) {
        for (int i = 0; i < strlen(buffer); i++) {
            if (buffer[i] == '\n') {
                fprintf(output_file, "%s\n", buffer);
                file_index = 0;
            }
            else {
                buffer[i] -= key[key_index % strlen(key)];
                key_index++;
                file_index++;
            }
        }
    }
    if (file_index > 0) {
        fprintf(output_file, "%s", buffer);
    }
}

int main() {
    char input_file_name[100], output_file_name[100], key[MAX_KEY_LENGTH + 1];
    printf("Enter the name of the input file: ");
    scanf("%s", input_file_name);
    printf("Enter the name of the output file: ");
    scanf("%s", output_file_name);
    printf("Enter the encryption key (up to %d characters): ", MAX_KEY_LENGTH);
    scanf("%s", key);

    FILE *input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    encrypt_file(input_file, output_file, key);

    fclose(input_file);
    fclose(output_file);

    return 0;
}