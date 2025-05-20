//FormAI DATASET v1.0 Category: Data validation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

//function to validate integer input
int validate_int_input() {
    int num;
    char temp[10];
    bool valid = false;
    while (!valid) {
        printf("Please enter an integer: ");
        scanf("%s", temp);
        if (isdigit(temp[0]) || (temp[0] == '-' && isdigit(temp[1]))) {
            num = atoi(temp);
            valid = true;
        }
        else {
            printf("Invalid input! Please try again.\n");
        }
    }
    return num;
}

//function to validate float input
float validate_float_input() {
    float num;
    char temp[10];
    bool valid = false;
    while (!valid) {
        printf("Please enter a float: ");
        scanf("%s", temp);
        int count = 0;
        for (int i = 0; i < strlen(temp); i++) {
            if (isdigit(temp[i])) {
                continue;
            }
            else if (temp[i] == '.' && count == 0) {
                count++;
                continue;
            }
            else {
                count = -1;
                break;
            }
        }
        if (count == 1) {
            num = atof(temp);
            valid = true;
        }
        else {
            printf("Invalid input! Please try again.\n");
        }
    }
    return num;
}

//function to validate char input
char validate_char_input() {
    char ch;
    printf("Please enter a character: ");
    scanf(" %c", &ch);
    return ch;
}

int main() {
    int num = validate_int_input();
    printf("Valid integer entered: %d\n", num);
    float f_num = validate_float_input();
    printf("Valid float entered: %f\n", f_num);
    char character = validate_char_input();
    printf("Valid character entered: %c\n", character);
    return 0;
}