//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char s[15];
    printf("Hello and welcome to the Periodic Table Quiz!\n");
    printf("\nWhat year was the first periodic table published?\n");
    printf("choices: a) 1869 b) 1776 c) 1798 d) 1935\n");
    scanf("%s",s);
    if(strcmp(s,"a")==0){
        printf("Correct! You move on to the next question.\n");
    }else{
        printf("Sorry, that's incorrect. The correct answer is a) 1869.\n");
        printf("Better luck next time!\n");
        exit(0);
    }

    printf("\nWhat is the symbol for Iron?\n");
    printf("choices: a) Ir b) Fe c) In d) En\n");
    scanf("%s",s);
    if(strcmp(s,"b")==0){
        printf("Correct! You move on to the next question.\n");
    }else{
        printf("Sorry, that's incorrect. The correct answer is b) Fe.\n");
        printf("Better luck next time!\n");
        exit(0);
    }

    printf("\nWhich country produces the most Gold?\n");
    printf("choices: a) Russia b) Australia c) China d) United States\n");
    scanf("%s",s);
    if(strcmp(s,"c")==0){
        printf("Correct! You move on to the next question.\n");
    }else{
        printf("Sorry, that's incorrect. The correct answer is c) China.\n");
        printf("Better luck next time!\n");
        exit(0);
    }
    
    printf("\nWhat is the atomic number of Carbon?\n");
    printf("choices: a) 6 b) 14 c) 22 d) 52\n");
    scanf("%s",s);
    if(strcmp(s,"a")==0){
        printf("Correct! You move on to the next question.\n");
    }else{
        printf("Sorry, that's incorrect. The correct answer is a) 6.\n");
        printf("Better luck next time!\n");
        exit(0);
    }
    
    printf("\nWhat is the symbol for Sodium?\n");
    printf("choices: a) So b) Sd c) Sa d) Na\n");
    scanf("%s",s);
    if(strcmp(s,"d")==0){
        printf("Correct! You move on to the next question.\n");
    }else{
        printf("Sorry, that's incorrect. The correct answer is d) Na.\n");
        printf("Better luck next time!\n");
        exit(0);
    }
    
    printf("\nWhat is the chemical symbol for Gold?\n");
    printf("choices: a) Gd b) Au c) Ag d) Cu\n");
    scanf("%s",s);
    if(strcmp(s,"b")==0){
        printf("Congratulations! You have completed the Periodic Table Quiz!\n");
    }else{
        printf("Sorry, that's incorrect. The correct answer is b) Au.\n");
        printf("Better luck next time!\n");
    }

    return 0;
}