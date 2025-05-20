#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char input[1000];
    printf("Enter your text: ");
    fgets(input, sizeof(input), stdin);

    srand(time(0));

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ') {
            printf("SPACE");
        } else {
            int choice = rand() % 3;
            switch (choice) {
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

    return 0;
}
