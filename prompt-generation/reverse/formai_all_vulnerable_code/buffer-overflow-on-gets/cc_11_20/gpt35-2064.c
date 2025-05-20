//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//A structure to hold the sentiment and its value
struct Sentiment{
    char name[30];
    int value;
};

//Function to find the sentiment given a phrase
struct Sentiment findSentiment(char *phrase){
    struct Sentiment sentiment;
    int score = 0;
    int len = strlen(phrase);
    int i = 0;
    while(i<len){
        if(phrase[i] == ' '){
            i++;
            continue;
        }
        if(phrase[i] == 'h'){
            if(i+4<len && phrase[i+1] == 'a' && phrase[i+2] == 'p' && phrase[i+3] == 'p' && phrase[i+4] == 'y'){
                score += 2;
                i +=5;
                continue;
            }
        }
        if(phrase[i] == 's'){
            if(i+4<len && phrase[i+1] == 'a' && phrase[i+2] == 'd'){
                score -= 2;
                i +=3;
                continue;
            }
        }
        if(phrase[i] == ':'){
            if(i+1<len && phrase[i+1] == ')'){
                score += 1;
                i +=2;
                continue;
            }
            else if(i+1<len && phrase[i+1] == '('){
                score -= 1;
                i +=2;
                continue;
            }
        }
        if(i+2<len && phrase[i] == 'l' && phrase[i+1] == 'o' && phrase[i+2] == 'l'){
            score += 1;
            i +=3;
            continue;
        }
        if(i+2<len && phrase[i] == 'w' && phrase[i+1] == 't' && phrase[i+2] == 'f'){
            score -= 1;
            i +=3;
            continue;
        }
        i++;
    }
    sentiment.value = score;
    if(score == 0){
        strcpy(sentiment.name,"neutral");
    }
    else if(score > 0){
        strcpy(sentiment.name,"positive");
    }
    else{
        strcpy(sentiment.name,"negative");
    }
    return sentiment;
}

int main(){
    char phrase[1000];
    struct Sentiment sentiment;
    printf("Enter a phrase: ");
    gets(phrase);
    sentiment = findSentiment(phrase);
    printf("The sentiment of the phrase is %s\n",sentiment.name);
    printf("The sentiment value is %d\n",sentiment.value);
    return 0;
}