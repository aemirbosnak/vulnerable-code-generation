//FormAI DATASET v1.0 Category: Binary Converter ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// shape-shift function that converts decimal to binary
void decimal_to_binary(int decimal_num){
    int binary_arr[32];
    int i = 0;
    while(decimal_num > 0){
        binary_arr[i] = decimal_num % 2;
        decimal_num /= 2;
        i++;
    }
    // shape-shifting print statement based on the length of binary number
    printf("Binary number: ");
    if(i < 5){ // if length < 5
        printf("🔴");
        for(int j = i-1; j >= 0; j--){
            if(binary_arr[j]){
                printf("1");
            }
            else{
                printf("0");
            }
        }
        printf("🔴\n");
    }
    else if(i >= 5 && i < 10){ // if length is between 5 and 9
        printf("🟠");
        for(int j = i-1; j >= 0; j--){
            if(binary_arr[j]){
                printf("1");
            }
            else{
                printf("0");
            }
        }
        printf("🟠\n");
    }
    else{ // if length is 10 or more
        printf("🟢");
        for(int j = i-1; j >= 0; j--){
            if(binary_arr[j]){
                printf("1");
            }
            else{
                printf("0");
            }
        }
        printf("🟢\n");
    }
}

int main(){
    int decimal_num;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal_num);
    decimal_to_binary(decimal_num);
    return 0;
}