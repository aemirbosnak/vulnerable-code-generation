//FormAI DATASET v1.0 Category: Text processing ; Style: inquisitive
#include<stdio.h>
#include<string.h>

int main() {
    char text[1000];
    int vowels=0, consonants=0, digits=0, spaces=0;
    printf("Enter any text: ");

    /* read input from user */
    fgets(text, sizeof(text), stdin);

    /* remove trailing newline character */
    text[strlen(text)-1] = '\0';

    /* check each character of the text */
    for(int i=0; text[i]!='\0'; i++) {

        /* check for vowels */
        if(text[i]=='a' || text[i]=='e' || text[i]=='i' || text[i]=='o' || text[i]=='u' 
           || text[i]=='A' || text[i]=='E' || text[i]=='I' || text[i]=='O' || text[i]=='U') 
        {
            vowels++;
        }

        /* check for consonants */
        else if((text[i]>='a' && text[i]<='z') || (text[i]>='A' && text[i]<='Z')) 
        {
            consonants++;
        }

        /* check for digits */
        else if(text[i]>='0' && text[i]<='9') 
        {
            digits++;
        }

        /* check for spaces */
        else if(text[i] == ' ')
        {
            spaces++;
        }
    }

    /* display the results */
    printf("\nTotal vowels in the text: %d", vowels);
    printf("\nTotal consonants in the text: %d", consonants);
    printf("\nTotal digits in the text: %d", digits);
    printf("\nTotal spaces in the text: %d", spaces);

    return 0;
}