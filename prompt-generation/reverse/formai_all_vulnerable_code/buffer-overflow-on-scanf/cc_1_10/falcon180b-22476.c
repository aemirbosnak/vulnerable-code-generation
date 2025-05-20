//Falcon-180B DATASET v1.0 Category: Text processing ; Style: romantic
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>

//Function to remove punctuations from the string
void removePunctuations(char* str){
    int i=0;
    int j=0;
    char temp[100];
    while(str[i]!='\0'){
        if(!isalnum(str[i])){
            i++;
        }else{
            temp[j++]=tolower(str[i]);
        }
        i++;
    }
    temp[j]='\0';
    strcpy(str,temp);
}

//Function to check if two strings are anagrams
bool isAnagram(char* str1, char* str2){
    int len1=strlen(str1);
    int len2=strlen(str2);
    if(len1!=len2){
        return false;
    }
    int count[26]={0};
    for(int i=0;str1[i]!='\0';i++){
        count[(int)str1[i]-97]++;
    }
    for(int j=0;str2[j]!='\0';j++){
        count[(int)str2[j]-97]--;
    }
    for(int k=0;k<26;k++){
        if(count[k]!=0){
            return false;
        }
    }
    return true;
}

int main(){
    char str1[100],str2[100];
    printf("Enter the first string: ");
    scanf("%s",str1);
    printf("Enter the second string: ");
    scanf("%s",str2);
    removePunctuations(str1);
    removePunctuations(str2);
    if(isAnagram(str1,str2)){
        printf("The strings are anagrams of each other.");
    }else{
        printf("The strings are not anagrams of each other.");
    }
    return 0;
}