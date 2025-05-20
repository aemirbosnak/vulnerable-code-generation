//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_LEN 100
#define MAX_FILE_NAME_LEN 1000
#define MAX_LINE_LEN 10000

typedef struct {
    char key[MAX_KEY_LEN];
    char file_name[MAX_FILE_NAME_LEN];
    char output_file_name[MAX_FILE_NAME_LEN];
    int key_len;
    int file_len;
} Config;

Config config;

void generate_key() {
    srand(time(NULL));
    for (int i = 0; i < MAX_KEY_LEN; i++) {
        char c = (char) (rand() % 26 + 'a');
        config.key[i] = c;
    }
    config.key_len = strlen(config.key);
}

void encrypt_file(FILE *fp_in, FILE *fp_out) {
    char c;
    char line[MAX_LINE_LEN];
    int line_len = 0;
    while ((c = fgetc(fp_in))!= EOF) {
        if (isalpha(c)) {
            c = (char) ((c - 'a' + config.key_len) % 26 + 'a');
        } else {
            c = c;
        }
        line[line_len++] = c;
        if (line_len == MAX_LINE_LEN - 1 || c == '\n') {
            line[line_len] = '\0';
            fprintf(fp_out, "%s", line);
            line_len = 0;
        }
    }
    if (line_len > 0) {
        line[line_len] = '\0';
        fprintf(fp_out, "%s", line);
    }
    fclose(fp_in);
    fclose(fp_out);
}

int main() {
    char file_name[MAX_FILE_NAME_LEN];
    char output_file_name[MAX_FILE_NAME_LEN];
    printf("Enter the file name to encrypt: ");
    scanf("%s", file_name);
    printf("Enter the output file name: ");
    scanf("%s", output_file_name);
    strcpy(config.file_name, file_name);
    strcpy(config.output_file_name, output_file_name);
    generate_key();
    FILE *fp_in = fopen(file_name, "r");
    if (fp_in == NULL) {
        printf("Error: file not found\n");
        return 1;
    }
    FILE *fp_out = fopen(output_file_name, "w");
    if (fp_out == NULL) {
        printf("Error: couldn't create output file\n");
        return 1;
    }
    encrypt_file(fp_in, fp_out);
    printf("File encrypted successfully\n");
    return 0;
}