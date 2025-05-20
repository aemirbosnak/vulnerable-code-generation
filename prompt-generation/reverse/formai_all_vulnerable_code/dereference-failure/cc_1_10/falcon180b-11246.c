//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

void reverse(char* str, int start, int end) {
    char temp;
    while(start < end) {
        temp = *(str+start);
        *(str+start) = *(str+end);
        *(str+end) = temp;
        start++;
        end--;
    }
}

void reverseWords(char* str) {
    int i, j, k, len;
    char* word;

    i = 0;
    while(str[i]!= '\0') {
        if(isspace(str[i])) {
            j = i + 1;
            while(!isspace(str[j]) && str[j]!= '\0') {
                j++;
            }
            len = j - i - 1;
            word = malloc(len + 1);
            strncpy(word, str + i + 1, len);
            word[len] = '\0';
            reverse(str, i, j - 1);
            i = j;
            printf("%s ", word);
            free(word);
        } else {
            i++;
        }
    }
}

int main() {
    char str[MAX_SIZE];

    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);

    reverseWords(str);

    return 0;
}