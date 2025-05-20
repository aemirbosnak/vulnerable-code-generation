//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: lively
#include<stdio.h>

int main(){

    char input[50];
    printf("Enter your text to convert to ASCII art: ");
    scanf("%s", input);

    printf("\n");

    int i = 0;

    while(input[i]){

        switch(input[i]){
            case 'a':
                printf("  /\\");
                printf(" /  \\");
                printf("/____\\");
                printf("\n");
                printf(" /\\  ");
                printf("/  \\ ");
                printf("/    \\");
                printf("\n");
                break;

            case 'b':
                printf(" |___\\");
                printf("|    /");
                printf("|___/");
                printf("\n");
                printf("|    \\");
                printf("|____/");
                printf("|    \\");
                printf("\n");
                break;

            case 'c':
                printf(".-/");
                printf("o o");
                printf("\\-.");
                printf("\n");
                printf("/__/__\\");
                printf("/_\\/__\\");
                printf("\n");
                break;

            case 'd':
                printf(" |\\");
                printf(" | \\");
                printf(" |  |");
                printf("\n");
                printf(" |  |");
                printf(" | /");
                printf(" |/ ");
                printf("\n");
                break;

            //continue for the entire alphabet

            default:
                printf("Invalid character entered!\n");
                break;
        }
        i++;
    }
    return 0;
}