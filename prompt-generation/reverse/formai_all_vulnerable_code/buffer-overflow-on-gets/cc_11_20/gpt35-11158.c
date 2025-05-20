//FormAI DATASET v1.0 Category: String manipulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100];
    int i, j, choice, index, len;

    printf("Enter a string: ");
    gets(str); // User enters a string using gets() function.

    printf("Operations available:\n1. Reverse the string.\n2. Change to uppercase.\n3. Change to lowercase.\n4. Replace a character by another.\n");
    printf("Enter your choice (1, 2, 3 or 4): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: // Reverses the string.
            printf("Original string: %s\n", str);
            len = strlen(str);
            char temp;
            for(i=0,j=len-1;i<j;i++,j--) {
                temp=str[i];
                str[i]=str[j];
                str[j]=temp;
            }
            printf("After reversal: %s\n", str);
            break;

        case 2: // Changes string to uppercase.
            printf("Original string: %s\n", str);
            len = strlen(str);
            for(i=0;i<len;i++) {
                if(str[i]>='a' && str[i]<='z') {
                    str[i] -= 32;
                }
            }
            printf("After converting to uppercase: %s\n", str);
            break;

        case 3: // Changes string to lowercase.
            printf("Original string: %s\n", str);
            len = strlen(str);
            for(i=0;i<len;i++) {
                if(str[i]>='A' && str[i]<='Z') {
                    str[i] += 32;
                }
            }
            printf("After converting to lowercase: %s\n", str);
            break;

        case 4: // Replaces a character by another.
            printf("Original string: %s\n", str);
            len = strlen(str);
            char old_ch, new_ch;
            printf("Enter the character to be replaced: ");
            scanf(" %c", &old_ch);
            printf("Enter the new character: ");
            scanf(" %c", &new_ch);
            for(i=0;i<len;i++) {
                if(str[i] == old_ch) {
                    str[i] = new_ch;
                }
            }
            printf("After replacing %c with %c: %s\n", old_ch, new_ch, str);
            break;
            
        default:
            printf("Invalid choice!\n");
            break;
    }
    return 0;
}