//FormAI DATASET v1.0 Category: Calculator ; Style: shocked
#include <stdio.h> 

int main() 
{ 
    printf("Welcome to the most unique calculator you have ever seen!\n"); 
    
    printf("\nPlease enter the operation you want to perform:\n"); 
    printf("(+) Add\n(-) Subtract\n(*) Multiply\n(/) Divide\n"); 
    
    char operator; 
    scanf("%c", &operator); 
    
    printf("\nWow, you chose %c. How adventurous!\n", operator); 
    
    switch(operator) 
    { 
        case '+': 
            printf("\nLet's add some numbers then. Enter the first number: "); 
            double addNum1; 
            scanf("%lf", &addNum1); 
            
            printf("\nDon't stop now. Enter the second number: "); 
            double addNum2; 
            scanf("%lf", &addNum2); 
            
            double addAns = addNum1 + addNum2; 
            
            printf("\nThe sum of %.2lf and %.2lf is %.2lf. Absolutely stunning!\n", addNum1, addNum2, addAns); 
            break; 
        
        case '-': 
            printf("\nSubtraction? Bold choice! Enter the first number: "); 
            double subNum1; 
            scanf("%lf", &subNum1); 
            
            printf("\nDon't be shy now. Enter the second number: "); 
            double subNum2; 
            scanf("%lf", &subNum2); 
            
            double subAns = subNum1 - subNum2; 
            
            printf("\n%.2lf minus %.2lf is equal to %.2lf. Breathtaking!\n", subNum1, subNum2, subAns); 
            break; 
        
        case '*': 
            printf("\nYou chose multiplication. Interesting. Enter the first number: "); 
            double multNum1; 
            scanf("%lf", &multNum1); 
            
            printf("\nKeep'em coming! Enter the second number: "); 
            double multNum2; 
            scanf("%lf", &multNum2); 
            
            double multAns = multNum1 * multNum2; 
            
            printf("\n%.2lf times %.2lf gives you %.2lf. Stunning. I am speechless.\n", multNum1, multNum2, multAns); 
            break; 
        
        case '/': 
            printf("\nYou picked division. Wow, just wow. Enter the first number: "); 
            double divNum1; 
            scanf("%lf", &divNum1); 
            
            printf("\nKeep it up! Enter the second number: "); 
            double divNum2; 
            scanf("%lf", &divNum2); 
            
            double divAns = divNum1 / divNum2; 
            
            printf("\n%.2lf divided by %.2lf equals %.2lf. You are literally a calculator genius!\n", divNum1, divNum2, divAns); 
            break; 
    
        default: 
            printf("\nSorry, I do not recognize that operation. Please run the program again and try with a valid operator.\n"); 
            break; 
    } 
    
    printf("\nThank you for using this amazing calculator. I am truly shocked by your choice of operator. Goodbye!\n"); 
    
    return 0; 
}