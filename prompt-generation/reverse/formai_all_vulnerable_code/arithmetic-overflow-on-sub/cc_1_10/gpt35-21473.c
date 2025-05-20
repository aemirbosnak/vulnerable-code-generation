//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define MAX 1000

int main(){
    char para[MAX];
    int len, count=0, i, total_words=0, time_taken=0;

    //Get Input Paragraph
    printf("Type the following paragraph:\n");
    printf("The quick brown fox jumps over the lazy dog.\n");

    fgets(para, MAX, stdin);
    len=strlen(para);

    //Removing new line character from input
    if (para[len-1] == '\n'){
        para[len-1] = '\0';
    }
    printf("#########################\n");

    //Implementing Typing Test
    clock_t start=clock();
    i=0;
    while(para[i] != '\0'){
        if(para[i] == ' ' || para[i] == '.' || para[i] == ','){
            total_words++;
        }
        i++;
    }

    printf("***Typing Test: Enter the above paragraph***\n");
    while(1){
        char typed_para[MAX];
        fgets(typed_para, MAX, stdin);

        if (strcmp(typed_para, para) == 0){
            printf("#############################\n");
            printf("Typed Paragraph:\n%s\n", typed_para);
            printf("#############################\n");
            break;
        }
        else{
            printf("Incorrect Typed Paragraph. Please type again:\n");
            count++;
        }
    }
    clock_t end=clock();
    time_taken= ((end-start)*1000/CLOCKS_PER_SEC);

    //Typing Speed
    int typing_speed= (total_words*60)/time_taken;
    printf("Total Words:\t%d\n", total_words);
    printf("Time Taken:\t%d (ms)\n", time_taken);
    printf("Typing Speed:\t%d (Words per minute)\n", typing_speed);
    printf("Mistyped Paragraph count:\t%d\n", count);
    
    return 0; 
}