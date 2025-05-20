//FormAI DATASET v1.0 Category: File Encyptor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_FILE_SIZE 2048

void* encrypt(void * arg);

char* key = "encryption key";

int main() {
    char file_name[100];
    printf("Enter file name to encrypt: ");
    scanf("%s", file_name);

    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Unable to open file!\n");
        exit(EXIT_FAILURE);
    } else {
        printf("File opened successfully!\n");
    }

    char buffer[MAX_FILE_SIZE];
    size_t bytes_read = fread(buffer, sizeof(char), MAX_FILE_SIZE, file);
    buffer[bytes_read] = '\0';

    fclose(file);

    pthread_t t1, t2;

    pthread_create(&t1, NULL, encrypt, buffer);
    pthread_create(&t2, NULL, encrypt, buffer);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Encryption complete!\n");

    return 0;
}

void* encrypt(void* arg) {
    char* buffer = (char*)arg;

    int len = strlen(buffer);
    int key_len = strlen(key);

    for (int i = 0; i < len; i++) {
        buffer[i] ^= key[i % key_len];
    }

    return NULL;
}