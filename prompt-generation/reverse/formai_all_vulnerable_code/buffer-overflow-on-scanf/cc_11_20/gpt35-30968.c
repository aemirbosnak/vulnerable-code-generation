//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: immersive
#include<stdio.h>
#include<string.h>

/* Function to convert character to ASCII art */
char* convertToAsciiArt(char ch){
    switch(ch){
        case 'A':
            return "  /\\  \n /  \\ \n/____\\\n/    \\\n";
        case 'B':
            return " ____ \n|    \\\n|____/\n|    \\\n|____/\n";
        case 'C':
            return "  ___\n /   \\\n/     \\\n\\     /\n \\___/\n";
        case 'D':
            return " ____ \n|    \\\n|     \\\n|     /\n|____/\n";
        case 'E':
            return " ____\n|    \n|____\n|    \n|____\n";
        case 'F':
            return " ____\n|    \n|____\n|    \n|\n";
        case 'G':
            return "  ___\n /   \\\n/     \\\n\\   __/\n \\___\\\n";
        case 'H':
            return "    |  \n ___|___\n|       |\n|       |\n|       |\n";
        case 'I':
            return " ___\n|   |\n|   |\n|   |\n|___|\n";
        case 'J':
            return "   ___\n  |   |\n  |   |\n  |   |\n  |___|\n";
        case 'K':
            return "|    / \n|___/  \n| \\    \n|  \\   \n|   \\  \n";
        case 'L':
            return "|\n|\n|\n|\n|____\n";
        case 'M':
            return "/\\   /\\ \n\\ \\ / / \n \\ V /  \n  \\ /   \n   V    \n";
        case 'N':
            return "\\     / \n \\   /  \n  \\ /   \n   |    \n   |    \n";
        case 'O':
            return "  ___  \n /   \\ \n/     \\\n\\     /\n \\___/\n";
        case 'P':
            return " ____ \n|    |\n|____|\n|     \n|\n";
        case 'Q':
            return "  ___  \n /   \\ \n/     \\\n\\  \\  /\n \\__\\/\n";
        case 'R':
            return " ____ \n|    |\n|____|\n| \\   \n|  \\  \n";
        case 'S':
            return " ____ \n|     \n|____\n     |\n____|\n";
        case 'T':
            return " _____ \n   |\n   |\n   |\n   |\n";
        case 'U':
            return "|       |\n|       |\n|       |\n \\     /\n  \\___/\n";
        case 'V':
            return "\\     / \n \\   /  \n  \\ /   \n   V    \n";
        case 'W':
            return "|       |\n|       |\n|   V   |\n \\ / \\ / \n  V   V  \n";
        case 'X':
            return "\\    /\n \\  /\n  \\/\n  /\\\n /  \\\n";
        case 'Y':
            return "\\     /\n \\   /\n  \\ /\n   |\n   |\n";
        case 'Z':
            return " ____\n    /\n  __/\n /  \n/____\n";
        default:
            return "";
    }
}

int main(){
    char input[100];
    printf("Enter a word or phrase to convert to ASCII art\n");
    scanf("%s", input);
    int len = strlen(input);
    char output[len][1000];
    for(int i=0; i<len; i++){
        char *temp = convertToAsciiArt(input[i]);
        if(strcmp(temp, "") == 0){
            printf("Invalid character '%c' detected! Try again.\n", input[i]);
            return 0;
        }
        strcpy(output[i], temp);
    }
    for(int i=0; i<5; i++){
        for(int j=0; j<len; j++){
            printf("%s", strtok(output[j], "\n"));
            if(strlen(output[j]) > 1){
                strtok(NULL, "\n");
            }
        }
        printf("\n");
    }
    return 0;
}