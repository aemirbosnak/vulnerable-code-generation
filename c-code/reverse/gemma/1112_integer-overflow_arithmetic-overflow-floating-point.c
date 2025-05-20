#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int celsius, galactic;
    printf("Enter temperature in Celsius: ");
    scanf("%d", &celsius);

    galactic = (celsius * 2) + 1000000000000000000;

    printf("Temperature in Galactic: %d\n", galactic);

    return 0;
}
