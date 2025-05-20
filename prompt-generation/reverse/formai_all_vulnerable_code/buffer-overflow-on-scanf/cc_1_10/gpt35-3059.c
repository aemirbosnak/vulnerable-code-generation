//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main(){
    char input[100];
    printf("Enter a text to generate ASCII Art: ");
    scanf("%[^\n]", input); //Read input until new line character is encountered
    int length = strlen(input);

    //Check if the length of input is less than 3 characters
    if(length < 3){
        printf("Error: Text must be at least 3 characters long.");
        return 0;
    }

    //Generate the ASCII Art
    printf("\nHere is your ASCII Art:\n\n");

    //Print the first line
    for(int i=0; i<length; i++){
        printf("_____");
    }
    printf("__\n");

    //Print the second line
    printf("/");
    for(int i=0; i<length; i++){
        printf("    ");
    }
    printf("\\\n");

    //Print the third line
    printf("|");
    for(int i=0; i<length; i++){
        printf(" %c%c ", input[i], input[i]);
    }
    printf("|\n");

    //Print the fourth line
    for(int i=0; i<length; i++){
        printf("\\___");
    }
    printf("/\n");

    //Print the fifth line
    printf("|");
    for(int i=0; i<length; i++){
        printf("    ");
    }
    printf("|\n");

    //Print the sixth line
    printf("\\");
    for(int i=0; i<length; i++){
        printf("    ");
    }
    printf("/\n");

    return 0;
}