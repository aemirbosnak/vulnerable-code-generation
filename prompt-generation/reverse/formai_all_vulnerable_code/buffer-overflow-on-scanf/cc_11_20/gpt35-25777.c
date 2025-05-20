//FormAI DATASET v1.0 Category: String manipulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[1000];
    int choice, num, len;
    
    printf("Enter a string: ");
    fgets(str, 1000, stdin);
    
    printf("Choose a task:\n");
    printf("1. Calculate string length\n2. Reverse string\n3. Remove vowels\n4. Replace character\n");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            len = strlen(str);
            printf("The length of the string is: %d\n", len);
            break;
        case 2:
            printf("The reversed string is: ");
            for(int i = strlen(str)-1; i >= 0; i--) {
                printf("%c", str[i]);
            }
            printf("\n");
            break;
        case 3:
            printf("The string without vowels is: ");
            for(int i = 0; i < strlen(str); i++) {
                if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' && str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') {
                    printf("%c", str[i]);
                }
            }
            printf("\n");
            break;
        case 4:
            printf("Enter the character you want to replace: ");
            char oldChar = getchar();
            printf("Enter the character you want to replace it with: ");
            char newChar = getchar();
            printf("Enter the number of times you want to replace the character: ");
            scanf("%d", &num);
            printf("The new string is: ");
            for(int i = 0; i < strlen(str); i++) {
                if(str[i] == oldChar && num) {
                    printf("%c", newChar);
                    num--;
                } else {
                    printf("%c", str[i]);
                }
            }
            printf("\n");
            break;
        default:
            printf("Invalid choice\n");
    }
    
    return 0;
}