//FormAI DATASET v1.0 Category: Syntax parsing ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to represent a token
struct Token{
    char value[20];  // Actual value of the token
    int type;        // Type of the token (1 for Identifier, 2 for Operator, 3 for Number, 4 for String)
};

// Function to get the type of a token
int getType(char *value){
    if(strlen(value) == 1 && (value[0] == '+' || value[0] == '-' || value[0] == '*' || value[0] == '/' || value[0] == '=')){
        return 2;
    }
    else if(isdigit(value[0])){
        return 3;
    }
    else if(strlen(value) >= 2 && value[0] == '"' && value[strlen(value)-1] == '"'){
        return 4;
    }
    else{
        return 1;
    }
}

// Function to print a token
void printToken(struct Token token){
    switch(token.type){
        case 1:
            printf("[Identifier: %s] ", token.value);
            break;
        case 2:
            printf("[Operator: %s] ", token.value);
            break;
        case 3:
            printf("[Number: %s] ", token.value);
            break;
        case 4:
            printf("[String: %s] ", token.value);
            break;
    }
}

int main(){
    char input[100];
    printf("Enter a statement: ");
    fgets(input, 100, stdin);
    input[strlen(input)-1] = '\0';  // Removing the newline character
    
    // Tokenizing the input
    char *tokenized[20];
    char *temp = strtok(input, " ");
    int i = 0;
    while(temp != NULL){
        tokenized[i++] = temp;
        temp = strtok(NULL, " ");
    }
    
    // Parsing the tokens and getting their types
    struct Token tokens[20];
    for(int j=0; j<i; j++){
        strcpy(tokens[j].value, tokenized[j]);
        tokens[j].type = getType(tokenized[j]);
    }
    
    // Printing the resultant tokens
    for(int j=0; j<i; j++){
        printToken(tokens[j]);
    }
    printf("\n");
    
    return 0;
}