//FormAI DATASET v1.0 Category: File Encyptor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 100
#define MAX_PASSWORD_LEN 50
#define MAX_BUFFER_SIZE 1024

void encrypt(FILE *input_file, FILE *output_file, char *password) {
    char c;
    int i = 0;
    int password_len = strlen(password);
    int j = 0;
    while ((c = fgetc(input_file)) != EOF) {
        if (i == password_len)
            i = 0;
        char encrypted_char = c ^ password[i];
        i++;
        fputc(encrypted_char, output_file);
        j++;
    }
}

void decrypt(FILE *input_file, FILE *output_file, char *password) {
    encrypt(input_file, output_file, password);
}

int main() {
    char input_file_name[MAX_FILE_NAME_LEN];
    char output_file_name[MAX_FILE_NAME_LEN];
    char password[MAX_PASSWORD_LEN];

    printf("Enter name of input file: ");
    scanf("%s", input_file_name);

    printf("Enter name of output file: ");
    scanf("%s", output_file_name);

    printf("Enter password: ");
    scanf("%s", password);

    FILE *input_file = fopen(input_file_name, "rb");
    FILE *output_file = fopen(output_file_name, "wb");

    if (input_file == NULL || output_file == NULL) {
        printf("Could not open file");
        exit(1);
    }

    encrypt(input_file, output_file, password);

    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully\n");

    return 0;
}