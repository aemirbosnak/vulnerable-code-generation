//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to translate from English to C Alien Language
void english_to_alien(char *str){
    int len = strlen(str);
    for(int i=0; i<len; i++){
        if(str[i] == 'a'){
            printf("W");
        }
        else if(str[i] == 'b'){
            printf("D");
        }
        else if(str[i] == 'c'){
            printf("F");
        }
        else if(str[i] == 'd'){
            printf("P");
        }
        else if(str[i] == 'e'){
            printf("M");
        }
        else if(str[i] == 'f'){
            printf("L");
        }
        else if(str[i] == 'g'){
            printf("S");
        }
        else if(str[i] == 'h'){
            printf("V");
        }
        else if(str[i] == 'i'){
            printf("N");
        }
        else if(str[i] == 'j'){
            printf("U");
        }
        else if(str[i] == 'k'){
            printf("Z");
        }
        else if(str[i] == 'l'){
            printf("Q");
        }
        else if(str[i] == 'm'){
            printf("G");
        }
        else if(str[i] == 'n'){
            printf("Y");
        }
        else if(str[i] == 'o'){
            printf("X");
        }
        else if(str[i] == 'p'){
            printf("J");
        }
        else if(str[i] == 'q'){
            printf("H");
        }
        else if(str[i] == 'r'){
            printf("K");
        }
        else if(str[i] == 's'){
            printf("R");
        }
        else if(str[i] == 't'){
            printf("B");
        }
        else if(str[i] == 'u'){
            printf("A");
        }
        else if(str[i] == 'v'){
            printf("T");
        }
        else if(str[i] == 'w'){
            printf("E");
        }
        else if(str[i] == 'x'){
            printf("O");
        }
        else if(str[i] == 'y'){
            printf("I");
        }
        else if(str[i] == 'z'){
            printf("C");
        }
        else if(str[i] == ' '){
            printf(" ");
        }
    }
}

int main(){
    char english[100], alien[100];
    printf("Enter English Sentence:\n");
    scanf("%[^\n]", english);
    getchar();
    english_to_alien(english);
    printf("\nEnter C Alien Sentence:\n");
    scanf("%[^\n]", alien);
    getchar();
    printf("Oh, C Alien says: ");
    puts(alien);
    printf("\n");

    return 0;
}