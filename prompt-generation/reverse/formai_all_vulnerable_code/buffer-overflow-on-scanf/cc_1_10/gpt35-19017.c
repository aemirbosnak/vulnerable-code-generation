//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: futuristic
#include <stdio.h>
#include <string.h>

int main()
{
    char text[1000];   //declaring a character array to store the text to be converted
    char morse[26][10] = {       //declaring a 2D array to store the morsecode corresponding to each alphabet
        {".-"},
        {"-..."},
        {"-.-."},
        {"-.."},
        {"."},
        {"..-."},
        {"--."},
        {"...."},
        {".."},
        {".---"},
        {"-.-"},
        {".-.."},
        {"--"},
        {"-."},
        {"---"},
        {".--."},
        {"--.-"},
        {".-."},
        {"..."},
        {"-"},
        {"..-"},
        {"...-"},
        {".--"},
        {"-..-"},
        {"-.--"},
        {"--.."}
    };
    printf("Enter text to convert to morse code:\n");  //prompt user to enter text
    scanf("%[^\n]", text);   //read the text entered by the user
    printf("Text entered: %s\n", text);  //print the entered text

    for(int i = 0; i < strlen(text); i++) {
        if(text[i] == ' ')
            printf("   ");    //if space is encountered, print three spaces to indicate word separator
        else if(text[i] >= 'A' && text[i] <= 'Z')
            printf("%s ", morse[text[i] - 'A']);    //if uppercase alphabet is encountered, print the morsecode corresponding to it
        else if(text[i] >= 'a' && text[i] <= 'z')
            printf("%s ", morse[text[i] - 'a']);    //if lowercase alphabet is encountered, print the morsecode corresponding to it
        else if(text[i] >= '0' && text[i] <= '9')
            printf("%s ", morse[text[i] - '0' + 22]);    //if a number is encountered, print the morsecode corresponding to it
        else
            printf("  ");    //if any other character is encountered, print two spaces to indicate invalid character
    }

    return 0;
}