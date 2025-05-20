//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: futuristic
#include<stdio.h>
#include<string.h>

void convert_hex_to_decimal(char*);
void convert_decimal_to_hex(int);

int main() {
    int choice=0, decimal=0;
    char hex[20];
    printf("Welcome to the futuristic hexadecimal converter!\n");
    do {
        printf("\nChoose the option from the below menu:\n");
        printf("1. Convert hexadecimal to decimal\n");
        printf("2. Convert decimal to hexadecimal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the hexadecimal number: ");
                scanf("%s", hex);
                convert_hex_to_decimal(hex);
                break;
            case 2:
                printf("Enter the decimal number: ");
                scanf("%d", &decimal);
                printf("The hexadecimal equivalent is: ");
                convert_decimal_to_hex(decimal);
                break;
            case 3:
                printf("Exiting the program.");
                break;
            default:
                printf("Invalid choice, please choose again.");
        }
    } while(choice!=3);
    return 0;
}

void convert_hex_to_decimal(char* hex) {
    int i=0, decimal=0;
    int len = strlen(hex);
    for(i=0; i<len; i++) {
        char c = hex[i];
        int temp = 0;
        if(c>='0' && c<='9') {
            temp = c - '0';
        }
        else if(c>='a' && c<='f') {
            temp = c - 'a' + 10;
        }
        else if(c>='A' && c<='F') {
            temp = c - 'A' + 10;
        }
        decimal = 16*decimal + temp;
    }
    printf("The decimal equivalent is: %d", decimal);
}

void convert_decimal_to_hex(int decimal) {
    int i=0, temp=0;
    char hex[20];
    while(decimal>0) {
        temp = decimal % 16;
        if(temp<10) {
            hex[i] = temp + '0';
        }
        else {
            hex[i] = temp - 10 + 'a';
        }
        decimal /= 16;
        i++;
    }
    for(int j=i-1; j>=0; j--) {
        printf("%c", hex[j]);
    }
}