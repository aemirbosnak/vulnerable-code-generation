//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

typedef struct {
    char *name;
    int line_num;
} VarInfo;

int main(int argc, char **argv) {
    FILE *fp;
    char line[MAX_LINE_LEN];
    char *filename = argv[1];
    char *var_name = argv[2];
    int var_line_num = atoi(argv[3]);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    int num_vars = 0;
    VarInfo *vars = malloc(sizeof(VarInfo) * num_vars);

    int line_num = 1;
    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        char *token = strtok(line, " \t\n\r\f\v");
        while (token!= NULL) {
            if (strcmp(token, var_name) == 0) {
                if (num_vars == 0) {
                    vars = realloc(vars, sizeof(VarInfo) * num_vars + 1);
                }
                vars[num_vars].name = strdup(var_name);
                vars[num_vars].line_num = line_num;
                num_vars++;
            }
            token = strtok(NULL, " \t\n\r\f\v");
        }
        line_num++;
    }

    fclose(fp);

    printf("Variable '%s' appears on the following lines:\n", var_name);
    for (int i = 0; i < num_vars; i++) {
        printf("%d: %s\n", vars[i].line_num, vars[i].name);
    }

    free(vars);

    return 0;
}