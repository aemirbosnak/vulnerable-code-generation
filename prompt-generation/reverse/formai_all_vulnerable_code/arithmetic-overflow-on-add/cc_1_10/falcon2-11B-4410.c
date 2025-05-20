//Falcon2-11B DATASET v1.0 Category: Binary Converter ; Style: happy
#include <stdio.h>
#include <string.h>
#define MAX_NUM 1000

void decimalToBinary(int num, char* str, int len) {
    int i;
    int rem;
    char* str_end = str + len;
    
    while (num > 0) {
        rem = num % 2;
        num /= 2;
        str[i] = '1' + rem;
        i++;
        if (str_end - str >= (len - i)) {
            str[i] = '\0';
            break;
        }
    }
}

int binaryToDecimal(char* str, int len) {
    int i;
    int num = 0;
    int power = 1;
    for (i = len - 1; i >= 0; i--) {
        if (str[i] == '1') {
            num += power;
        }
        power *= 2;
    }
    return num;
}

int main() {
    char str[MAX_NUM + 1];
    int len = sizeof(str) - 1;
    int num;
    int dec_num;
    int bin_num;
    
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    decimalToBinary(num, str, len);
    printf("Binary representation: %s\n", str);
    
    printf("Enter a binary number: ");
    scanf("%s", str);
    bin_num = binaryToDecimal(str, len);
    printf("Decimal representation: %d\n", bin_num);
    
    return 0;
}