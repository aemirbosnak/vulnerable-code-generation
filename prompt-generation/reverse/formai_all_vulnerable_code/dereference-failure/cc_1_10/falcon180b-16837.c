//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 256
#define MAX_LINE_LENGTH 1024
#define MAX_DATA_SIZE 1024 * 1024 * 10 // 10 MB

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    char data[MAX_DATA_SIZE];
} FileData;

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        exit(1);
    }

    FileData data;
    memset(&data, 0, sizeof(data));

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);

    if (file_size <= 0 || file_size > MAX_DATA_SIZE) {
        printf("Invalid file size.\n");
        exit(1);
    }

    rewind(fp);

    if (fread(data.file_name, 1, MAX_FILE_NAME_LEN, fp)!= MAX_FILE_NAME_LEN) {
        printf("Error reading file name.\n");
        exit(1);
    }

    data.file_name[MAX_FILE_NAME_LEN - 1] = '\0';

    if (fread(data.data, 1, file_size, fp)!= file_size) {
        printf("Error reading data.\n");
        exit(1);
    }

    printf("File name: %s\n", data.file_name);
    printf("File size: %ld bytes\n", file_size);
    printf("Data:\n");

    char line[MAX_LINE_LENGTH];
    int line_num = 1;
    for (int i = 0; i < file_size; i += MAX_LINE_LENGTH) {
        memset(line, 0, sizeof(line));
        int bytes_read = fread(line, 1, MAX_LINE_LENGTH, fp);
        if (bytes_read == 0) {
            printf("End of file reached.\n");
            break;
        }
        line[bytes_read - 1] = '\0';
        printf("%d: %s\n", line_num++, line);
    }

    fclose(fp);
    return 0;
}