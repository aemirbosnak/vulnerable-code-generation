//FormAI DATASET v1.0 Category: Syntax parsing ; Style: expert-level
#include <stdio.h>
#include <string.h>

int main()
{
    char input[1000];
    int i=0, j=0, k=0, flag=0;
    printf("Enter C Syntax code: ");
    fgets(input, 1000, stdin);
    int len = strlen(input);

    for(i=0; i<len-1; i++){
        
        if(input[i] == ' ' || input[i] == '\t'){
            continue;
        }
        else if(input[i] == '/' && input[i+1] == '/') {
            printf("Single Line Comment Found.\n");
            break;
        }
        else if (input[i] == '/' && input[i+1] == '*') {
            i = i + 2;
            while(i<len-1 && ! (input[i] == '*' && input[i+1] == '/')) {
                i++;
            }
            if(i==len-1) {
                printf("Error! Multi-line Comment is not closed till end.\n");
            }
            else {
                printf("Multi-line Comment Found.\n");
                i++;
            }  
        }
        else if(i<len-1 && input[i] == '#' && input[i-1] == '\n') {
            printf("Preprocessor Directive Found.\n");
            j=i;
            while(j<len && input[j] != ' ' && input[j] != '\n' && input[j] != '\t') {
                j++;
            }
            printf("Preprocessor Identifier: ");
            for(k=i+1; k<=j-1; k++) {
                printf("%c", input[k]);
            }
            printf("\n");
            flag = 1;
            break;
        }
        else if(input[i] == '(' && input[i-1] == ' ' && input[i+1] != ' ') {
            printf("Function Declaration Found.\n");
            j=i;
            while(input[j] != ' ') {
                j--;
            }
            printf("Function Return Type: ");
            for(k=j+1; k<i; k++) {
                printf("%c", input[k]);
            }
            printf("\n");
            printf("Function Name: ");
            for(k=i+1; k<len-1; k++) {
                if(input[k] == '(') {
                    break;
                }
                printf("%c", input[k]);
            }
            printf("\n");
            flag = 1;
            break;
        }
        else if(input[i] == ';' && input[i-1] != ' ' && input[i+1] == ' ') {
            printf("Statement Ended.\n");
        }
        else if(input[i] == '{') {
            printf("Opening Brace.\n");
        }
        else if(input[i] == '}') {
            printf("Closing Brace.\n");
        }
    }

    if(i==len-1 && flag==0) {
        printf("Code is valid but No significant statement found.\n");
    }

    return 0;
}