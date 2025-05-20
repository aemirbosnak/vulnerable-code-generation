//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numerator;
    int denominator;
} Fraction;

void display(Fraction f) {
    if (f.denominator == 0) {
        printf("O, Fate! The denominator is zero, we are in dire straits!\n");
    } else if (f.numerator == 0) {
        printf("A piteous fraction: 0/1, love's beauty fades to naught.\n");
    } else {
        printf("Oh, sweet love! The fraction is: %d/%d, as stars align.\n", f.numerator, f.denominator);
    }
}

Fraction add(Fraction a, Fraction b) {
    Fraction result;
    result.numerator = (a.numerator * b.denominator) + (b.numerator * a.denominator);
    result.denominator = a.denominator * b.denominator;
    if (result.denominator == 0) printf("What cruel hand writes this? Denominator shall not be ghostly.\n");
    return result;
}

Fraction subtract(Fraction a, Fraction b) {
    Fraction result;
    result.numerator = (a.numerator * b.denominator) - (b.numerator * a.denominator);
    result.denominator = a.denominator * b.denominator;
    return result;
}

Fraction multiply(Fraction a, Fraction b) {
    Fraction result;
    result.numerator = a.numerator * b.numerator;
    result.denominator = a.denominator * b.denominator;
    return result;
}

Fraction divide(Fraction a, Fraction b) {
    Fraction result;
    if (b.numerator == 0) {
        printf("Oh woe! Division by zero, a tragedy for the realm of math.\n");
        result.numerator = 0;
        result.denominator = 0;
    } else {
        result.numerator = a.numerator * b.denominator;
        result.denominator = a.denominator * b.numerator;
    }
    return result;
}

void menu() {
    printf("\n--- A Most Serene Arithmetic Menu ---\n");
    printf("1. Add Fractions\n");
    printf("2. Subtract Fractions\n");
    printf("3. Multiply Fractions\n");
    printf("4. Divide Fractions\n");
    printf("5. Exit\n");
}

int main() {
    Fraction f1, f2, result;
    int choice;

    printf("Enter the numerator for the first fraction, sweet Juliet: ");
    scanf("%d", &f1.numerator);
    printf("Enter the denominator for the first fraction, dear Romeo: ");
    scanf("%d", &f1.denominator);
    
    while (1) {
        menu();
        printf("What choice does thine heart desire? ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the numerator for the second fraction: ");
                scanf("%d", &f2.numerator);
                printf("Enter the denominator for the second fraction: ");
                scanf("%d", &f2.denominator);
                result = add(f1, f2);
                display(result);
                break;
                
            case 2:
                printf("Enter the numerator for the second fraction: ");
                scanf("%d", &f2.numerator);
                printf("Enter the denominator for the second fraction: ");
                scanf("%d", &f2.denominator);
                result = subtract(f1, f2);
                display(result);
                break;

            case 3:
                printf("Enter the numerator for the second fraction: ");
                scanf("%d", &f2.numerator);
                printf("Enter the denominator for the second fraction: ");
                scanf("%d", &f2.denominator);
                result = multiply(f1, f2);
                display(result);
                break;
                
            case 4:
                printf("Enter the numerator for the second fraction: ");
                scanf("%d", &f2.numerator);
                printf("Enter the denominator for the second fraction: ");
                scanf("%d", &f2.denominator);
                result = divide(f1, f2);
                display(result);
                break;
                
            case 5:
                printf("Ah, to part is such sweet sorrow. Farewell, dear user!\n");
                exit(0);
                
            default:
                printf("Alas! That choice is like a hidden dagger—no chance for love here.\n");
                break;
        }
    }
    return 0;
}