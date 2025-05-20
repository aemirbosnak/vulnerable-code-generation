//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct {
    char *str;
    int len;
} String;

void init_string(String *s) {
    s->str = malloc(MAX_SIZE * sizeof(char));
    s->len = 0;
}

void append_string(String *s, char c) {
    if (s->len == MAX_SIZE) {
        printf("Error: String is full!\n");
        exit(1);
    }
    s->str[s->len++] = c;
}

void print_string(String s) {
    printf("%s", s.str);
}

int main() {
    String s1, s2;
    init_string(&s1);
    init_string(&s2);

    int n1, n2;
    printf("Enter the length of the first string: ");
    scanf("%d", &n1);

    for (int i = 0; i < n1; i++) {
        char c;
        printf("Enter character %d: ", i + 1);
        scanf(" %c", &c);
        append_string(&s1, c);
    }

    printf("Enter the length of the second string: ");
    scanf("%d", &n2);

    for (int i = 0; i < n2; i++) {
        char c;
        printf("Enter character %d: ", i + 1);
        scanf(" %c", &c);
        append_string(&s2, c);
    }

    String result;
    init_string(&result);

    int carry = 0;
    int i = n1 - 1, j = n2 - 1;
    while (i >= 0 || j >= 0 || carry!= 0) {
        int sum = (i >= 0? s1.str[i] - '0' : 0) + (j >= 0? s2.str[j] - '0' : 0) + carry;
        carry = sum / 10;
        result.str[result.len++] = (char)(sum % 10 + '0');

        if (i >= 0) i--;
        if (j >= 0) j--;
    }

    printf("Result: ");
    print_string(result);

    return 0;
}