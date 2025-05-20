//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000
#define KEY_SIZE 10

char *encrypt(char *text, char *key);
char *decrypt(char *text, char *key);

int main() {
    char input[MAX_SIZE];
    char key[KEY_SIZE];
    char choice;
    FILE *file;
    char *result;
    int len;

    printf("Welcome to the File Encryptor!\n");
    printf("Please enter the file name: ");
    scanf("%s", input);

    file = fopen(input, "r");
    if (file == NULL) {
        printf("Error: file not found!\n");
        exit(1);
    }

    printf("Please enter the encryption key: ");
    scanf("%s", key);

    result = (char *) malloc(MAX_SIZE);
    len = 0;

    while ((choice = fgetc(file))!= EOF) {
        if (isalpha(choice)) {
            choice = toupper(choice);
            choice = (char) (choice + (int) key[len % KEY_SIZE] - 65);
            result[len++] = choice;
        } else {
            result[len++] = choice;
        }
    }

    fclose(file);
    result[len] = '\0';

    printf("Encrypted file:\n%s\n", result);

    return 0;
}

char *encrypt(char *text, char *key) {
    int i;
    char *result = (char *) malloc(strlen(text) + 1);

    for (i = 0; text[i]!= '\0'; i++) {
        if (isalpha(text[i])) {
            text[i] = toupper(text[i]);
            text[i] = (char) (text[i] + (int) key[i % strlen(key)] - 65);
        }
    }

    strcpy(result, text);

    return result;
}

char *decrypt(char *text, char *key) {
    int i;
    char *result = (char *) malloc(strlen(text) + 1);

    for (i = 0; text[i]!= '\0'; i++) {
        if (isalpha(text[i])) {
            text[i] = toupper(text[i]);
            text[i] = (char) (text[i] - (int) key[i % strlen(key)] + 65);
        }
    }

    strcpy(result, text);

    return result;
}