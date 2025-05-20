//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: romantic
#include<stdio.h>

int main(){
    char input[1000];
    printf("Hello my love, please enter your message: ");
    scanf("%[^\n]s",input);

    int score = 0;
    char *token = strtok(input," ");
    while(token != NULL){
        if(strcmp(token,"love")==0){
            score += 5;
        }
        else if(strcmp(token,"adore")==0 || strcmp(token,"adored")==0){
            score += 4;
        }
        else if(strcmp(token,"romance")==0 || strcmp(token,"romantic")==0){
            score += 3;
        }
        else if(strcmp(token,"affection")==0){
            score += 2;
        }
        else if(strcmp(token,"like")==0 || strcmp(token,"cute")==0){
            score += 1;
        }
        else if(strcmp(token,"hate")==0 || strcmp(token,"fight")==0 || strcmp(token,"angry")==0){
            score -= 3;
        }
        else if(strcmp(token,"dislike")==0 || strcmp(token,"gross")==0){
            score -= 2;
        }
        else if(strcmp(token,"annoy")==0 || strcmp(token,"irritate")==0){
            score -= 1;
        }
        token = strtok(NULL," ");
    }

    if(score <= -1){
        printf("I'm sorry my love, please forgive me. I didn't mean to hurt you.\n");
    }
    else if(score >= 0 && score <= 4){
        printf("Thank you my love, your message is appreciated.\n");
    }
    else if(score >= 5 && score <= 8){
        printf("Oh my love, your message is so sweet. You make my heart flutter.\n");
    }
    else if(score >= 9 && score <= 12){
        printf("My dearest love, your message is so romantic. I am swept off my feet.\n");
    }
    else if(score >= 13){
        printf("My eternal love, your message is beyond words. I am yours forever.\n");
    }

    return 0;
}