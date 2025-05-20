//Falcon-180B DATASET v1.0 Category: File handling ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

typedef struct {
    char *filename;
    FILE *fp;
    int linenum;
    char line[MAX_LINE_LEN];
} FILE_HANDLE;

FILE_HANDLE *fh_open(char *filename) {
    FILE_HANDLE *fh = malloc(sizeof(FILE_HANDLE));
    fh->filename = filename;
    fh->fp = fopen(filename, "r");
    fh->linenum = 0;
    strcpy(fh->line, "");
    return fh;
}

int fh_close(FILE_HANDLE *fh) {
    if (fh->fp!= NULL) {
        fclose(fh->fp);
    }
    free(fh);
    return 0;
}

int fh_nextline(FILE_HANDLE *fh) {
    char c;
    fh->linenum++;
    strcpy(fh->line, "");
    while ((c = fgetc(fh->fp))!= EOF && c!= '\n') {
        strncat(fh->line, &c, 1);
    }
    return 0;
}

int fh_getline(FILE_HANDLE *fh, char *buffer) {
    strcpy(buffer, fh->line);
    return 0;
}

int main() {
    FILE_HANDLE *fh = fh_open("test.txt");
    while (fh_nextline(fh) == 0) {
        printf("Line %d: %s\n", fh->linenum, fh->line);
    }
    fh_close(fh);
    return 0;
}