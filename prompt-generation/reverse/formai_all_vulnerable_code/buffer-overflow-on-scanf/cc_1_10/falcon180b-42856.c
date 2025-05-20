//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1024*1024*10 //10MB

typedef struct {
    char *name;
    char *content;
    int size;
} File;

int is_virus(char *content) {
    char *keywords[] = {"virus", "malware", "trojan", "worm"};
    int num_keywords = sizeof(keywords)/sizeof(char *);

    for(int i=0; i<num_keywords; i++) {
        if(strstr(content, keywords[i])) {
            return 1;
        }
    }

    return 0;
}

int main() {
    char buffer[MAX_FILE_SIZE];
    File *files = NULL;
    int num_files = 0;

    printf("Enter file paths:\n");
    while(1) {
        char path[256];
        scanf("%s", path);

        FILE *fp = fopen(path, "r");
        if(fp == NULL) {
            printf("Invalid file path.\n");
            continue;
        }

        fseek(fp, 0, SEEK_END);
        int file_size = ftell(fp);
        if(file_size > MAX_FILE_SIZE) {
            printf("File is too large.\n");
            fclose(fp);
            continue;
        }

        rewind(fp);
        fread(buffer, file_size, 1, fp);
        fclose(fp);

        files = realloc(files, sizeof(File)*++num_files);
        files[num_files-1].name = strdup(path);
        files[num_files-1].content = strdup(buffer);
        files[num_files-1].size = file_size;
    }

    for(int i=0; i<num_files; i++) {
        if(is_virus(files[i].content)) {
            printf("Virus found in %s.\n", files[i].name);
        } else {
            printf("%s is clean.\n", files[i].name);
        }
    }

    for(int i=0; i<num_files; i++) {
        free(files[i].name);
        free(files[i].content);
    }
    free(files);

    return 0;
}