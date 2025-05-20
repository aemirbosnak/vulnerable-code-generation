//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: active
#include <stdio.h>
#include <string.h>

// function to convert all characters to lowercase
void toLower(char *str) {
    for(int i=0; str[i]!='\0'; i++) {
        if(str[i]>='A' && str[i]<='Z') {
            str[i] = str[i] + 32;
        }
    }
}

// function to check if a character is a punctuation
int isPunctuation(char ch) {
    if(ch=='.' || ch==',' || ch==';' || ch==':' || ch=='?' || ch=='!' || ch=='(' || ch==')' || ch=='\'' || ch=='\"') {
        return 1;
    }
    return 0;
}

// function to remove punctuations from a string
void removePunctuations(char *str) {
    for(int i=0; str[i]!='\0'; i++) {
        if(isPunctuation(str[i])) {
            for(int j=i; str[j]!='\0'; j++) {
                str[j] = str[j+1];
            }
            i--;
        }
    }
}

int main() {

    char sentence[500];
    int count[26] = {0};

    printf("Enter a sentence: ");
    gets(sentence);

    toLower(sentence);
    removePunctuations(sentence);

    for(int i=0; sentence[i]!='\0'; i++) {
        if(sentence[i]>='a' && sentence[i]<='z') {
            count[sentence[i]-'a']++;
        }
    }

    printf("Letter frequency count:\n");
    for(int i=0; i<26; i++) {
        if(count[i]>0) {
            printf("%c: %d\n", i+'a', count[i]);
        }
    }

    return 0;
}