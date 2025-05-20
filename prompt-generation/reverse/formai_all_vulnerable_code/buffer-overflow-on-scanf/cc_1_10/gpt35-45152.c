//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int i, j, count = 0;
    char str[100];
    char unique[100];
    int frequency[100];

    //user input
    printf("Enter a string:\n");
    scanf("%s", str);
    
    //determine unique characters
    for(i=0; str[i]!='\0'; i++){
        if(str[i]!=' '){
            for(j=i+1; str[j]!='\0'; j++){
                if(str[j]==str[i]){
                    str[j]=' ';
                }
            }
            unique[count] = str[i];
            count++;
        }
    }
    unique[count] = '\0';

    //count frequency of unique characters
    for(i=0;unique[i]!='\0';i++){
        frequency[i]=0;
        for(j=0;str[j]!='\0';j++){
            if(unique[i]==str[j]){
                frequency[i]++;
            }
        }
    }

    //print results
    printf("Unique Characters:\n");
    for(i=0;unique[i]!='\0';i++){
        printf("%c ",unique[i]);
    }
    printf("\n");

    printf("Frequency of Unique Characters:\n");
    for(i=0;unique[i]!='\0';i++){
        printf("%c: %d\n",unique[i],frequency[i]);
    }

    return 0;
}