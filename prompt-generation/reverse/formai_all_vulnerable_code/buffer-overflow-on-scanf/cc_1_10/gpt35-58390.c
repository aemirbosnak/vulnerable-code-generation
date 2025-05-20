//FormAI DATASET v1.0 Category: Text processing ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char *text = malloc(sizeof(char)*100); // Dynamic memory allocation for the text input.
    memset(text, 0, sizeof(char)*100); // Initializing text with 0 to avoid garbage values.
    printf("Enter the text:\n");
    scanf("%[^\n]", text); // To accept the entire sentence including spaces.
    getchar(); // Flushing the newline character.
    printf("\nYou entered: %s\n", text);
    int len = strlen(text);
    printf("Length of the entered text = %d\n", len);

    // Converting the entire text to Uppercase
    for(int i=0; i<len; i++){
        if(text[i]>='a' && text[i]<='z'){
            text[i] = text[i] - 32; // Converting lowercase letter to uppercase letter.
        }
    }
    printf("\nThe Converted Uppercase Text = %s\n", text);

    // Counting the number of occurrences of a letter 'a'
    int count = 0;
    for(int i=0; i<len; i++){
        if(text[i]=='a' || text[i]=='A'){
            count++;
        }
    }
    printf("\nNumber of occurrences of letter 'a' in the entered text = %d\n", count);

    // Reversing the entire text.
    char *rev_text = malloc(sizeof(char)*100); // Dynamic memory allocation for the reversed text.
    memset(rev_text, 0, sizeof(char)*100); // Initializing reversed text with 0 to avoid garbage values.
    for(int i=0; i<len; i++){
        rev_text[len-i-1] = text[i]; // Reversing the text.
    }
    printf("\nThe Reversed Text = %s\n", rev_text);

    // Checking if the entered text is a Palindrome or not.
    int palindrome = strcmp(text, rev_text);
    if(palindrome==0){
        printf("\nThe entered text is a Palindrome.\n");
    }
    else{
        printf("\nThe entered text is not a Palindrome.\n");
    }

    // Freeing the memory allocated dynamically.
    free(text);
    free(rev_text);
    return 0;
}