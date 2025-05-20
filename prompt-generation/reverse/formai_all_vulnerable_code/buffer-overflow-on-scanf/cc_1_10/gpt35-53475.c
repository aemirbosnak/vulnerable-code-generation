//FormAI DATASET v1.0 Category: String manipulation ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100

char* reverse_string(char* str) {
    int len = strlen(str);
    char* rev = (char*) malloc(sizeof(char) * len);
    int j = 0;
    for(int i = len-1; i >= 0; i--) {
        rev[j++] = str[i];
    }
    rev[j] = '\0';
    return rev;
}

int count_substring(char* str, char* sub) {
    int len_str = strlen(str);
    int len_sub = strlen(sub);
    int count = 0;
    for(int i = 0; i < len_str; i++) {
        if(str[i] == sub[0]) {
            int j = 1;
            while(j < len_sub && i+j < len_str) {
                if(str[i+j] != sub[j])
                    break;
                j++;
            }
            if(j == len_sub)
                count++;
        }
    }
    return count;
}

int main() {
    char str[MAX_LEN], sub[MAX_LEN];
    printf("Enter a string: ");
    scanf("%[^\n]s", str); // read the entire line, including whitespaces
    printf("Enter a substring: ");
    scanf(" %[^\n]s", sub); // read the entire line, including whitespaces
    printf("The reversed string is: %s\n", reverse_string(str));
    printf("The substring '%s' occurs %d times in '%s'\n", sub, count_substring(str, sub), str);
    int len = strlen(str);
    char* new_str = (char*) malloc(sizeof(char) * (2*len + 1));
    int j = 0;
    for(int i = 0; i < len; i++) {
        new_str[j++] = str[i];
        new_str[j++] = '-';
    }
    new_str[j-1] = '\0';
    printf("The new string is: %s\n", new_str);
    free(new_str);
    return 0;
}