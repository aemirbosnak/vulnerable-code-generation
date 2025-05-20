//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: complete
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void clearInputBuffer(){
    int c = 0;
    while(c != '\n' && c != EOF){
        c = getchar();
    }
}

void sanitizeInput(char* input){
    // Remove trailing white spaces
    int len = strlen(input);
    while(input[len-1] == ' '){
        input[len-1] = '\0';
        len--;
    }

    // Remove leading white spaces
    char* temp = input;
    while(*temp == ' '){
        temp++;
    }
    memmove(input, temp, strlen(temp)+1);

    // Remove special characters
    char* temp2 = input;
    while(*temp2 != '\0'){
        if(!((*temp2 >= 'A' && *temp2 <= 'Z') || (*temp2 >= 'a' && *temp2 <= 'z') || (*temp2 >= '0' && *temp2 <= '9') || *temp2 == ' ')){
            *temp2 = '\0';
        }
        temp2++;
    }
}

int main(){
    int num;
    char input[100];

    printf("Enter a number: ");
    scanf("%d", &num);
    clearInputBuffer();

    printf("Enter a string: ");
    fgets(input, 100, stdin);
    sanitizeInput(input);

    printf("Sanitized Input: %s\n", input);

    return 0;
}