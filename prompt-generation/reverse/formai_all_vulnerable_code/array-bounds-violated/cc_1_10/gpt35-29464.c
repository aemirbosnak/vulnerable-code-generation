//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: rigorous
#include <stdio.h>
#include <ctype.h>

char * morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
                 "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
                 "..-","...-",".--","-..-","-.--","--.."};

char* textToMorse(char *s){

    static char output[1000];
    char c;
    int i=0;
    int j=0;

    while((c = *s++) != '\0'){
        if(isalpha(c) || isdigit(c)) {
            c = toupper(c);
            if (isdigit(c)) {
                output[i++] = '>';
            }
            int index = c - 'A';
            char *m = morse[index];
            while(*m){
                output[i++] = *m++;
            }
            output[i++] = ' ';
            j=0;
        }
        else if (isspace(c)){
            j++;
            if(j == 2){
                output[--i] = ' ';
                output[i+1] = '/';
                output[i+2] = ' ';
                i += 3;
                j=0;
            }
        }
        else{
            continue; 
        }
    }
    output[--i] = '\0';
    return output;
}

int main(void) {

    char input[1000];
    printf("Enter text to convert to Morse code: ");
    fgets(input, 1000, stdin);
    char *output = textToMorse(input);
    printf("\nMorse code: %s\n", output);

    return 0;
}