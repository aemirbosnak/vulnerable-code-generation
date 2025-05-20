//Falcon2-11B DATASET v1.0 Category: Image Classification system ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE_LENGTH 100
#define MAX_CHAR_LENGTH 1000
#define MAX_FILES 100

typedef struct {
    char name[MAX_CHAR_LENGTH];
    int count;
    int flag;
} data;

typedef struct {
    char type[MAX_CHAR_LENGTH];
    char label[MAX_CHAR_LENGTH];
} file_type;

int main() {
    int num_files = 0;
    data files[MAX_FILES];
    file_type file_types[MAX_FILES];

    printf("Enter the number of files: ");
    scanf("%d", &num_files);

    for(int i = 0; i < num_files; i++) {
        printf("Enter the name of file %d: ", i+1);
        scanf("%s", files[i].name);
        printf("Enter the type of file %d: ", i+1);
        scanf("%s", file_types[i].type);
        printf("Enter the label of file %d: ", i+1);
        scanf("%s", file_types[i].label);
        files[i].count = 0;
        files[i].flag = 0;
    }

    for(int i = 0; i < num_files; i++) {
        if(file_types[i].type[0] == 'I') {
            files[i].count++;
        }
    }

    for(int i = 0; i < num_files; i++) {
        if(files[i].count > 0 && files[i].count < 2) {
            printf("%s - %s\n", files[i].name, file_types[i].label);
            files[i].flag = 1;
        }
    }

    for(int i = 0; i < num_files; i++) {
        if(files[i].flag == 0) {
            printf("No classification for file %s\n", files[i].name);
        }
    }

    return 0;
}