//FormAI DATASET v1.0 Category: HTML beautifier ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);
void clean(char line[], int len);
void beautify(char line[], int len);

int main(void){
    int len;
    char line[MAXLINE];

    while((len = get_line(line, MAXLINE)) > 0){
        clean(line, len);
        beautify(line, len);
        printf("%s\n", line);
    }

    return 0;
}

int get_line(char line[], int maxline){
    int c, i;

    for(i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if(c == '\n'){
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}

void copy(char to[], char from[]){
    int i;

    i = 0;

    while((to[i] = from[i]) != '\0')
        ++i;
}

void clean(char line[], int len){
    int i;

    for(i = len - 1; i >= 0; --i){
        if(line[i] == ' ' && line[i - 1] == ' '){
            for(int j = i; j < len; ++j)
                line[j] = line[j + 1];

            --len;
        }
    }

    line[len] = '\0';
}

void beautify(char line[], int len){
    int tabs;

    for(int i = 0; i < len; ++i){
        if(line[i] == '<'){
            if(line[i+1] == '/')
                tabs--;
            else
                tabs++;

            for(int j = 0; j < tabs; ++j)
                printf("\t");
        }

        printf("%c", line[i]);

        if(line[i] == '>'){
            if(line[i-1] != '/')
                printf("\n");

            for(int j = 0; j < tabs; ++j)
                printf("\t");
        }   
    }

}