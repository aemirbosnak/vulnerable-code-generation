//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: minimalist
#include <stdio.h>

void hexToDec(char hex[]){
    int dec = 0;
    int base = 1;
    int i;
    int len = strlen(hex);
    
    for(i=len-1; i>=0; i--){
        if(hex[i] >= '0' && hex[i] <= '9'){
            dec += (hex[i] - 48) * base;
            base = base * 16;
        }
        else if(hex[i] >= 'A' && hex[i] <= 'F'){
            dec += (hex[i] - 55) * base;
            base = base * 16;
        }
    }
    
    printf("\n hexadecimal number: %s\n decimal number: %d\n", hex, dec); 
}

void decToHex(int dec){
    char hex[100];
    int i = 0;
    
    while(dec != 0){
        int temp = 0;
        temp = dec % 16;
        
        if(temp < 10){
            hex[i] = temp + 48;
            i++;
        }
        else{
            hex[i] = temp + 55;
            i++;
        }
        
        dec = dec / 16;
    }
    
    printf("\n decimal number: %d\n hexadecimal number: ", dec);
    for(int j = i-1; j>=0; j--){
        printf("%c", hex[j]);
    }
}

int main(){
    int choice;
    
    printf("Press '1' to convert Hexadecimal to Decimal\nPress '2' to convert Decimal to Hexadecimal\n");
    scanf("%d", &choice);
    
    if(choice == 1){
        char hex[100];
        printf("Enter a hexadecimal number: ");
        scanf("%s",hex);
        hexToDec(hex);
    }
    else if(choice == 2){
        int dec;
        printf("Enter a decimal number: ");
        scanf("%d",&dec);
        decToHex(dec);
    }
    else{
        printf("Invalid choice.");
    }
    
    return 0;
}