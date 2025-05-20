//FormAI DATASET v1.0 Category: Arithmetic ; Style: ultraprecise
#include <stdio.h>

int main() {
    int num1, num2, num3, result;
    
    printf("Please enter three integers to be added: \n");
    scanf("%d %d %d", &num1, &num2, &num3);
    
    result = num1 + num2 + num3;
    
    printf("Result of addition: %d\n", result);
    
    if(result % 2 == 0) {
        printf("The result is an even number.\n");
    } else {
        printf("The result is an odd number.\n");
    }
    
    printf("Result multiplied by 10: %d\n", result * 10);
    
    float float_result = (float) result;
    
    printf("Result as float: %f\n", float_result);
    
    printf("Largest number entered: %d\n", num1 > num2 ? (num1 > num3 ? num1 : num3) : (num2 > num3 ? num2 : num3));
    
    if(num1 == num2 && num2 == num3) {
        printf("All numbers are equal.\n");
    } else {
        printf("There are no two equal numbers.\n");
    }
    
    if(result > 100) {
        printf("The result is greater than 100.\n");
    } else if(result < 50) {
        printf("The result is smaller than 50.\n");
    } else {
        printf("The result is between 50 and 100 inclusive.\n");
    }
    
    int max_num = num1;
    
    if(num2 > max_num) {
        max_num = num2;
    }
    
    if(num3 > max_num) {
        max_num = num3;
    }
    
    printf("Maximum number: %d\n", max_num);
    
    return 0;
}