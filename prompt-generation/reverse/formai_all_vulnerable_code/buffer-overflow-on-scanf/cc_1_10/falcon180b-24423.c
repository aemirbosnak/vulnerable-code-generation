//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 10
#define MAX_FILE_LENGTH 100
#define NUM_ROUNDS 10

void encrypt(char *key, char *file, char *output) {
    FILE *fp;
    char line[MAX_FILE_LENGTH];
    char encrypted_line[MAX_FILE_LENGTH];
    int i, j, len, key_index;

    fp = fopen(file, "r");
    if (fp == NULL) {
        printf("Error: File %s not found.\n", file);
        exit(1);
    }

    fseek(fp, 0, SEEK_SET);
    while (fgets(line, MAX_FILE_LENGTH, fp)!= NULL) {
        len = strlen(line);
        for (i = 0; i < len; i++) {
            if (isalpha(line[i])) {
                line[i] = tolower(line[i]);
            }
        }
        key_index = 0;
        for (i = 0; i < len; i++) {
            j = line[i] - 'a';
            j = (j + key[key_index] - 'a') % 26;
            if (isalpha(line[i])) {
                encrypted_line[i] = j + 'a';
            } else {
                encrypted_line[i] = line[i];
            }
            key_index = (key_index + 1) % MAX_KEY_LENGTH;
        }
        encrypted_line[len] = '\0';
        fputs(encrypted_line, output);
    }

    fclose(fp);
    fclose(output);
}

int main() {
    char key[MAX_KEY_LENGTH];
    char file[MAX_FILE_LENGTH];
    char output[MAX_FILE_LENGTH];
    int i;

    printf("Enter the file name: ");
    scanf("%s", file);

    printf("Enter the key (up to %d characters): ", MAX_KEY_LENGTH);
    scanf("%s", key);

    strcat(file, ".enc");
    strcat(output, ".dec");

    encrypt(key, file, output);

    printf("Encryption completed.\n");
    printf("The encrypted file is %s.\n", output);

    return 0;
}