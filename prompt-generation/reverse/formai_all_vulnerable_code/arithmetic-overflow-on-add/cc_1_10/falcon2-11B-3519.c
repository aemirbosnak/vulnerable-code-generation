//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE 1000000
#define MAX_MSG_SIZE 100000
#define MAX_KEY_SIZE 100

typedef struct {
    int file_size;
    char *msg;
    char *key;
} Stego_msg;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [image_file] [secret_message] [key]\n", argv[0]);
        return 1;
    }

    FILE *image_file = fopen(argv[1], "rb");
    if (image_file == NULL) {
        perror("Error opening image file");
        return 1;
    }

    FILE *secret_file = fopen(argv[2], "r");
    if (secret_file == NULL) {
        perror("Error opening secret file");
        fclose(image_file);
        return 1;
    }

    FILE *key_file = fopen(argv[3], "r");
    if (key_file == NULL) {
        perror("Error opening key file");
        fclose(secret_file);
        fclose(image_file);
        return 1;
    }

    char *image_data = NULL;
    fseek(image_file, 0, SEEK_END);
    int image_size = ftell(image_file);
    rewind(image_file);
    image_data = (char*)malloc(image_size + MAX_MSG_SIZE);
    fread(image_data, 1, image_size, image_file);

    char *secret_data = NULL;
    fseek(secret_file, 0, SEEK_END);
    int secret_size = ftell(secret_file);
    rewind(secret_file);
    secret_data = (char*)malloc(secret_size + MAX_MSG_SIZE);
    fread(secret_data, 1, secret_size, secret_file);

    char *key = NULL;
    fseek(key_file, 0, SEEK_END);
    int key_size = ftell(key_file);
    rewind(key_file);
    key = (char*)malloc(key_size + MAX_MSG_SIZE);
    fread(key, 1, key_size, key_file);

    int key_len = strlen(key);
    int msg_len = strlen(secret_data);

    int j = 0;
    for (int i = 0; i < msg_len; i++) {
        if (i % key_len == 0) {
            int index = (i / key_len) % MAX_FILE_SIZE;
            if (index < MAX_FILE_SIZE) {
                image_data[index] = (char)(((int)image_data[index] + (int)secret_data[i]) % 256);
            } else {
                printf("Error: Secret message too long.\n");
                return 1;
            }
        }
    }

    printf("Steganography successful! The stego image data is: %s\n", image_data);

    free(image_data);
    free(secret_data);
    free(key);

    fclose(image_file);
    fclose(secret_file);
    fclose(key_file);

    return 0;
}