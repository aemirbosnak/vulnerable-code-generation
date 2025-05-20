//FormAI DATASET v1.0 Category: Data recovery tool ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 50
#define MAX_DATA_SIZE 100

void recover_data(char* file_name);
void print_data(char* data);

int main() {
    char file_name[MAX_FILENAME];
    printf("Enter the file name: ");
    scanf("%s", file_name);
    printf("\n");

    recover_data(file_name);

    return 0;
}

void recover_data(char* file_name) {
    FILE* fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("File not found!");
        exit(0);
    }

    char* data = (char*)malloc(MAX_DATA_SIZE * sizeof(char));
    int i = 0;
    char c = fgetc(fp);
    while (c != EOF) {
        data[i] = c;
        i++;
        c = fgetc(fp);
    }
    fclose(fp);

    int len = strlen(data);
    for (int i = 0; i < len; i++) {
        if (data[i] > 127) {
            data[i] = data[i] - 127;
        } else {
            data[i] = data[i] + 127;
        }
    }

    // save recovered data into a new file
    char new_file_name[MAX_FILENAME + 5];
    strcpy(new_file_name, "new_");
    strcat(new_file_name, file_name);
    FILE* new_fp = fopen(new_file_name, "w");
    fprintf(new_fp, "%s", data);
    fclose(new_fp);

    print_data(data);
}

void print_data(char* data) {
    printf("Recovered data:\n");
    printf("=======================\n");
    for (int i = 0; i < strlen(data); i++) {
        printf("%c", data[i]);
    }
    printf("\n=======================\n");
}