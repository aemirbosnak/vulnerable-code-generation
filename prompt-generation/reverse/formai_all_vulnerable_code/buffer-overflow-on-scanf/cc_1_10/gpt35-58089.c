//FormAI DATASET v1.0 Category: Math exercise ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>                                                     
#include <time.h>                                                  
                                                                       
int main() {                                                            
    srand(time(0));                                                    
    int a = rand() % 100;                                               
    int b = rand() % 100;                                               
    
    int sum = a + b;                                                    
    int product = a * b;                                                
    float quotient = (float)a / (float)b;                               
    int difference = a - b;                                             
    
    printf("Welcome to this peaceful math exercise program!\n");        
    printf("The first number is %d and the second number is %d.\n", a, b);
    
    printf("Please enter the sum of the two numbers: ");                 
    int user_sum;                                                        
    scanf("%d", &user_sum);                                              
    
    if(user_sum != sum) {                                                
        printf("Incorrect. The correct answer is %d.\n", sum);           
    } else {                                                             
        printf("Correct! The sum is %d.\n", sum);                         
    }                                                                    
    
    printf("Please enter the product of the two numbers: ");             
    int user_product;                                                    
    scanf("%d", &user_product);                                          
    
    if(user_product != product) {                                        
        printf("Incorrect. The correct answer is %d.\n", product);       
    } else {                                                             
        printf("Correct! The product is %d.\n", product);                 
    }                                                                    
    
    printf("Please enter the quotient of the two numbers (to 2 decimal places): ");
    float user_quotient;                                                 
    scanf("%f", &user_quotient);                                         
    
    if(user_quotient != quotient) {                                      
        printf("Incorrect. The correct answer is %.2f.\n", quotient);    
    } else {                                                             
        printf("Correct! The quotient is %.2f.\n", quotient);             
    }                                                                    
    
    printf("Please enter the difference of the two numbers: ");           
    int user_difference;                                                 
    scanf("%d", &user_difference);                                       
    
    if(user_difference != difference ) {                                 
        printf("Incorrect. The correct answer is %d.\n", difference);    
    } else {                                                             
        printf("Correct! The difference is %d.\n", difference);           
    }                                                                    
    
    printf("Thanks for practicing your math skills today!\n");            
    return 0;                                                             
}