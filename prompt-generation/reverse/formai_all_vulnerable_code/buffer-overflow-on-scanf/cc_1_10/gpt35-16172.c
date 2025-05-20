//FormAI DATASET v1.0 Category: String manipulation ; Style: satisfied
#include <stdio.h>
#include <string.h>

int main() {
    char string1[50];
    char string2[50];
    int length1, length2;

    printf("Enter a string: ");
    fgets(string1, sizeof(string1), stdin);  //reading string using fgets
    
    length1 = strlen(string1);
    printf("The length of the string is %d\n", length1);

    printf("Enter another string: ");
    scanf("%s", string2);  //reading string using scanf
    
    length2 = strlen(string2);
    printf("The length of the string is %d\n", length2);

    printf("Concatenating the two strings...\n");
    strcat(string1, string2);

    printf("The concatenated string is: %s\n", string1);
    
    printf("Finding the character 'a' in the string...\n");
    char* ptr = strchr(string1, 'a');

    if (ptr != NULL) {
        printf("The character 'a' is found at position %d\n", ptr - string1 + 1);
    }
    else {
        printf("The character 'a' is not found\n");
    }
    
    printf("Counting the occurrences of 'e' in the string...\n");
    int count = 0;
    for (int i = 0; i < strlen(string1); i++) {
        if (string1[i] == 'e') {
            count++;
        }
    }
    printf("The character 'e' appears %d times in the string\n", count);

    printf("Replacing all lowercase 'o' letters with uppercase 'O' letters...\n");
    for (int i = 0; i < strlen(string1); i++) {
        if (string1[i] == 'o') {
            string1[i] = 'O';
        }
    }
    printf("The updated string is: %s\n", string1);

    return 0;
}