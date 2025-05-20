//FormAI DATASET v1.0 Category: String manipulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LENGTH 255

// Function to capitalize the first letter of each word in a string
void capitalizeFirstLetter(char* str){
    int length = strlen(str);
    int i = 0;
    while(i < length){
        // Capitalize the first letter of each word
        if(i == 0 || str[i-1] == ' '){
            if(str[i] >= 'a' && str[i] <= 'z'){
                str[i] -= 32;
            }
        }
        i++;
    }
}

// Function to reverse a string
void reverseString(char* str){
    int length = strlen(str);
    int left = 0, right = length-1;
    while(left < right){
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

int main(){
    char str[MAX_STR_LENGTH];

    printf("Enter a string: ");
    fgets(str, MAX_STR_LENGTH, stdin);

    // Remove the newline character from the input string
    if(str[strlen(str)-1] == '\n'){
        str[strlen(str)-1] = '\0';
    }

    int choice;
    printf("Choose an operation to perform:\n");
    printf("1. Capitalize the first letter of each word in the string.\n");
    printf("2. Reverse the string.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            capitalizeFirstLetter(str);
            printf("New string: %s\n", str);
            break;

        case 2:
            reverseString(str);
            printf("New string: %s\n", str);
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}