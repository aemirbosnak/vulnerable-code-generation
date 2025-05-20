//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Cryptic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char code[100000], token[100];
    int i=0, j=0, indentLevel=0, inlineComment=0, multiComment=0, bracketCount=0;

    printf("Enter the ugly HTML code:\n");
    fgets(code, 100000, stdin);

    printf("\n\n");

    while(code[i]!='\0'){

        // Check for inline comment
        if(code[i]=='/' && code[i+1]=='/'){
            inlineComment=1;
        }

        // Check for multiline comments
        if(code[i]=='/' && code[i+1]=='*'){
            multiComment=1;
        }

        // Ignore the contents of comments
        if(inlineComment || multiComment){
            i++;
            continue;
        }

        // Check for line breaks
        if(code[i]=='\n'){
            printf("\n");
            for(j=0; j<indentLevel; j++){
                printf("    ");
            }
        }

        // Check for closing bracket
        if(code[i]=='}'){
            indentLevel--;
        }

        // Print the current token
        printf("%c", code[i]);

        // Check for opening bracket
        if(code[i]=='{'){
            bracketCount++;
            indentLevel++;

            printf("\n");

            for(j=0; j<indentLevel; j++){
                printf("    ");
            }
        }

        // Check for end of tag
        if(code[i]=='>' && token[0]=='<'){
            printf("\n");
            for(j=0; j<indentLevel; j++){
                printf("    ");
            }
        }

        // Reset token if end of tag
        if(code[i]=='>'){
            memset(token, 0, 100);
            j=0;
        }
        else{
            // Build the token
            token[j]=code[i];
            j++;
        }

        // Check for end of inline comment
        if(code[i]=='\n' && inlineComment){
            inlineComment=0;
        }

        // Check for end of multiline comment
        if(code[i-1]=='*' && code[i]=='/' && multiComment){
            multiComment=0;
        }

        i++;
    }

    return 0;
}