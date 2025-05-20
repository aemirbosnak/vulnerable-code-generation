//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct {
    char filename[MAX_SIZE];
    int linenumber;
    char datatype[MAX_SIZE];
    char varname[MAX_SIZE];
} VarInfo;

void extract_metadata(FILE* fp, VarInfo* vars, int count) {
    char line[MAX_SIZE];
    char keyword[MAX_SIZE];
    int i;

    while (fgets(line, MAX_SIZE, fp)!= NULL) {
        for (i = 0; i < count; i++) {
            strcpy(vars[i].filename, "");
            strcpy(vars[i].datatype, "");
            strcpy(vars[i].varname, "");
        }

        sscanf(line, "%s", keyword);

        if (strcmp(keyword, "filename") == 0) {
            fgets(line, MAX_SIZE, fp);
            strcpy(vars[0].filename, line);
        } else if (strcmp(keyword, "linenumber") == 0) {
            fgets(line, MAX_SIZE, fp);
            vars[0].linenumber = atoi(line);
        } else if (strcmp(keyword, "datatype") == 0) {
            fgets(line, MAX_SIZE, fp);
            strcpy(vars[1].datatype, line);
        } else if (strcmp(keyword, "varname") == 0) {
            fgets(line, MAX_SIZE, fp);
            strcpy(vars[2].varname, line);
        }
    }
}

int main(int argc, char* argv[]) {
    FILE* fp;
    VarInfo vars[3];

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    extract_metadata(fp, vars, 3);

    printf("Filename: %s\n", vars[0].filename);
    printf("Line number: %d\n", vars[0].linenumber);
    printf("Datatype: %s\n", vars[1].datatype);
    printf("Variable name: %s\n", vars[2].varname);

    fclose(fp);

    return 0;
}