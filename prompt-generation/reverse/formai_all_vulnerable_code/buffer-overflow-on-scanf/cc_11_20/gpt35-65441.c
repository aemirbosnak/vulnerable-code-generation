//FormAI DATASET v1.0 Category: Spell checking ; Style: all-encompassing
#include <stdio.h>

int main(){
    char word[100];
    printf("Enter a word for spell checking: ");
    scanf("%s",word);
    int i=0, len=0, error=0;
    // finding the length of the word
    while(word[i]!='\0'){
        len++;
        i++;
    }
    // checking if the first letter is uppercase
    if(word[0]>='a' && word[0]<='z'){
        printf("\nDid you mean to capitalize the first letter? (y/n): ");
        char response;
        scanf(" %c",&response);
        if(response=='y'){
            word[0] = word[0] - 32; // converting lowercase to uppercase ASCII value
        }
        else{
            error++;
        }
    }
    // checking for letters other than alphabets
    for(i=0;i<len;i++){
        if(!isalpha(word[i])){
            printf("\nInvalid character detected. Please only enter alphabets.");
            return 0;
        }
    }
    // checking for common spelling errors
    if(strcmp(word,"definitely")==0){
        printf("\nDid you mean 'defiantly' instead of 'definitely'? (y/n): ");
        char response;
        scanf(" %c",&response);
        if(response=='y'){
            word[7] = 'a'; // replacing 'i' with 'a'
        }
        else{
            error++;
        }
    }
    // checking if the word ends in 's' or 'es' which makes it plural
    if(word[len-1]=='s' && (word[len-2]!='e' || (word[len-2]=='e' && word[len-3]=='s'))){
        printf("\n'%s' is a plural word. Did you mean to use the singular form? (y/n): ",word);
        char response;
        scanf(" %c",&response);
        if(response=='y'){
            if(word[len-2]=='e' && word[len-3]=='s'){ // removing 'es'
                word[len-2] = '\0';
                word[len-3] = '\0';
            }
            else{ // removing 's'
                word[len-1] = '\0';
            }
        }
        else{
            error++;
        }
    }
    // printing final result
    if(error==0){
        printf("\n'%s' is spelled correctly.",word);
    }
    else{
        printf("\nSorry, there were %d error/s found while spell checking '%s'.",error,word);
    }
    return 0;
}