//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: irregular
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    printf("Welcome to the Alien Language Translator!\n");
    printf("Enter the number of Alien words you wish to translate: ");
    int num_words;
    scanf("%d", &num_words);
    
    char alien_words[num_words][20];
    char translated_words[num_words][20];
    
    printf("\nBegin entering the Alien words:\n");
    for(int i=0; i<num_words; i++){
        printf("Alien Word #%d: ", i+1);
        scanf("%s", alien_words[i]);
    }
    
    printf("\nTranslating...\n\n");
    
    for(int i=0; i<num_words; i++){
        int len = strlen(alien_words[i]);
        char temp[len+1];
        strcpy(temp, alien_words[i]);
        
        for(int j=0; j<len;){
            if(temp[j]=='D'){
                if((j+1)<len && temp[j+1]=='O'){
                    translated_words[i][j/2] = 'A';
                    j += 2;
                }
                else{
                    translated_words[i][j/2] = 'E';
                    j += 1;
                }
            }
            else if(temp[j]=='E'){
                if((j+1)<len && temp[j+1]=='N'){
                    translated_words[i][j/2] = 'I';
                    j += 2;
                }
                else{
                    translated_words[i][j/2] = 'U';
                    j += 1;
                }
            }
            else if(temp[j]=='T'){
                if((j+1)<len && temp[j+1]=='R'){
                    if((j+2)<len && temp[j+2]=='I'){
                        translated_words[i][j/3] = 'L';
                        j += 3;
                    }
                    else{
                        translated_words[i][j/2] = 'O';
                        j += 2;
                    }
                }
                else{
                    translated_words[i][j/2] = 'N';
                    j += 1;
                }
            }
            else{
                translated_words[i][j/2] = '-';
                j += 1;
            }
        }
    }
    
    printf("Translation Complete!\n\n");
    
    for(int i=0; i<num_words; i++){
        printf("Alien Word #%d: %s -> Translated Word: %s\n", i+1, alien_words[i], translated_words[i]);
    }
    
    printf("\nThank you for using the Alien Language Translator! Exiting...\n");
    return 0;
}