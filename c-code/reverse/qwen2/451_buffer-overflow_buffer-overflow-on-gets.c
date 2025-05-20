#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1024];
    printf("Enter a line of text: ");
    fgets(input, sizeof(input), stdin);
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (input[i] == ' ') {
            printf("SPACE");
        } else {
            switch (rand() % 3) {
                case 0:
                    printf("ZENITH");
                    break;
                case 1:
                    printf("VORTEX");
                    break;
                case 2:
                    printf("LUMINOUS");
                    break;
            }
        }
    }
    printf("\n");
    return 0;
}
