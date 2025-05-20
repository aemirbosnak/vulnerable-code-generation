//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONVERT_NUM 10

typedef struct ConversionRate {
    char currency_from[MAX_CONVERT_NUM];
    char currency_to[MAX_CONVERT_NUM];
    float conversion_factor;
} ConversionRate;

ConversionRate conversion_rates[] = {
    {"USD", "EUR", 0.99},
    {"USD", "GBP", 0.84},
    {"USD", "JPY", 133.22},
    {"EUR", "USD", 1.01},
    {"EUR", "GBP", 0.85},
    {"EUR", "JPY", 138.11},
    {"GBP", "USD", 1.16},
    {"GBP", "EUR", 1.11},
    {"GBP", "JPY", 143.83},
    {"JPY", "USD", 0.0079},
    {"JPY", "EUR", 0.0071},
    {"JPY", "GBP", 0.0069}
};

int main() {
    char currency_from[MAX_CONVERT_NUM];
    char currency_to[MAX_CONVERT_NUM];
    float amount;
    float converted_amount;

    printf("Enter the currency you are converting from: ");
    scanf("%s", currency_from);

    printf("Enter the currency you are converting to: ");
    scanf("%s", currency_to);

    printf("Enter the amount you want to convert: ");
    scanf("%f", &amount);

    for (int i = 0; i < MAX_CONVERT_NUM; i++) {
        if (strcmp(conversion_rates[i].currency_from, currency_from) == 0 && strcmp(conversion_rates[i].currency_to, currency_to) == 0) {
            converted_amount = amount * conversion_rates[i].conversion_factor;
            break;
        }
    }

    if (converted_amount == 0) {
        printf("Error: Conversion rate not found.\n");
    } else {
        printf("The converted amount is: %.2f %s.\n", converted_amount, currency_to);
    }

    return 0;
}