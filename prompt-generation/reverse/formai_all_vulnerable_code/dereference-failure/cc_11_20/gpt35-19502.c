//FormAI DATASET v1.0 Category: Log analysis ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 100000
#define MAX_NUM_LOG_TYPES 100

typedef struct{
    char* name;
    int count;
}LogType;

int main(){
    char* filename = "sample_log_file.txt";
    FILE* file_pointer = fopen(filename, "r");
    if(!file_pointer){
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char* line_buffer = malloc(MAX_LINE_LENGTH * sizeof(char));
    if(!line_buffer){
        printf("Error: failed to allocate memory for line buffer.\n");
        exit(1);
    }

    char** log_lines = malloc(MAX_NUM_LINES * sizeof(char*));
    if(!log_lines){
        printf("Error: failed to allocate memory for log lines.\n");
        exit(1);
    }

    int num_lines = 0;
    while(fgets(line_buffer, MAX_LINE_LENGTH, file_pointer)){
        log_lines[num_lines] = malloc(MAX_LINE_LENGTH * sizeof(char));
        if(!log_lines[num_lines]){
            printf("Error: failed to allocate memory for log line %d.\n", num_lines);
            exit(1);
        }
        strncpy(log_lines[num_lines], line_buffer, MAX_LINE_LENGTH);
        num_lines++;
    }

    fclose(file_pointer);
    free(line_buffer);

    LogType* log_types = malloc(MAX_NUM_LOG_TYPES * sizeof(LogType));
    if(!log_types){
        printf("Error: failed to allocate memory for log types.\n");
        exit(1);
    }

    int num_log_types = 0;
    for(int i = 0; i < num_lines; i++){
        char* type_start = strchr(log_lines[i], '[');
        if(!type_start){
            continue;
        }
        type_start++;

        char* type_end = strchr(type_start, ']');
        if(!type_end){
            continue;
        }

        int type_length = type_end - type_start;
        char* type_copy = malloc(type_length * sizeof(char));
        if(!type_copy){
            printf("Error: failed to allocate memory for log type copy.\n");
            exit(1);
        }
        strncpy(type_copy, type_start, type_length);

        int type_found = 0;
        for(int j = 0; j < num_log_types; j++){
            if(strcmp(log_types[j].name, type_copy) == 0){
                log_types[j].count++;
                type_found = 1;
                break;
            }
        }
        if(!type_found){
            log_types[num_log_types].name = type_copy;
            log_types[num_log_types].count = 1;
            num_log_types++;
        }
    }

    for(int i = 0; i < num_log_types; i++){
        printf("%s: %d\n", log_types[i].name, log_types[i].count);
        free(log_types[i].name);
    }
    free(log_types);
    for(int i = 0; i < num_lines; i++){
        free(log_lines[i]);
    }
    free(log_lines);

    return 0;
}