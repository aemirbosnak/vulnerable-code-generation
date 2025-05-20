//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: complex
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void delay(){
    int i,j;
    for(i=0;i<1500;i++)
        for(j=0;j<150;j++);
}

void dot(){
    printf(". ");
    delay();   
}

void dash(){
    printf("- ");
    delay();   
}

void encode(char c[]){
    int i,j;
    char morse[37][5]={
        {".-"},      //A
        {"-..."},    //B
        {"-.-."},    //C
        {"-.."},     //D
        {"."},       //E
        {"..-."},    //F
        {"--."},     //G
        {"...."},    //H
        {".."},      //I
        {".---"},    //J
        {"-.-"},     //K
        {".-.."},    //L
        {"--"},      //M
        {"-."},      //N
        {"---"},     //O
        {".--."},    //P
        {"--.-"},    //Q
        {".-."},     //R
        {"..."},     //S
        {"-"},       //T
        {"..-"},     //U
        {"...-"},    //V
        {".--"},     //W
        {"-..-"},    //X
        {"-.--"},    //Y
        {"--.."},    //Z
        {"-----"},   //0
        {".----"},   //1
        {"..---"},   //2
        {"...--"},   //3
        {"....-"},   //4
        {"....."},   //5
        {"-...."},   //6
        {"--..."},   //7
        {"---.."},   //8
        {"----."},   //9
        {"--..--"},  //,
        {".-.-.-"},  //.
        {"..--.."}   //?
    };
    char letters[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.?";
    for(i=0;c[i]!='\0';i++){
        for(j=0;j<37;j++){
            if(toupper(c[i])==letters[j]){
                printf("%s ",morse[j]);
            }
        }
    }
}

int main(){
    char text[100];
    printf("Enter the text to be converted to Morse Code:\n");
    scanf("%[^\n]s",text);
    printf("\nThe Morse Code Representation of the entered text:\n");
    encode(text);
    printf("\n");
    return 0;
}