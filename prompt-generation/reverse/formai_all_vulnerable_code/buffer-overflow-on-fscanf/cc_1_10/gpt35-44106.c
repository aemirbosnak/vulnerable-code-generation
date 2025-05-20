//FormAI DATASET v1.0 Category: Spell checking ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_WORD_LEN 30 //MAXIMUM WORD LENGTH TO BE CHECKED
#define MAX_WORD_COUNT 1000 //MAXIMUM NUMBER OF WORDS TO BE CHECKED IN A FILE

char dictionary[MAX_WORD_COUNT][MAX_WORD_LEN];
//ARRAY TO STORE DICTIONARY WORDS

//FUNCTION TO CONVERT ALL CAPITAL CASE CHARS IN A STRING TO LOWER CASE
void toLowerCase(char *str){
    int len=strlen(str);
    for(int i=0;i<len;i++){
        if(str[i]>='A' && str[i]<='Z')
            str[i]=str[i]+32;
    }
}

//FUNCTION TO CHECK SPELLING OF GIVEN WORD
int checkSpelling(char *word,int dictSize){
    toLowerCase(word);

    for(int i=0;i<dictSize;i++){
        if(strcmp(dictionary[i],word)==0)
            return 1;
    }
    return 0;
}

int main(){
    char fileName[100];
    printf("Enter Name of File To Check Spellings: ");
    scanf("%s",fileName);
    FILE *fptr=fopen(fileName,"r");
    if(fptr==NULL){
        printf("File Not Found!");
        exit(0);
    }

    //READ DICTIONARY WORDS AND STORE IN ARRAY
    FILE *dictFptr=fopen("dictionary.txt","r");
    int dictSize=0;
    while(!feof(dictFptr)){
        fscanf(dictFptr,"%s",dictionary[dictSize]);
        dictSize++;
    }
    fclose(dictFptr);

    char str[MAX_WORD_LEN];
    int lineNo=1;
    int wordCount=0;
    while(fgets(str,MAX_WORD_LEN,fptr)){
        toLowerCase(str);
        char *word=strtok(str," \n\t");

        while(word!=NULL){
            if(!checkSpelling(word,dictSize)){
                printf("\n\nError: Spelling mistake in word '%s' on line %d\n\n",word,lineNo);
            }
            word=strtok(NULL," \n\t");
            wordCount++;
        }
        lineNo++;
    }
    printf("\nSpell Checking Completed! Total Words Checked: %d",wordCount);

    fclose(fptr);
    return 0;
}