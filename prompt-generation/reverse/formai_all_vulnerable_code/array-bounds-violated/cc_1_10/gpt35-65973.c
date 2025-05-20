//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LEN 50

struct wordFreq{
    char word[MAX_LEN];
    int freq;
};

int main(){
    char str[500];
    struct wordFreq wFreq[MAX_WORDS];
    int i, j, k, len, count = 0;

    printf("Enter a string: ");
    fgets(str, 500, stdin);
    len = strlen(str);

    if (str[len-1] == '\n'){
        str[len-1] = '\0';
    }

    char *token = strtok(str, " ");

    while(token != NULL && count < MAX_WORDS){
        int flag = 0;
        for(i = 0; i < count; i++){
            if(strcmp(token, wFreq[i].word) == 0){
                wFreq[i].freq++;
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            strcpy(wFreq[count].word, token);
            wFreq[count].freq = 1;
            count++;
        }
        token = strtok(NULL, " ");
    }

    printf("\nWord Frequency:\n");
    for(i = 0; i < count; i++){
        printf("%s : %d\n", wFreq[i].word, wFreq[i].freq);
    }

    return 0;
}