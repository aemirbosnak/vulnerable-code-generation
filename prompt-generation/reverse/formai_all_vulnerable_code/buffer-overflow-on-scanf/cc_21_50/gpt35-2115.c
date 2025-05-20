//FormAI DATASET v1.0 Category: String manipulation ; Style: introspective
#include<stdio.h>
#include<string.h>

int main(){
    printf("Welcome to the C String Manipulation Program!\n");
    char input[100], temp;
    printf("Please input a string:\n");
    scanf("%s", input);
    int length = strlen(input);
    printf("The length of the entered string is: %d\n", length);

    //Checking for palindrome
    int i, j;
    for(i=0, j=length-1; i<j; i++, j--){
        if(input[i] != input[j]){
            printf("This is not a palindrome string.\n");
            break;
        }
    }
    if(i >= j)
        printf("This is a palindrome string.\n");

    //Reversing the string
    for(i=0, j=length-1; i<j; i++, j--){
        temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }
    printf("The reverse of the string is: %s\n", input);

    //Counting the vowels and consonants
    int vowels = 0, consonants = 0;
    for(i=0; i<length; i++){
        if(input[i] == 'A' || input[i] == 'a' || input[i] == 'E' || input[i] == 'e' ||
           input[i] == 'I' || input[i] == 'i' || input[i] == 'O' || input[i] == 'o' ||
           input[i] == 'U' || input[i] == 'u')
            vowels++;
        else if((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z'))
            consonants++;
    }
    printf("Number of vowels in the entered string is: %d\n", vowels);
    printf("Number of consonants in the entered string is: %d\n", consonants);

    //Converting to uppercase
    for(i=0; i<length; i++){
        if(input[i] >= 'a' && input[i] <= 'z')
            input[i] = input[i] - 32;
    }
    printf("Uppercase of the entered string is: %s\n", input);

    //Sorting the string in alphabetical order
    for(i=0; i<length-1; i++){
        for(j=i+1; j<length; j++){
            if(input[i] > input[j]){
                temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
        }
    }
    printf("The sorted string is: %s\n", input);

    return 0;
}