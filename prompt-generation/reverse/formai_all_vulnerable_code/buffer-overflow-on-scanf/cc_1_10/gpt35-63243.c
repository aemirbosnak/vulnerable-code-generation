//FormAI DATASET v1.0 Category: Data recovery tool ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure of the file record
typedef struct file_record {
    char name[50];
    int size;
    char data[1000];
} FileRecord;

// function to read the file data and store it in a FileRecord structure
FileRecord read_file(char* filename) {
    FileRecord record;
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error reading file %s\n", filename);
        exit(1);
    }
    strcpy(record.name, filename);
    fseek(fp, 0L, SEEK_END);
    record.size = ftell(fp);
    rewind(fp);
    fread(record.data, sizeof(char), record.size, fp);
    fclose(fp);
    return record;
}

// function to write the file data from a FileRecord structure to the disk
void write_file(FileRecord record) {
    FILE* fp = fopen(record.name, "w");
    fwrite(record.data, sizeof(char), record.size, fp);
    fclose(fp);
}

// function to recover a file by reading its data from a backup file and writing it to the original file
void recover_file(char* filename, char* backup) {
    FileRecord original = read_file(filename);
    FileRecord backup_data = read_file(backup);
    if(backup_data.size != original.size) {
        printf("Error: Backup file size does not match the original file size.\n");
        return;
    }
    memcpy(original.data, backup_data.data, backup_data.size);
    write_file(original);
    printf("File %s successfully recovered.\n", filename);
}

int main() {
    char filename[50], backup[50];
    printf("Enter the filename to recover: ");
    scanf("%s", filename);
    printf("Enter the backup filename: ");
    scanf("%s", backup);
    recover_file(filename, backup);
    return 0;
}