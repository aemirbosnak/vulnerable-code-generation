//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert_to_cat_language(char input[]);
void convert_to_english_language(char input[]);

int main() {
    char input[100];
    int choice;
    printf("Welcome to the Cat Language Translator!\n");
    do {
        printf("\nPlease choose an option:\n");
        printf("1. Convert English to Cat Language\n");
        printf("2. Convert Cat Language to English\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
    
        switch(choice) {
            case 1:
                printf("\nEnter English text: ");
                getchar(); // remove newline from previous input
                fgets(input, 100, stdin);
                convert_to_cat_language(input);
                break;
            case 2:
                printf("\nEnter Cat text: ");
                getchar(); // remove newline from previous input
                fgets(input, 100, stdin);
                convert_to_english_language(input);
                break;
            case 3:
                printf("\nThanks for using the Cat Language Translator!\n");
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    } while(choice != 3);
    
    return 0;
}

void convert_to_cat_language(char input[]) {
    int i;
    for(i = 0; i < strlen(input); i++) {
        switch(input[i]) {
            case 'a':
                printf("meow ");
                break;
            case 'b':
                printf("purr ");
                break;
            case 'c':
                printf("hiss ");
                break;
            // add more cases as needed
            default:
                printf("%c", input[i]);
        }
    }
}

void convert_to_english_language(char input[]) {
    int i;
    char* token;
    char delimiter[] = " ";
    token = strtok(input, delimiter);
    while(token != NULL) {
        if(strcmp(token, "meow") == 0) {
            printf("a");
        } else if(strcmp(token, "purr") == 0) {
            printf("b");
        } else if(strcmp(token, "hiss") == 0) {
            printf("c");
        } else {
            printf("%s", token);
        }
        token = strtok(NULL, delimiter);
    }
}