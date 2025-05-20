//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

// Define a structure to hold information about infected files
typedef struct {
    char filename[100];
    int is_infected;
} FileInfo;

// Define a function to check if a file is infected or not
int is_infected(char* buffer, int size) {
    for (int i = 0; i < size; i++) {
        if (buffer[i] == 'v' && buffer[i+1] == 'i' && buffer[i+2] == 'r' && buffer[i+3] == 'u' && buffer[i+4] == 's') {
            return 1;
        }
    }
    return 0;
}

// Define a function to scan a file for viruses
void scan_file(char* filename, FileInfo* file_info) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Can't open file '%s'\n", filename);
        return;
    }
    char buffer[MAX_FILE_SIZE];
    int n = fread(buffer, sizeof(char), MAX_FILE_SIZE, fp);
    fclose(fp);
    if (is_infected(buffer, n)) {
        printf("File '%s' is infected with viruses.\n", filename);
        file_info->is_infected = 1;
    } else {
        printf("File '%s' is clean.\n", filename);
        file_info->is_infected = 0;
    }
    strcpy(file_info->filename, filename);
}

int main() {
    char filepath[100];
    printf("Enter the full path of the file or folder to scan: ");
    scanf("%s", filepath);
    FileInfo file_list[100];
    int num_files = 0;
    if (strstr(filepath, ".exe") != NULL || strstr(filepath, ".dll") != NULL) {
        scan_file(filepath, &file_list[0]);
        num_files++;
    } else {
        FILE* fp = popen("ls -p | grep -v /", "r");
        char filename[100];
        while (fgets(filename, sizeof(filename), fp) != NULL) {
            filename[strlen(filename)-1] = '\0';
            char fullpath[100];
            sprintf(fullpath, "%s/%s", filepath, filename);
            if (strstr(fullpath, ".exe") != NULL || strstr(fullpath, ".dll") != NULL) {
                scan_file(fullpath, &file_list[num_files]);
                num_files++;
            }
        }
        pclose(fp);
    }
    printf("\nScan results:\n\n");
    for (int i = 0; i < num_files; i++) {
        printf("File %d: %s\n", i+1, file_list[i].filename);
        if (file_list[i].is_infected) {
            printf("This file is infected!\n");
        }
        printf("\n");
    }
    printf("\nScan complete.\n");
    return 0;
}