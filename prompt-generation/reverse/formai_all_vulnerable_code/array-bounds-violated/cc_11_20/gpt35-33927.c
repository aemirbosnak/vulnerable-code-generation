//FormAI DATASET v1.0 Category: String manipulation ; Style: bold
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], temp[100];
    int choice;

    printf("Enter a string: "); // taking input of str1
    fgets(str1, 100, stdin);

    printf("Choose an operation to perform:\n"); // giving options to user
    printf("1. Reverse the string\n");
    printf("2. Convert to uppercase\n");
    printf("3. Convert to lowercase\n");
    printf("4. Sort the string\n");
    printf("5. Concatenate two strings\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1: // reversing str1
            for(int i=0, j=strlen(str1)-1; i<j; i++, j--) {
                temp[i] = str1[j];
                temp[j] = str1[i];
            }
            printf("The reversed string is: %s", temp);
            break;
        case 2: // converting str1 to uppercase
            for(int i=0; i<strlen(str1); i++) {
                if(str1[i] >= 'a' && str1[i] <= 'z') {
                    str1[i] = str1[i] - 32;
                }
            }
            printf("The uppercase string is: %s", str1);
            break;
        case 3: // converting str1 to lowercase
            for(int i=0; i<strlen(str1); i++) {
                if(str1[i] >= 'A' && str1[i] <= 'Z') {
                    str1[i] = str1[i] + 32;
                }
            }
            printf("The lowercase string is: %s", str1);
            break;
        case 4: // sorting str1
            for(int i=0; i<strlen(str1)-1; i++) {
                for(int j=i+1; j<strlen(str1); j++) {
                    if(str1[i] > str1[j]) {
                        char temp2 = str1[i];
                        str1[i] = str1[j];
                        str1[j] = temp2;
                    }
                }
            }
            printf("The sorted string is: %s", str1);
            break;
        case 5: // concatenating str1 with str2
            printf("Enter another string to concatenate: ");
            getchar(); // clearing input buffer
            fgets(str2, 100, stdin);
            str2[strlen(str2)-1] = '\0'; // replacing newline character at end with null character
            strcat(str1, str2);
            printf("The concatenated string is: %s", str1);
            break;
        default: // invalid input
            printf("Invalid choice!");
    }

    return 0;
}