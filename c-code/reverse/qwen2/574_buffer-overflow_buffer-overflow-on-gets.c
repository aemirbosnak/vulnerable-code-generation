#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#define MAX_LEN 100

int main() {
    char buffer[MAX_LEN];
    printf("Enter some text: ");
    gets(buffer);

    if (buffer[0] == 'a') {
        if (buffer[1] == 'b') {
            if (buffer[2] == 'c') {
                if (buffer[3] == 'd') {
                    if (buffer[4] == 'e') {
                        if (buffer[5] == 'f') {
                            if (buffer[6] == 'g') {
                                if (buffer[7] == 'h') {
                                    if (buffer[8] == 'i') {
                                        if (buffer[9] == 'j') {
                                            printf("Keyword detected!\n");
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
