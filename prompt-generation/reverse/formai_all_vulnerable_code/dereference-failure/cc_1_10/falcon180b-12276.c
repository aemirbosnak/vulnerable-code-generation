//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_FILE_SIZE 1000000

int main() {
    char key[MAX_KEY_LENGTH];
    printf("Enter encryption key: ");
    scanf("%s", key);
    char filename[100];
    printf("Enter filename to encrypt: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    rewind(file);

    char *data = (char*)malloc(filesize + 1);
    fread(data, filesize, 1, file);
    fclose(file);

    int keyindex = 0;
    int dataindex = 0;
    while (dataindex < filesize) {
        if (keyindex == strlen(key)) {
            keyindex = 0;
        }
        data[dataindex++] = data[dataindex - 1] ^ key[keyindex++];
    }

    file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    fwrite(data, filesize, 1, file);
    fclose(file);

    printf("File encrypted successfully.\n");
    return 0;
}