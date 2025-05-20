#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char input[100];
    printf("Enter text: ");
    gets(input);
    srand(time(0));
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ') {
            printf("SPACE");
        } else {
            int randNum = rand() % 5;
            switch(randNum) {
                case 0:
                    printf("FUTUROLOGY");
                    break;
                case 1:
                    printf("CYBERNETIC");
                    break;
                case 2:
                    printf("TECHNOLOGICAL");
                    break;
                case 3:
                    printf("INNOVATIVE");
                    break;
                case 4:
                    printf("ADVANCED");
                    break;
            }
        }
    }
    return 0;
}
