//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

struct string {
    char *str;
    int len;
};

struct string *strings;
int num_strings;

void init_strings() {
    strings = (struct string *) malloc(MAX_SIZE * sizeof(struct string));
    num_strings = 0;
}

void add_string(char *s) {
    if (num_strings >= MAX_SIZE) {
        printf("Error: Maximum number of strings reached!\n");
        exit(1);
    }
    strings[num_strings].str = (char *) malloc((strlen(s) + 1) * sizeof(char));
    strcpy(strings[num_strings].str, s);
    strings[num_strings].len = strlen(s);
    num_strings++;
}

void print_strings() {
    for (int i = 0; i < num_strings; i++) {
        printf("%d. %s (%d)\n", i+1, strings[i].str, strings[i].len);
    }
}

int main() {
    init_strings();
    char str[MAX_SIZE];
    while (1) {
        printf("Enter a string (or type 'done' to finish):\n");
        scanf("%s", str);
        if (strcmp(str, "done") == 0) {
            break;
        }
        add_string(str);
    }
    printf("Strings entered:\n");
    print_strings();
    return 0;
}