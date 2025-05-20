//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void display_menu();
int get_input(int min, int max);
void convert_to_hex(int num);
int convert_to_decimal(char hex[]);

//main function
int main(){
    int option, num;
    char hex[100];

    do{
        display_menu();
        option = get_input(1, 3);

        switch(option){
            case 1:
                printf("Enter a decimal number: ");
                num = get_input(0, 2147483647);
                printf("The hexadecimal value of %d is ", num);
                convert_to_hex(num);
                break;

            case 2:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hex);
                printf("The decimal value of %s is %d\n", hex, convert_to_decimal(hex));
                break;

            case 3:
                printf("Exiting program...");
                exit(0);
                break;
        }

    }while(option != 3);

    return 0;
}

//function to display the menu
void display_menu(){
    printf("\n=======================\n");
    printf("     HEX CONVERTER     \n");
    printf("=======================\n");
    printf("1. Convert decimal to hexadecimal\n");
    printf("2. Convert hexadecimal to decimal\n");
    printf("3. Exit\n\n");
    printf("Enter your choice: ");
}

//function to get input from user within a range
int get_input(int min, int max){
    int input;

    do{
        scanf("%d", &input);

        if(input < min || input > max){
            printf("Invalid input. Please enter a number between %d and %d: ", min, max);
        }

    }while(input < min || input > max);

    return input;
}

//function to convert decimal to hexadecimal
void convert_to_hex(int num){
    char hex[100];
    int i = 0;

    while(num != 0){
        int rem = num % 16;
        if(rem < 10){
            hex[i++] = rem + 48;
        }
        else{
            hex[i++] = rem + 55;
        }

        num /= 16;
    }

    for(int j = i - 1; j >= 0; j--){
        printf("%c", hex[j]);
    }

    printf("\n");
}

//function to convert hexadecimal to decimal
int convert_to_decimal(char hex[]){
    int decimal = 0, len = 0;

    for(int i = 0; hex[i] != '\0'; i++){
        len++;
    }

    len--;

    for(int i = 0; hex[i] != '\0'; i++){
        if(hex[i] >= '0' && hex[i] <= '9'){
            decimal += (hex[i] - 48) * pow(16,len);
            len--;
        }
        else if(hex[i] >= 'A' && hex[i] <= 'F'){
            decimal += (hex[i] - 55) * pow(16,len);
            len--;
        }
        else if(hex[i] >= 'a' && hex[i] <= 'f'){
            decimal += (hex[i] - 87) * pow(16,len);
            len--;
        }
    }

    return decimal;
}