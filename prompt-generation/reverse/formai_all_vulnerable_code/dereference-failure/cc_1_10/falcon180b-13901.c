//Falcon-180B DATASET v1.0 Category: Text processing ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1000

typedef struct {
    char *string;
    int length;
} String;

String create_string(char *str) {
    String s;
    s.string = str;
    s.length = strlen(str);
    return s;
}

String concatenate_strings(String s1, String s2) {
    String s;
    s.string = malloc(s1.length + s2.length + 1);
    strcpy(s.string, s1.string);
    strcat(s.string, s2.string);
    s.length = s1.length + s2.length;
    return s;
}

void print_string(String s) {
    printf("%s\n", s.string);
}

int main() {
    char input_string[MAX_STRING_LENGTH];
    String current_string = create_string("");

    printf("Enter a string:\n");
    fgets(input_string, MAX_STRING_LENGTH, stdin);

    int i = 0;
    while (input_string[i]!= '\0') {
        if (isalpha(input_string[i])) {
            current_string = concatenate_strings(current_string, create_string(&input_string[i]));
            i += strlen(&input_string[i]);
        } else {
            i++;
        }
    }

    print_string(current_string);

    return 0;
}