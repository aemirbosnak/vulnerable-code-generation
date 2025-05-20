//FormAI DATASET v1.0 Category: Educational ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STRING_LENGTH 1000

int main(){
    char input[MAX_STRING_LENGTH], modified_input[MAX_STRING_LENGTH];
    int i, j, len;

    printf("Enter your name: ");
    fgets(input, MAX_STRING_LENGTH, stdin);
    len = strlen(input);
    for(i = 0, j = 0; i < len; i++){
        if(input[i] >= 'A' && input[i] <= 'Z'){
            modified_input[j] = input[i] + 32;
        }
        else if(input[i] >= 'a' && input[i] <= 'z'){
            modified_input[j] = input[i] - 32;
        }
        else{
            modified_input[j] = input[i];
        }
        j++;
    }
    modified_input[j] = '\0';
    printf("Modified input: %s", modified_input);

    printf("\nAre you sure you want to continue? (Y/N) ");
    char sure_input[MAX_STRING_LENGTH];
    scanf("%s", sure_input);
    if(strcmp(sure_input, "Y") == 0 || strcmp(sure_input, "y") == 0){
        printf("Well, that's what they all say before it's too late...\n");
    }
    else{
        printf("Wise choice. Always question everything.\n");
    }

    printf("\nOne more question. What's your favorite number? ");
    int fav_num;
    scanf("%d", &fav_num);
    if(fav_num == 666){
        printf("Wow, that's a bit suspicious...\n");
    }
    else{
        printf("Interesting choice. It's always good to keep an open mind.\n");
    }

    printf("\nOkay, one final question. What's your biggest fear? ");
    char fear_input[MAX_STRING_LENGTH];
    scanf("%s", fear_input);
    if(strcmp(fear_input, "government surveillance") == 0){
        printf("You're not paranoid if they really are watching you...\n");
    }
    else{
        printf("Ah, I see. A healthy fear is a sign of intelligence.\n");
    }

    printf("\nThanks for answering my questions. Just remember: trust no one.\n");

    return 0;
}