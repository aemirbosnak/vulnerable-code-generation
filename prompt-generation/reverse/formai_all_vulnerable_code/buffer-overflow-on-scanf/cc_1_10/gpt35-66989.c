//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: genious
#include<stdio.h>
#include<string.h>

//Function to translate from English to C Cat Language
void translateToCatLanguage(char* str) {
    int n = strlen(str);
    char result[n+1];
    int i;
    for(i=0;i<n;i++) {
        if(str[i]=='C' || str[i]=='c') {
            result[i] = 'Meow';
            result[++i] = 'e';
            result[++i] = 'o';
            result[++i] = 'w';
        } else {
            result[i] = str[i];
        }
    }
    result[n] = '\0';
    printf("In C Cat Language: %s\n", result);
}

//Function to translate from C Cat Language to English
void translateToEnglish(char* str) {
    int n = strlen(str);
    char result[n+1];
    int i;
    for(i=0;i<n;i++) {
        if(str[i]=='M' && str[i+1]=='e' && str[i+2]=='o' && str[i+3]=='w') {
            result[i] = 'C';
            i += 3;
        } else {
            result[i] = str[i];
        }
    }
    result[n] = '\0';
    printf("In English: %s\n", result);
}

int main() {
    int choice;
    printf("Welcome to C Cat Language Translator!\n");
    while(1) {
        //Menu for user to select choice of translation
        printf("Choose an option:\n");
        printf("1. Translate from English to C Cat Language\n2. Translate from C Cat Language to English\n3. Exit\n");
        scanf("%d", &choice);
        char str[100];
        switch(choice) {
            case 1:
                printf("Enter a sentence in English: ");
                getchar();
                fgets(str, 100, stdin);
                translateToCatLanguage(str);
                break;
            case 2:
                printf("Enter a sentence in C Cat Language: ");
                getchar();
                fgets(str, 100, stdin);
                translateToEnglish(str);
                break;
            case 3:
                printf("Thank you for using C Cat Language Translator!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}