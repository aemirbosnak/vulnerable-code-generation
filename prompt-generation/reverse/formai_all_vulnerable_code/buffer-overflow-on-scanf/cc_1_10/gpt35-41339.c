//FormAI DATASET v1.0 Category: Log analysis ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 512
#define MAX_FILE 1024

void analyze_file(char*);
void print_results(int, int, int);

int main() {
    char file_name[MAX_FILE];
    
    printf("Enter file name: ");
    scanf("%s", file_name);
    
    analyze_file(file_name);
    
    return 0;
}

void analyze_file(char* file_name) {
    FILE* fp;
    char line[MAX_LINE];
    int error_count = 0, warning_count = 0, info_count = 0;
    
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    
    while (fgets(line, MAX_LINE, fp) != NULL) {
        if (strstr(line, "ERROR") != NULL) {
            error_count++;
        } else if (strstr(line, "WARNING") != NULL) {
            warning_count++;
        } else if (strstr(line, "INFO") != NULL) {
            info_count++;
        }
    }
    
    fclose(fp);
    
    print_results(error_count, warning_count, info_count);
}

void print_results(int error_count, int warning_count, int info_count) {
    printf("\n--- Log analysis results ---\n");
    printf("Error count: %d\n", error_count);
    printf("Warning count: %d\n", warning_count);
    printf("Info count: %d\n", info_count);
}