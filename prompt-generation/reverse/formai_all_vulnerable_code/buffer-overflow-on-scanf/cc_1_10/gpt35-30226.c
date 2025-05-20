//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* translateAlienLanguage(char* input){
    int len_input = strlen(input);
    char* output = malloc(2 * len_input * sizeof(char));
    int i, j = 0;
    for(i = 0; i < len_input; i++){
        if(input[i] == '1'){
            output[j++] = 'a';
            output[j++] = 'x';
            output[j++] = 'o';
        }
        else if(input[i] == '2'){
            output[j++] = 'b';
            output[j++] = 'l';
            output[j++] = 'i';
            output[j++] = 'x';
        }
        else if(input[i] == '3'){
            output[j++] = 'c';
            output[j++] = 'y';
            output[j++] = 'x';
            output[j++] = 'a';
        }
        else if(input[i] == '4'){
            output[j++] = 'd';
            output[j++] = 'i';
            output[j++] = 'z';
            output[j++] = 'z';
        }
        else if(input[i] == '5'){
            output[j++] = 'e';
            output[j++] = 'v';
            output[j++] = 'a';
        }
        else if(input[i] == '6'){
            output[j++] = 'f';
            output[j++] = 'i';
            output[j++] = 'n';
            output[j++] = 'x';
        }
        else if(input[i] == '7'){
            output[j++] = 'g';
            output[j++] = 'l';
            output[j++] = 'a';
            output[j++] = 'x';
        }
        else if(input[i] == '8'){
            output[j++] = 'h';
            output[j++] = 'u';
            output[j++] = 'b';
            output[j++] = 'b';
        }
        else if(input[i] == '9'){
            output[j++] = 'i';
            output[j++] = 'n';
            output[j++] = 't';
            output[j++] = 'i';
            output[j++] = 'l';
            output[j++] = 'y';
        }
        else if(input[i] == '0'){
            output[j++] = 'j';
            output[j++] = 'o';
            output[j++] = 'o';
            output[j++] = 'm';
        }
    }
    output[j] = '\0';
    return output;
} 

int main(){
    printf("Enter alien language input code: ");
    char input[100];
    scanf("%s", input);
    char* output = translateAlienLanguage(input);
    printf("Translated output: %s\n", output);
    free(output);
    return 0;
}