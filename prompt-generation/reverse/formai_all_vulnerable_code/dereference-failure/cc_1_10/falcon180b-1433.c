//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char encrypted_file_name[MAX_FILE_NAME_LENGTH];
    char key[MAX_KEY_LENGTH];
} file_info;

void generate_key(char *key) {
    int i;
    for (i = 0; i < strlen(key); i++) {
        key[i] = tolower(key[i]);
    }
}

void encrypt_file(char *file_name, char *key) {
    FILE *input_file, *output_file;
    char ch;
    int i, j;

    input_file = fopen(file_name, "r");
    if (input_file == NULL) {
        printf("Error: File not found.\n");
        return;
    }

    output_file = fopen(file_name, "w");
    if (output_file == NULL) {
        printf("Error: File could not be opened for writing.\n");
        fclose(input_file);
        return;
    }

    for (i = 0; (ch = getc(input_file))!= EOF; i++) {
        ch = tolower(ch);
        j = 0;
        while (key[j]!= '\0') {
            if (ch == key[j]) {
                ch = 'a' + (j % 26);
            }
            j++;
        }
        fprintf(output_file, "%c", ch);
    }

    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <file_name> <key> <encrypted_file_name>\n", argv[0]);
        return 1;
    }

    file_info file_info;
    strcpy(file_info.file_name, argv[1]);
    strcpy(file_info.key, argv[2]);
    strcpy(file_info.encrypted_file_name, argv[3]);

    generate_key(file_info.key);
    encrypt_file(file_info.file_name, file_info.key);

    printf("File encrypted successfully.\n");
    printf("Encrypted file name: %s\n", file_info.encrypted_file_name);

    return 0;
}