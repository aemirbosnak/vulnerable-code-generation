//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define the function to convert text to ASCII art
void text_to_ascii_art(char* text){

    //Length of the input text
    int length = strlen(text);
    //Define array of ASCII characters
    char ascii_chars[][10] = {
                        "  *****  ",
                        " *     * ",
                        "*  0  0 *",
                        "*   ^   *",
                        " * \\_/ * ",
                        "  *****  "
                        };
    int row, col, i, j;

    //Loop through each row of the ASCII art array
    for(row=0; row<6; row++){
        //Loop through each character of the input text
        for(i=0; i<length; i++){
            //Get the ASCII code of the current character
            int ascii_code = (int)text[i];

            //Print the corresponding row of the ASCII character for the current row of the ASCII art
            for(col=0; col<7; col++){
                if(ascii_code>=65 && ascii_code<=90){
                    printf("%c", ascii_chars[row][col]+(ascii_code-65));
                } else if(ascii_code>=97 && ascii_code<=122){
                    printf("%c", ascii_chars[row][col]+(ascii_code-97));
                } else if(ascii_code>=48 && ascii_code<=57){
                    printf("%c", ascii_chars[row][col]+(ascii_code-48));
                } else {
                    printf("%c", ascii_chars[row][col]);
                }
            }

            //Print a space between characters
            printf("  ");
        }

        //Print a new line after each row of the ASCII art is printed
        printf("\n");
    }
}

int main(){

    //Get user input
    char input[100];
    printf("Enter some text to convert to ASCII art:\n");
    scanf("%[^\n]", input);

    //Convert the input text to ASCII art
    text_to_ascii_art(input);

    return 0;
}