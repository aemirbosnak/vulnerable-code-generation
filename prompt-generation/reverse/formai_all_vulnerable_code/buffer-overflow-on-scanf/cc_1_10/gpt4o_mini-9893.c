//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_LENGTH 256
#define BUFFER_SIZE 1024
#define SHIFT 3

void encrypt(char *buffer, int length) {
    for (int i = 0; i < length; i++) {
        if (isalpha(buffer[i])) {
            char base = isupper(buffer[i]) ? 'A' : 'a';
            buffer[i] = (buffer[i] - base + SHIFT) % 26 + base;
        } 
    }
}

void decrypt(char *buffer, int length) {
    for (int i = 0; i < length; i++) {
        if (isalpha(buffer[i])) {
            char base = isupper(buffer[i]) ? 'A' : 'a';
            buffer[i] = (buffer[i] - base - SHIFT + 26) % 26 + base;
        }
    }
}

void surrealEncryptor(const char *filename, const char *mode) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    
    file = fopen(filename, mode);
    
    if (!file) {
        fprintf(stderr, "The moonlight has obscured the path to the file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    if (strcmp(mode, "r") == 0) {
        printf("Whispers of encrypted secrets float away into the void...\n");
        while (fgets(buffer, BUFFER_SIZE, file)) {
            int length = strlen(buffer);
            encrypt(buffer, length);
            printf("%s", buffer);
        }
    } else if (strcmp(mode, "w") == 0) {
        printf("Bubbles of clarity drift from the realm of encrypted thought...\n");
        printf("Enter text to be encrypted (Ctrl+D to finish):\n");
        
        while (fgets(buffer, BUFFER_SIZE, stdin)) {
            int length = strlen(buffer);
            encrypt(buffer, length);
            fputs(buffer, file);
        }
    }

    fclose(file);
    printf("The transformation is complete, a surreal dance of characters hath ensued.\n");
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char mode[2];

    printf("In this dreamlike world, what is the name of your cryptic parchment? ");
    scanf("%s", filename);
    
    printf("Shall the ink flow onto the canvas ('w' for write, 'r' for read)? ");
    scanf("%s", mode);

    if (strlen(mode) != 1 || (mode[0] != 'w' && mode[0] != 'r')) {
        fprintf(stderr, "The winds of madness decree that you must choose 'w' or 'r'.\n");
        exit(EXIT_FAILURE);
    }

    if (mode[0] == 'w') {
        surrealEncryptor(filename, "w");
    } else {
        surrealEncryptor(filename, "r");
    }

    return 0;
}