//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256
#define MAX_FILE_NAME 50

void encrypt_char(char *input, int key) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            input[i] = (char)(((input[i] - 'a' + key) % 26) + 'a');
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] = (char)(((input[i] - 'A' + key) % 26) + 'A');
        }
    }
}

int main() {
    char input_file_name[MAX_FILE_NAME], output_file_name[MAX_FILE_NAME], key;
    FILE *input_file, *output_file;
    char file_content[MAX_CHAR];

    printf("Enter the name of the input file: ");
    scanf("%s", input_file_name);
    printf("Enter the name of the output file: ");
    scanf("%s", output_file_name);
    printf("Enter the key value: ");
    scanf("%d", &key);

    input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    fread(file_content, sizeof(char), MAX_CHAR, input_file);
    encrypt_char(file_content, key);
    fwrite(file_content, sizeof(char), strlen(file_content), output_file);

    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully.\n");

    return 0;
}