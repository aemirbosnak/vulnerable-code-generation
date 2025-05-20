//FormAI DATASET v1.0 Category: String manipulation ; Style: expert-level
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// function to reverse a string
char* reverseString(char *str) {
    int len = strlen(str);
    char *rev = malloc(sizeof(char) * (len+1));
    for(int i=0; i<len; i++) {
        rev[i] = str[len-i-1];
    }
    rev[len] = '\0';
    return rev;
}

// function to check whether two strings are anagrams or not
int checkAnagram(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if(len1 != len2) {
        return 0;
    }
    int freq1[26] = {0};
    int freq2[26] = {0};
    for(int i=0; i<len1; i++) {
        freq1[str1[i]-'a']++;
        freq2[str2[i]-'a']++;
    }
    for(int i=0; i<26; i++) {
        if(freq1[i] != freq2[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[100], sub[100], ch;
    int idx, num, i, j;
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    printf("\nYou entered: %s", str);
    
    printf("\nEnter a character to find its index: ");
    scanf("%c", &ch);
    idx = strchr(str, ch) - str;
    printf("\nThe index of %c in the string is: %d\n", ch, idx);
    
    printf("\nEnter a substring to find its occurrences: ");
    scanf("%s", sub);
    num = 0;
    for(i=0; i<strlen(str); i++) {
        j = i;
        int k = 0;
        while(str[j] == sub[k] && k < strlen(sub)) {
            j++;
            k++;
        }
        if(k == strlen(sub)) {
            num++;
        }
    }
    printf("\nThe substring %s occurs %d times in the string\n", sub, num);
    
    char *rev = reverseString(str);
    printf("\nThe reversed string is: %s\n", rev);
    
    printf("\nEnter a string to check for anagram: ");
    char str2[100];
    scanf("%s", str2);
    int anagram = checkAnagram(str, str2);
    if(anagram) {
        printf("\n%s and %s are anagrams\n", str, str2);
    } else {
        printf("\n%s and %s are not anagrams\n", str, str2);
    }
    return 0;
}