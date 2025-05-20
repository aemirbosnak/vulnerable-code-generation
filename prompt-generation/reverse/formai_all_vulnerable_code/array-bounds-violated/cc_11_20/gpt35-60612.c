//FormAI DATASET v1.0 Category: Word Count Tool ; Style: minimalist
#include<stdio.h>
#include<string.h>
#define MAX_WORD_LENGTH 20
#define MAX_WORDS 200

int main(int argc, char const *argv[]){

    char input_string[10000];
    int length = 0, i = 0, j = 0, word_count = 0, flag = 0, word_length = 0, repeated_count = 0;
    char words_arr[MAX_WORDS][MAX_WORD_LENGTH];

    printf("Enter the string to count words: ");
    fgets(input_string, sizeof(input_string), stdin);

    length = strlen(input_string);
    if(input_string[length-1]=='\n')
        input_string[length-1]='\0';

    while(input_string[i]!='\0'){
        if(input_string[i]==' ' || input_string[i]=='\t' || input_string[i]=='\n' || input_string[i]==','
            || input_string[i]=='.' || input_string[i]=='\r'){

            if(word_length!=0){
                words_arr[word_count][word_length]='\0';
                word_count++;
                word_length=0;
            }
        }else{
            if(word_length==0){
                j=i;
            }
            words_arr[word_count][word_length]=input_string[i];
            word_length++;
        }

        i++;
    }

    for(i=0; i<word_count; i++){
        flag = 1;
        for(j=0; j<word_count; j++){
            if(strcmp(words_arr[i], words_arr[j]) == 0){
                if(i>j){
                    repeated_count++;
                }
                if(flag){
                    printf("%s : %d\n", words_arr[i], 1);
                }
                flag = 0;
            }
        }
    }

    printf("Repeated words count = %d", repeated_count);

    return 0;
}