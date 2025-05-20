//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: calm
#include<stdio.h>

// Function to convert English to C Cat Language
void engToCat(char english[]) {
    int i=0;
    
    // Loop through each letter of the english input
    while(english[i] != '\0') {
        if(english[i] == 'c' || english[i] == 'C') {
            printf("meow ");
        }
        else if(english[i] == 'a' || english[i] == 'A') {
            printf("purr ");
        }
        else if(english[i] == 't' || english[i] == 'T') {
            printf("hiss ");
        }
        else {
            printf("%c", english[i]);
        }
        i++;
    }
    printf("\n");
}

// Function to convert C Cat Language to English
void catToEng(char cat[]) {
    int i=0;
    
    // Loop through each word of the C Cat Language input
    while(cat[i] != '\0') {
        if(cat[i] == 'm' && cat[i+1] == 'e' && cat[i+2] == 'o' && cat[i+3] == 'w') {
            printf("c");
            i+=3;
        }
        else if(cat[i] == 'p' && cat[i+1] == 'u' && cat[i+2] == 'r' && cat[i+3] == 'r') {
            printf("a");
            i+=3;
        }
        else if(cat[i] == 'h' && cat[i+1] == 'i' && cat[i+2] == 's' && cat[i+3] == 's') {
            printf("t");
            i+=3;
        }
        else {
            printf("%c", cat[i]);
        }
        i++;
    }
    printf("\n");
}

int main() {
    int option;
    char english[100], cat[100];
    
    printf("Welcome to the C Cat Language Translator\n\n");
    
    do {
        printf("Enter 1 to translate from English to C Cat Language\n");
        printf("Enter 2 to translate from C Cat Language to English\n");
        printf("Enter 3 to exit\n\n");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                printf("Enter the English text to translate:\n");
                fflush(stdin);
                fgets(english, 100, stdin);
                printf("The C Cat Language translation is:\n");
                engToCat(english);
                break;
            case 2:
                printf("Enter the C Cat Language to translate:\n");
                fflush(stdin);
                fgets(cat, 100, stdin);
                printf("The English translation is:\n");
                catToEng(cat);
                break;
            case 3:
                printf("Thanks for using the C Cat Language Translator\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
        printf("\n");
    } while(option != 3);
    
    return 0;
}