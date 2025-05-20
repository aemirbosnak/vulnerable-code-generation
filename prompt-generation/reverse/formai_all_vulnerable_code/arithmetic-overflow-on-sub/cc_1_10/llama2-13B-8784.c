//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STR_LEN 1024

void print_string(const char *str) {
    printf("String: %s\n", str);
}

void swap_case(char *str) {
    int i, j;
    char temp;

    for (i = 0; i < strlen(str); i++) {
        if (islower(str[i])) {
            temp = str[i];
            str[i] = toupper(str[i]);
            str[j] = temp;
            j++;
        }
    }
}

void reverse_string(char *str) {
    int i, j;

    for (i = 0; i < strlen(str); i++) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        j--;
    }
}

void generate_random_string(char *str, int len) {
    int i;
    for (i = 0; i < len; i++) {
        str[i] = 'a' + (rand() % 26);
    }
}

int main() {
    char str[MAX_STR_LEN];
    srand(time(NULL));

    printf("Enter a string: ");
    fgets(str, MAX_STR_LEN, stdin);

    print_string(str);

    swap_case(str);
    print_string(str);

    reverse_string(str);
    print_string(str);

    generate_random_string(str, 10);
    print_string(str);

    return 0;
}