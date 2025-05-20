//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char hex[100], decimal[100], ch;
    int len, i, j, count = 0, flag = 0, digit;
    
    printf("Enter a hexadecimal number: ");
    scanf("%[^\n]", hex);
    len = strlen(hex);
    
    if(len > 8) {
        printf("Error: Input must be a valid hexadecimal number.\n");
        exit(0);
    }
    
    for(i = 0; i < len; i++) {
        ch = hex[i];
        
        if(!isxdigit(ch)) {
            printf("Error: Input must be a valid hexadecimal number.\n");
            exit(0);
        }
    }
    
    for(i = len - 1, j = 0; i >= 0; i--, j++) {
        count++;
        
        if(hex[i] >= '0' && hex[i] <= '9') {
            decimal[j] = hex[i] - '0';
        } else if(hex[i] >= 'A' && hex[i] <= 'F') {
            decimal[j] = hex[i] - 'A' + 10;
        } else if(hex[i] >= 'a' && hex[i] <= 'f') {
            decimal[j] = hex[i] - 'a' + 10;
        } else {
            printf("Error: Input must be a valid hexadecimal number.\n");
            exit(0);
        }
    }
    
    if(count == 0) {
        printf("Error: Input must be a valid hexadecimal number.\n");
        exit(0);
    }
    
    printf("Decimal equivalent: ");
    
    for(i = 0; i < strlen(decimal); i++) {
        printf("%d", decimal[i]);
    }
    
    printf("\n");
    
    return 0;
}