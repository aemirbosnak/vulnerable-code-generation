//FormAI DATASET v1.0 Category: String manipulation ; Style: complex
#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100], temp[100];
    int choice, i, j, k;
    printf("Enter a string: ");
    fgets(s1, 100, stdin);
    s1[strcspn(s1, "\n")] = '\0'; // to remove the newline character added by fgets
    
    while(1) {
        printf("\nChoose an option:\n1. Count the number of vowels in the string.\n2. Convert the string to uppercase.\n3. Reverse the string.\n4. Exit\n");
        scanf("%d", &choice);
        getchar(); // to remove the newline character left in the input stream
        
        switch(choice) {
            case 1:
                j = 0;
                for(i=0; s1[i]!='\0'; i++) {
                    if(s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u' || s1[i] == 'A' || s1[i] == 'E' || s1[i] == 'I' || s1[i] == 'O' || s1[i] == 'U') {
                        j++;
                    }
                }
                printf("The string contains %d vowels.\n", j);
                break;
                
            case 2:
                for(i=0; s1[i]!='\0'; i++) {
                    if(s1[i]>='a' && s1[i]<='z') {
                        s1[i] -= 32;
                    }
                }
                printf("The uppercase string is: %s\n", s1);
                break;
                
            case 3:
                j = strlen(s1) - 1;
                for(i=0; i<j; i++, j--) {
                    temp[i] = s1[j];
                    temp[j] = s1[i];
                }
                if(strlen(s1) % 2 != 0) {
                    temp[i] = s1[i];
                }
                printf("The reversed string is: %s\n", temp);
                break;
                
            case 4:
                return 0;
                
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}