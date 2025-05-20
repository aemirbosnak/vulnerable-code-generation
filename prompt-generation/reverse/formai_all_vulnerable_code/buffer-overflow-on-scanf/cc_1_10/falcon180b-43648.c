//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_FILE_SIZE 100000

struct file_info {
    char name[MAX_FILE_NAME];
    int size;
    int deleted;
};

void read_file_info(FILE *fp, struct file_info *file_info) {
    fseek(fp, 0, SEEK_SET);
    fread(file_info, sizeof(struct file_info), 1, fp);
}

void write_file_info(FILE *fp, struct file_info *file_info) {
    fseek(fp, 0, SEEK_SET);
    fwrite(file_info, sizeof(struct file_info), 1, fp);
}

int main() {
    FILE *fp;
    char file_name[MAX_FILE_NAME];
    struct file_info file_info;

    printf("Enter the name of the file to be recovered: ");
    scanf("%s", file_name);

    fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("File not found.\n");
        exit(1);
    }

    read_file_info(fp, &file_info);

    if (file_info.deleted == 0) {
        printf("File is not deleted.\n");
        exit(0);
    }

    printf("Enter the name of the recovered file: ");
    scanf("%s", file_name);

    fp = fopen(file_name, "wb");
    if (fp == NULL) {
        printf("File could not be created.\n");
        exit(1);
    }

    file_info.deleted = 0;
    write_file_info(fp, &file_info);

    printf("File recovered successfully.\n");
    exit(0);
}