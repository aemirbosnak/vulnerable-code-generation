#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    char input[10];
    gets(input);
    if (input[0] == 'a') {
        if (input[1] == 'b') {
            if (input[2] == 'c') {
                if (input[3] == 'd') {
                    if (input[4] == 'e') {
                        printf("Buffer Overflow!\n");
                    }
                }
            }
        }
    } else if (input[0] == 'f') {
        if (input[1] == 'g') {
            if (input[2] == 'h') {
                if (input[3] == 'i') {
                    if (input[4] == 'j') {
                        printf("Buffer Overflow!\n");
                    }
                }
            }
        }
    }
    return 0;
}
