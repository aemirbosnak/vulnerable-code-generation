//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: artistic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_WORDS 1000000
#define WORD_LENGTH 100

struct word_count{
    char word[WORD_LENGTH];
    int count;
};

int spam_detection(char* email){
    FILE* fp = fopen("spam_words.txt", "r");
    struct word_count words[MAX_WORDS];
    int num_words = 0;
    char word[WORD_LENGTH];
    char* token;
    int i;

    if(fp == NULL){
        printf("Error opening file.\n");
        return 1;
    }

    while(fscanf(fp, "%s", word)!= EOF){
        num_words++;
        if(num_words == MAX_WORDS){
            printf("Maximum number of words reached.\n");
            fclose(fp);
            return 1;
        }
        strcpy(words[num_words-1].word, word);
        words[num_words-1].count = 0;
    }

    fclose(fp);

    token = strtok(email, " ");
    while(token!= NULL){
        for(i=0; i<num_words; i++){
            if(strcmp(token, words[i].word) == 0){
                words[i].count++;
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    int total_words = 0;
    int spam_count = 0;

    for(i=0; i<num_words; i++){
        if(words[i].count > 0){
            spam_count += words[i].count;
            total_words += words[i].count;
        }
    }

    if(total_words == 0){
        printf("Email is empty.\n");
        return 1;
    }

    float spam_percentage = (float)spam_count / total_words * 100;

    if(spam_percentage >= 50){
        printf("Email is spam.\n");
    }
    else{
        printf("Email is not spam.\n");
    }

    return 0;
}

int main(){
    char email[1000];

    printf("Enter email: ");
    scanf("%s", email);

    spam_detection(email);

    return 0;
}