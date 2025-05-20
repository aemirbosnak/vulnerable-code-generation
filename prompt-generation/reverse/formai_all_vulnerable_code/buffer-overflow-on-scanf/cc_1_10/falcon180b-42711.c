//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_BUFF_SIZE 1024
#define MAX_FILE_SIZE 10000
#define MAX_NUM_FILES 100

typedef struct {
    char filename[MAX_FILE_SIZE];
    char backup_filename[MAX_FILE_SIZE];
    char file_size[MAX_FILE_SIZE];
} FileInfo;

void read_file(char* filename, char* buffer, int* buffer_size) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    rewind(file);
    if (file_size > MAX_BUFF_SIZE) {
        printf("Error: File %s is too large to read\n", filename);
        exit(1);
    }
    fread(buffer, 1, file_size, file);
    buffer[file_size] = '\0';
    *buffer_size = file_size;
    fclose(file);
}

void write_file(char* filename, char* buffer, int buffer_size) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    fwrite(buffer, 1, buffer_size, file);
    fclose(file);
}

void backup_file(char* filename, char* backup_filename) {
    char buffer[MAX_BUFF_SIZE];
    int buffer_size = 0;
    read_file(filename, buffer, &buffer_size);
    char* new_filename = malloc(sizeof(char) * (strlen(filename) + 5));
    strcpy(new_filename, filename);
    strcat(new_filename, ".bak");
    write_file(new_filename, buffer, buffer_size);
    free(new_filename);
}

int main() {
    char filename[MAX_FILE_SIZE];
    printf("Enter filename: ");
    scanf("%s", filename);
    char backup_filename[MAX_FILE_SIZE];
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".bak");
    backup_file(filename, backup_filename);
    printf("Backup created: %s\n", backup_filename);
    return 0;
}