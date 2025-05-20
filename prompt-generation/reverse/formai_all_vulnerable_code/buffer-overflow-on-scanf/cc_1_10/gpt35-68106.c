//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: high level of detail
#include<stdio.h>
#include<string.h>

// Function to swap the order of two characters in a string
void swap(char *s, int i, int j){
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

// Function to convert English to Alien Language
void englishToAlien(char *s){
    int n = strlen(s);
    
    // Generating the Alien Language
    for(int i=0; i<n; i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            swap(s, i, i+1);
            i++;
        }
        else{
            swap(s, i-1, i+1);
            i += 2;
        }
    }
}

// Function to convert Alien Language to English
void alienToEnglish(char *s){
    int n = strlen(s);
    
    // Generating the English Language
    for(int i=0; i<n; i++){
        if(s[i+1] >= 'a' && s[i+1] <= 'z'){
            swap(s, i, i+1);
            i++;
        }
        else{
            swap(s, i-1, i+1);
            i += 2;
        }
    }
}

// Driver code
int main(){
    char s[100];
    int op;
    printf("Welcome to Alien Language Translator\n");
    printf("Enter 1 for English to Alien Language\n");
    printf("Enter 2 for Alien Language to English\n");
    scanf("%d", &op);
    
    // Take input from user
    printf("Enter the string: ");
    scanf("%s", s);
    
    switch(op){
        case 1:
            englishToAlien(s);
            printf("Alien Language: %s", s);
            break;
        case 2:
            alienToEnglish(s);
            printf("English Language: %s", s);
            break;
        default:
            printf("Invalid option selected!");
    }
    return 0;
}