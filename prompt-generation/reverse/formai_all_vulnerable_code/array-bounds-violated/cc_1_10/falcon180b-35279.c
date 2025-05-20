//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000
#define MAX_FILE_NAME_SIZE 256

typedef struct {
    char name[MAX_FILE_NAME_SIZE];
    int size;
} file_info;

char input_file_name[MAX_FILE_NAME_SIZE];
char output_file_name[MAX_FILE_NAME_SIZE];

int main() {
    printf("Welcome to the Future File Synchronizer!\n");
    printf("Please enter the name of the input file: ");
    scanf("%s", input_file_name);
    printf("Please enter the name of the output file: ");
    scanf("%s", output_file_name);

    FILE* input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error: Input file not found.\n");
        return 1;
    }
    FILE* output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error: Output file not found.\n");
        return 1;
    }

    char input_buffer[MAX_FILE_SIZE];
    char output_buffer[MAX_FILE_SIZE];
    file_info input_file_info;
    file_info output_file_info;

    fseek(input_file, 0, SEEK_END);
    input_file_info.size = ftell(input_file);
    rewind(input_file);
    fread(input_buffer, sizeof(char), input_file_info.size, input_file);
    input_buffer[input_file_info.size] = '\0';
    strcpy(input_file_info.name, input_file_name);

    fwrite(&input_file_info, sizeof(file_info), 1, output_file);
    fwrite(input_buffer, sizeof(char), input_file_info.size, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("File synchronization complete!\n");
    return 0;
}