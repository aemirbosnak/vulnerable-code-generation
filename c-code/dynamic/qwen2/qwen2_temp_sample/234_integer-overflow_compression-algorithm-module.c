#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compressData(int *data, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i]; // Integer overflow vulnerability here
        if (sum > 2147483647 || sum < -2147483648) {
            printf("Integer overflow detected!\n");
            exit(1);
        }
    }
    printf("Sum: %d\n", sum);
}

int main() {
    int data[] = {2147483640, 10};
    int size = sizeof(data) / sizeof(data[0]);

    compressData(data, size);

    return 0;
}
