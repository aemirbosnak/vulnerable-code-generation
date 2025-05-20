#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void translate(char *alien) {
    int len = strlen(alien);
    for (int i = 0; i < len; ++i) {
        alien[i] = toupper(alien[i]);
    }
}

int main() {
    char alien[100];
    fgets(alien, sizeof(alien), stdin);
    translate(alien);
    printf("%s\n", alien);
    return 0;
}
