#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    char hex[10];
    int num;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    num = 0;
    for (int i = 0; hex[i] != '\0'; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            num = num * 16 + (hex[i] - '0');
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            num = num * 16 + (hex[i] - 'A' + 10);
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            num = num * 16 + (hex[i] - 'a' + 10);
        }
    }

    switch(num) {
        case 1:
            for(int j=0;j<5;j++){
                printf("One\n");
            }
            break;
        case 2:
            for(int k=0;k<3;k++){
                printf("Two\n");
            }
            break;
        default:
            printf("Other\n");
            break;
    }

    return 0;
}
