//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: lively
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//function to remove special characters from string
char *removeSpecial(char *s){
    int i, j;
    char *temp = malloc(strlen(s)+1);
    for(i=0, j=0; s[i]!='\0'; i++){
        if(isalpha(s[i])){
            temp[j++] = s[i];
        }
    }
    temp[j] = '\0';
    return temp;
}

int main(){
    char input[1000], *token, *temp, *wordlist[1000];
    int wordfreq[1000] = {0}, i, j, k, flag, count=0;
    
    printf("Enter a string: ");
    gets(input); //getting the input from user
    
    //separating the input into individual words by space
    token = strtok(input, " ");
    while(token != NULL){
        temp = removeSpecial(token); //removing special characters from word
        for(i=0, flag=0; i<count; i++){
            if(strcmp(temp, wordlist[i]) == 0){ //checking if word already exists
                wordfreq[i]++; //if exists, increment its frequency
                flag = 1;
                break;
            }
        }
        if(flag == 0){ //if word does not exist, add it to list
            wordlist[count] = malloc(strlen(temp)+1);
            strcpy(wordlist[count], temp);
            wordfreq[count]++;
            count++;
        }
        token = strtok(NULL, " ");
    }
    
    //printing the word frequencies
    printf("\nWORD FREQUENCY:\n");
    for(i=0; i<count; i++){
        printf("%s - %d\n", wordlist[i], wordfreq[i]);
        free(wordlist[i]); //freeing the allocated memory for each word
    }
    
    return 0;
}