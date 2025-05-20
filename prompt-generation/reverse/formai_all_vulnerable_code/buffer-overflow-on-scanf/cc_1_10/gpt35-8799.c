//FormAI DATASET v1.0 Category: String manipulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char input[100], output[100], choice;
    int len, i, j, k;
    
    printf("Welcome to the surrealist C string manipulation program!\n");
    printf("Please enter a string: ");
    scanf("%s", input);
    len = strlen(input);
    printf("\n");

    printf("Now select what operation you'd like to perform:\n");
    printf("a = reverse string\nb = capitalize odd letters\nc = add 'random' to every odd letter\n");
    scanf(" %c", &choice);

    switch(choice){
        case 'a':
            j = 0;
            for(i=len-1; i>=0; i--){
              output[j++] = input[i];
            }
            output[j] = '\0';
            printf("\nReversed string: %s\n", output);
            break;
        case 'b':
            for(i=0; i<len; i++){
                if(i%2){
                    output[i] = toupper(input[i]);   
                } else {
                    output[i] = input[i];
                }
            }
            output[len] = '\0';
            printf("\nCapitalized odd letters: %s\n", output);
            break;
        case 'c':
            k = 0;
            for(i=0; i<len; i++){
                output[k++] = input[i];
                if(i%2){
                    strcat(output, "random");
                    k += 6;
                }
            }
            printf("\nAdded 'random' to every odd letter: %s\n", output);
            break;
        default:
            printf("\nInvalid choice! Please try again.\n");
    }
    return 0;
}