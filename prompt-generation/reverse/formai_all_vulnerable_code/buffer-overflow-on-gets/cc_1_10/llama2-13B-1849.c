//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define STRING_SIZE 1024

void print_string(const char *str) {
    printf("%s\n", str);
}

void reverse_string(char *str) {
    int i, j, temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void rotate_string(char *str, int num_rotations) {
    int i, j, temp;
    for (i = 0; i < num_rotations; i++) {
        for (j = 0; j < strlen(str); j++) {
            temp = str[j];
            str[j] = str[j + i];
            str[j + i] = temp;
        }
    }
}

void shuffle_string(char *str) {
    int i, j, temp;
    for (i = 0; i < strlen(str); i++) {
        j = rand() % (i + 1);
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char str[STRING_SIZE];
    gets(str); // read a line of input from the user

    print_string(str); // print the original string

    reverse_string(str); // reverse the string
    print_string(str); // print the reversed string

    rotate_string(str, 3); // rotate the string 3 times
    print_string(str); // print the rotated string

    shuffle_string(str); // shuffle the string
    print_string(str); // print the shuffled string

    return 0;
}