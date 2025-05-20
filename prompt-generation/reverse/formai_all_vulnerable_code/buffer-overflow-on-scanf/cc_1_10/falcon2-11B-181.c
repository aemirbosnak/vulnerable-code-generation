//Falcon2-11B DATASET v1.0 Category: Antivirus scanner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_MAX_SIZE 100

void readFile(char* filename, char* str) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    str = (char*)malloc(size + 1);
    fread(str, size, 1, file);
    str[size] = '\0';

    fclose(file);
}

void scanFile(char* filename, char* str) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file))!= -1) {
        if (strstr(line, "X")!= NULL || strstr(line, "V")!= NULL || strstr(line, "Y")!= NULL) {
            str[strlen(str)] = '1';
        }
    }

    free(line);
    fclose(file);
}

void printStr(char* str) {
    printf("%s", str);
}

int main() {
    char filename[FILE_MAX_SIZE];
    printf("Enter file name: ");
    scanf("%s", filename);

    char* str = (char*)malloc(FILE_MAX_SIZE);
    readFile(filename, str);

    scanFile(filename, str);

    printStr(str);

    free(str);

    return 0;
}