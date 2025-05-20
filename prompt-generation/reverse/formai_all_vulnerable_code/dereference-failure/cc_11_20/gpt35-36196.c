//FormAI DATASET v1.0 Category: Log analysis ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
    int total_lines = 0, unique_lines = 0, i = 0, j = 0, flag = 0, k;
    char line[500];
    char **lines = (char **)malloc(0 * sizeof(char *));

    while(fgets(line, 500, stdin)) {
        total_lines++;
        flag = 0;

        for(i = 0; i < unique_lines; i++) {
            if(strcmp(line, lines[i]) == 0) {
                flag = 1;
                break;
            }
        }

        if(!flag) {
            unique_lines++;

            char **lines_temp = (char **)malloc(unique_lines * sizeof(char *));
            for(i = 0; i < unique_lines - 1; i++) {
                lines_temp[i] = lines[i];
            }

            lines_temp[unique_lines - 1] = strdup(line);
            free(lines);
            lines = lines_temp;
        }
    }

    printf("Total Number of Lines: %d\n", total_lines);
    printf("Number of Unique Lines: %d\n", unique_lines);

    for(i = 0; i < unique_lines; i++) {
        int count = 0;
        for(j = 0; j < strlen(lines[i]); j++) {
            if(lines[i][j] == 'C' || lines[i][j] == 'c') {
                count++;
            }
        }
        printf("Line %d contains %d 'C' or 'c'\n", i+1, count);
    }

    for(i = 0; i < unique_lines; i++) {
        free(lines[i]);
    }
    
    free(lines);

    return EXIT_SUCCESS;
}