//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_FILE_NAME 100
#define MAX_LINE_SIZE 1000

struct file{
    char name[MAX_FILE_NAME];
    FILE* fp;
};

struct file* open_file(char* filename){
    struct file* fp = (struct file*)malloc(sizeof(struct file));
    strcpy(fp->name, filename);
    fp->fp = fopen(filename, "r");
    if(fp->fp == NULL){
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    return fp;
}

void close_file(struct file* fp){
    fclose(fp->fp);
    free(fp);
}

char* read_line(FILE* fp){
    char* line = (char*)malloc(MAX_LINE_SIZE);
    char* ptr = line;
    int c;
    while((c = fgetc(fp))!= EOF){
        if(c == '\n'){
            *ptr = '\0';
            break;
        }
        else if(isalnum(c)){
            *ptr++ = toupper(c);
        }
    }
    return line;
}

int main(){
    char* filename = "test.txt";
    struct file* fp = open_file(filename);
    char* line;
    while((line = read_line(fp->fp))!= NULL){
        printf("%s", line);
    }
    close_file(fp);
    return 0;
}