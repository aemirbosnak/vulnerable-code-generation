//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000
#define MAX_NUM 100

typedef struct {
    char *str;
    int len;
} String;

String newString(char *s) {
    String str;
    str.len = strlen(s);
    str.str = malloc(str.len + 1);
    strcpy(str.str, s);
    return str;
}

void printString(String s) {
    printf("%s\n", s.str);
}

int compareStrings(String s1, String s2) {
    return strcmp(s1.str, s2.str);
}

void concatenateStrings(String s1, String s2, String *result) {
    result->len = s1.len + s2.len;
    result->str = malloc(result->len + 1);
    strcpy(result->str, s1.str);
    strcat(result->str, s2.str);
}

int main() {
    String s1 = newString("Hello");
    String s2 = newString("World");
    String s3;

    concatenateStrings(s1, s2, &s3);

    printString(s1);
    printString(s2);
    printString(s3);

    String s4 = newString("123");
    String s5 = newString("456");
    String s6;

    concatenateStrings(s4, s5, &s6);

    printString(s4);
    printString(s5);
    printString(s6);

    int res = compareStrings(s1, s2);
    printf("Result: %d\n", res);

    res = compareStrings(s4, s5);
    printf("Result: %d\n", res);

    res = compareStrings(s3, s6);
    printf("Result: %d\n", res);

    free(s1.str);
    free(s2.str);
    free(s3.str);
    free(s4.str);
    free(s5.str);
    free(s6.str);

    return 0;
}