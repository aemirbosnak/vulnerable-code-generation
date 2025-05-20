//FormAI DATASET v1.0 Category: Binary Converter ; Style: Ken Thompson
#include<stdio.h>

void binary(int dec) {
    if(dec<=1) {
        printf("%d",dec);
        return;
    }
    int rem = dec % 2;
    binary(dec/2);
    printf("%d",rem);
}

int decimal(char bin[20]) {
    int dec = 0, i = 0, j = 0;
    while(bin[i]) {
        if(bin[i] == '1') {
            j = 1;
            dec = dec + j;
        }
        j = j*2;
        i++;
    }
    return dec;
}

int main() {
    int choice;
    
    while(1) {
        printf("Enter 1 to convert decimal to binary.\nEnter 2 to convert binary to decimal.\nEnter 3 to exit.\n");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("\nEnter decimal number: ");
                int dec;
                scanf("%d",&dec);
                printf("Binary conversion of %d is: ",dec);
                binary(dec);
                printf("\n");
                break;
            
            case 2:
                printf("\nEnter binary number: ");
                char bin[20];
                scanf("%s",bin);
                printf("Decimal conversion of %s is: %d\n",bin,decimal(bin));
                break;
            
            case 3:
                printf("Exiting program!\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}