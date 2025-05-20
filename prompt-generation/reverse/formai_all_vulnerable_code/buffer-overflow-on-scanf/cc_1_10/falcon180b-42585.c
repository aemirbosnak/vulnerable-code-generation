//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: shape shifting
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX_LENGTH 1000
#define TRUE 1
#define FALSE 0

typedef struct {
    char *string;
    int length;
} string_t;

void initialize_string(string_t *s) {
    s->string = (char *)malloc(MAX_LENGTH * sizeof(char));
    s->length = 0;
    s->string[0] = '\0';
}

void append_string(string_t *s, char *append) {
    int i, j;
    for (i = 0; i < strlen(append); i++) {
        if (s->length == MAX_LENGTH - 1) {
            printf("Error: String is full.\n");
            return;
        }
        s->string[s->length++] = append[i];
    }
    s->string[s->length] = '\0';
}

void print_string(string_t *s) {
    printf("%s", s->string);
}

void reverse_string(string_t *s) {
    int i, j;
    char temp;
    for (i = 0, j = s->length - 1; i < j; i++, j--) {
        temp = s->string[i];
        s->string[i] = s->string[j];
        s->string[j] = temp;
    }
}

void capitalize_string(string_t *s) {
    int i;
    for (i = 0; i < s->length; i++) {
        if (isalpha(s->string[i])) {
            s->string[i] = toupper(s->string[i]);
        }
    }
}

int main() {
    string_t s;
    char input[MAX_LENGTH];

    initialize_string(&s);

    printf("Enter a string: ");
    scanf("%s", input);

    append_string(&s, input);
    print_string(&s);

    reverse_string(&s);
    print_string(&s);

    capitalize_string(&s);
    print_string(&s);

    return 0;
}