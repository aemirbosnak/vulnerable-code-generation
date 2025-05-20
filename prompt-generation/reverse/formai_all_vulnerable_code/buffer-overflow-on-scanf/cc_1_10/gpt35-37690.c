//FormAI DATASET v1.0 Category: Temperature Converter ; Style: decentralized
#include<stdio.h>

float c_to_f(float c_temp){
    return (c_temp * 9/5) + 32;
}

float c_to_k(float c_temp){
    return c_temp + 273.15;
}

void print_menu(){
    printf("\n=========TEMPERATURE CONVERTER=========\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Celsius to Kelvin\n");
    printf("3. Exit\n");
    printf("Enter your choice (1-3): ");
}

int main(){
    int choice;
    float c_temp, f_temp, k_temp;

    do{
        print_menu();
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter Celsius temperature: ");
                scanf("%f", &c_temp);
                f_temp = c_to_f(c_temp);
                printf("%.2f Celsius = %.2f Fahrenheit\n", c_temp, f_temp);
                break;
            case 2:
                printf("Enter Celsius temperature: ");
                scanf("%f", &c_temp);
                k_temp = c_to_k(c_temp);
                printf("%.2f Celsius = %.2f Kelvin\n", c_temp, k_temp);
                break;
            case 3:
                printf("Thank you for using this program!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    }while(choice != 3);

    return 0;
}