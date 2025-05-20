#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int convert(int temp, char scale) {
    if (scale == 'C') {
        return temp * 9 / 5 + 32;
    } else if (scale == 'G') {
        return (temp - 300) * 1000;
    } else {
        printf("Invalid scale\n");
        return -1;
    }
}

int main() {
    int temp = 300;
    char scale = 'G';
    int result = convert(temp, scale);
    printf("%d\n", result);
    return 0;
}
