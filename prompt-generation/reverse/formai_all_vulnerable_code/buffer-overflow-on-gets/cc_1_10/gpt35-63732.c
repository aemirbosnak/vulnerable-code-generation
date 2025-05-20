//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Ken Thompson
#include<stdio.h>
#include<string.h>

int main()
{
    char text[100], code[100], morse[26][10] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};        //morse code array for all the alphabets along with space and numbers
    int i, j, k = 0;

    printf("Enter text to be converted to Morse code: ");
    gets(text);     //taking input from the user

    for(i=0; i<strlen(text); i++)       //iterating through the string one character at a time
    {
        if(text[i] == ' ')      //if a space is detected, copy it directly into the result array
        {
            code[k++] = ' ';
            continue;
        }

        else if(text[i] >= '0' && text[i] <= '9')   //if a number is detected, calculate its numerical value as an index of the morse code array
        {
            j = text[i] - '0';
            strcpy(code+k, morse[j]);
            k += strlen(morse[j]);
            continue;
        }

        else if(text[i] >= 'a' && text[i] <= 'z')   //if a lowercase alphabet is detected, calculate its alphabetical value as an index of the morse code array
        {
            j = text[i] - 'a';
            strcpy(code+k, morse[j]);
            k += strlen(morse[j]);
            continue;
        }

        else if(text[i] >= 'A' && text[i] <= 'Z')   //if an uppercase alphabet is detected, convert it to lowercase and calculate its alphabetical value as an index of the morse code array
        {
            j = tolower(text[i]) - 'a';
            strcpy(code+k, morse[j]);
            k += strlen(morse[j]);
            continue;
        }

        else    //if any other character is detected, ignore it and move on to the next character
        {
            continue;
        }
    }

    code[k] = '\0';     //adding null character to mark the end of the result array

    printf("\nMorse code: %s\n\n", code);     //printing the resultant morse code

    return 0;
}