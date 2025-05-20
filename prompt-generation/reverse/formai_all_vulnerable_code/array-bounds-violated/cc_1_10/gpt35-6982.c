//FormAI DATASET v1.0 Category: Text Summarizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1000
#define SUMMARY_LENGTH 3

int main()
{
    char text[MAX_STRING_LENGTH];
    char summary[MAX_STRING_LENGTH];
    char temp[MAX_STRING_LENGTH];
    int sentence_count = 0;
    int summary_count = 0;
    int i,j,k;

    printf("Enter the text to be summarized:\n");

    fgets(text, MAX_STRING_LENGTH, stdin); //input the text from user

    for(i=0;i<strlen(text);i++){ //to count the number of sentences present in text
        if(text[i]=='.'){
            sentence_count++;
        }
    }
    //to check if the number of sentences is greater than or equals to summary length or not
    if(sentence_count >= SUMMARY_LENGTH){
        for(i=0;i<strlen(text);i++){
            if(text[i]!='.' && text[i]!='\n'){
                temp[j++] = text[i];
            }
            else{
                temp[j] = '\0';
                j = 0;
                if(summary_count<SUMMARY_LENGTH-1){
                    strcat(summary, temp);
                    strcat(summary, ". ");
                }
                summary_count++;
            }
            if(summary_count == SUMMARY_LENGTH-1){
                break;
            }
        }
    }
    else{
        strcpy(summary, "The text has less number of sentences than required for summary");
    }

    printf("The summarized text is: %s", summary);

    return 0;
}