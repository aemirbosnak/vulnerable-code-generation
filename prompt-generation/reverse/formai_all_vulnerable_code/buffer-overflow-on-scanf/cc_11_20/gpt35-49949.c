//FormAI DATASET v1.0 Category: String manipulation ; Style: energetic
#include <stdio.h>
#include <string.h>

int main() {
    char string1[100], string2[100];
    char temp[100], choice;
    int length, flag = 0;
    
    printf("Enter the first string: ");
    scanf("%s", string1);
    printf("Enter the second string: ");
    scanf("%s", string2);
    
    printf("Choose an operation:\n");
    printf("a. Concatenate the two strings\n");
    printf("b. Reverse the first string\n");
    printf("c. Check if the two strings are equal\n");
    printf("d. Convert the first string to uppercase\n");
    scanf(" %c", &choice);
    
    switch(choice) {
        case 'a':
            strcat(string1, string2);
            printf("Concatenated string: %s\n", string1);
            break;
        case 'b':
            length = strlen(string1);
            for(int i = length-1, j = 0; i >= 0; i--, j++) {
                temp[j] = string1[i];
            }
            printf("Reversed string: %s\n", temp);
            break;
        case 'c':
            if(strcmp(string1, string2) == 0) {
                printf("The two strings are equal\n");
            } else {
                printf("The two strings are not equal\n");
            }
            break;
        case 'd':
            length = strlen(string1);
            for(int i = 0; i < length; i++) {
                if(string1[i] >= 97 && string1[i] <= 122) {
                    string1[i] = string1[i] - 32;
                }
            }
            printf("Uppercased string: %s\n", string1);
            break;
        default:
            printf("Invalid choice\n");
            flag = 1;
            break;
    }
    
    if(flag == 0) {
        printf("Program complete\n");
    }
    
    return 0;
}