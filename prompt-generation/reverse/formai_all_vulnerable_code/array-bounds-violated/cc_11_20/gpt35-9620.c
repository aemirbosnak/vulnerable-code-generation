//FormAI DATASET v1.0 Category: Syntax parsing ; Style: peaceful
#include <stdio.h>

int main() {
    char c[1000];
    int i, j, flag = 0;

    printf("Enter a string of C code:");
    fgets(c, sizeof(c), stdin);

    for (i = 0; c[i] != '\0'; i++) {
        if (c[i] == '(') {
            j = i + 1;
            while (c[j] != ')') {
                if (c[j] == ';' || c[j] == ':') {
                    flag = 1;
                    break;
                }
                j++;
            }
            if (c[j] == ')') {
                if (flag == 0) {
                    printf("No semi-colon or colon after open parenthesis.\n");
                    break;
                }
                flag = 0;
            }
        }
        else if (c[i] == ')') {
            j = i - 1;
            while (c[j] != '(') {
                if (c[j] == ';') {
                    flag = 1;
                    break;
                }
                j--;
            }
            if (c[j] == '(') {
                if (flag == 0) {
                    printf("No semi-colon after close parenthesis.\n");
                    break;
                }
                flag = 0;
            }
        }
    }

    if (c[i] == '\0')
        printf("Syntax usage is correct!\n");

    return 0;
}