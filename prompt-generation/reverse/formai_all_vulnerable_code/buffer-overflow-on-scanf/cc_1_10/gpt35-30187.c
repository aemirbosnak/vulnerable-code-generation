//FormAI DATASET v1.0 Category: File Encyptor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 10000

void XOR_encrypt(char *data, int key) {
    int len = strlen(data);

    for (int i = 0; i < len; i++) {
        data[i] = data[i] ^ key;
    }
}

int main() {
    // Get the file name from user
    char file_name[100];
    printf("Enter the file name: ");
    scanf("%s", file_name);

    // Open the file
    FILE* fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file!\n");
        return 1;
    }

    // Read the contents of the file into buffer
    char file_buffer[MAX_FILE_SIZE];
    int file_size = 0;
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        file_buffer[file_size++] = ch;
    }
    fclose(fp);

    // Encrypt the contents of the file
    XOR_encrypt(file_buffer, 0xFF);

    // Write the encrypted contents back to the file
    fp = fopen(file_name, "w");
    if (fp == NULL) {
        printf("Error: Unable to open file!\n");
        return 1;
    }
    fwrite(file_buffer, sizeof(char), file_size, fp);
    fclose(fp);

    printf("File encrypted successfully!\n");

    return 0;
}