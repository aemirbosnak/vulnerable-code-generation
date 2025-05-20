//FormAI DATASET v1.0 Category: Spell checking ; Style: genious
#include<stdio.h>
#include<string.h>
#include<ctype.h>

char dictionary[][20] = {"spell", "checker", "program", "example", "code", "genius"};

int checkWord(char *word){
    int i, len, flag = 0;
    char temp[20];

    len = strlen(word);

    for(i=0;i<len;i++){
        temp[i] = tolower(word[i]);
    }
    temp[i] = '\0';

    for(i=0;i<6;i++){
        if(strcmp(dictionary[i], temp) == 0){
            flag = 1;
            break;
        }
    }

    return flag;
}

int main(){

    char sentence[100], word[20], ch;
    int i, j = 0, len, flag;

    printf("Enter a sentence: ");
    gets(sentence);

    len = strlen(sentence);

    for(i=0;i<=len;i++){

        ch = sentence[i];

        if(isalnum(ch)){
            word[j] = ch;
            j++;
        }

        else if(ch == ' ' || ch == '\0'){

            word[j] = '\0';
            flag = checkWord(word);

            if(flag == 0){
                printf("'%s' is misspelled.\n", word);
            }

            j=0;

        }

    }

    return 0;
}