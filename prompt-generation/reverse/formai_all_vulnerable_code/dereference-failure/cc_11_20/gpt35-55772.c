//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUME_LENGTH 1000 // Maximum length of resume file
#define MAX_KEYWORD_LENGTH 50 // Maximum length of keyword

int main(int argc, char **argv)
{
    if(argc < 3) {
        printf("Usage: %s [resume_file] [keywords_file]\n", argv[0]);
        return 0;
    }

    char *resume_file = argv[1]; // File path to resume
    char *keywords_file = argv[2]; // File path to keywords

    // Opening resume file
    FILE *fp_resume = fopen(resume_file, "r");
    if(fp_resume == NULL) {
        printf("Error: Cannot open resume file\n");
        return 0;
    }

    // Reading resume content
    char *resume_content = (char *) malloc(sizeof(char) * MAX_RESUME_LENGTH);
    fgets(resume_content, MAX_RESUME_LENGTH, fp_resume);

    // Closing resume file
    fclose(fp_resume);

    // Opening keywords file
    FILE *fp_keywords = fopen(keywords_file, "r");
    if(fp_keywords == NULL) {
        printf("Error: Cannot open keywords file\n");
        return 0;
    }

    char **keywords = (char **) malloc(sizeof(char *) * MAX_KEYWORD_LENGTH);
    int num_keywords = 0;

    // Reading keywords content
    char *line_buffer = (char *) malloc(sizeof(char) * MAX_KEYWORD_LENGTH);
    while(fgets(line_buffer, MAX_KEYWORD_LENGTH, fp_keywords) != NULL) {
        int len = strlen(line_buffer);
        if(line_buffer[len-1] == '\n') {
            line_buffer[len-1] = '\0';
        }
        keywords[num_keywords++] = line_buffer;
        line_buffer = (char *) malloc(sizeof(char) * MAX_KEYWORD_LENGTH);
    }

    // Closing keywords file
    fclose(fp_keywords);

    // Parsing resume content for keywords
    int *keyword_hits = (int *) malloc(sizeof(int) * num_keywords);
    memset(keyword_hits, 0, sizeof(int) * num_keywords);

    char *token;
    token = strtok(resume_content, " \n\t");

    while(token != NULL) {
        for(int i = 0; i < num_keywords; i++) {
            if(strcasecmp(token, keywords[i]) == 0) {
                keyword_hits[i] += 1;
            }
        }
        token = strtok(NULL, " \n\t");
    }

    // Printing keyword frequency
    printf("Keyword Frequency:\n");
    for(int i = 0; i < num_keywords; i++) {
        printf("%s: %d\n", keywords[i], keyword_hits[i]);
    }

    // Freeing resources
    for(int i = 0; i < num_keywords; i++) {
        free(keywords[i]);
    }

    free(keywords);
    free(line_buffer);
    free(resume_content);
    free(keyword_hits);

    return 0;
}