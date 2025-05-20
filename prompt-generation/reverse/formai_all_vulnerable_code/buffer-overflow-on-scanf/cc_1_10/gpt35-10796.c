//FormAI DATASET v1.0 Category: Data recovery tool ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define BUFFER_SIZE 512

void recover_data(const char* f_name);
char* get_extension(char* f_name);

int main() {
    char f_name[MAX_FILE_NAME_LENGTH];
    printf("Please enter the name of the file to recover data from: ");
    scanf("%s", f_name);
    recover_data(f_name);
    return 0;
}

void recover_data(const char* f_name) {
    FILE* file;
    file = fopen(f_name, "rb");

    if (file == NULL) {
        printf("Unable to open file!");
        exit(1);	
    }

    char* extension = get_extension((char*) f_name);
    char new_file_name[MAX_FILE_NAME_LENGTH] = "recovered_data";

    if (extension != NULL) {
        strcat(new_file_name, ".");
        strcat(new_file_name, extension);
    }

    FILE* new_file = fopen(new_file_name, "wb");

    if (new_file == NULL) {
        printf("Error creating new file!");
        fclose(file);
        exit(1);
    }

    int n_read;
    char buffer[BUFFER_SIZE];

    while ((n_read = fread(buffer, sizeof(char), BUFFER_SIZE, file)) > 0) {
        fwrite(buffer, sizeof(char), n_read, new_file);
    }

    fclose(file);
    fclose(new_file);
    printf("Data recovered and saved to file: %s\n", new_file_name);
}

char* get_extension(char* f_name) {
    char* dot = strrchr(f_name, '.');
    if (!dot || dot == f_name) {
        return NULL;
    }
    return dot + 1;
}