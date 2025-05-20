//FormAI DATASET v1.0 Category: String manipulation ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

int main() {
    char string1[50], string2[50], temp[50];
    
    printf("Enter string 1: ");
    scanf("%s", string1);
    printf("Enter string 2: ");
    scanf("%s", string2);
    
    printf("\nOriginal strings:\n");
    printf("String 1: %s\n", string1);
    printf("String 2: %s\n", string2);
    
    // Reverse the order of characters in string 1
    int i, j;
    for(i=0, j=strlen(string1)-1; i<j; i++, j--) {
        temp[i] = string1[j];
        temp[j] = string1[i];
    }
    temp[i] = '\0';
    strcpy(string1, temp);
    
    printf("\nAfter reversing string 1:\n");
    printf("String 1: %s\n", string1);
    
    // Concatenate string 1 and string 2
    strcat(string1, string2);
    
    printf("\nAfter concatenating string 1 and string 2:\n");
    printf("String 1: %s\n", string1);
    
    // Convert string 1 to all uppercase
    for(i=0; string1[i]!='\0'; i++) {
        if(string1[i] >= 'a' && string1[i] <= 'z') {
            string1[i] = string1[i] - 32;
        }
    }
    
    printf("\nAfter converting string 1 to uppercase:\n");
    printf("String 1: %s\n", string1);
    
    // Compare string 1 and string 2
    int result = strcmp(string1, string2);
    if(result == 0) {
        printf("\nThe strings are identical.\n");
    }
    else if(result > 0) {
        printf("\nString 1 is greater than string 2.\n");
    }
    else {
        printf("\nString 2 is greater than string 1.\n");
    }
    
    return 0;
}