//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main() {
    char alienMessage[100];
    int i;

    printf("Welcome to the C Alien Language Translator! Please enter a message in C Alien language.\n");
    scanf("%s", alienMessage);

    printf("Your message in C language is: ");

    for(i = 0; i < strlen(alienMessage); i++) {
        switch(alienMessage[i]) {
            case 'P':
                printf("printf(\"Hello, world!\"); ");
                break;
            case 'I':
                printf("int ");
                break;
            case 'F':
                printf("float ");
                break;
            case 'C':
                printf("char ");
                break;
            case 'S':
                printf("string ");
                break;
            case 'L':
                printf("long ");
                break;
            case '(': 
                printf("[");
                break;
            case ')': 
                printf("]");
                break;
            case '{': 
                printf("{\n");
                break;
            case '}': 
                printf("\n}\n");
                break;
            case ';':
                printf(";\n");
                break;
            case ' ':
                printf(" ");
                break;
            default:
                printf("%c", alienMessage[i]);
                break;
        }
    }

    printf("\nThank you for using our C Alien Language Translator! Have a great day!\n");

    return 0;
}