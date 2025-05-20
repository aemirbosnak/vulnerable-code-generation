//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: complete
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Function to check if a words matches a positive word from the positive words list
int isPositive(char* word){
    char positiveWords[10][20]={"love","happy","great","best","excited","fun","good","cool","fine","nice"};
    int i;
    for(i=0;i<10;i++){
        if(strcmp(word,positiveWords[i])==0)
        return 1;
    }
    return 0;
}

//Function to check if a words matches a negative word from the negative words list
int isNegative(char* word){
    char negativeWords[10][20]={"hate","sad","worst","disappointed","bored","bad","dislike","horrible","angry","miserable"};
    int i;
    for(i=0;i<10;i++){
        if(strcmp(word,negativeWords[i])==0)
        return 1;
    }
    return 0;
}

//Function to calculate sentiment score of a string
float calculateSentimentScore(char* string){
    char word[20];
    int posCount=0,negCount=0,totalWords=0;
    float score;
    FILE* fp=fopen(string,"r");
    if(fp==NULL){
        printf("Error opening file\n");
        exit(0);
    }
    while(fscanf(fp,"%s",word)!=EOF){
         if(isPositive(word))
         posCount++;
         else if(isNegative(word))
         negCount++;
         totalWords++;
    }
    fclose(fp);
    if(totalWords==0){
        printf("Empty file or cannot calculate sentiment score.\n");
        exit(0);
    }
    score=(posCount-negCount)*1.0/totalWords;
    return score;
}

int main(){
    char fileName[30];
    printf("Enter Filename: ");
    scanf("%s",fileName);
    float score=calculateSentimentScore(fileName);
    if(score>0.5)
    printf("Positive Sentiment Score: %f\n",score);
    else if(score<0.5)
    printf("Negative Sentiment Score: %f\n",score);
    else
    printf("Neutral Sentiment Score: %f\n",score);
    return 0;
}