//FormAI DATASET v1.0 Category: Text processing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void toUpperCase(char *str){
    int i=0;
    while(str[i]!='\0'){
        if(str[i]>='a' && str[i]<='z')
            str[i] = str[i] - ('a'-'A');
        i++;
    }
}

void toLowerCase(char *str){
    int i=0;
    while(str[i]!='\0'){
        if(str[i]>='A' && str[i]<='Z')
            str[i] = str[i] + ('a'-'A');
        i++;
    }
}

int main(){
    char sentence[100];
    int choice;

    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);

    printf("What do you want to do with the sentence?\n");
    printf("1. Convert to UPPERCASE\n");
    printf("2. Convert to lowercase\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);

    switch(choice){
        case 1:
            toUpperCase(sentence);
            printf("The sentence in UPPERCASE is: %s", sentence);
            break;

        case 2:
            toLowerCase(sentence);
            printf("The sentence in lowercase is: %s", sentence);
            break;

        default:
            printf("Invalid choice. Please enter 1 or 2.");
    }

    return 0;
}