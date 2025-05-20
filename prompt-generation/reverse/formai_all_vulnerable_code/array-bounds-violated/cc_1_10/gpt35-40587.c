//FormAI DATASET v1.0 Category: Text Summarizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_STRING_SIZE 100000
#define MAX_SENTENCE_SIZE 100

char* read_file(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }
    char* content = (char*) malloc(MAX_STRING_SIZE * sizeof(char));
    int size = 0;
    int c;
    while((c = fgetc(fp)) != EOF) {
        content[size++] = c;
    }
    content[size] = '\0';
    fclose(fp);
    return content;
}

int is_delimeter(char c) {
    static const char delimeters[] = " \n\t.,!?:;()<>[]{}-\"'";
    for(int i = 0; delimeters[i] != '\0'; i++) {
        if(c == delimeters[i]) {
            return 1;
        }
    }
    return 0;
}

int get_word_count(char* str) {
    int count = 0;
    int i = 0;
    while(str[i] != '\0') {
        while(is_delimeter(str[i])) {
            i++;
        }
        if(str[i] != '\0') {
            count++;
        }
        while(!is_delimeter(str[i]) && str[i] != '\0') {
            i++;
        }
    }
    return count;
}

int get_sentence_count(char* str) {
    int count = 0;
    int i = 0;
    while(str[i] != '\0') {
        if(str[i] == '.' || str[i] == '!' || str[i] == '?') {
            count++;
        }
        i++;
    }
    return count;
}

void print_summary(char* summary[], int count) {
    printf("\nSummary:\n");
    for(int i = 0; i < count; i++) {
        printf("%s ", summary[i]);
    }
    printf("\n");
}

void text_summarizer(char* content) {
    char* sentences[MAX_SENTENCE_SIZE];
    int sentence_count = 0;
    char* ptr = strtok(content, ".!?");
    while(ptr != NULL) {
        if(get_word_count(ptr) > 3) {
            sentences[sentence_count] = ptr;
            sentence_count++;
        }
        ptr = strtok(NULL, ".!?");
    }
    int summary_count = sentence_count / 2;
    char* summary[summary_count];
    int index = 0;
    for(int i = 0; i < summary_count; i++) {
        summary[i] = sentences[index];
        index += 2;
    }
    print_summary(summary, summary_count);
}

int main() {
    printf("Enter the filename to summarize: ");
    char filename[256];
    fgets(filename, 256, stdin);
    filename[strlen(filename) - 1] = '\0';
    char* content = read_file(filename);
    text_summarizer(content);
    return 0;
}