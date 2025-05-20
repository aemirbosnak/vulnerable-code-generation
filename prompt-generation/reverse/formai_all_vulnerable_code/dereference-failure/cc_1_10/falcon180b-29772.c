//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *str;
    int size;
} String;

String createString(char *str) {
    String s;
    s.str = malloc(MAX_SIZE * sizeof(char));
    s.size = strlen(str);
    strcpy(s.str, str);
    return s;
}

void printString(String s) {
    printf("%s\n", s.str);
}

void concatenateStrings(String s1, String s2) {
    s1.str = realloc(s1.str, s1.size + s2.size + 1);
    strcat(s1.str, s2.str);
    s1.size += s2.size;
}

void reverseString(String s) {
    char *temp = malloc(s.size * sizeof(char));
    int i, j;
    for (i = 0, j = s.size - 1; i < j; i++, j--) {
        temp[i] = s.str[j];
        temp[j] = s.str[i];
    }
    s.str = temp;
}

int main() {
    String s1 = createString("Hello");
    String s2 = createString("World");
    String s3;

    concatenateStrings(s1, s2);
    printString(s1); // Output: HelloWorld

    s3 = createString("Hello");
    reverseString(s3);
    printString(s3); // Output: olleH

    free(s1.str);
    free(s2.str);
    free(s3.str);

    return 0;
}