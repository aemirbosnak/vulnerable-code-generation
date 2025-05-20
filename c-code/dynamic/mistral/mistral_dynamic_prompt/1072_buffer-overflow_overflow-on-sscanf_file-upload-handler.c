#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char fileName[BUFFER_SIZE];
    char fileData[BUFFER_SIZE];
    FILE *fp;

    if (argc != 3) {
        printf("Usage: uploader <filename> <data>\n");
        return 1;
    }

    strcpy(fileName, argv[1]);
    strcpy(fileData, argv[2]);

    fp = fopen(fileName, "w+");
    if (fp == NULL) {
        perror("Error opening file");
        return 2;
    }

    size_t bytesRead = fwrite(fileData, 1, strlen(fileData), fp);
    if (bytesRead == strlen(fileData)) {
        printf("File upload successful.\n");
    } else {
        perror("Error writing to file");
        fclose(fp);
        return 3;
    }

    fseek(fp, 0, SEEK_SET);
    char buffer[BUFFER_SIZE];
    size_t charsRead;

    while ((charsRead = fread(buffer, 1, BUFFER_SIZE, fp)) > 0) {
        printf("Data read from file:\n%s", buffer);
    }

    fclose(fp);

    int number;
    if (sscanf(fileData, "%*[^0-9]%d", &number) != 1) {
        printf("Invalid data format.\n");
        return 4;
    }

    printf("Number found in data: %d\n", number);

    return 0;
}
