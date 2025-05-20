//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_COUNT 100

typedef struct {
    char filename[MAX_LINE_LENGTH];
    int linecount;
    int charcount;
} FileStats;

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s <logfile>\n", argv[0]);
        return 1;
    }

    char logfile[MAX_LINE_LENGTH];
    strcpy(logfile, argv[1]);

    FILE *fp = fopen(logfile, "r");
    if(fp == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    int filecount = 0;
    FileStats files[MAX_FILE_COUNT];

    char line[MAX_LINE_LENGTH];
    while(fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *filename = strtok(line, " ");
        if(filename == NULL) {
            continue;
        }

        int index = 0;
        for(int i=0; i<filecount; i++) {
            if(strcmp(files[i].filename, filename) == 0) {
                index = i;
                break;
            }
        }

        if(index == 0) {
            if(filecount >= MAX_FILE_COUNT) {
                printf("Maximum number of files reached.\n");
                break;
            }

            strcpy(files[filecount].filename, filename);
            files[filecount].linecount = 0;
            files[filecount].charcount = 0;
            filecount++;
        }

        int linecount = 0;
        int charcount = 0;
        char *token = strtok(NULL, " ");
        while(token!= NULL) {
            if(isalpha(token[0])) {
                charcount++;
            }
            linecount++;
            token = strtok(NULL, " ");
        }

        files[index].linecount++;
        files[index].charcount += charcount;
    }

    fclose(fp);

    printf("File\tLines\tChars\n");
    for(int i=0; i<filecount; i++) {
        printf("%s\t%d\t%d\n", files[i].filename, files[i].linecount, files[i].charcount);
    }

    return 0;
}