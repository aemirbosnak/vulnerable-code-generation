//FormAI DATASET v1.0 Category: String manipulation ; Style: shocked
#include<stdio.h>
#include<string.h>

int main() {

    char str1[50];
    printf("Enter a string: ");
    scanf("%[^\n]", str1);

    char str2[50] = "WOW, ";
    strcat(str2, str1);
    printf("%s\n", str2);

    int len = strlen(str1);
    printf("The string length of '%s' is %d\n", str1, len);

    printf("The uppercase of '%s' is ", str1);
    for(int i = 0; i < len; i++) {
        printf("%c", toupper(str1[i]));
    }
    printf("\n");

    printf("The lowercase of '%s' is ", str1);
    for(int i = 0; i < len; i++) {
        printf("%c", tolower(str1[i]));
    }
    printf("\n");

    printf("The reversed string is '");
    for(int i = len-1; i >= 0; i--) {
        printf("%c", str1[i]);
    }
    printf("'\n");

    printf("The ASCII value of '%s' is ", str1);
    for(int i = 0; i < len; i++) {
        printf("%d ", str1[i]);
    }
    printf("\n");

    char copied[50];
    strcpy(copied, str1);
    printf("The copied string is '%s'\n", copied);

    printf("The total number of vowels in '%s' is ", str1);
    int count = 0;
    for(int i = 0; i < len; i++) {
        if(str1[i] == 'a' || str1[i] == 'e' || str1[i] == 'i' || str1[i] == 'o' || str1[i] == 'u' || 
           str1[i] == 'A' || str1[i] == 'E' || str1[i] == 'I' || str1[i] == 'O' || str1[i] =='U') {
            count++;
        }
    }
    printf("%d\n", count);

    printf("'coding' in '%s' can be replaced with 'programming' to make it '%s'\n", str1, strstr(str1, "coding"));

    return 0;
}