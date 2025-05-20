//FormAI DATASET v1.0 Category: Error handling ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *file = fopen("data.txt", "r");
    char c;

    if(file == NULL) {
        printf("Error opening file.");
        exit(EXIT_FAILURE);
    }

    while((c = fgetc(file)) != EOF) {
        if(!isdigit(c)) {
            printf("Invalid data format.");
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);

    int amount;
    printf("Enter the amount: ");
    if(scanf("%d", &amount) != 1) {
        printf("Invalid amount.");    
        exit(EXIT_FAILURE);
    }

    int rate;
    printf("Enter the interest rate: ");
    if(scanf("%d", &rate) != 1) {
        printf("Invalid interest rate.");
        exit(EXIT_FAILURE);
    }

    int years;
    printf("Enter the number of years: ");
    if(scanf("%d", &years) != 1) {
        printf("Invalid number of years.");
        exit(EXIT_FAILURE);
    }

    if(years < 0) {
        printf("Years cannot be negative.");
        exit(EXIT_FAILURE);
    }

    float result = amount;
    for(int i = 0; i < years; i++) {
        result += (result * rate) / 100;
    }

    printf("After %d years, the investment will be worth %.2f", years, result);

    return 0;
}