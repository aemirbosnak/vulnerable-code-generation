//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the maximum length of the input string
#define MAX_STRING_LENGTH 100

// Define the maximum number of terms in the polynomial
#define MAX_TERMS 10

// Define the structure of a term in the polynomial
typedef struct term {
    int coefficient;
    int exponent;
} term;

// Define the structure of the polynomial
typedef struct polynomial {
    int num_terms;
    term terms[MAX_TERMS];
} polynomial;

// Function to read a string from the user
char* read_string() {
    char* str = malloc(MAX_STRING_LENGTH * sizeof(char));
    if (str == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Enter a polynomial: ");
    scanf("%s", str);
    return str;
}

// Function to parse a string into a polynomial
polynomial parse_polynomial(char* str) {
    polynomial poly;
    poly.num_terms = 0;

    // Split the string into terms
    char* tokens = strtok(str, " ");
    while (tokens != NULL) {
        // Parse the coefficient and exponent of the term
        int coefficient = 0;
        int exponent = 0;
        sscanf(tokens, "%d^%d", &coefficient, &exponent);

        // Add the term to the polynomial
        poly.terms[poly.num_terms].coefficient = coefficient;
        poly.terms[poly.num_terms].exponent = exponent;
        poly.num_terms++;

        // Get the next term
        tokens = strtok(NULL, " ");
    }

    return poly;
}

// Function to evaluate a polynomial at a given value of x
int evaluate_polynomial(polynomial poly, int x) {
    int result = 0;
    for (int i = 0; i < poly.num_terms; i++) {
        result += poly.terms[i].coefficient * pow(x, poly.terms[i].exponent);
    }
    return result;
}

// Function to print a polynomial
void print_polynomial(polynomial poly) {
    for (int i = 0; i < poly.num_terms; i++) {
        printf("%dx^%d + ", poly.terms[i].coefficient, poly.terms[i].exponent);
    }
    printf("\n");
}

int main() {
    // Read a polynomial from the user
    char* str = read_string();

    // Parse the polynomial into a data structure
    polynomial poly = parse_polynomial(str);

    // Evaluate the polynomial at x = 2
    int result = evaluate_polynomial(poly, 2);

    // Print the result
    printf("The value of the polynomial at x = 2 is: %d\n", result);

    // Free the allocated memory
    free(str);

    return 0;
}