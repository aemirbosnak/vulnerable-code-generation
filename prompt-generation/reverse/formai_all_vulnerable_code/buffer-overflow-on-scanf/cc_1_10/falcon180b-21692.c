//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 100
#define MAX_FILE_NAME_SIZE 1000

typedef struct {
    char key[MAX_KEY_SIZE];
    int key_size;
} Key;

int is_valid_key(char* key) {
    for (int i = 0; i < strlen(key); i++) {
        if (!isalpha(key[i])) {
            return 0;
        }
    }
    return 1;
}

int get_key(char* key) {
    int key_size = 0;
    printf("Enter key: ");
    scanf("%s", key);
    while (!is_valid_key(key)) {
        printf("Invalid key. Key must contain only alphabets.\n");
        printf("Enter key: ");
        scanf("%s", key);
    }
    return key_size;
}

void encrypt_file(char* input_file_name, char* output_file_name, Key key) {
    FILE* input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }
    FILE* output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }
    char ch;
    while ((ch = fgetc(input_file))!= EOF) {
        if (isalpha(ch)) {
            ch = (ch + key.key_size - 65) % 26 + 65;
        }
        fputc(ch, output_file);
    }
    fclose(input_file);
    fclose(output_file);
}

int main() {
    char key[MAX_KEY_SIZE];
    int key_size = get_key(key);
    printf("Enter input file name: ");
    scanf("%s", key);
    printf("Enter output file name: ");
    scanf("%s", key);
    encrypt_file(key, key, (Key) {.key = key,.key_size = key_size });
    printf("File encrypted successfully.\n");
    return 0;
}