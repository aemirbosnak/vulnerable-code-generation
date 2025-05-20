//FormAI DATASET v1.0 Category: String manipulation ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main() {
    char str1[50], str2[50], temp[50];
    int choice, len1, len2, len_temp, i, j, k;
    
    printf("Welcome to the Peaceful String Manipulation Program!\n");
    printf("Please enter the first string: ");
    fgets(str1, 50, stdin); // Using fgets for input to prevent overflow
    
    printf("\nGreat! Now please enter the second string: ");
    fgets(str2, 50, stdin);
    
    len1 = strlen(str1);
    len2 = strlen(str2);
    
    printf("\nWhat would you like to do with these strings?\n");
    printf("1. Concatenate the strings\n");
    printf("2. Compare the strings\n");
    printf("3. Reverse the strings\n");
    printf("4. Find the length of each string\n");
    printf("5. Exit the program\n");
    
    printf("\nEnter your choice (1-5): ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1: // Concatenating strings
            printf("You have chosen to concatenate the strings.\n");
            printf("The result is: ");
            
            strcat(str1, str2); // Using strcat to concatenate str2 to str1
            puts(str1);
            break;
        case 2: // Comparing strings
            printf("You have chosen to compare the strings.\n");
            if(strcmp(str1, str2) == 0) // Using strcmp to compare str1 and str2
                printf("The strings are equal.\n");
            else
                printf("The strings are not equal.\n");
            break;
        case 3: // Reversing strings
            printf("You have chosen to reverse the strings.\n");
            len_temp = len1 + len2;
            
            for(i = len_temp-1, j = 0; i >= 0; i--, j++) {
                if(i >= len2) // Copying str1 to temp
                    temp[j] = str1[i - len2];
                else // Copying str2 to temp
                    temp[j] = str2[i];
            }
            temp[j] = '\0'; // Adding null character at the end
            
            printf("The result is: ");
            puts(temp);
            break;
        case 4: // Finding length of strings
            printf("You have chosen to find the length of each string.\n");
            printf("Length of first string: %d\n", len1-1); // len-1 to remove the newline character
            printf("Length of second string: %d\n", len2-1);
            break;
        default: // Exiting the program
            printf("You have chosen to exit the program.\n");
            return 0;
    }
    return 0;
}