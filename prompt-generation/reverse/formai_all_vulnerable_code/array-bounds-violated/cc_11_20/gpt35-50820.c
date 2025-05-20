//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: energetic
#include<stdio.h>
#include<string.h>

//Function to check if character is a vowel
int isVowel(char letter){
    if(letter=='a' || letter=='e' || letter=='i' || letter=='o' || letter=='u' || letter=='A' || letter=='E' || letter=='I' || letter=='O' || letter=='U')
        return 1;
    else
        return 0;
}

int main(){

    char sentence[100];
    int i,j,spaceCount=0,vowelCount=0,consonantCount=0;

    printf("Enter a sentence in C Cat Language: ");
    fgets(sentence,100,stdin);

    //Removing newline character at the end of the input
    if(sentence[strlen(sentence)-1]=='\n')
        sentence[strlen(sentence)-1]='\0';

    //Converting lower case vowels to upper case and vice versa
    for(i=0;sentence[i]!='\0';i++){
        if(isVowel(sentence[i])){
            if(sentence[i]>='a' && sentence[i]<='z')
                sentence[i]-=32;
            else if(sentence[i]>='A' && sentence[i]<='Z')
                sentence[i]+=32;
        }
    }

    //Counting number of spaces, vowels and consonants in the sentence
    for(i=0;i<strlen(sentence);i++){
        if(sentence[i]==' ')
            spaceCount++;
        else if(isVowel(sentence[i]))
            vowelCount++;
        else if((sentence[i]>='a' && sentence[i]<='z') || (sentence[i]>='A' && sentence[i]<='Z'))
            consonantCount++;
    }

    //Printing the original and translated sentence along with the counts
    printf("\n\nOriginal Sentence: %s",sentence);
    printf("\nTranslated Sentence: %s",sentence);
    printf("\nNumber of Spaces: %d",spaceCount);
    printf("\nNumber of Vowels: %d",vowelCount);
    printf("\nNumber of Consonants: %d",consonantCount);

    return 0;
}