//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_FILE_NAME_LENGTH 1000
#define MAX_LINE_LENGTH 1000

void encrypt(FILE *input_file, FILE *output_file, char *key) {
    char input_buffer[MAX_LINE_LENGTH];
    char output_buffer[MAX_LINE_LENGTH];
    int key_index = 0;
    while (fgets(input_buffer, MAX_LINE_LENGTH, input_file)!= NULL) {
        int input_buffer_length = strlen(input_buffer);
        int output_buffer_index = 0;
        for (int i = 0; i < input_buffer_length; i++) {
            char c = input_buffer[i];
            if (isalpha(c)) {
                c = toupper(c);
                c = (c - 65 + key_index) % 26 + 65;
            }
            output_buffer[output_buffer_index++] = c;
        }
        output_buffer[output_buffer_index] = '\0';
        fputs(output_buffer, output_file);
        if (key_index < strlen(key) - 1) {
            key_index++;
        } else {
            key_index = 0;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return 1;
    }
    char input_file_name[MAX_FILE_NAME_LENGTH];
    strcpy(input_file_name, argv[1]);
    FILE *input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error opening %s\n", input_file_name);
        return 1;
    }
    char output_file_name[MAX_FILE_NAME_LENGTH];
    strcpy(output_file_name, argv[2]);
    FILE *output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error opening %s\n", output_file_name);
        return 1;
    }
    char key[MAX_KEY_LENGTH];
    strcpy(key, argv[3]);
    encrypt(input_file, output_file, key);
    fclose(input_file);
    fclose(output_file);
    return 0;
}