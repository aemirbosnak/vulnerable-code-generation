//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: systematic
#include <stdio.h>
#include <string.h>

// function to print the ASCII art for each character
void printASCII(char c){
    switch(c){
        case 'A':
            printf("        /\\      \n");
            printf("       /  \\     \n");
            printf("      /    \\    \n");
            printf("     /______\\   \n");
            printf("    /        \\  \n");
            printf("   /          \\ \n");
            break;
        case 'B':
            printf(" ________   \n");
            printf("|        \\  \n");
            printf("|         | \n");
            printf("|________/  \n");
            printf("|         \\ \n");
            printf("|_________/ \n");
            break;
        case 'C':
            printf("  _______  \n");
            printf(" /       \\ \n");
            printf("|          \n");
            printf("|          \n");
            printf("|          \n");
            printf(" \\_______/ \n");
            break;
        case 'D':
            printf(" ________  \n");
            printf("|        \\ \n");
            printf("|         |\n");
            printf("|         |\n");
            printf("|         |\n");
            printf("|________/\n");
            break;
        case 'E':
            printf(" ________ \n");
            printf("|         \n");
            printf("|         \n");
            printf("|______   \n");
            printf("|         \n");
            printf("|________ \n");
            break;
        default:
            printf("Oops! We don't have ASCII art for that character!\n");
    }
}

int main(){
    char userString[50];
    printf("Enter a string: ");
    scanf("%s", userString);
    
    int len = strlen(userString);
    for(int i=0; i<len; i++){
        printASCII(userString[i]);  // print the ASCII art for each character in the string
    }
    
    return 0;
}