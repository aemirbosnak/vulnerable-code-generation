//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define MAX_STR_LEN 10000

typedef struct {
    char *str;
    int len;
} String;

void init_string(String *s) {
    s->str = (char *)malloc(MAX_STR_LEN * sizeof(char));
    s->len = 0;
    s->str[0] = '\0';
}

void append_string(String *s, char *str) {
    int len = strlen(str);
    if (s->len + len >= MAX_STR_LEN) {
        printf("Error: String is too long\n");
        exit(1);
    }
    strcat(s->str, str);
    s->len += len;
}

void reverse_string(String *s) {
    int i = 0, j = s->len - 1;
    char temp;
    while (i < j) {
        temp = s->str[i];
        s->str[i] = s->str[j];
        s->str[j] = temp;
        i++;
        j--;
    }
}

void capitalize_string(String *s) {
    int i = 0;
    while (s->str[i]!= '\0') {
        if (isalpha(s->str[i])) {
            s->str[i] = toupper(s->str[i]);
        }
        i++;
    }
}

void print_string(String *s) {
    printf("%s\n", s->str);
}

int main() {
    String s1, s2;
    int choice, len;
    char str[100];

    init_string(&s1);
    init_string(&s2);

    do {
        printf("Enter your choice:\n");
        printf("1. Append string\n");
        printf("2. Reverse string\n");
        printf("3. Capitalize string\n");
        printf("4. Print string\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the string to append:\n");
                scanf("%s", str);
                append_string(&s1, str);
                printf("String appended successfully\n");
                break;
            case 2:
                reverse_string(&s1);
                printf("String reversed successfully\n");
                break;
            case 3:
                capitalize_string(&s1);
                printf("String capitalized successfully\n");
                break;
            case 4:
                print_string(&s1);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 5);

    return 0;
}