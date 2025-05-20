//FormAI DATASET v1.0 Category: String manipulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str1[50], str2[50];
    int choice, len, i, j, k;
    
    // Get user input
    printf("Enter string 1: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter string 2: ");
    fgets(str2, sizeof(str2), stdin);
    
    // Present options to user
    printf("Choose an option:\n");
    printf("1. Concatenate the two strings\n");
    printf("2. Remove all the vowels from both strings\n");
    printf("3. Remove all the consonants from both strings\n");
    printf("4. Replace a character in string 1 with a character from string 2\n");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            len = strlen(str1);
            str1[len-1] = ' '; // add a space at the end of str1 to separate it from str2
            strcat(str1, str2); // concatenate str2 onto str1
            printf("Result: %s", str1);
            break;
            
        case 2:
            len = strlen(str1);
            for(i=0; i<len; i++) {
                if(str1[i] == 'a' || str1[i] == 'e' || str1[i] == 'i' || str1[i] == 'o' || str1[i] == 'u')
                    str1[i] = '-';
            }
            len = strlen(str2);
            for(i=0; i<len; i++) {
                if(str2[i] == 'a' || str2[i] == 'e' || str2[i] == 'i' || str2[i] == 'o' || str2[i] == 'u')
                    str2[i] = '-';
            }
            printf("Result:\n");
            printf("String 1: %s\n", str1);
            printf("String 2: %s\n", str2);
            break;
            
        case 3:
            len = strlen(str1);
            for(i=0; i<len; i++) {
                if(str1[i] != 'a' && str1[i] != 'e' && str1[i] != 'i' && str1[i] != 'o' && str1[i] != 'u' && str1[i] != ' ')
                    str1[i] = '-';
            }
            len = strlen(str2);
            for(i=0; i<len; i++) {
                if(str2[i] != 'a' && str2[i] != 'e' && str2[i] != 'i' && str2[i] != 'o' && str2[i] != 'u' && str2[i] != ' ')
                    str2[i] = '-';
            }
            printf("Result:\n");
            printf("String 1: %s\n", str1);
            printf("String 2: %s\n", str2);
            break;
            
        case 4:
            printf("Enter the index of the character in string 1 to replace (starting from 0): ");
            scanf("%d", &i);
            printf("Enter the index of the character in string 2 to use for replacement (starting from 0): ");
            scanf("%d", &j);
            if(i >= strlen(str1) || j >= strlen(str2)) {
                printf("Invalid indices entered.\n");
                exit(1);
            }
            printf("Result: ");
            for(k=0; k<strlen(str1); k++) {
                if(k == i)
                    printf("%c", str2[j]);
                else
                    printf("%c", str1[k]);
            }
            break;
            
        default:
            printf("Invalid option selected.\n");
            exit(1);
    }
    
    return 0;
}