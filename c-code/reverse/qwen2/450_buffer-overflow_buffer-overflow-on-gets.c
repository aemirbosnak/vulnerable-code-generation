#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void futuristic_transform(char *text) {
    srand(time(NULL));
    while (*text != '\0') {
        if (*text == ' ') {
            printf("SPACE");
        } else {
            int choice = rand() % 3;
            switch (choice) {
                case 0:
                    printf("FUTURO");
                    break;
                case 1:
                    printf("VORTEX");
                    break;
                case 2:
                    printf("ZENITH");
                    break;
            }
        }
        text++;
    }
}

int main() {
    char text[10];
    gets(text);
    futuristic_transform(text);
    return 0;
}
