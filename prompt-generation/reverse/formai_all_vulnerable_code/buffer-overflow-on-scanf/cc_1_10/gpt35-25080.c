//FormAI DATASET v1.0 Category: Color Code Converter ; Style: innovative
#include<stdio.h>

char* hexToBinary(char hex[]) {
    int i;
    char *binary;
    binary = (char*)malloc(17);
    binary[16] = '\0';

    for(i=0; hex[i]!='\0'; i++) {
        switch(hex[i]) {
            case '0':
                strcat(binary, "0000");
                break;
            case '1':
                strcat(binary, "0001");
                break;
            case '2':
                strcat(binary, "0010");
                break;
            case '3':
                strcat(binary, "0011");
                break;
            case '4':
                strcat(binary, "0100");
                break;
            case '5':
                strcat(binary, "0101");
                break;
            case '6':
                strcat(binary, "0110");
                break;
            case '7':
                strcat(binary, "0111");
                break;
            case '8':
                strcat(binary, "1000");
                break;
            case '9':
                strcat(binary, "1001");
                break;
            case 'A':
            case 'a':
                strcat(binary, "1010");
                break;
            case 'B':
            case 'b':
                strcat(binary, "1011");
                break;
            case 'C':
            case 'c':
                strcat(binary, "1100");
                break;
            case 'D':
            case 'd':
                strcat(binary, "1101");
                break;
            case 'E':
            case 'e':
                strcat(binary, "1110");
                break;
            case 'F':
            case 'f':
                strcat(binary, "1111");
                break;
            default:
                printf("Error: Invalid hexadecimal digit \n");
        }
    }

    return binary;
}

int hexToDecimal(char hex[]) {
    int decimal = 0, i, value, len;
    len = strlen(hex);
    len--;

    for(i=0; hex[i]!='\0'; i++) {
        if(hex[i]>='0' && hex[i]<='9') {
            value = hex[i] - 48;
        }
        else if(hex[i]>='a' && hex[i]<='f') {
            value = hex[i] - 97 + 10;
        }
        else if(hex[i]>='A' && hex[i]<='F') {
            value = hex[i] - 65 + 10;
        }

        decimal += value * pow(16, len);
        len--;
    }

    return decimal;
}

void decimalToBinary(int decimal) {
    int binary[100], i=0, j;

    while(decimal>0) {
        binary[i] = decimal % 2;
        i++;
        decimal /= 2;
    }

    printf("\nBinary number of Decimal value: ");
    for(j=i-1; j>=0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

void hexToRGB(char hex[]) {
    int r, g, b;
    sscanf(hex, "%02x%02x%02x", &r, &g, &b);

    printf("\nRGB code of Hex code %s is (%d, %d, %d).\n", hex, r, g, b);
}

int main() {
    char hex[10];
    int option, decimal;
    char *binary;

    printf("1. Hex to Binary\n2. Hex to Decimal\n3. Decimal to Binary\n4. Hex to RGB\nChoose an option: ");
    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("\nEnter a hexadecimal number [maximum 4 digits]: ");
            scanf("%s", hex);
            binary = hexToBinary(hex);
            printf("\nBinary number of Hexadecimal value %s: %s\n", hex, binary);
            break;

        case 2:
            printf("\nEnter a hexadecimal number [maximum 4 digits]: ");
            scanf("%s", hex);
            decimal = hexToDecimal(hex);
            printf("\nDecimal number of Hexadecimal value %s: %d\n", hex, decimal);
            break;

        case 3:
            printf("\nEnter a decimal number: ");
            scanf("%d", &decimal);
            decimalToBinary(decimal);
            break;

        case 4:
            printf("\nEnter a hexadecimal number [maximum 6 digits]: ");
            scanf("%s", hex);
            hexToRGB(hex);
            break;

        default:
            printf("\nInvalid option!\n");
            break;
    }

    return 0;
}