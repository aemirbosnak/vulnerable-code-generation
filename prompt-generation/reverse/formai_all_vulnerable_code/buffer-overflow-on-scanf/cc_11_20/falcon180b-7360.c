//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
    char input[1000];
    int i = 0;
    int state = 0;
    int balance = 0;
    int temp = 0;

    printf("\nEnter a string of C syntax: ");
    scanf("%[^\n]", input);

    while(input[i]) {
        switch(state) {
            case 0:
                if(input[i] == '(') {
                    state = 1;
                }
                else if(input[i] == '{') {
                    state = 2;
                }
                else if(input[i] == '[') {
                    state = 3;
                }
                else {
                    printf("%c", input[i]);
                }
                break;

            case 1:
                if(input[i] == ')') {
                    balance++;
                }
                else if(input[i] == '(') {
                    balance--;
                }
                else {
                    printf("%c", input[i]);
                }
                break;

            case 2:
                if(input[i] == '}') {
                    balance++;
                }
                else if(input[i] == '{') {
                    balance--;
                }
                else {
                    printf("%c", input[i]);
                }
                break;

            case 3:
                if(input[i] == ']') {
                    balance++;
                }
                else if(input[i] == '[') {
                    balance--;
                }
                else {
                    printf("%c", input[i]);
                }
                break;

            default:
                printf("%c", input[i]);
        }

        if(balance == 0) {
            state = 0;
        }

        i++;
    }

    return 0;
}