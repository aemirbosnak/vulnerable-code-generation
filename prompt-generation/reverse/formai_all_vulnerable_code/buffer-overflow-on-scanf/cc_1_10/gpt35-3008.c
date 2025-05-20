//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: funny
#include <stdio.h>
#include <math.h>

int main() {
    
    printf("Welcome to the Scientific Calculator! Now featuring the world's first and only 'Complaining Mode'! \n");
    
    int operation;
    float num, result;
    printf("Enter a number: ");
    scanf("%f", &num);
    
    printf("Choose an operation: \n");
    printf("1 - Square Root\n");
    printf("2 - Logarithm\n");
    printf("3 - Sine\n");
    printf("4 - Cosine\n");
    printf("5 - Tangent\n");
    printf("6 - Complaining Mode\n");
    printf("7 - Exit\n");
    
    scanf("%d", &operation);

    switch(operation) {
        case 1:
            result = sqrt(num);
            printf("The square root of %.2f is %.2f\n", num, result);
            break;
            
        case 2:
            result = log10(num);
            printf("The logarithm of %.2f is %.2f\n", num, result);
            break;
            
        case 3:
            result = sin(num);
            printf("The sine of %.2f is %.2f\n", num, result);
            break;
            
        case 4:
            result = cos(num);
            printf("The cosine of %.2f is %.2f\n", num, result);
            break;
            
        case 5:
            result = tan(num);
            printf("The tangent of %.2f is %.2f\n", num, result);
            break;
            
        case 6:
            printf("Oh great, Complaining Mode, just what we need! \n");
            printf("What's your problem? ");
            char complaint[100];
            scanf("%s", complaint);
            printf("Well, it's not my fault you're having a bad day, but I guess I'll just compute %f anyway\n", num);
            result = num + 42;
            printf("Here you go, %f, happy now? (I doubt it)\n", result);
            break;
            
        case 7:
            printf("Goodbye! Thanks for using the Scientific Calculator, where we always calculate, no matter how bad your day is ;) \n");
            return 0;

        default:
            printf("That is an invalid input! \n");
            break;
    }
    
    main();
}