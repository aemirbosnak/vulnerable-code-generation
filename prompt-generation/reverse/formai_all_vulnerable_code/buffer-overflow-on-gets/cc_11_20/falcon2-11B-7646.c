//Falcon2-11B DATASET v1.0 Category: Word Frequency Counter ; Style: energetic
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main() {
    char str[100];
    char *words[50];
    int count[100];
    int i,j,n;
    int min=100;

    printf("Enter a string: ");
    gets(str);

    words[0] = strtok(str," ");
    for(i=1; i<50; i++){
        words[i] = strtok(NULL, " ");
    }
    n = sizeof(words)/sizeof(char*);

    for(i=0; i<n; i++){
        for(j=0; words[i][j]!='\0'; j++){
            words[i][j]=tolower(words[i][j]);
        }
        count[i]=0;
    }

    for(i=0; str[i]!='\0'; i++){
        for(j=0; j<n; j++){
            if(words[j][0]==str[i]){
                count[j]++;
            }
        }
    }

    for(i=0; i<n; i++){
        if(count[i]>min){
            min=count[i];
        }
    }

    printf("Word frequency: \n");
    for(i=0; i<n; i++){
        if(count[i]==min){
            printf("%s : %d\n", words[i], count[i]);
        }
    }

    return 0;
}