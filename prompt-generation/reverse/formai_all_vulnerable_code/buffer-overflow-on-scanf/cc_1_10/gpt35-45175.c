//FormAI DATASET v1.0 Category: Spell checking ; Style: visionary
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int check_word(char *);
void suggest_spellings(char *);

int main(){
    char word[50];
    printf("Enter word to be checked: ");
    scanf("%s",word);
    int check = check_word(word);
    if(check==1){
        printf("The spelling is correct.\n");
    }
    else if(check==0){
        suggest_spellings(word);
    }
    return 0;
}

int check_word(char *word){
    //assume that the correct spelling is "programming"
    char correct_spelling[50] = "programming";
    int len = strlen(word);
    if(len!=strlen(correct_spelling)){
        return 0; //spellings are different
    }
    else{
        for(int i=0;i<len;i++){
            if(tolower(word[i])!=tolower(correct_spelling[i])){
                return 0; //spellings are different
            }
        }
        return 1; //spellings are same
    }
}

void suggest_spellings(char *word){
    //List of possible spellings
    char list[5][50] = {"programing","programmin","progaming","program","programmingg"};
    printf("The spelling is incorrect. Possible suggestions are: \n");
    for(int i=0;i<5;i++){
        int len1 = strlen(word), len2 = strlen(list[i]);
        if(len1==len2){
            int flag=1;
            for(int j=0;j<len1;j++){
                if(tolower(list[i][j])!=tolower(word[j])){
                    flag=0; //different spellings
                    break;
                }
            }
            if(flag==1){
                printf("%s\n",list[i]); //similar spellings
            }
        }
        else if(len1+1==len2){
            int flag=1;
            for(int j=0,k=0;j<len2;j++,k++){
                if(j==len1){
                    if(tolower(list[i][j])!=tolower(list[i][j+1])){
                        flag=0; //different spellings
                        break;
                    }
                    else{
                        k--; //skip extra character in suggestion
                        continue;
                    }
                }
                if(tolower(word[k])!=tolower(list[i][j])){
                    flag=0; //different spellings
                    break;
                }
            }
            if(flag==1){
                printf("%s\n",list[i]); //similar spellings
            }
        }
    }
}