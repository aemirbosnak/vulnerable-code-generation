//FormAI DATASET v1.0 Category: String manipulation ; Style: complete
#include<stdio.h>
#include<string.h>

//function to check if two C strings are equal or not
int compareStrings(char str1[], char str2[]) {
    int i=0, flag=0;
    //loop until both strings are not empty and characters are same
    while(str1[i] != '\0' && str2[i] != '\0') {
        if(str1[i] != str2[i]) {
            flag = 1;
            break;
        }
        i++;
    }
    //if flag is set during while loop, strings are not equal
    if(flag)
        return 0;
    //if both strings ended at same position, they are equal
    if(str1[i] == '\0' && str2[i] == '\0')
        return 1;
    return 0;
}

//function to reverse a C string
void reverseString(char str[]) {
    int i=0, len=strlen(str)-1;
    char temp;
    //loop until middle character of the string
    while(i < len/2) {
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
        i++;
    }
}

//function to count number of words in a C string
int countWords(char str[]) {
    int i=0, count=0;
    //loop until end of string
    while(str[i] != '\0') {
        //increment count if space is found
        if(str[i] == ' ')
            count++;
        i++;
    }
    //return count+1 as last word doesn't have space after it
    return count+1;
}

//function to check if a string is palindrome or not
int isPalindrome(char str[]) {
    int i=0, len=strlen(str)-1;
    //loop until middle character of the string
    while(i < len/2) {
        //return 0 if characters are not same
        if(str[i] != str[len-i-1])
            return 0;
        i++;
    }
    //if all characters matched, string is palindrome
    return 1;
}

int main() {
    char str1[50], str2[50];
    int choice, res;
    //display menu to user
    printf("Welcome to C String Manipulation Menu\n");
    printf("1. Compare two strings\n");
    printf("2. Reverse a string\n");
    printf("3. Count number of words in a string\n");
    printf("4. Check if a string is palindrome\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    //perform operation according to user's choice
    switch(choice) {
        case 1:
            printf("Enter first string: ");
            scanf("%s", str1);
            printf("Enter second string: ");
            scanf("%s", str2);
            res = compareStrings(str1, str2);
            if(res)
                printf("Strings are equal.\n");
            else
                printf("Strings are not equal.\n");
            break;
        case 2:
            printf("Enter string to be reversed: ");
            scanf("%s", str1);
            reverseString(str1);
            printf("Reversed String: %s\n", str1);
            break;
        case 3:
            printf("Enter string to count words: ");
            scanf(" %[^\n]s", str1);
            res = countWords(str1);
            printf("Number of words: %d\n", res);
            break;
        case 4:
            printf("Enter string to check palindrome: ");
            scanf("%s", str1);
            res = isPalindrome(str1);
            if(res)
                printf("String is palindrome.\n");
            else
                printf("String is not palindrome.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
    return 0;
}