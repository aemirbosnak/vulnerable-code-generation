//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: romantic
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//Function to generate a random string of given length
char* generateRandomString(int length) {
    char* result = (char*)malloc(length+1);
    srand(time(NULL));
    for(int i=0; i<length; i++) {
        result[i] = rand()%26 + 'a'; //Generating lowercase alphabets
    }
    result[length] = '\0';
    return result;
}

//Function to reverse a string
void reverseString(char* str) {
    int length = strlen(str);
    char* reversed = (char*)malloc(length+1);
    for(int i=0; i<length; i++) {
        reversed[length-1-i] = str[i];
    }
    reversed[length] = '\0';
    printf("Reversed string: %s\n", reversed);
    free(reversed);
}

//Function to check if two strings are anagrams of each other
int areAnagrams(char* str1, char* str2) {
    int length1 = strlen(str1);
    int length2 = strlen(str2);
    if(length1!= length2) {
        return 0;
    }
    char* str1Copy = (char*)malloc(length1+1);
    char* str2Copy = (char*)malloc(length2+1);
    strcpy(str1Copy, str1);
    strcpy(str2Copy, str2);
    for(int i=0; i<length1; i++) {
        str1Copy[i] = tolower(str1Copy[i]);
        str2Copy[i] = tolower(str2Copy[i]);
    }
    if(strcmp(str1Copy, str2Copy) == 0) {
        return 1;
    }
    return 0;
}

//Main function
int main() {
    int length;
    printf("Enter the length of the string: ");
    scanf("%d", &length);
    char* randomString = generateRandomString(length);
    printf("Random string: %s\n", randomString);
    reverseString(randomString);
    char* reversedString = (char*)malloc(strlen(randomString)+1);
    strcpy(reversedString, randomString);
    printf("Reversed string: %s\n", reversedString);
    if(areAnagrams(randomString, reversedString)) {
        printf("The strings are anagrams of each other.\n");
    }
    else {
        printf("The strings are not anagrams of each other.\n");
    }
    free(randomString);
    free(reversedString);
    return 0;
}