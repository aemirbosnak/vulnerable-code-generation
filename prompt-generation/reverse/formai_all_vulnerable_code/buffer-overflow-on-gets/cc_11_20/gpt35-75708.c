//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: detailed
#include<stdio.h>
#include<string.h>

//Function to translate C Cat Language to English

void cCatTranslator(char input[]) {
    char word[20], output[1000];
    int i = 0, j = 0;
    while(input[i] != '\0') {
        if(input[i] == '>' && input[i+1] == '>') {
            strcat(output, "please ");
            i += 2;
            j += 7;
        }
        else if(input[i] == '<' && input[i+1] == '<') {
            strcat(output, "thank you ");
            i += 2;
            j += 10;
        }
        else if(input[i] == ')' && input[i+1] == ':') {
            strcat(output, "smile ");
            i += 2;
            j += 6;
        }
        else if(input[i] == '(' && input[i+1] == ':') {
            strcat(output, "frown ");
            i += 2;
            j += 6;
        }
        else if(input[i] == ')' && input[i+1] == ';') {
            strcat(output, "wink ");
            i += 2;
            j += 5;
        }
        else if(input[i] == '(' && input[i+1] == ';') {
            strcat(output, "sad wink ");
            i += 2;
            j += 9;
        }
        else if(input[i] == ')' && input[i+1] == '/') {
            strcat(output, "smile blush ");
            i += 2;
            j += 13;
        }
        else if(input[i] == '(' && input[i+1] == '/') {
            strcat(output, "frown blush ");
            i += 2;
            j += 13;
        }
        else {
            j += 1;
            word[j] = input[i];
            if(input[i+1] == ' ' || input[i+1] == '\0') {
                word[j+1] = '\0';
                if(strcmp(word, "meow") == 0)
                    strcat(output, "hello ");
                else if(strcmp(word, "purrr") == 0)
                    strcat(output, "goodbye ");
                else if(strcmp(word, "scratch") == 0)
                    strcat(output, "bye ");
                else if(strcmp(word, "hiss") == 0)
                    strcat(output, "no ");
                else
                    strcat(output, word);
                j = 0;
                word[0] = '\0';
            }
            i++;
        }
    }
    printf("%s", output);
}

int main() {
    char input[1000];
    printf("Enter the sentence in C Cat Language: ");
    gets(input);
    cCatTranslator(input);
    return 0;
}