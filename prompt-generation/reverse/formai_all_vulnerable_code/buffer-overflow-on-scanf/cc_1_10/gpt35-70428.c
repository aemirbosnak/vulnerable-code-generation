//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINES 1000
#define MAX_CHARS 200

int main()
{
    char file_name[20];
    char resume[MAX_LINES][MAX_CHARS];
    char *token;
    FILE *fp;
    int i = 0, j;
    int match_count = 0;
    char keywords[4][20] = {"Experience", "Education", "Skills", "Projects"};

    printf("Enter name of a file you wish to see: ");
    scanf("%s", file_name);

    fp = fopen(file_name, "r");

    if (fp == NULL) {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(resume[i], MAX_CHARS, fp)) {
        i++;
    }

    fclose(fp);

    printf("Resume:\n");
    for (j = 0; j < i; j++) {
        printf("%s", resume[j]);
    }

    printf("\n");

    for (j = 0; j < 4; j++) {
        match_count = 0;
        printf("%s:\n", keywords[j]);
        for (i = 0; i < MAX_LINES; i++) {
            if (strstr(resume[i], keywords[j])) {
                match_count++;
            }
            if (match_count > 0 && match_count < 2) {
                token = strtok(resume[i], " ");
                while (token != NULL) {
                    printf("%s ", token);
                    token = strtok(NULL, " ");
                }
                printf("\n");
            }
        }
        printf("\n");
    }
    return 0;
}