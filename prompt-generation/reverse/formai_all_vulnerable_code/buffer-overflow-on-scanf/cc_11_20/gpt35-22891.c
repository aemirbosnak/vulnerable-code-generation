//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: all-encompassing
#include<stdio.h>

int main()
{
    // This program is an Alien Language Translator
    printf("Welcome to the C Alien Language Translator v1.0!\n");

    char input[100];
    int i, choice;

    while(1){
        printf("\nPress 1 to translate to Alien Language\nPress 2 to translate from Alien Language\nPress 3 to exit\n");
        scanf("%d",&choice);
        getchar();

        switch(choice){
            case 1:
                printf("\nEnter the sentence to convert to Alien Language: ");
                fgets(input, 100, stdin);
                for(i=0; input[i]!='\0'; i++){
                    if(input[i] == 'a'){
                        printf("!");
                    }
                    else if(input[i] == 'b'){
                        printf("@");
                    }
                    else if(input[i] == 'c'){
                        printf("#");
                    }
                    else if(input[i] == 'd'){
                        printf("$");
                    }
                    else{
                        printf("%c", input[i]);
                    }
                }
                break;
            case 2:
                printf("\nEnter the sentence to convert from Alien Language: ");
                fgets(input, 100, stdin);
                for(i=0; input[i]!='\0'; i++){
                    switch(input[i]){
                        case '!':
                            printf("a");
                            break;
                        case '@':
                            printf("b");
                            break;
                        case '#':
                            printf("c");
                            break;
                        case '$':
                            printf("d");
                            break;
                        default:
                            printf("%c", input[i]);
                    }
                }
                break;
            case 3:
                printf("\nThank you for using the C Alien Language Translator v1.0!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}