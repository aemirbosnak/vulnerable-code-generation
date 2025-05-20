//FormAI DATASET v1.0 Category: String manipulation ; Style: accurate
#include <stdio.h>
#include <string.h>

void reverse(char str[]) {
    int length = strlen(str);
    for(int i = 0; i < length/2; i++) {
        char temp = str[i];
        str[i] = str[length-i-1];
        str[length-i-1] = temp;
    }
}

int main() {
    char inputString[50];
    char choice;
    
    printf("Enter a string: ");
    scanf("%s", inputString);
    printf("\n");
    
    do {
        printf("Choose an operation: \n");
        printf("1. Reverse the string\n");
        printf("2. Find the length of the string\n");
        printf("3. Compare two strings\n");
        printf("4. Convert the string to uppercase\n");
        printf("5. Convert the string to lowercase\n");
        printf("6. Exit the program\n");
        printf("\n");
        
        scanf(" %c", &choice);
        
        switch(choice) {
            case '1': 
                reverse(inputString);
                printf("Reversed string: %s\n", inputString);
                break;
            case '2': 
                printf("Length of the string: %d\n", strlen(inputString));
                break;
            case '3': {
                char compareString[50];
                printf("Enter the string to compare with: ");
                scanf("%s", compareString);
                if(strcmp(inputString, compareString) == 0) {
                    printf("Strings are equal!\n");
                } else {
                    printf("Strings are not equal!\n");
                }
                break;
            }
            case '4': 
                for(int i = 0; inputString[i] != '\0'; i++) {
                    if(inputString[i] >= 97 && inputString[i] <= 122) {
                        inputString[i] -= 32;
                    }   
                }
                printf("Uppercase string: %s\n", inputString);
                break;
            case '5':
                for(int i = 0; inputString[i] != '\0'; i++) {
                    if(inputString[i] >= 65 && inputString[i] <= 90) {
                        inputString[i] += 32;
                    }   
                }
                printf("Lowercase string: %s\n", inputString);
                break;
            case '6':
                printf("Exiting the program...\n");
                break;    
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while(choice != '6');
    
    return 0;
}