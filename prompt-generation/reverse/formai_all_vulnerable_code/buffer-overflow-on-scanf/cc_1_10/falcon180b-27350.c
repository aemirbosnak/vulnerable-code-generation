//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int is_valid_email(char* email) {
    int i = 0;
    int at_count = 0;
    int dot_count = 0;

    while (email[i]!= '\0') {
        if (email[i] == '@') {
            at_count++;
        } else if (email[i] == '.') {
            dot_count++;
        }
        i++;
    }

    if (at_count!= 1 || dot_count < 1) {
        return 0;
    }

    return 1;
}

int main() {
    char input_string[100];
    char temp_string[100];
    int i, j;

    printf("Enter a string: ");
    scanf("%s", input_string);

    strcpy(temp_string, input_string);
    for (i = 0, j = strlen(temp_string) - 1; i < j; i++, j--) {
        char c = temp_string[i];
        temp_string[i] = temp_string[j];
        temp_string[j] = c;
    }

    printf("Reversed string: %s\n", temp_string);

    if (is_valid_email(input_string)) {
        printf("Valid email address\n");
    } else {
        printf("Invalid email address\n");
    }

    return 0;
}