//FormAI DATASET v1.0 Category: String manipulation ; Style: multivariable
#include <stdio.h>
#include <string.h>

int main() {
    char str1[50], str2[50], str3[50], str4[50], temp[50];
    int i, j, k;

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    printf("Enter third string: ");
    scanf("%s", str3);

    printf("Enter fourth string: ");
    scanf("%s", str4);

    // Print all strings
    printf("\nString 1: %s\n", str1);
    printf("String 2: %s\n", str2);
    printf("String 3: %s\n", str3);
    printf("String 4: %s\n", str4);

    // Swap first and second string
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);

    printf("\nAfter swapping first and second string:\n");
    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);

    // Find the length of third string
    printf("\nLength of third string: %d\n", strlen(str3));

    // Concatenate first and third string
    strcat(str1, str3);
    printf("\nAfter concatenating first and third string:\n");
    printf("String 1: %s\n", str1);

    // Compare fourth string with concatenated string
    if (strcmp(str4, str1) == 0) {
        printf("\nFourth string is equal to concatenated string.\n");
    } else {
        printf("\nFourth string is not equal to concatenated string.\n");
    }

    // Convert all characters of second string to uppercase
    for (i=0; str2[i]!='\0'; i++) {
        if(str2[i] >= 'a' && str2[i] <= 'z') {
            str2[i] = str2[i] - 32;
        }
    }
    printf("\nSecond string in uppercase: %s\n", str2);

    // Find all occurrences of 't' in third string
    printf("\nOccurrences of 't' in third string: ");
    for (i=0; str3[i]!='\0'; i++) {
        if (str3[i] == 't') {
            printf("%d ", i);
        }
    }

    return 0;
}